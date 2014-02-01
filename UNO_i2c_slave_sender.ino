/* Arduino Uno is used as an i2c slave device that sends information to the master
*  device (Arduino Mega) when requested. The information that is requested its
*  if one of the buttons has been pressed
*/


#include <Wire.h>

const int UNO_i2c_Sender = 2;    // i2c Slave Address used on Arduino Uno

const int buttonH = 8;  // Button H
const int buttonL = 9;  // Button L

char buttonPressed = 'H';  // variable that will be sent to Master  

void setup()
{
  //Serial.begin(9600);
  Wire.begin(UNO_i2c_Sender);   // join i2c bus with address #2
  Wire.onRequest(requestEvent); // register event
}

void loop()
{  
  /* The status of buttonPressed is changed by pressing one of the
  *  two push buttons.
  */
 
  if(digitalRead(buttonH) == HIGH)
  {
    buttonPressed = 'H';
  }
  else if (digitalRead(buttonL)== HIGH)
  {
    buttonPressed = 'L';
  }
  
  delay(100);  
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent()
{
  Wire.write(buttonPressed); // respond to master with the button pressed
}
