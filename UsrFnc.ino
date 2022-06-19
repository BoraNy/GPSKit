void drawDottedLineHorizontal(int y) {
  bool invBit = false;
  for (int x = 0; x <= SCREEN_WIDTH; x++) {
    display.drawPixel(x, y, invBit);
    invBit = !invBit;
  }
}

void dataSensIndicator(void) {
  digitalWrite(USR_LED_0, LOW);
  delay(10);
  digitalWrite(USR_LED_0, HIGH);
}

void ShowMenuIcon(int bitmap_id) {
  if (menu.newTabFlag) {
    display.clearDisplay();
    drawBitmap(bitmap_id);
    delay(1000);
    display.clearDisplay();
    menu.newTabFlag = false;
  }
  logic.lastState = true;
}

void saveLocationToEEPROM(void) {
  /* Check if Latitude is negative eg.-45.3251 (EEPROM doesn't support negative value) */
  if (gps_var.start_latitude < 0)
    EEPROM.write(4, 1);  // Address 4 store sign bit (1 Neg, 0 Pos)
  else
    EEPROM.write(4, 0);
  delay(10);  // Give EEPROM 10ms to write data

  /* Convert Laititude float to int and store in EEPROM */
  eeprom.lat_bias = int(abs(gps_var.start_latitude));
  eeprom.lat_fract[0] = gps_var.start_latitude - eeprom.lat_bias;
  eeprom.lat_fract[1] = eeprom.lat_fract[0] - int(eeprom.lat_fract[0] * 1e2) * 1e-2;
  eeprom.lat_fract[2] = eeprom.lat_fract[1] - int(eeprom.lat_fract[1] * 1e4) * 1e-4;

  /* Convert Floating Point to Int */
  eeprom.lat_fract[0] = int(eeprom.lat_fract[0] * 1e2);
  eeprom.lat_fract[1] = int(eeprom.lat_fract[1] * 1e4);
  eeprom.lat_fract[2] = int(eeprom.lat_fract[2] * 1e6);

  /* Save Latitude to EEPROM */
  eeprom.array_index = 0;  // Reset Array Index
  EEPROM.write(0, eeprom.lat_bias);
  for (eeprom.index = 1; eeprom.index < 4; eeprom.index++) {
    EEPROM.write(eeprom.index, eeprom.lat_fract[eeprom.array_index]);
    eeprom.array_index++;
    delay(10);
  }

  /* Check if Longitude is negative (EEPROM doesn't support negative value) */
  if (gps_var.start_longitude < 0)
    EEPROM.write(9, 1);  // Address 9 store sign bit (1 Neg, 0 Pos)
  else
    EEPROM.write(9, 0);
  delay(10); /* Give EEPROM 10ms to write data */

  /* Convert Longitude float to int and store in EEPROM */
  eeprom.lng_bias = int(abs(gps_var.start_longitude));
  eeprom.lng_fract[0] = gps_var.start_longitude - eeprom.lng_bias;
  eeprom.lng_fract[1] = eeprom.lng_fract[0] - int(eeprom.lng_fract[0] * 1e2) * 1e-2;
  eeprom.lng_fract[2] = eeprom.lng_fract[1] - int(eeprom.lng_fract[1] * 1e4) * 1e-4;

  /* Convert Float to Int */
  eeprom.lng_fract[0] = int(eeprom.lng_fract[0] * 1e2);
  eeprom.lng_fract[1] = int(eeprom.lng_fract[1] * 1e4);
  eeprom.lng_fract[2] = int(eeprom.lng_fract[2] * 1e6);

  /* Save Latitude to EEPROM */
  eeprom.array_index = 0; /* Reset Array Index */
  EEPROM.write(5, eeprom.lng_bias);
  for (eeprom.index = 6; eeprom.index < 9; eeprom.index++) {
    EEPROM.write(eeprom.index, eeprom.lng_fract[eeprom.array_index]);
    eeprom.array_index++;
    delay(10);
  }
}

