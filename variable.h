#ifndef VARIABLE_H_
#define VARIABLE_H_

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define DHT11_PIN   2
#define A_Pin       2
#define B_Pin       3
#define C_Pin       4

/* Icon Enumeration */
typedef enum {
        CONNECTING_ICON = 0,
        GPS_ICON = 4,
        SATELLITE_ICON = 6,
        DEVIATION_MAP_ICON = 5,
        COMPASS_ICON = 1,
        ALTIMETER_ICON = 2,
        HARDWARE_ICON = 3
} ICON;

/* Deviation Map Variable */
struct deviMap_s {
        double old_latitude = 0, old_longitude = 0, new_latitude = 0, new_longitude = 0;
        int x_point = 64, y_point = 32, x_change = 0, y_change = 0;
        bool deviationMapStartPointFlag = true;
} deviMap;

/* Logical Variable */
struct logic_s {
        bool lastState = true, newState = false;
} logic;

/* EEPROM Variable */
struct eeprom_s {
        int index = 0, array_index = 0;
        double eeprom_lat, lat_bias, lat_fract[3];
        double eeprom_lng, lng_bias, lng_fract[3];
} eeprom;

/* Menu Variable */
struct menu_s {
        int tab = 0;
        bool switchMenu = false;
        int iconX = 0, iconY = 0;
        bool newTabFlag = false, gpsMenuFlag = false;
        char month[12][4] = {
                "DEC", "JAN", "FEB", "MAR", "APR", "MAY",
                "JUN", "JUL", "AUG", "SEP", "OCT", "NOV"
        };
} menu;

/* Altitude Menu Variable */
struct altitude_graph_s {
        bool pixel = false, drawMesh = true;
        int x_increment = 0, y_altitude = 0;
        float altitude_indicator_old = 0, altitude_indicator_new = 0;
        bool show_altitude_menu = false;
} altitude_graph;

/* GPS Menu Variable */
struct gps_s {
        long satellite_start_up_time = 0;
        bool log_start_point = false, show_question_mark = true;
        double start_latitude = 0, start_longitude = 0;
        double distanceFromStartPoint = 0;
        unsigned long satellite_acquiring_time = 0;

        /* Reception Info */
        int reception_signal_amplitude = 0, hdop_value = 0;
} gps_var;

/* Compass Menu Variable */
struct compass_s {
        bool switch_arrow = false, special_arrow_flag = false;
        unsigned long arrowTick = 0;
        float heading = 0, headingOld = 0, p1 = 0.5, p2 = 0.5;
} compass_var;

/* System Timer Variable */
struct SysClkTmr_s {
        long lastTick = 0;
        bool tickState = false;
} SysClkTmr;

#endif /* End VARIABLE_H_ */
