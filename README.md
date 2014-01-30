This is a simple I2C demo using three Arduinos, one for master and two for slaves. 
Four of the sample codes in the Arduino sketches were modified to make the codes 
for each of the devices (master_reader, master_writer, slave_receiver and slave_sender).
The two sample codes for the master were incorporated and loaded into an Arduino Mega.
The slave_sender code was modified and uploaded into an Arduino Uno and the slave_reader
was modified and uploaded into an Arduino Micro.

The Mega will request information from the Uno and then the Mega will send the information
it has received from the Uno to the Micro. When the Mega requests infromration from the Uno.
the Uno send if one of the two buttons have been pressed and send either and H or an L 
depending on the button. Then the Mega takes this value and sends it to the Micro. The Micro
will turn on or off an LED depending on the value received.

In simple words, the Mega will send a command to the Micro to turn on and LED depending on the
value it has received from the Uno.