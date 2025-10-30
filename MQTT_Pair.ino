#include <WiFiS3.h>
#include <MQTTClient.h>

const char WIFI_SSID[] = "SmithWifi";
const char WIFI_PASSWORD[] = "smith123";

const char MQTT_BROKER_ADRRESS[] = "mqtt-dashboard.com";
const int MQTT_PORT = 1883;
const char MQTT_CLIENT_ID[] = "MZ53ZYVBng";
const char MQTT_USERNAME[] = "";
const char MQTT_PASSWORD[] = "";

const char PUBLISH_TOPIC[] = "arduino-uno-r4/sendSmith";
const char SUBSCRIBE_TOPIC[] = "arduino-uno-r4/sendSmith";

const int PUBLISH_INTERVAL = 100;

const int ledPin = 3;

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
    int val = analogRead(A0) / 4;
    String val_str = String(val);
    char messageBuffer[10];
    val_str.toCharArray(messageBuffer, 10);
    mqtt.publish(PUBLISH_TOPIC, messageBuffer);
    Serial.println("Arduino UNO R4 - sent to MQTT:");
    Serial.print("- topic: ");
    Serial.println(PUBLISH_TOPIC);
    Serial.print("- payload:");
    Serial.println(messageBuffer);
}

void messageReceived(String &topic, String &payload)
{
    int val = payload.toInt();
    analogWrite(ledPin, val);
    Serial.println("Arduino UNO R4 - received from MQTT:");
    Serial.println("- topic: " + topic);
    Serial.println("- payload:");
    Serial.println(payload);
}