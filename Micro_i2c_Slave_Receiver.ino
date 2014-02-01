/* Arduino Micro is being used as a receiving i2c device that will turn on or off
*  and LED depending on the value received by the master device.
*/
#include <Wire.h>

const int Micro_i2c_Receiver  = 2;   // i2c Slave Address used on Arduino Micro

const int testLED = 13;              // LED used for testing

void setup()
{
  Wire.begin(Micro_i2c_Receiver);    // join i2c bus with address #4
  Wire.onReceive(receiveEvent);      // register event
  Serial.begin(9600);                // start serial for output
  pinMode(testLED,OUTPUT);           // sets testLED as output
  digitalWrite(testLED,HIGH);        // turns on testLED
}

void loop()
{
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(Wire.available())           // loop through all but the last
  {
    char c = Wire.read();           // receive byte as a character
    Serial.print(c);                // print the character
    
    /* Depending on the value sent by the master device the testLED 
    * will be either on or off
    */   
    if (c == 'H')
    {
      digitalWrite(testLED,HIGH);
    }
    else if (c == 'L')
    {
      digitalWrite(testLED,LOW);
    }
    
  }
  
}
