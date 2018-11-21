#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char *ssid="PIJUSH_HP6GEN";
const char *psw="pijushhp6gen";
int val;
int sensorPin= A0;
WiFiClient Client ;

unsigned long channelID = 561929;
const char *WriteAPIKey= "KVFLK2MKUSRSA1V8";

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid,psw);
    ThingSpeak.begin(Client);// put your setup code here, to run once:
}

void loop() {
     val=analogRead(sensorPin);
     float mv=(val/1024.0)*3300.0;
     float cel=mv/10.0;
     Serial.println(cel);
     ThingSpeak.writeField(channelID,cel,1,WriteAPIKey);
     delay(100);// put your main code here, to run repeatedly:
}
