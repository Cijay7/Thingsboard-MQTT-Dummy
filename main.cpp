#include <WiFi.h>
#include <ThingsBoard.h>
#include <Arduino_MQTT_Client.h>
#include <Update.h>
#include <ArduinoHttpClient.h>
// #include <Adafruit_SSD1306.h>

// #define SCREEN_WIDTH 128 // OLED display width, in pixels
// #define SCREEN_HEIGHT 32 
// #define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
// #define SCREEN_ADDRESS 0x3C
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

String wifiSSID = "Crocodic Frontend";
String wifiPassword = "crocodichebat";

#define TB_SERVER "thingsboard.cloud"
#define TOKEN "7iiz1xihn5b5m8twlmk7"

constexpr uint16_t MAX_MESSAGE_SIZE = 512U;

WiFiClient espClient;
Arduino_MQTT_Client mqttClient(espClient);
ThingsBoard tb(mqttClient, MAX_MESSAGE_SIZE);

void connectToWiFi() {
  if (WiFi.status() == WL_CONNECTED) return;  // Only connect if not already connected
  Serial.println("Connecting to WiFi...");
  
  WiFi.begin(wifiSSID.c_str(), wifiPassword.c_str());  // Use wifiSSID and wifiPassword
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi");
  } else {
    Serial.println("\nFailed to connect to WiFi.");
  }
}

void connectToThingsBoard() {
  if (!tb.connected()) {
    Serial.println("Connecting to ThingsBoard server");
    
    if (!tb.connect(TB_SERVER, TOKEN)) {
      Serial.println("Failed to connect to ThingsBoard");
    } else {
      Serial.println("Connected to ThingsBoard");
    }
  }
}

void sendDataToThingsBoard(float temp, int hum, float s1,float s2,float s3,float s4,float s5,float s6,float s7,float s8,float s9,float s10,float s11,float s12) {
  String jsonData = "{\"temperature\":" + String(temp) + ", \"humidity\":" + String(hum) + ", \"accident\":" + String(s1) + ", \"airheight\":" + String(s2) + ", \"cumulativeflow\":" + String(s3) + ", \"flowdirection\":" + String(s4) + ", \"flowratesignal\":" + String(s5) + ", \"inputvoltage\":" + String(s6) + ", \"instantaneousflow\":" + String(s7) + ", \"largeinstantaneousflow\":" + String(s8) + ", \"velocityofflow\":" + String(s9) + ", \"verticalangel\":" + String(s10) + ", \"waterlevel\":" + String(s11) + ", \"waterlevelsignal\":" + String(s12) + "}";
  tb.sendTelemetryJson(jsonData.c_str());
  Serial.println("Data sent");
}

float randTemp() {
  return random(2500, 3000) / 100.0;  // Random float between 25.00 and 30.00
}

float randHum() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand1() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand2() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand3() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand4() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand5() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand6() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand7() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand8() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand9() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand10() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand11() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}

float rand12() {
  return random(100, 10000) / 100.0;  // Random float between 40.00 and 60.00
}
void setup() {
  Serial.begin(115200);
  // display.display();
  connectToWiFi();
  connectToThingsBoard();
}

void loop() {
  connectToWiFi();  // Reconnect to WiFi if disconnected
  
  if (!tb.connected()) {
    connectToThingsBoard();
  }
  
  tb.loop();  // Maintain ThingsBoard connection
  
  float temp = randTemp();
  float hum = randHum();
  float s1= rand1();
  float s2= rand2();
  float s3= rand3();
  float s4= rand4();
  float s5= rand5();
  float s6= rand6();
  float s7= rand7();
  float s8= rand8();
  float s9= rand9();
  float s10= rand10();
  float s11= rand11();
  float s12= rand12();


  Serial.println(temp);
  Serial.println(hum);

  sendDataToThingsBoard(temp, hum,s1,s2,s3,s4,s5,s6,s7,s8,s9,s10,s11,s12);

  delay(60000);  // Wait for 3 seconds before next loop
}
