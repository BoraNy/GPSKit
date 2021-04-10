void SatelliteTracker(void) {
  /* Dispatch Incoming Characters */
  if (ss.available() > 0) {
    gps.encode(ss.read());
    if (totalGPGSVMessages.isUpdated()) {
      for (int i = 0; i < 4; ++i) {
        int no = atoi(satNumber[i].value());
        if (no >= 1 && no <= MAX_SATELLITES) {
          sats[no - 1].elevation = atoi(elevation[i].value());
          sats[no - 1].azimuth = atoi(azimuth[i].value());
          sats[no - 1].snr = atoi(snr[i].value());
          sats[no - 1].active = true;
        }
      }

      int totalMessages = atoi(totalGPGSVMessages.value());
      int currentMessage = atoi(messageNumber.value());

      if (totalMessages == currentMessage) {
        static int snr[12], satellite_id[12], j = 0;

        /* Get Satellite ID */
        for (int i = 0; i < MAX_SATELLITES; ++i)
          if (sats[i].active) {
            satellite_id[j] = i + 1;
            j++;
          } j = 0;

        /* Max Satellite Reception on Clear Day */
        for (int i = 0; i < MAX_SATELLITES; ++i)
          if (sats[i].active) {
            snr[j] = sats[i].snr;
            j++;
          } j = 0;

        /* Setup GUI Header */
        display.fillRect(0, 0, 128, 9, WHITE);
        display.setTextSize(1);
        display.setTextColor(BLACK);
        display.setCursor(13, 1);   display.print("SATELLITE TRACKER");

        /* Display Satellite Number */
        display.setTextColor(WHITE);
        display.setCursor(80, 11);  display.print(satellite_id[0]);
        display.print(',');         display.print(satellite_id[1]);
        display.print(',');         display.print(satellite_id[2]);

        display.setCursor(80, 21);  display.print(satellite_id[3]);
        display.print(',');         display.print(satellite_id[4]);
        display.print(',');         display.print(satellite_id[5]);

        display.setCursor(80, 31);  display.print(satellite_id[6]);
        display.print(',');         display.print(satellite_id[7]);
        display.print(',');         display.print(satellite_id[8]);

        display.setCursor(80, 41);  display.print(satellite_id[9]);
        display.print(',');         display.print(satellite_id[10]);
        display.print(',');         display.print(satellite_id[11]);

        display.drawLine(78, 51, 128, 51, WHITE);
        display.setCursor(80, 55);
        display.print(F("SAT: "));  display.print(gps.satellites.value());

        /* Display SNR Bar graph */
        for (int i = 10; i < 64; i++) {  /* 25% */
          display.drawPixel(19, i, logic.lastState);
          logic.lastState = !logic.lastState;
        }
        for (int i = 10; i < 64; i++) {  /* 50% */
          display.drawPixel(38, i, logic.lastState);
          logic.lastState = !logic.lastState;
        }
        for (int i = 10; i < 64; i++) {  /* 75% */
          display.drawPixel(57, i, logic.lastState);
          logic.lastState = !logic.lastState;
        }
        display.drawLine(77, 10, 77, 63, WHITE); /* 100% Reception Signal Line */
        display.fillRect(0, 13, map(snr[0], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 17, map(snr[1], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 21, map(snr[2], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 25, map(snr[3], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 29, map(snr[4], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 33, map(snr[5], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 37, map(snr[6], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 41, map(snr[7], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 45, map(snr[8], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 49, map(snr[9], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 53, map(snr[10], 0, 99, 1, 75), 3, WHITE);
        display.fillRect(0, 57, map(snr[11], 0, 99, 1, 75), 3, WHITE);

        /* Reset All Active Satellite Reception State */
        for (int i = 0; i < MAX_SATELLITES; ++i)
          sats[i].active = false;

        if (gps.satellites.value() == 0) {
          display.setTextColor(BLACK);
          display.fillRect(2, 31, 73, 9, WHITE);
          display.setCursor(3, 32);
          display.print(F("ACQUIRING..."));
        }

        display.display();
        display.clearDisplay();
      }
    }
  }
}
