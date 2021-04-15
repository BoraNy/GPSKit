void noReceptionSignal(void) {
        /* Show tip if reception time took too long */
        gps_var.satellite_acquiring_time = millis();
        if ((gps.location.lat() == 0) && (gps.location.lng() == 0)
            && (gps_var.satellite_acquiring_time > 180000)) {
                for (int step = 0; step < 5; step++) {
                        logic.lastState = true;
                        display.clearDisplay();
                        display.setTextColor(WHITE);
                        display.setCursor(1, 1);    display.print(F("SIGNAL RECEPTION TOOK"));
                        display.setCursor(40, 11);  display.print(F("TOO LONG"));
                        display.setCursor(13, 39);  display.print(F("CHECK THE ANTENNA"));

                        /* Show Date and Time */
                        display.setCursor(1, 50);
                        display.print(gps.time.hour() + getTimeZone(gps.location.lng()));
                        display.print(':');
                        if (gps.time.minute() < 10) display.print(F("0"));
                        display.print(gps.time.minute());
                        display.print(F(" UTC"));
                        display.setCursor(60, 50);
                        if (gps.date.day() < 10) display.print('0');
                        display.print(gps.date.day());
                        display.print('/');
                        display.print(menu.month[gps.date.month()]);
                        display.print('/');
                        display.print(gps.date.year());
                        gps_var.show_question_mark = !gps_var.show_question_mark;

                        /* Text Flash Info */
                        if (gps_var.show_question_mark) {
                                display.fillRect(0, 24, 128, 9, WHITE);
                                display.setTextColor(BLACK);
                                display.setCursor(19, 25);  display.print(F("ARE YOU INDOOR?"));
                        } else {
                                display.fillRect(0, 24, 128, 9, BLACK);
                                display.setTextColor(WHITE);
                                display.setCursor(19, 25);  display.print(F("ARE YOU INDOOR?"));
                        }
                        display.display();

                        /* Switch to Other Menu */
                        ButtonIO();
                        decodeGPSNMEA(1000);
                }
        }
}

void GPSMenu(void) {
        /* Read and Decode GPS Data */
        decodeGPSNMEA(1000);

        /* Check if time is not yet getting from the satellites */
        if ((gps.location.lat() == 0) && (gps.location.lng() == 0) &&
            (gps.time.hour() == 0) && (gps.time.minute() == 0)) {
                gps_var.satellite_start_up_time = millis();

                display.clearDisplay();
                display.setTextSize(1);
                display.setTextColor(WHITE);

                for (int step = 0; step < 5; step++) {
                        gps_var.show_question_mark = !gps_var.show_question_mark;

                        display.setCursor(4, 1);
                        if (gps_var.show_question_mark) {
                                display.fillRect(0, 0, 128, 9, WHITE);
                                display.setTextColor(BLACK);
                                display.print(F("ACQUIRING SATELLITES"));
                        } else {
                                display.fillRect(0, 0, 128, 9, BLACK);
                                display.setTextColor(WHITE);
                                display.print(F("ACQUIRING SATELLITE"));
                        }
                        display.drawBitmap(37, 10, connecting_icon, 54, 54, WHITE);
                }

                /* If reception took too long show tips */
                noReceptionSignal();
                display.display();
        } else {
                /* Menu After Satellite is Connected */
                /* Start Saving Startup Location */
                if ((!gps_var.log_start_point) && (gps.location.lat() > 0)
                    && (gps.location.lng() > 0)) {
                        gps_var.start_latitude = gps.location.lat();
                        gps_var.start_longitude = gps.location.lng();
                        
                        /* Save Location to EEPROM */
                        saveLocationToEEPROM();

                        /* Set Logging Startup Location to Stop */
                        gps_var.log_start_point = true;
                }
                /* End Saving Startup Location */

                display.clearDisplay();

                display.fillRect(0, 0, 128, 9, WHITE);
                display.setTextSize(1);
                display.setTextColor(BLACK);

                display.setCursor(1, 1);
                display.print(gps.time.hour() + 7);
                display.print(':');
                if (gps.time.minute() < 10) display.print('0');
                display.print(gps.time.minute());

                display.print(':');
                if (gps.time.second() < 10) display.print('0');
                display.print(gps.time.second());

                display.setCursor(62, 1);
                if (gps.date.day() < 10) display.print('0');
                display.print(gps.date.day());

                display.print('/');
                display.print(menu.month[gps.date.month()]);

                display.print('/');
                display.print(gps.date.year());

                /* Draw Split Verticle Line */
                display.drawLine(59, 10, 59, 64, WHITE);

                display.setCursor(1, 11);
                display.setTextColor(WHITE);
                display.print(F("LATITUDE"));
                display.setCursor(65, 11);
                display.print(gps.location.lat(), 6);

                display.setCursor(1, 20);
                display.print(F("LONGITUDE "));
                display.setCursor(65, 20);
                display.print(gps.location.lng(), 6);

                display.setCursor(1, 29);
                display.print(F("ALTITUDE"));

                display.setCursor(65, 29);
                display.print(gps.altitude.meters());
                display.print(F(" m"));

                display.setCursor(1, 38);
                display.print(F("SPEED"));
                display.setCursor(65, 38);
                display.print(gps.speed.kmph());
                display.print(F(" Km/h"));

                display.setCursor(1, 47);
                display.print(F("SATELLITE"));

                display.setCursor(65, 47);
                display.print(gps.satellites.value());

                if (gps.satellites.value() <= 4) {
                        if (gps_var.show_question_mark)
                                display.drawBitmap(80, 47, mini_satellite_icon,
                                                   13, 7, 1);
                        else
                                display.print(' ');
                        gps_var.show_question_mark = !gps_var.show_question_mark;
                }
                else
                        display.drawBitmap(80, 47, mini_satellite_icon, 13, 7, 1); /* Draw Mini Satellite */

                display.setCursor(1, 56);
                display.print(gps.course.deg());
                display.print(F("deg"));
                display.setCursor(65, 56);
                display.print(F("HDOP "));
                display.print(gps.hdop.hdop());

                /* Show Tip When Acquiring Satellite Took Too Long */
                noReceptionSignal();

                display.display();

                if (gps.satellites.value() == 0)
                        digitalWrite(LED_BUILTIN, HIGH);
                else
                        digitalWrite(LED_BUILTIN, LOW);

                /* Show Update Interval Menu */
                while(!digitalRead(B_Pin))
                        receptionSignalGraphMenu();
        }
}

