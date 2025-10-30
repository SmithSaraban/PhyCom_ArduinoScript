#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "SmithWifi";
const char WIFI_PASSWORD[] = "smith123";

const char MQTT_BROKER_ADRRESS[] = "phycom.it.kmitl.ac.th"; //Host ของเว็ป
const int MQTT_PORT = 1883; //เลขนี้เสมอ
const char MQTT_CLIENT_ID[] = "client_89ef2aca"; //ClientID ที่เว็ป gen ให้
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

const char PUBLISH_TOPIC[] = "67070179/temp";
const char SUBSCRIBE_TOPIC[] = "67070179/temp";

const int PUBLISH_INTERVAL = 3000; //ส่งทุกๆ 3 วินาที

WiFiClient network;
MQTTClient mqtt = MQTTClient(256);

unsigned long lastPublishTime = 0;

void setup()
{
    Serial.begin(9600);
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
    int sensorValue = analogRead(A0);
    float voltage = sensorValue * (5.0 / 1023.0);
    float temperatureC = (voltage-0.6) * 100;
    String val_str = String(temperatureC);
    char messageBuffer[20];
    val_str.toCharArray(messageBuffer, 20);
    mq+tt.publish(PUBLISH_TOPIC, messageBuffer);
    Serial.println("Arduino UNO R4 - sent to MQTT:");
    Serial.print("- topic: ");
    Serial.println(PUBLISH_TOPIC);
    Serial.print("- payload :");
    Serial.println(messageBuffer);
}

void messageReceived(String &topic, String &payload)
{
    float val = payload.toFloat();
    Serial.println("Arduino UNO R4 - received from MQTT:");
    Serial.println("- topic: " + topic);
    Serial.print("- payload: ");
    Serial.print(payload);
    Serial.println(" Celcius");
    delay(10);
}