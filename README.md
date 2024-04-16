# Room-Conditions-Monitoring
IoT Project

This contains pressure, humidity and temperature detection as IoT project.
Its a team project for semester 5. For Temperature and Humidity DHT11, for pressure BMP180 is used. Initially data is being sent to Arduino by DHT11 and BMP180. Then by SPI(Serial Peripheral Interface) data is sent to NodeMCU in string form. The data is being retrieved in float form in NodeMCU code and is sent to thingspeak.com.   

The main benefit of this system is you can have multiple sensor data, as using only ESP32(NodeMCU) allows only two sensor connections. Furthermore, the data sent from Arduino to NodeMCU is in string form which reduces the processing time, make system more effiecient.

Then the data is sent to thinkspeak where it being displayed and can be accessed around the globe. It also creates XML, JSON & CSV files for ML uses.

ThingSpeak Link :  https://thingspeak.com/channels/2358684
Channel ID: 2358684