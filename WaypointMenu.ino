void WaypointMenu(void)
{
        /*
            Latitude Min/Max: -90 -> 90
            Longitude Min/Max: -180 -> 180
         */

        /* Get Waypoint From EEPROM */
        if(waypoint.isStartUp) {
                while(true) {
                        display.clearDisplay();
                        display.setTextSize(1);
                        display.setTextColor(BLACK);
                        display.fillRect(0, 0, 128, 9, WHITE);
                        display.setCursor(1, 1);
                        display.print(F("SELECT WAYPOINT"));

                        display.setTextColor(WHITE);
                        display.setCursor(1, 29);
                        display.print(F("WAYPOINT: "));
                        display.print(waypoint.waypoint_select);
                        display.setCursor(1, 56);
                        display.print(F("PRESS (B) TO SELECT"));
                        display.display();

                        if (waypoint.waypoint_select > 5) waypoint.waypoint_select = 0;

                        /* Get Waypoint ID */
                        static unsigned long last_interrupt_time = 0;
                        if (!digitalRead(C_Pin)) {
                                if (millis() - last_interrupt_time > 200) {
                                        waypoint.waypoint_select++;
                                }
                                last_interrupt_time = millis(); /* Update Interrupt Time */
                        }

                        /* Get Coordinate From EERPROM */
                        if(!digitalRead(B_Pin)) {
                                if (millis() - last_interrupt_time > 200) {
                                        last_interrupt_time = millis(); /* Update Interrupt Time */
                                        /* Read Latitude */
                                        waypoint.x_goto_lat = decodeFromEEPROM(
                                                waypoint.waypoint_memory_address[waypoint.waypoint_select]);
                                        /* Read Longitude */
                                        waypoint.y_goto_lng = decodeFromEEPROM(
                                                waypoint.waypoint_memory_address[waypoint.waypoint_select] + 6
                                                );

                                        display.clearDisplay();
                                        display.fillRect(0, 0, 128, 9, WHITE);
                                        display.setTextColor(BLACK);
                                        display.setCursor(1, 1);
                                        display.print(F("SELECTED WAYPOINT: "));
                                        display.print(waypoint.waypoint_select);
                                        display.setTextColor(WHITE);

                                        display.setCursor(1, 29);
                                        display.print(waypoint.x_goto_lat, 6);
                                        display.print(',');
                                        display.print(waypoint.y_goto_lng, 6);
                                        display.display();

                                        /* End Select Waypoint */
                                        waypoint.isStartUp = false;

                                        /* Exit Loop */
                                        break;
                                }
                        }
                }
        }

        decodeGPSNMEA(1000);

        /* Read Button to Adjust Scale */
        if(!digitalRead(B_Pin)) {
                static unsigned long last_interrupt_time = 0;
                if (millis() - last_interrupt_time > 200) {
                        waypoint.scale *= 1e-1;
                }
                last_interrupt_time = millis(); /* Update Interrupt Time */
        }
        if(!digitalRead(C_Pin)) {
                static unsigned long last_interrupt_time = 0;
                if (millis() - last_interrupt_time > 200) {
                        waypoint.scale++;
                }
                last_interrupt_time = millis(); /* Update Interrupt Time */
        }

        /* Limit Value */
        if(waypoint.scale > 10) waypoint.scale = 10;
        if(waypoint.scale < 0.0000000001) waypoint.scale = 0.0000000001;

        if (gps.satellites.value() == 0) {
                display.fillRect(42, 28, 43, 9, WHITE);
                display.setTextColor(BLACK);
                display.setCursor(43, 29);
                display.print(F("NO DATA"));
        }

        /* Get Current Coordinate */
        waypoint.x_now = gps.location.lat();
        waypoint.y_now = gps.location.lng();

        /* Get Distance and Course Between Waypoints */
        waypoint.distance_between_waypoints = gps.distanceBetween(
                waypoint.x_goto_lat, waypoint.y_goto_lng,
                waypoint.x_now, waypoint.y_now
                );
        waypoint.course_to_waypoint = gps.courseTo(
                waypoint.x_goto_lat, waypoint.y_goto_lng,
                waypoint.x_now, waypoint.y_now
                );

        /* Reduce Distance Scale */
        waypoint.distance_between_waypoints = waypoint.distance_between_waypoints * waypoint.scale;

        /* Calculate Endpoint Coordinate on Screen */
        waypoint.course_to_waypoint = 360 - waypoint.course_to_waypoint;
        waypoint.screen_x = 64 + waypoint.distance_between_waypoints * cos(waypoint.course_to_waypoint * M_PI / 180);
        waypoint.screen_y = 32 + waypoint.distance_between_waypoints * sin(waypoint.course_to_waypoint * M_PI / 180);

        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(1, 1);
        display.print('x'); display.print(waypoint.scale, 10);
        display.setCursor(1, 56);
        display.print(waypoint.distance_between_waypoints);
        display.print(F("m "));
        display.print(360 - waypoint.course_to_waypoint);
        display.print(F("DEG"));

        /* Draw Current Pos BMP */
        display.drawBitmap(59, 27, navCurrentPos, 10, 10, 1);
        display.drawBitmap((waypoint.screen_x - 2), (waypoint.screen_y - 11), navFlag, 10, 10, 1);

        /* Draw Line from current point to Way point */
        display.drawLine(64, 32, waypoint.screen_x, waypoint.screen_y, WHITE);

        display.display();
}
