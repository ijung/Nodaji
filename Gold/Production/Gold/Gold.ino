/*
* Bluetooh Basic: LED ON OFF - Avishkar
* Coder - Mayoogh Girish
* Website - http://bit.do/Avishkar
* Download the App : https://github.com/Mayoogh/Arduino-Bluetooth-Basic
* This program lets you to control a LED on pin 13 of arduino using a bluetooth module
*/
char data = 0;            //Variable for storing received data
char data2 = '\0';
void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission 
}
void loop()
{
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      data2 = data;
      Serial.print(data);          //Print Value inside data in Serial monitor
            
   }
   else
   {
    if(data2 != '\0')
    {
      Serial.print("\n");
      Serial.print("Rcv Complete.");
      Serial.print("\n");
      data2 = '\0';
    }
    
   }
   delay(10);
}
