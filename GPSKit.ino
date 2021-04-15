#include "bitmap.h"
#include "variable.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Dusk2Dawn.h>
#include <EEPROM.h>
#include <LSM303.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <dhtnew.h>
#include <math.h>

/* Function Prototypes */
void ShowMenuIcon(int bitmap_id);
void saveLocationToEEPROM(void);
void decodeLocationFromEEPROM(void);
static void decodeGPSNMEA(unsigned long ms);
void WarningAlert(void);
void drawBitmap(int id);
void AltitudeMenu(void);
void ButtonIO(void);
void CompassMenu(void);
void DeviationMap(void);
int getTimeZone(double longitude);
void noReceptionSignal(void);
void GPSMenu(void);
void InfoMenu(void);
void SatelliteTracker(void);
void StartPointLog(void);

/* Create Objects from Classes */
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);
LSM303 compass;
TinyGPSPlus gps;
SoftwareSerial ss(10, 11);
DHTNEW dht11(DHT11_PIN);

/* Config Custom Satellite Tracker Decoder */
TinyGPSCustom totalGPGSVMessages(gps, "GPGSV", 1); /* $GPGSV first element  */
TinyGPSCustom messageNumber(gps, "GPGSV", 2);      /* $GPGSV second element */
TinyGPSCustom satsInView(gps, "GPGSV", 3);         /* $GPGSV third element  */
TinyGPSCustom satNumber[4];                        /* to be initialized later */
TinyGPSCustom elevation[4];
TinyGPSCustom azimuth[4];
TinyGPSCustom snr[4];
static const int MAX_SATELLITES = 40;
struct {
        bool active;
        int elevation, azimuth, snr;
} sats[MAX_SATELLITES];

void setup() {
        /* Check OLED for Error &  Clear Adafruit Logo */
        if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
                while (true)
                        WarningAlert(); // LED Alert if the OLED did not start
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(1, 1);
        display.print(F("[  OK  ] SSD1306"));
        display.display();
        delay(500);

        /* GPIO & Interrupt Setup */
        attachInterrupt(digitalPinToInterrupt(A_Pin), AButtonISR, FALLING);
        attachInterrupt(digitalPinToInterrupt(B_Pin), BButtonISR, FALLING);
        pinMode(A_Pin, INPUT_PULLUP);
        pinMode(B_Pin, INPUT_PULLUP);
        pinMode(C_Pin, INPUT_PULLUP);
        pinMode(LED_BUILTIN, OUTPUT);
        display.setCursor(1, 11);
        display.print(F("[  OK  ] GPIO"));
        display.display();
        delay(500);

        /* SoftwareSerial Setup & Init all the uninitialized TinyGPSCustom objects */
        ss.begin(9600);
        for (int i = 0; i < 4; ++i) {
                satNumber[i].begin(gps, "GPGSV", 4 + 4 * i);  /* offsets 4, 8, 12, 16 */
                elevation[i].begin(gps, "GPGSV", 5 + 4 * i);  /* offsets 5, 9, 13, 17 */
                azimuth[i].begin(gps, "GPGSV", 6 + 4 * i);    /* offsets 6, 10, 14, 18 */
                snr[i].begin(gps, "GPGSV", 7 + 4 * i);        /* offsets 7, 11, 15, 19 */
        }
        display.setCursor(1, 21);
        display.setTextColor(WHITE);
        display.print(F("[  OK  ] NEO-6M"));
        display.display();
        delay(500);

        /* LSM303 Compass Setup */
        Wire.begin();
        compass.init();
        compass.enableDefault();
        compass.m_min = (LSM303::vector<int16_t>) {
                -32767, -32767, -32767
        };
        compass.m_max = (LSM303::vector<int16_t>) {
                +32767, +32767, +32767
        };
        display.setCursor(1, 31);
        display.print(F("[  OK  ] LSM303DLHC"));
        display.display();
        delay(500);

        /* Show DHT11 Initialzaiton Info */
        display.setCursor(1, 41);
        display.print(F("[FAILED] DHT11"));
        display.display();

        /* Blinking Cursor */
        gps_var.show_question_mark = !gps_var.show_question_mark;
        for (int blink = 0; blink < 5; blink++) {
                display.fillRect(1, 51, 7, 7, BLACK); /* Update Screen */
                gps_var.show_question_mark = !gps_var.show_question_mark;
                display.setCursor(1, 51);
                if (gps_var.show_question_mark)
                        display.print('_');
                else
                        display.print(' ');
                display.display();
                delay(300);
        }
        delay(1000);
        display.clearDisplay();

        /* Show Rangeman Car Logo */
        display.drawBitmap(32, 0, cat_rangeman_icon, 64, 64, 1);
        display.display();
        delay(3000);
        display.clearDisplay();
}

void loop() {
        UIMenu();
}
