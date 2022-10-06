#include <EEPROM.h>

void setup() {
  for(int i = 0; 1 < 255; i++)
  EEPROM.write(i, 15);
}

void loop() {

}
