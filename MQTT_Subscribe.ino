#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "SmithWifi";
const char WIFI_PASSWORD[] = "smith123";

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th"; //Host ของเว็ป
const int MQTT_PORT = 1883; //เลขนี้เสมอ
const char MQTT_CLIENT_ID[] = "client_d0bce171"; //ClientID ที่เว็ป gen ให้
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

const char PUBLISH_TOPIC[] = "67070179/venus";
const char SUBSCRIBE_TOPIC[] = "67070179/venus";

const int PUBLISH_INTERVAL = 3000; //ส่งทุกๆ /1000 วินาที

const int red = 2;
const int green = 3;
const int blue = 4;

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    digitalWrite(blue, HIGH);
    int status = WL_IDLE_STATUS;
    while (status != WL_CONNECTED)
    {
        Serial.print("Arduino UNO R4 - Attempting to connect to SSID: ");
        Serial.println(WIFI_SSID);
        status = WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
        delay(10000);
    }
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    connectToMQTT();
}

void loop()
{
    if (!mqtt.connected()) // ถ้าหลุด จะเชื่อมต่อใหม่
    {
        connectToMQTT();
    }

    mqtt.loop();
    if (millis() - lastPublishTime > PUBLISH_INTERVAL)
    {
        sendToMQTT();
        
        lastPublishTime = millis();
    }
}

void connectToMQTT()
{
    mqtt.begin(MQTT_BROKER_ADRRESS, MQTT_PORT, network);
    mqtt.onMessage(messageReceived);
    Serial.print("Arduino UNO R4 - Connecting to MQTT broker");
    while (!mqtt.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD))
    {
        Serial.print(".");
        delay(100);
    }
    Serial.println();
    if (!mqtt.connected())
    {
      Serial.println("Arduino UNO R4 - MQTT broker Timeout!");
      return;
    }
    if (mqtt.subscribe(SUBSCRIBE_TOPIC))
    {
        Serial.print("Arduino UNO R4 - Subscribed to the topic: ");
    }
    else
    {
        Serial.print("Arduino UNO R4 - Failed to subscribe to the topic: ");
    }
    Serial.println(SUBSCRIBE_TOPIC);
    Serial.println("Arduino UNO R4 - MQTT broker Connected!");
}

void sendToMQTT()
{
    Serial.println("Arduino UNO R4 - sent to MQTT:");
    Serial.print("- topic: ");
    Serial.println(PUBLISH_TOPIC);
    Serial.print("- payload :");
    Serial.println("Nothing");
}

void messageReceived(String &topic, String &payload)
{
    int value = payload.toInt();
    Serial.println("Get value from MQTT!: " + value);
    if(value >= 36 && value <= 50){
      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
    }
    else if(value >= 26 && value <= 35){
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
    }
    else if(value >= 10 && value <= 25){
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      digitalWrite(blue, HIGH);
    }
    else {
      digitalWrite(red, HIGH);
      digitalWrite(green, HIGH);
      digitalWrite(blue, HIGH);
    }
}