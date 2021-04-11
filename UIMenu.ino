void UIMenu(void){
        CButton(); /* Get C Button Input */

        if((menu.iconX > 32) && (menu.iconY == 32)) {
                /* Move Icon Cursor to Home */
                menu.iconX = 0;
                menu.iconY = 0;
        }

        if((menu.iconX < 0) && (menu.iconY == 0)) {
                /* Move Icon Cursor to END */
                menu.iconX = 32;
                menu.iconY = 32;
        }

        if((menu.iconX > 96) && (menu.iconY == 0)) {
                /* Move to Second Line */
                menu.iconX = 0;
                menu.iconY = 32;
        }

        if((menu.iconX < 0) && (menu.iconY == 32)) {
                /* Move to First Line */
                menu.iconX = 96;
                menu.iconY = 0;
        }

        /* Get Tab ID on First Line */
        if ((menu.iconY == 0) && (menu.switchMenu == false)) {
                if(menu.iconX == 0)
                        menu.tab = 0;
                if(menu.iconX == 32)
                        menu.tab = 1;
                if(menu.iconX == 64)
                        menu.tab = 2;
                if(menu.iconX == 96)
                        menu.tab = 3;
        }
        /* Get Tab ID on Second Line */
        if((menu.iconY == 32) && (menu.switchMenu == false)) {
                if(menu.iconX == 0) {
                        menu.tab = 4;
                        altitude_graph.drawMesh = true;
                }
                if(menu.iconX == 32)
                        menu.tab = 5;
        }

        /* Show Menu ID */
        char menuTitle[6][11] = {
                "GPS", "SAT.TRACK", "DEVI.MAP",
                "DIGI.COMP", "ALTI.GRAPH", "SYS.INFO"
        };
        int strLen, xCursor;
        strLen = 6*strlen(menuTitle[menu.tab]);
        xCursor = 128 - strLen;
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(xCursor, 51);
        display.print(menuTitle[menu.tab]);

        /* Draw Menu Icons */
        display.drawBitmap(4, 4, menuGPS, 24, 24, 1);
        display.drawBitmap(36, 4, menuSatellite, 24, 24, 1);
        display.drawBitmap(68, 4, menuRadar, 24, 24, 1);
        display.drawBitmap(100, 4, menuCompass, 24, 24, 1);
        display.drawBitmap(4, 36, menuAltimeter, 24, 24, 1);
        display.drawBitmap(36, 36, menuHardware, 24, 24, 1);
        display.drawRoundRect(menu.iconX, menu.iconY, 32, 32, 3, WHITE);
        display.display();
        /* Clear ID Char */
        display.fillRect(xCursor, 51, strLen, 7, BLACK);

        while (menu.switchMenu) {
                switch (menu.tab) {
                case 0:
                        ShowMenuIcon(GPS_ICON);
                        GPSMenu();
                        ButtonIO();
                        display.clearDisplay();
                        break;

                case 1:
                        ShowMenuIcon(SATELLITE_ICON);
                        SatelliteTracker();
                        ButtonIO();
                        break;

                case 2:
                        ShowMenuIcon(DEVIATION_MAP_ICON);
                        DeviationMap();
                        ButtonIO();
                        display.clearDisplay();
                        break;

                case 3:
                        ShowMenuIcon(COMPASS_ICON);
                        CompassMenu();
                        ButtonIO();
                        display.clearDisplay();
                        break;

                case 4:
                        ShowMenuIcon(ALTIMETER_ICON);
                        AltitudeMenu();
                        ButtonIO();
                        break;

                case 5:
                        ShowMenuIcon(HARDWARE_ICON);
                        InfoMenu();
                        ButtonIO();
                        break;
                }
        }
}
