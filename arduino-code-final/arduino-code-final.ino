#include <Wire.h>// facilitates communication with I2C devices
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

Adafruit_BMP085 bmp;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);//initializes serial communication for debugging purposes
  dht.begin();// initializes communication with the DHT sensor.
  bmp.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float p = 0.0;
  if(!bmp.begin())
  {
    p = NULL;
  }
  else
  {
    p = bmp.readPressure() / 100.0F;
  } 
  
  Serial.print("T:");
  Serial.print(t);
  Serial.print(";H:");
  Serial.print(h);
  Serial.print(";P:");
  Serial.print(p);
  Serial.println();

  delay(1000);
}
