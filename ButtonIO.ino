void BButtonISR(void) {
        static unsigned long last_interrupt_time = 0;
        if (menu.switchMenu == false) {
                if (millis() - last_interrupt_time > 200) {
                        menu.iconX -= 32;
                        menu.newTabFlag = true;
                }
                last_interrupt_time = millis(); /* Update Interrupt Time */
        }
        /* Clear Old Rectangle */
        display.drawRoundRect(menu.iconX + 32, menu.iconY, 32, 32, 3, BLACK);
}

void AButtonISR(void){
        static unsigned long last_interrupt_time = 0;
        if (millis() - last_interrupt_time > 200) {
                menu.switchMenu = !menu.switchMenu;
                menu.newTabFlag = true;
        }
        display.clearDisplay();
        last_interrupt_time = millis(); /* Update Interrupt Time */
}

void CButton(void)
{
        static unsigned long last_interrupt_time = 0;
        while(!digitalRead(C_Pin)) {
                if (millis() - last_interrupt_time > 200) {
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
                display.setCursor(25, 1);  display.print(F("PROGRAMMED BY"));
                display.setCursor(43, 11); display.print(F("BORA NY"));
                display.setCursor(28, 51); display.print(F("make.believe"));
                display.display();
        }

        /*
           // Switch to Start Point Logging //
           while (!digitalRead(A_Pin)) {
                display.clearDisplay();
                altitude_graph.x_increment = 0; // Reset Altitude Graph //
                altitude_graph.drawMesh = true;
                StartPointLog();
           }
         */

        // Switch to GPS Recption Menu //
        while (!digitalRead(C_Pin)) {
                display.clearDisplay();
                altitude_graph.x_increment = 0; // Reset Altitude Graph //
                altitude_graph.drawMesh = true;
                StartPointLog();
        }
}
