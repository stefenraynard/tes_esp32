#define BLYNK_TEMPLATE_ID "TMPL64Ibjp0xi"
#define BLYNK_TEMPLATE_NAME "BlinkSOS"
#define BLYNK_AUTH_TOKEN "from the blynk web console"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <ArduinoOTA.h>


char ssid[] = "SSID name";
char pass[] = "123456789";

const int led1 = 12;
BlynkTimer timer;

void pulse(int count, int highTime, int lowTime, String letter, String symbol) {
  Blynk.virtualWrite(V1, letter); 
  Serial.print("\nSending Letter: ");
  Serial.print(letter);
  Serial.print(" ");

  for (int i = 0; i < count; i++) {
    digitalWrite(led1, HIGH);
    Blynk.virtualWrite(V2, 1);   
    Serial.print(symbol); 
    delay(highTime);
    
    digitalWrite(led1, LOW);
    Blynk.virtualWrite(V2, 0);   
    delay(lowTime);
    
    Blynk.run();
    ArduinoOTA.handle();
  }
}

void runSOSSequence() {
  Serial.println("\n--- Starting SOS Sequence ---");
  
  pulse(3, 400, 400, "S", ".");
  
  pulse(3, 1200, 400, "O", "-");
  
  pulse(3, 400, 400, "S", ".");
  
  Serial.println("\nSequence Complete. Waiting...");
  Blynk.virtualWrite(V1, "IDLE");
}

void setup() {
  pinMode(led1, OUTPUT);
  Serial.begin(115200); 
  
  Serial.println("Booting...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  ArduinoOTA.setHostname("SOS-ESP32C3");
  ArduinoOTA.begin();

  timer.setInterval(10000L, runSOSSequence);
}

void loop() {
  Blynk.run();
  timer.run();
  ArduinoOTA.handle();
}