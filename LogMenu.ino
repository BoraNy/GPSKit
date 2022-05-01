void LogMenu(void)
{
    static float latMem[6] = {0, 0, 0, 0, 0, 0},
				 lngMem[6] = {0, 0, 0, 0, 0, 0};
    static int index = 0, writeMemoryAddress = 10;

    /* Decode 6 Coordinates from EEPROM */
    if(waypoint.isStartUp)
    {
        display.clearDisplay();
        display.setCursor(1, 1);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.print(F("DECODING EEPROM..."));
        display.display();

        writeMemoryAddress = 10;
        for(int i = 0; i < 6; i++)
        {
            latMem[i] = decodeFromEEPROM(writeMemoryAddress);
            writeMemoryAddress += 6;
            delay(10);
            lngMem[i] = decodeFromEEPROM(writeMemoryAddress);
            writeMemoryAddress += 6;
            delay(10);
        }
        waypoint.isStartUp = false;
        writeMemoryAddress = 10;
        index = 0;
    }

    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(1, 1);
    display.print(latMem[0], 6);
    display.print(',');
    display.print(lngMem[0], 6);
    display.setCursor(1, 11);
    display.print(latMem[1], 6);
    display.print(',');
    display.print(lngMem[1], 6);
    display.setCursor(1, 21);
    display.print(latMem[2], 6);
    display.print(',');
    display.print(lngMem[2], 6);
    display.setCursor(1, 31);
    display.print(latMem[3], 6);
    display.print(',');
    display.print(lngMem[3], 6);
    display.setCursor(1, 41);
    display.print(latMem[4], 6);
    display.print(',');
    display.print(lngMem[4], 6);
    display.setCursor(1, 51);
    display.print(latMem[5], 6);
    display.print(',');
    display.print(lngMem[5], 6);
    display.display();

    /* Max Array Index */
    if(index > 5)
        index = 0;
    /* Max Write EEPROM Address for 6 Coordinates */
    if (writeMemoryAddress > 76)
        writeMemoryAddress = 10;

    /* Write Current Location to EEPROM */
    if(!digitalRead(C_Pin))
    {
        display.setTextSize(1);
        display.setTextColor(WHITE);
        static unsigned long last_interrupt_time = 0;
        if ((millis() - last_interrupt_time) > 200)
        {
            switch (index)
            {
            case 0:
                display.fillRect(1, 1, 128, 9, BLACK);
                display.setCursor(1, 1);
                display.print(F("WRITING...  "));
                display.print(index);
                break;
            case 1:
                display.fillRect(1, 11, 128, 9, BLACK);
                display.setCursor(1, 11);
                display.print(F("WRITING...  "));
                display.print(index);
                break;
            case 2:
                display.fillRect(1, 21, 128, 9, BLACK);
                display.setCursor(1, 21);
                display.print(F("WRITING...  "));
                display.print(index);
                break;
            case 3:
                display.fillRect(1, 31, 128, 9, BLACK);
                display.setCursor(1, 31);
                display.print(F("WRITING...  "));
                display.print(index);
                break;
            case 4:
                display.fillRect(1, 41, 128, 9, BLACK);
                display.setCursor(1, 41);
                display.print(F("WRITING...  "));
                display.print(index);
                break;
            case 5:
                display.fillRect(1, 51, 128, 9, BLACK);
                display.setCursor(1, 51);
                display.print(F("WRITING...  "));
                display.print(index);
                break;
            }
            display.display();
            latMem[index] = gps.location.lat();
            lngMem[index] = gps.location.lng();
            writeToEEPROM(writeMemoryAddress, latMem[index]);
            writeMemoryAddress += 6;
            writeToEEPROM(writeMemoryAddress, lngMem[index]);
            writeMemoryAddress += 6;
            index++;
        }
        last_interrupt_time = millis(); /* Update Interrupt Time */
    }

    /* Clear Locations in EEPROM */
    while(!digitalRead(B_Pin))
    {
        display.clearDisplay();
        display.setCursor(1, 1);
        display.print(F("ERASING EEPROM..."));
        display.display();

        /* Erase all waypoint memory from EEPROM */
        for(writeMemoryAddress = 10; writeMemoryAddress < 77; writeMemoryAddress++)
        {
            EEPROM.write(writeMemoryAddress, 0);
            delay(10);
        }

        /* Clear Coordinates Array */
        for(int i = 0; i < 6; i++)
        {
            latMem[i] = 0;
            lngMem[i] = 0;
        }
        display.clearDisplay();
        index = 0;
        writeMemoryAddress = 10;
        break;
    }
    decodeGPSNMEA(1000);
}
