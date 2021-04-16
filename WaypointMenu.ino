void WaypointMenu(void)
{
        /* Latitude Min/Max: -90 -> 90
           Longitude Min/Max: -180 -> 180
         */

        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(1, 1);

        /* Read Button to Adjust Scale */
        if(!digitalRead(B_Pin)) {
                static unsigned long last_interrupt_time = 0;
                if (millis() - last_interrupt_time > 200) {
                        waypoint.scale -= 5;
                }
                last_interrupt_time = millis(); /* Update Interrupt Time */
        }
        if(!digitalRead(C_Pin)) {
                static unsigned long last_interrupt_time = 0;
                if (millis() - last_interrupt_time > 200) {
                        waypoint.scale += 5;
                }
                last_interrupt_time = millis(); /* Update Interrupt Time */
        }

        /* Limit Value */
        if(waypoint.scale > 50) waypoint.scale = 50;
        if(waypoint.scale < 5) waypoint.scale = 5;

        /* Get Current Coordinate */
        waypoint.x_now = long(gps.location.lat() * 1e6);
        waypoint.y_now = long(gps.location.lng() * 1e6);

        /* Get Coordinate from start point */
        waypoint.x_start = long(static_start_latitude * 1e6);
        waypoint.y_start = long(static_start_logitude * 1e6);


        /* Map Value to Fit the Screen */
        waypoint.x_now = map(waypoint.x_now, -90*1e6, 90*1e6, 5, 128);
        waypoint.y_now = map(waypoint.y_now, -180*1e6, 180*1e6, 5, 64);

        waypoint.x_start = map(waypoint.x_start, -90*1e6, 90*1e6, 5, 128);
        waypoint.y_start = map(waypoint.y_start, -180*1e6, 180*1e6, 5, 64);

        waypoint.x_now = waypoint.x_now * waypoint.scale;
        waypoint.y_now = waypoint.y_now * waypoint.scale;
        waypoint.x_start = waypoint.x_start * waypoint.scale;
        waypoint.y_start = waypoint.y_start * waypoint.scale;

        /* Draw Home Mark */
        display.drawBitmap(waypoint.x_start, waypoint.y_start, navFlag, 10, 10, 1);

        /* Draw Current Pos Mark */
        display.drawBitmap(waypoint.x_now, waypoint.y_now, navCurrentPos, 10, 10, 1);

        /* Draw Line */
        display.drawLine(waypoint.x_start, waypoint.y_start,
                         waypoint.x_now, waypoint.y_now, WHITE);

        display.display();
        decodeGPSNMEA(1000);
}
