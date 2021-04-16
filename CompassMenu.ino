void CompassMenu(void) {
        compass.read();
        compass_var.heading = atan2(compass.m.y, compass.m.x) * 180 / PI;
        if (compass_var.heading < 0)
                compass_var.heading = 360 + compass_var.heading;

        /* Apply Low Pass Filter for Compass Reading */
        compass_var.heading = compass_var.headingOld * compass_var.p1 +
                              compass_var.heading * compass_var.p2;
        compass_var.headingOld = compass_var.heading;

        display.clearDisplay();
        /* White Rectangle */
        display.fillRect(1, 1, 128, 9, WHITE);
        display.setTextSize(1);
        display.setTextColor(BLACK);
        display.setCursor(19, 2);
        display.print(F("DIGITAL COMPASS"));

        /* Compass GUI */
        display.setTextColor(WHITE);
        display.setTextSize(2);

        /* Compass Heading */
        if ((compass_var.heading > 0) && (compass_var.heading < 10)) /* 1 Chars */
                display.setCursor(116, 39);
        if ((compass_var.heading > 10) && (compass_var.heading < 100)) /* 2 Chars */
                display.setCursor(104, 39);
        if (compass_var.heading > 100) /* 3 Chars */
                display.setCursor(92, 39);
        display.print(int(compass_var.heading));

        /* Cardinal Indicator */
        if (strlen(gps.cardinal(compass_var.heading)) == 1) /* 1 Chars */
                display.setCursor(116, 20);
        if (strlen(gps.cardinal(compass_var.heading)) == 2) /* 2 Chars */
                display.setCursor(104, 20);
        if (strlen(gps.cardinal(compass_var.heading)) == 3) /* 3 Chars */
                display.setCursor(92, 20);
        display.print(gps.cardinal(compass_var.heading));

        /* Compass Indicator */
        display.setTextSize(1);
        display.setCursor(43, 13);
        display.print('N');
        display.setCursor(43, 54);
        display.print('S');
        display.setCursor(22, 34);
        display.print('W');
        display.setCursor(64, 34);
        display.print('E');
        display.drawPixel(45, 37, WHITE);
        display.drawCircle(45, 37, 26, WHITE);

        /* Draw Compass Line */
        int r = 20;

        /* Indicator */
        display.fillCircle(5, 15, 2, WHITE);
        display.setCursor(3, 20); display.print('N');

        /* Pointing North */
        display.drawLine(45, 37,
                         45 + r * cos((360 - compass_var.heading - 90)*M_PI / 180),
                         37 + r * sin((360 -compass_var.heading - 90)*M_PI / 180), WHITE);
        /* Dot North */
        display.fillCircle(45 + r * cos((360 - compass_var.heading - 90)*M_PI / 180),
                           37 + r * sin((360 -compass_var.heading - 90)*M_PI / 180), 2, WHITE);

        /* Heading */
        display.drawLine(45, 37,
                         45 + r * cos((compass_var.heading - 90)*M_PI / 180),
                         37 + r * sin((compass_var.heading - 90)*M_PI / 180), WHITE);

        /* NEWS Indicator */
        if ((int(compass_var.heading) == 0)   || (int(compass_var.heading) == 90) ||
            (int(compass_var.heading) == 180) || (int(compass_var.heading) == 270))
                digitalWrite(LED_BUILTIN, HIGH);
        else
                digitalWrite(LED_BUILTIN, LOW);

        display.display();
}
