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
                                        waypoint.x_start = decodeFromEEPROM(
                                                waypoint.waypoint_memory_address[waypoint.waypoint_select]);
                                        /* Read Longitude */
                                        waypoint.y_start = decodeFromEEPROM(
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
                                        display.print(waypoint.x_start, 6);
                                        display.print(',');
                                        display.print(waypoint.y_start, 6);
                                        display.display();
                                        delay(3000);

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
        if(waypoint.scale < 0.00001) waypoint.scale = 0.00001;

        if (gps.satellites.value() == 0) {
                display.fillRect(42, 28, 43, 9, WHITE);
                display.setTextColor(BLACK);
                display.setCursor(43, 29);
                display.print(F("NO DATA"));
        }

        /* Get Distance and Course Between Waypoints */
        waypoint.distance_between_waypoints = gps.distanceBetween(
                waypoint.x_start, waypoint.y_start,
                waypoint.x_now, waypoint.y_now
                );
        waypoint.course_to_waypoint = gps.courseTo(
                waypoint.x_start, waypoint.y_start,
                waypoint.x_now, waypoint.y_now
                );

        /* Reduce Distance Scale */
        waypoint.distance_between_waypoints = waypoint.distance_between_waypoints * waypoint.scale;

        /* Get Current Coordinate */
        waypoint.x_now = gps.location.lat();
        waypoint.y_now = gps.location.lng();

        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(1, 1);
        display.print('x'); display.print(waypoint.scale, 5);
        display.setCursor(1, 56);
        display.print(waypoint.distance_between_waypoints);
        display.print('m');

        /* Draw Home Mark */
        display.drawBitmap(64 + (waypoint.distance_between_waypoints * cos(waypoint.course_to_waypoint * RAD_TO_DEG)),
                           32 + (waypoint.distance_between_waypoints * sin(waypoint.course_to_waypoint * RAD_TO_DEG)), navFlag, 10, 10, 1);

        /* Draw Current Pos Mark */
        display.drawBitmap(59, 27, navCurrentPos, 10, 10, 1);

        /* Draw Line Between Two Way Points*/
        display.drawLine(64, 32,
                         64 + (waypoint.distance_between_waypoints * cos(waypoint.course_to_waypoint * RAD_TO_DEG)),
                         32 + (waypoint.distance_between_waypoints * sin(waypoint.course_to_waypoint * RAD_TO_DEG)), WHITE);

        display.display();
}
