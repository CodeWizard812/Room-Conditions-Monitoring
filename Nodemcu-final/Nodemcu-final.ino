#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h> //simplifies the process of sending HTTP requests and handling responses
String URL="http://api.thingspeak.com/update?api_key=6JF5WMFN4THKHTH8&field1=";
void setup(){
  Serial.begin(9600);
  WiFi.disconnect();
  delay(500);
  Serial.print("Start connection");
  WiFi.begin("Galaxy","nuke3848");
  while((!(WiFi.status()== WL_CONNECTED))){ 
      delay(200);
      Serial.print("..");
    }
  Serial.println("Connected");
}

void loop(){
  if(Serial.available()>0){
    String data=Serial.readStringUntil('\n');
    if(data.length()>=22){
    float p = 0.0;
    float t = 0.0;
    float h = 0.0;

    // Create a string stream to parse the input string
    String key;
    float value;

    // Use indexOf to find the position of each parameter
    int start = 0;
    int end = data.indexOf(';');

    // Iterate through parameters and extract values
    while (end != -1) {
      String param = data.substring(start, end);

      // Split parameter into key and value
      int colonIndex = param.indexOf(':');
      key = param.substring(0, colonIndex);
      value = param.substring(colonIndex + 1).toFloat();

      // Assign values based on key
      if (key == "T") {
        t = value;
      } else if (key == "H") {
        h = value;
      } else if (key == "P") {
        p = value;
      }

      // Move to the next parameter
      start = end + 1;
      end = data.indexOf(';', start);
    }

    // Handle the last parameter (pressure)
    String lastParam = data.substring(start);
    int lastColonIndex = lastParam.indexOf(':');
    key = lastParam.substring(0, lastColonIndex);
    value = lastParam.substring(lastColonIndex + 1).toFloat();
    if (key == "P") {
      p = value;
    }

    // Print the extracted values
    Serial.print("Temperature:");
    Serial.print(t);
    Serial.print(" Humidity:");
    Serial.print(h);
    Serial.print(" Pressure:");
    Serial.print(p);

    sendData(t,h,p);
    }
  }
}
void sendData(float t, float h, float p){
    WiFiClient client;
    HTTPClient http;
    String newUrl=URL +String(t)+"&field2="+String(h)+"&field3="+String(p);
    http.begin(client,newUrl);
    int responsecode=http.GET();
    String data=http.getString();
    Serial.println(data);
    http.end();
}