void LogMenu(void){
        static float latMem[6], lngMem[6];
        static int index = 0, writeMemoryAddress = 10;

        /* Max Array Index */
        if(index > 5)
                index = 0;
        /* Max Write EEPROM Address for 6 Coordinates */
        if (writeMemoryAddress > 54)
                writeMemoryAddress = 10;

        /* Clear Current Location to Memory */
        if(!digitalRead(C_Pin)) {
                static unsigned long last_interrupt_time = 0;
                if (millis() - last_interrupt_time > 200) {
                        latMem[index] = gps.location.lat();
                        lngMem[index] = gps.location.lng();
                }
                last_interrupt_time = millis(); /* Update Interrupt Time */

                writeToEEPROM(writeMemoryAddress, gps.location.lat());
                writeMemoryAddress += 6;

                writeToEEPROM(writeMemoryAddress, gps.location.lng());
                writeMemoryAddress += 6;

                index++;
        }

        /* Clear Location Memory */
        while(!digitalRead(B_Pin)) {
                for(int i = 0; i < 6; i++) {
                        latMem[i] = 0;
                        lngMem[i] = 0;
                }
                index = 0;
                break;
        }

        /* Decode 6 Coordinates from EEPROM */
        if(waypoint.isStartUp) {
                writeMemoryAddress = 10;
                index = 0;
                for(int i = 0; i < 7; i++) {
                        latMem[index] = decodeFromEEPROM(writeMemoryAddress);
                        writeMemoryAddress += 6;
                        delay(10);
                        lngMem[index] = decodeFromEEPROM(writeMemoryAddress);
                        writeMemoryAddress += 6;
                        delay(10);
                        index++;
                }
                waypoint.isStartUp = false;
                writeMemoryAddress = 10;
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
