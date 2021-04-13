void LogMenu(void){
        static float latMem[6], lngMem[6];
        static int index = 0;

        if(index > 5)
                index = 0;

        /* Clear Current Location to Memory */
        if(!digitalRead(C_Pin)) {
                static unsigned long last_interrupt_time = 0;
                if (millis() - last_interrupt_time > 200) {
                        latMem[index] = gps.location.lat();
                        lngMem[index] = gps.location.lng();
                        index++;
                }
                last_interrupt_time = millis(); /* Update Interrupt Time */
        }

        /* Clear Location Memory */
        while(!digitalRead(B_Pin)){
          for(int i = 0; i < 6; i++){
            latMem[i] = 0;
            lngMem[i] = 0;
          }
          break;
        }

        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);

        display.setCursor(1, 1);
        display.print(latMem[0], 6); display.print(','); display.print(lngMem[0], 6);
        display.setCursor(1, 11);
        display.print(latMem[1], 6); display.print(','); display.print(lngMem[1], 6);
        display.setCursor(1, 21);
        display.print(latMem[2], 6); display.print(','); display.print(lngMem[2], 6);
        display.setCursor(1, 31);
        display.print(latMem[3], 6); display.print(','); display.print(lngMem[3], 6);
        display.setCursor(1, 41);
        display.print(latMem[4], 6); display.print(','); display.print(lngMem[4], 6);
        display.setCursor(1, 51);
        display.print(latMem[5], 6); display.print(','); display.print(lngMem[5], 6);
        display.display();
        decodeGPSNMEA(1000);
}
