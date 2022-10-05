#include <EEPROM.h>

unsigned short current = 0;

void setup() {
  Serial.begin(9600);
  for(int dir = 0; dir < 255; dir++)
    EEPROM.write(dir, 2 * dir);

  for(int pin = 2; pin < 10; pin++)
    pinMode(pin, OUTPUT);
   
   EEPROM.write(10, 15);

}

void loop() {
  int val = EEPROM.read(current);
  
  Serial.print("Dir: ");
  Serial.print(current);
  Serial.print("\t");
  Serial.print("Val: ");
  Serial.println(val);
  for(int d = 0; d < 8; d++){
    int b = (1<<d) & val;
    if (b > 0)
      digitalWrite(2 + d, HIGH);
    else
      digitalWrite(2 + d, LOW);
    }
    delay(1500);
    current++;
    if (current > 254)
      current = 0;
}
