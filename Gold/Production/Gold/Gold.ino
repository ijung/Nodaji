#include <SoftwareSerial.h>
#include "HX711.h"

#define DATA A0
#define CLK A1
HX711 _scale;
SoftwareSerial BTserial(2, 3); // RX | TX

char c = ' ';

char data = 0;            //Variable for storing received data
char data2 = '\0';
void setup()
{
    Serial.begin(115200);
    BTserial.begin(115200);
    _scale.begin(DATA, CLK);
    
    _scale.set_scale(146.95);
    _scale.tare();
    _scale.power_down();
}
void loop()
{
  int weight = 0;
  if (BTserial.available())
  {  
      c = BTserial.read();

      switch(c)
      {
        case 'M':
        case 'm':
          _scale.power_up();
          weight = ((int)((_scale.get_units(10) / 10.0) + 0.5) * 10);
          BTserial.println(weight);
          break;
         case 'T':
         case 't':
          _scale.power_up();
          _scale.tare();
          break;           
      }
      _scale.power_down();
  }
  
  if (Serial.available())
  {
      c =  Serial.read();
      BTserial.write(c);
  }
  
  delay(100);
}

void reset(HX711 scale, int delayMS)
{
  scale.power_down();              // put the ADC in sleep mode
  delay(delayMS);
  scale.power_up();
}