void receptionSignalGraphMenu(void) {
        /* Show Icon once when press and hold */
        if (!digitalRead(A_Pin)) logic.newState = true;
        if (logic.newState == logic.lastState) menu.newTabFlag = true;

        if (menu.newTabFlag) {
                display.setTextSize(1);
                display.setTextColor(WHITE);
                display.clearDisplay();
                display.drawBitmap(40, 0, reception_signal_icon, 54, 54, 1);
                display.setCursor(16, 57);
                display.print(F("RECEPTION SIGNAL"));
                display.display();
                delay(1000);
                display.clearDisplay();
                menu.newTabFlag = false;
                logic.lastState = false;
        }

        display.clearDisplay();
        display.fillRect(0, 0, 128, 9, WHITE);

        display.setTextSize(1);
        display.setTextColor(BLACK);
        display.setCursor(19, 1);
        display.print(F("CONNECTION INFO"));

        display.setTextColor(WHITE);

        /* Do the Signal Reception Update Interval Calculation */
        gps_var.reception_signal_amplitude = map(gps.location.age(), 0, 1000, 1, 127);
        /* Do the HDOP Calculation */
        gps_var.hdop_value = map(gps.hdop.hdop(), 0, 100, 1, 127);

        /* Reception Signal Update */
        display.setCursor(1, 15);
        display.print(F("UPD INTERVAL: "));
        display.print(gps.location.age());
        display.print(F("ms"));
        display.fillRect(0, 25, gps_var.reception_signal_amplitude, 5, WHITE);

        display.setCursor(1, 35);
        display.print(F("HDOP VALUE: "));
        display.print(gps.hdop.hdop());
        display.fillRect(0, 45, gps_var.hdop_value, 5, WHITE);

        display.setCursor(1, 53);
        display.print(F("GPS STARTUP: "));
        /* Convert ms -> s, Minus 7500ms Delay on Startup */
        if (gps_var.satellite_start_up_time == 0)
                gps_var.satellite_start_up_time = 7500;
        display.print(((gps_var.satellite_start_up_time - 7500) / 1000.0F), 2);
        display.print('s');

        /* Read & Decode GPS Data */
        decodeGPSNMEA(1000);

        display.display();
        display.clearDisplay();
}
