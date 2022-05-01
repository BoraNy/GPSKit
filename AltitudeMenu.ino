void AltitudeMenu(void)
{
    /* Reset Graph */
    if (altitude_graph.x_increment > 128)
    {
        altitude_graph.x_increment = 0;
        altitude_graph.drawMesh = true;
        display.clearDisplay();
    }
    display.fillRect(0, 0, 128, 9, WHITE);
    display.setTextSize(1);
    display.setTextColor(BLACK);
    display.setCursor(21, 1);
    display.print(F("ALTITUDE GRAPH"));

    /* Get Altitude Value from GPS Data */
    altitude_graph.altitude_indicator_new = gps.altitude.meters();
    altitude_graph.y_altitude = altitude_graph.altitude_indicator_new;

    /* Draw Altitude Indicator */
    display.fillRect(118, 11, 10, 5, BLACK);
    if (altitude_graph.altitude_indicator_new > altitude_graph.altitude_indicator_old)
        display.drawBitmap(118, 11, rising_icon, 10, 5, 1);
    if (altitude_graph.altitude_indicator_new < altitude_graph.altitude_indicator_old)
        display.drawBitmap(118, 11, falling_icon, 10, 5, 1);
    if (altitude_graph.altitude_indicator_new == altitude_graph.altitude_indicator_old)
        display.drawBitmap(118, 11, no_changing_icon, 10, 5, 1);

    /* Erase old altitude text */
    display.fillRect(1, 11, 118, 7, BLACK);
    display.setTextColor(WHITE);
    display.setCursor(1, 11);
    if (gps.altitude.meters() > 0)
    {
        display.print(gps.altitude.meters());
        display.print('m');
    }
    else
    {
        if (gps_var.show_question_mark)
            display.print(F("NO DATA..."));
        else
            display.print(' ');
        gps_var.show_question_mark = !gps_var.show_question_mark;
    }

    altitude_graph.y_altitude = int(altitude_graph.y_altitude);

    /* Convert Altitude to Appropriate Screen Size */
    if ((altitude_graph.y_altitude > 0) && (altitude_graph.y_altitude <= 100))
        altitude_graph.y_altitude = 64 - map(altitude_graph.y_altitude,
                                             0, 100, 0, 44);

    if ((altitude_graph.y_altitude > 100) && (altitude_graph.y_altitude <= 500))
        altitude_graph.y_altitude = 64 - map(altitude_graph.y_altitude,
                                             0, 500, 0, 44);

    if ((altitude_graph.y_altitude > 500) && (altitude_graph.y_altitude <= 1000))
        altitude_graph.y_altitude = 64 - map(altitude_graph.y_altitude,
                                             0, 1000, 0, 44);

    if ((altitude_graph.y_altitude > 1000) && (altitude_graph.y_altitude <= 5000))
        altitude_graph.y_altitude = 64 - map(altitude_graph.y_altitude,
                                             0, 5000, 0, 44);

    if ((altitude_graph.y_altitude > 5000) && (altitude_graph.y_altitude <= 10000))
        altitude_graph.y_altitude = 64 - map(altitude_graph.y_altitude,
                                             0, 10000, 0, 44);

    /* Limit to 0, We never go under sea level */
    if (altitude_graph.y_altitude <= 0) altitude_graph.y_altitude = 63;

    /* Draw Mesh */
    if (altitude_graph.drawMesh)
    {
        for (int y = 20; y <= 64; y += 6)
            for (int x = 0; x <= 128; x++)
            {
                display.drawPixel(x, y, logic.lastState);
                logic.lastState = !logic.lastState;
            }
        altitude_graph.drawMesh = false;
    }

    /* Draw Altitude Line */
    display.drawLine(altitude_graph.x_increment, 64,
                     altitude_graph.x_increment, altitude_graph.y_altitude,
                     WHITE);
    altitude_graph.x_increment++;
    altitude_graph.altitude_indicator_old = altitude_graph.altitude_indicator_new;

    display.display();
    decodeGPSNMEA(1000);
}
