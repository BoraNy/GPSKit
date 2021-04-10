void BButtonISR(void) {
  static unsigned long last_interrupt_time = 0;
  if (millis() - last_interrupt_time > 200) {
    menu.tab++;
  }
  menu.newTabFlag = true;
  altitude_graph.drawMesh = true;
  altitude_graph.x_increment = 0;

  /* Reset to Main Menu if Exceeded */
  if (menu.tab > 5) menu.tab = 0;
  last_interrupt_time = millis(); /* Update Interrupt Time */
}

void ButtonIO(void) {
  /* Special Something? */
  while ((!digitalRead(A_Pin)) && (!digitalRead(C_Pin))) {
    menu.tab = 0;
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(1);
    for (int i = 0; i < 128; i++) {
      logic.lastState = !logic.lastState;
      display.drawPixel(i, 32, logic.lastState);
    }
    display.setCursor(25, 1);  display.print(F("PROGRAMMED BY"));
    display.setCursor(43, 11); display.print(F("BORA NY"));
    display.setCursor(28, 51); display.print(F("make.believe"));
    display.display();
  }

  /* Switch to Start Point Logging */
  while (!digitalRead(A_Pin)) {
    display.clearDisplay();
    altitude_graph.x_increment = 0; /* Reset Altitude Graph */
    altitude_graph.drawMesh = true;
    StartPointLog();
  }

  /* Switch to GPS Recption Menu */
  while (!digitalRead(C_Pin)) {
    display.clearDisplay();
    altitude_graph.x_increment = 0; /* Reset Altitude Graph */
    altitude_graph.drawMesh = true;
    receptionSignalGraphMenu();
  }
}
