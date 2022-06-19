/*
    Note: For each floating point value needed 5 memory address
          to store value, hence if first value start with memory Address
          10, so the next memory address for next value would be 16
 */

void writeToEEPROM(int address, double value) {
  int tempAddress = address;
  double tempValue = value, bias = 0;
  double fraction[3] = { 0, 0, 0 };

  /* Check if value is negative */
  if (tempValue < 0) {
    EEPROM.write(tempAddress, 1); /* 1 is negative, for sign bit*/
    delay(10);
  } else {
    EEPROM.write(tempAddress, 0);
    delay(10);
  }

  /* Convert float to int */
  bias = int(abs(tempValue));
  fraction[0] = tempValue - bias;
  fraction[1] = fraction[0] - int(fraction[0] * 1e2) * 1e-2;
  fraction[2] = fraction[1] - int(fraction[1] * 1e4) * 1e-4;

  fraction[0] = int(fraction[0] * 1e2);
  fraction[1] = int(fraction[1] * 1e4);
  fraction[2] = int(fraction[2] * 1e6);

  /* Save value to EEPROM */
  EEPROM.write((tempAddress + 1), bias);
  delay(10);
  EEPROM.write((tempAddress + 2), fraction[0]);
  delay(10);
  EEPROM.write((tempAddress + 3), fraction[1]);
  delay(10);
  EEPROM.write((tempAddress + 4), fraction[2]);
  delay(10);
}

double decodeFromEEPROM(int address) {
  double tempValue = 0;
  int tempAddress = address;
  int bias = 0, fraction[3] = { 0, 0, 0 }, signBit = 0;

  /* Read value from EEPROM address */
  signBit = EEPROM.read(tempAddress);
  delay(10);
  bias = EEPROM.read(tempAddress + 1);
  delay(10);
  fraction[0] = EEPROM.read(tempAddress + 2);
  delay(10);
  fraction[1] = EEPROM.read(tempAddress + 3);
  delay(10);
  fraction[2] = EEPROM.read(tempAddress + 4);
  delay(10);

  /* Reconstruct value to floating point */
  if (signBit == 1) /* Check if value is negative */
  {
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