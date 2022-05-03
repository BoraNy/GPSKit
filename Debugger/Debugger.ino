#include <EEPROM.h>

struct eeprom_s
{
	int memoryAddr = 0;
} eeprom;

char serialBuffer[50] = "";

void setup()
{
	Serial.begin(115200);
	
	for(eeprom.memoryAddr = 10; eeprom.memoryAddr < 77; eeprom.memoryAddr++)
	{
		sprintf(serialBuffer, "[%d] = %d",
			    eeprom.memoryAddr, EEPROM.read(eeprom.memoryAddr));
		Serial.println(serialBuffer);
	}
}

void loop()
{
	
}
