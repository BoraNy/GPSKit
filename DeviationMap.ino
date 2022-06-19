void DeviationMap(void) {
  /* Draw NEWS */
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(62, 1);
  display.print('^');
  display.setCursor(121, 29);
  display.print('>');
  display.setCursor(1, 29);
  display.print('<');
  display.setCursor(62, 57);
  display.print('_');

  /* Show Update Satellite Icon */
  display.fillRect(115, 0, 60, 7, BLACK);
  if (gps_var.show_question_mark)
    display.drawBitmap(115, 0, mini_satellite_icon, 13, 7, 1);
  else
    display.print(' ');
  gps_var.show_question_mark = !gps_var.show_question_mark;

  /* Get Startup Coordinate for Start Point */
  if (deviMap.deviationMapStartPointFlag) {
    deviMap.old_latitude = gps.location.lat() * 1e6;
    deviMap.old_longitude = gps.location.lng() * 1e6;
    deviMap.deviationMapStartPointFlag = false;
  }

  /* Get Current Location Coordinate */
  deviMap.new_latitude = gps.location.lat() * 1e6;
  deviMap.new_longitude = gps.location.lng() * 1e6;

  /* Calculate Distance Between Old and New Coordinate */
  display.setCursor(1, 1);
  display.fillRect(0, 0, 30, 9, BLACK);
  display.print(gps.distanceBetween(deviMap.old_latitude / 1e6,
                                    deviMap.old_longitude / 1e6,
                                    deviMap.new_latitude / 1e6,
                                    deviMap.new_longitude / 1e6));
  display.print('m');

  /* In case no GPS connected */
  if (gps.satellites.value() == 0) {
    display.fillRect(42, 28, 43, 9, WHITE);
    display.setTextColor(BLACK);
    display.setCursor(43, 29);
    display.print(F("NO DATA"));
  } else {
    /* Draw Grid */
    for (int x = 7; x <= 121; x++) {
      display.drawPixel(x, 32, logic.lastState);
      logic.lastState = !logic.lastState;
    }
    for (int y = 7; y <= 56; y++) {
      display.drawPixel(64, y, logic.lastState);
      logic.lastState = !logic.lastState;
    }

    /* Draw Point Respond to Update Coordinate */
    display.fillCircle(deviMap.x_point + deviMap.x_change,
                       deviMap.y_point + deviMap.y_change, 1, WHITE);
    delay(10);
    display.display();
    display.fillCircle(deviMap.x_point + deviMap.x_change,
                       deviMap.y_point + deviMap.y_change, 1, BLACK);
    delay(10);
    display.display();
    display.fillCircle(deviMap.x_point + deviMap.x_change,
                       deviMap.y_point + deviMap.y_change, 1, WHITE);
    delay(10);
    display.display();
  }

  /* Calculate Screen Point from Updating Coordinate */
  deviMap.x_change = deviMap.new_latitude - deviMap.old_latitude;
  deviMap.y_change = deviMap.new_longitude - deviMap.old_longitude;

  /* Update Old Coordinate with New Coordinate */
  deviMap.old_latitude = deviMap.new_latitude;
  deviMap.old_longitude = deviMap.new_longitude;

  display.display();
  decodeGPSNMEA(1000); /* Decode GPS Data */
}