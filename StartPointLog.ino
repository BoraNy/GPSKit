void StartPointLog(void) {
  /* Show Icon Once When Press and Hold */
  if (!digitalRead(A_Pin)) logic.newState = true;
  if (logic.newState == logic.lastState) menu.newTabFlag = true;
  if (menu.newTabFlag) {
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.clearDisplay();
    display.drawBitmap(40, 0, route_icon, 54, 54, 1);
    display.setCursor(28, 57);
    display.print(F("DATA LOGGING"));
    display.display();
    delay(1000);
    display.clearDisplay();
    menu.newTabFlag = false;
    logic.lastState = false;
  }

  /* Setup Start Point Log GUI */
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(31, 1);
  display.print(F("START POINT"));
  display.setCursor(1, 11);
  display.print(gps_var.start_latitude, 6);
  display.print(',');
  display.print(gps_var.start_longitude, 6);

  /* Calculation Distance from Start Point */
  display.setCursor(1, 21);
  display.fillRect(0, 20, 128, 9, WHITE);
  display.setTextColor(BLACK);
  display.print(F("DIST. FROM START PNT"));
  display.setCursor(1, 31);
  display.setTextColor(WHITE);

  gps_var.distanceFromStartPoint = gps.distanceBetween(
                                     gps_var.start_latitude, gps_var.start_longitude,
                                     gps.location.lat(), gps.location.lng());

  /* Set Distance From Start Point to 0 if Invalid*/
  if ((gps_var.start_latitude == 0) && (gps_var.start_longitude == 0))
    gps_var.distanceFromStartPoint = 0;
  display.print(gps_var.distanceFromStartPoint, 2);
  display.print('m');

  /* Show Heading Course to Start Point Destination */
  display.print(','); display.print(gps.courseTo(gps.location.lat(), gps.location.lng(),
                                    gps_var.start_latitude, gps_var.start_longitude));
  display.print(F("deg"));

  decodeLocationFromEEPROM(); /* Decode GPS Coordinate from EEPROM */

  display.fillRect(0, 40, 128, 9, WHITE);
  display.setTextColor(BLACK);
  display.setCursor(1, 41);
  display.print(F("EEPROM RECOVERY DATA"));
  display.setCursor(1, 51);
  display.setTextColor(WHITE);
  display.print(eeprom.eeprom_lat, 6);
  display.print(',');
  display.print(eeprom.eeprom_lng, 6);
  display.display();
  display.clearDisplay();
}
