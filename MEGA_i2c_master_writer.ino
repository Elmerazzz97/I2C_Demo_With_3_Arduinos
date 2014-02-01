/* Arduino Mega is being used as the master device in this i2c chain,
*  the Mega request information from one of the slave devices (Arduino Uno)
*  and then send the information received to the other slave device
*  (Arduino Micro)
*/

#include <Wire.h>

const int UNO_i2c_Sender = 2;             // i2c Slave Address used on Arduino Uno
const int Micro_i2c_Receiver  = 3;        // i2c Slave Address used on Arduino Micro

char command = 'H';                       // used to send commands to Arduino Micro

void setup()
{
  Wire.begin();                           // join i2c bus (address optional for master)
 // Serial.begin(9600);                   // initializes serial communication at 9600 Baud
}


void loop()
{
  requestCommand(UNO_i2c_Sender,1);
  /*
  Wire.requestFrom(UNO_i2c_Sender, 1);    // request 1 bytes from SLAVE_ADDRESS
  while(Wire.available())    // slave may send less than requested
  { 
    char c = Wire.read(); // receive a byte as character
    Serial.print(c);         // print the character
    if (c == 'S' || c == 'C')
    {
      command = c;
    }
  }
  */
  
  //Serial.println(command);
  
  sendCommand(Micro_i2c_Receiver, command);
  
  /*
  Wire.beginTransmission(Micro_i2c_Receiver); // Transmit to device Micro_i2c_Receiver
  Wire.write(command);
  Wire.endTransmission();
  */

  delay(500);
}

void requestCommand(int slaveAddress,int bytesToRequest)
{
  Wire.requestFrom(slaveAddress, bytesToRequest);    // request # bytes from slaveAddress
  while(Wire.available())                            // slave may send less than requested
  { 
    char c = Wire.read();                            // receive a byte as character
    if (c == 'H' || c == 'L')                        // if the recieve character is H or L then
    {
      command = c;                                   // store it in the variable command
    }
  }
}

void sendCommand(int slaveAddress, char sendCommand)
{
  Wire.beginTransmission(slaveAddress); // Opens transmission to slave device
  Wire.write(sendCommand);              // Sends this command to slave device
  Wire.endTransmission();               // Ends transmission to slave deivce
}
