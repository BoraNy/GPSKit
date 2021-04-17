/*
    Note: For each floating point value needed 5 memory address
          to store value, hence if first value start with memory Address
          10, so the next memory address for next value would be 16
 */

void writeToEEPROM(int address, double value){
        double tempValue = value, bias;
        double fraction[3] = {0, 0, 0};

        /* Check if value is negative */
        if(tempValue < 0) {
                EEPROM.write(address, 1); /* 1 is negative, for sign bit*/
                delay(10);
        } else {
                EEPROM.write(address, 0);
                delay(10);
        }

        /* Convert float to int */
        bias = int(abs(tempValue));
        fraction[0] = tempValue - bias;
        fraction[1] = fraction[0] - int(fraction[0] * 1e2) * 1e-2;
        fraction[2] = fraction[1] - int(fraction[1] * 1e4) * 1e-4;

        fraction[0] = int(fraction[0] * 1e2);
        fraction[0] = int(fraction[0] * 1e4);
        fraction[0] = int(fraction[0] * 1e6);

        /* Save value to EEPROM */
        EEPROM.write(address + 1, bias); delay(10);
        EEPROM.write(address + 2, fraction[0]); delay(10);
        EEPROM.write(address + 3, fraction[1]); delay(10);
        EEPROM.write(address + 4, fraction[2]); delay(10);
}

double decodeFromEEPROM(int address){
        double tempValue;
        int bias, fraction[3] = {0, 0, 0}, signBit;

        /* Read value from EEPROM address */
        signBit = EEPROM.read(address); delay(10);
        bias = EEPROM.read(address + 1); delay(10);
        fraction[0] = EEPROM.read(address + 2); delay(10);
        fraction[0] = EEPROM.read(address + 3); delay(10);
        fraction[0] = EEPROM.read(address + 4); delay(10);

        /* Reconstruct value to floating point */
        if(signBit < 0) { /* Check if value is negative */
                tempValue = -(
                        bias
                        + fraction[0] * 1e-2
                        + fraction[1] * 1e-4
                        + fraction[2] * 1e-6);
        } else {
                tempValue = bias
                            + fraction[0] * 1e-2
                            + fraction[1] * 1e-4
                            + fraction[2] * 1e-6;
        }

        return tempValue;
}
