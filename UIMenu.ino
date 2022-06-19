void UIMenu(void) {
  // AButtonISR();   /* Get A Button Input */
  BButtonISR(); /* Get B Button Input */
  CButton();    /* Get C Button Input */

  if ((menu.iconX > 96) && (menu.iconY == 32)) {
    /* Move Icon Cursor to Home */
    menu.iconX = 0;
    menu.iconY = 0;
  }

  if ((menu.iconX < 0) && (menu.iconY == 0)) {
    /* Move Icon Cursor to END */
    menu.iconX = 96;
    menu.iconY = 32;
  }

  if ((menu.iconX > 96) && (menu.iconY == 0)) {
    /* Move to Second Line */
    menu.iconX = 0;
    menu.iconY = 32;
  }

  if ((menu.iconX < 0) && (menu.iconY == 32)) {
    /* Move to First Line */
    menu.iconX = 96;
    menu.iconY = 0;
  }

  /* Get Tab ID on First Line */
  if ((menu.iconY == 0) && (menu.switchMenu == false)) {
    if (menu.iconX == 0)
      menu.tab = 0;
    if (menu.iconX == 32)
      menu.tab = 1;
    if (menu.iconX == 64)
      menu.tab = 2;
    if (menu.iconX == 96)
      menu.tab = 3;
  }
  /* Get Tab ID on Second Line */
  if ((menu.iconY == 32) && (menu.switchMenu == false)) {
    if (menu.iconX == 0) {
      menu.tab = 4;
      altitude_graph.drawMesh = true;
    }
    if (menu.iconX == 32)
      menu.tab = 5;
    if (menu.iconX == 64)
      menu.tab = 6;
    if (menu.iconX == 96) {
      waypoint.isStartUp = true;
      menu.tab = 7;
    }
  }

  /* Show Clock On Standby */
  menu.tick = millis();
  if (menu.tick - menu.lastTick >= 60000) /* Wait for 1 minute to Standby */
  {
    display.setTextSize(2);
    display.setTextColor(WHITE);
    while (true) {
      menu.lastTick = millis();

      if (!digitalRead(C_Pin)) break;

      decodeGPSNMEA(1000);
      display.clearDisplay();
      display.setCursor(31, 26);
      display.setTextSize(2);
      if ((gps.time.hour() + getTimeZone(gps.location.lng())) < 10)
        display.print(' ');
      display.print(gps.time.hour() + getTimeZone(gps.location.lng()));
      display.print(':');
      if (gps.time.minute() < 10)
        display.print('0');
      display.print(gps.time.minute());

      display.setTextSize(1);
      display.setCursor(94, 25);
      if (gps.time.second() < 10)
        display.print('0');
      display.print(gps.time.second());

      /* Show Time Zone */
      if (getTimeZone(gps.location.lng()) == 0) {
        display.setCursor(94, 34);
        display.print(F("UTC"));
      } else {
        display.setCursor(94, 34);
        display.print(F("GMT"));
        if (getTimeZone(gps.location.lng()) > 0)
          display.print('+');
        display.print(getTimeZone(gps.location.lng()));
      }

      display.display();
    }
    display.clearDisplay();
  }

  /* End Show Clock On Standby */

  /* Draw Menu Icons */
  display.drawBitmap(4, 4, menuGPS, 24, 24, 1);
  display.drawBitmap(36, 4, menuSatellite, 24, 24, 1);
  display.drawBitmap(68, 4, menuRadar, 24, 24, 1);
  display.drawBitmap(100, 4, menuCompass, 24, 24, 1);
  display.drawBitmap(4, 36, menuAltimeter, 24, 24, 1);
  display.drawBitmap(36, 36, menuHardware, 24, 24, 1);
  display.drawBitmap(68, 36, menuLog, 24, 24, 1);
  display.drawBitmap(100, 36, menuNavigation, 24, 24, 1);

  display.drawRoundRect(menu.iconX, menu.iconY, 32, 32, 3, WHITE);
  display.display();

  while (menu.switchMenu) {
    switch (menu.tab) {
      case 0:
        ShowMenuIcon(GPS_ICON);
        GPSMenu();
        ButtonIO();
        dataSensIndicator();
        menu.lastTick = millis();
        display.clearDisplay();
        break;

      case 1:
        ShowMenuIcon(SATELLITE_ICON);
        SatelliteTracker();
        ButtonIO();
        menu.lastTick = millis();
        break;

      case 2:
        ShowMenuIcon(DEVIATION_MAP_ICON);
        DeviationMap();
        ButtonIO();
        dataSensIndicator();
        menu.lastTick = millis();
        break;

      case 3:
        ShowMenuIcon(COMPASS_ICON);
        CompassMenu();
        ButtonIO();
        menu.lastTick = millis();
        display.clearDisplay();
        break;

      case 4:
        ShowMenuIcon(ALTIMETER_ICON);
        AltitudeMenu();
        ButtonIO();
        dataSensIndicator();
        menu.lastTick = millis();
        break;

      case 5:
        ShowMenuIcon(HARDWARE_ICON);
        InfoMenu();
        ButtonIO();
        dataSensIndicator();
        menu.lastTick = millis();
        break;

      case 6:
        LogMenu();
        dataSensIndicator();
        menu.lastTick = millis();
        break;

      case 7:
        WaypointMenu();
        dataSensIndicator();
        menu.lastTick = millis();
        display.clearDisplay();
        break;
    }
  }
}