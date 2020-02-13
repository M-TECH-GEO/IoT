// for ESP8266 NocdeMCU 12E.
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

char* ssid = "IoT_LAB";
char* password =  "asdfghjkl";
const char* mqttServer = "192.168.1.135";
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {

  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {

    delay(500);
    Serial.print("..");

  }

  Serial.println("\nConnected to the WiFi network");

  client.setServer(mqttServer, mqttPort);

  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");

    if (client.connect("ESP32Client" )) {

      Serial.println("connected");

    } else {

      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
      Serial.println("Reset");
      delay(1000);

    }
  }
}
void loop() {
  //Serial.println(WiFi.status());
  if (client.connected()) {
  client.publish("outTopic", "GEOINFORMATICS");
  }
}