void decodeLocationFromEEPROM(void) {
  /* Read from EEPROM Address 0, Latitude Bias */
  eeprom.lat_bias = EEPROM.read(0);
  eeprom.array_index = 0;  // Reset Array Index

  /* Read from EEPROM Address 1->3, Latitude Decimal */
  for (eeprom.index = 1; eeprom.index < 4; eeprom.index++) {
    eeprom.lat_fract[eeprom.array_index] = EEPROM.read(eeprom.index);
    eeprom.array_index++;
    delay(10);
  }

  /* Reconstruct Latitude data from EEPROM */
  if (EEPROM.read(4) == 1) /* Check Address 4 of EEPROM for sign bit */
    eeprom.eeprom_lat = -(eeprom.lat_bias
                          + eeprom.lat_fract[0] * 1e-2
                          + eeprom.lat_fract[1] * 1e-4
                          + eeprom.lat_fract[2] * 1e-6);
  else
    eeprom.eeprom_lat = eeprom.lat_bias
                        + eeprom.lat_fract[0] * 1e-2
                        + eeprom.lat_fract[1] * 1e-4
                        + eeprom.lat_fract[2] * 1e-6;

  /* Read from EEPROM Address 5, Longitude Bias */
  eeprom.lng_bias = EEPROM.read(5);
  eeprom.array_index = 0;  // Reset Array Index

  /* Read from EEPROM Address 6->8, Longitude Decimal */
  for (eeprom.index = 6; eeprom.index < 9; eeprom.index++) {
    eeprom.lng_fract[eeprom.array_index] = EEPROM.read(eeprom.index);
    eeprom.array_index++;
    delay(10);
  }

  /* Reconstruct Longitude data from EEPROM */
  if (EEPROM.read(9) == 1) /* Check Address 9 for sign bit */
    eeprom.eeprom_lng = -(eeprom.lng_bias
                          + eeprom.lng_fract[0] * 1e-2
                          + eeprom.lng_fract[1] * 1e-4
                          + eeprom.lng_fract[2] * 1e-6);
  else
    eeprom.eeprom_lng = eeprom.lng_bias
                        + eeprom.lng_fract[0] * 1e-2
                        + eeprom.lng_fract[1] * 1e-4
                        + eeprom.lng_fract[2] * 1e-6;
}

static void decodeGPSNMEA(unsigned long ms) {
  unsigned long start = millis();
  do {
    while (ss.available()) gps.encode(ss.read());
  } while ((millis() - start) < ms);
}

void WarningAlert(void) {
  /* Blink LED Using Timer */
  if ((millis() - SysClkTmr.lastTick) >= 500) SysClkTmr.tickState = !SysClkTmr.tickState;
  digitalWrite(LED_BUILTIN, SysClkTmr.tickState);
}

void drawBitmap(int id) {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  if (id == CONNECTING_ICON) {
    display.setCursor(22, 57);
    display.print(F("GPS NAVIGATION"));
    display.drawBitmap(38, 0, connecting_icon, 52, 52, 1);
  }
  if (id == COMPASS_ICON) {
    display.setCursor(19, 57);
    display.print(F("DIGITAL COMPASS"));
    display.drawBitmap(38, 0, compass_logo, 52, 52, 1);
  }
  if (id == ALTIMETER_ICON) {
    display.setCursor(37, 57);
    display.print(F("ALTIMETER"));
    display.drawBitmap(38, 0, altimeter_logo, 52, 52, 1);
  }
  if (id == HARDWARE_ICON) {
    display.setCursor(25, 57);
    display.print(F("HARDWARE INFO"));
    display.drawBitmap(38, 0, task_icon, 52, 52, 1);
  }
  if (id == GPS_ICON) {
    display.setCursor(22, 57);
    display.print(F("GPS NAVIGATION"));
    display.drawBitmap(38, 0, gps_map_icon, 52, 52, 1);
  }
  if (id == DEVIATION_MAP_ICON) {
    display.setCursor(25, 57);
    display.print(F("DEVIATION MAP"));
    display.drawBitmap(38, 0, radar_icon, 52, 52, 1);
  }
  if (id == SATELLITE_ICON) {
    display.setCursor(13, 57);
    display.print(F("SATELLITE TRACKER"));
    display.drawBitmap(38, 0, satellite_tracker_icon, 52, 52, 1);
  }
  display.display();
}