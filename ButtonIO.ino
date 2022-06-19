void AButtonISR(void) {
  static unsigned long last_interrupt_time = 0;
  if ((millis() - last_interrupt_time) > 500) {
    menu.switchMenu = !menu.switchMenu;
    menu.newTabFlag = true;
    altitude_graph.x_increment = 0;
  }
  display.clearDisplay();
  last_interrupt_time = millis(); /* Update Interrupt Time */
}

void BButtonISR(void) {
  static unsigned long last_interrupt_time = 0;
  while (!digitalRead(B_Pin)) {
    if ((millis() - last_interrupt_time) > 200) {
      menu.iconX -= 32;
      menu.newTabFlag = true;
    }
    last_interrupt_time = millis(); /* Update Interrupt Time */
  }
  /* Clear Old Rectangle */
  display.drawRoundRect(menu.iconX + 32, menu.iconY, 32, 32, 3, BLACK);
}

void CButton(void) {
  static unsigned long last_interrupt_time = 0;
  while (!digitalRead(C_Pin)) {
    if ((millis() - last_interrupt_time) > 200) {
      menu.iconX += 32;
      menu.newTabFlag = true;
    }
    last_interrupt_time = millis(); /* Update Interrupt Time */
    display.drawRoundRect(menu.iconX - 32, menu.iconY, 32, 32, 3, BLACK);
  }
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
    display.setCursor(25, 1);
    display.print(F("PROGRAMMED BY"));
    display.setCursor(43, 11);
    display.print(F("BORA NY"));
    display.setCursor(28, 51);
    display.print(F("make.believe"));
    display.display();
  }

  // Switch to GPS Recption Menu //
  while (!digitalRead(C_Pin)) {
    display.clearDisplay();
    altitude_graph.x_increment = 0;  // Reset Altitude Graph //
    altitude_graph.drawMesh = true;
    StartPointLog();
  }
}