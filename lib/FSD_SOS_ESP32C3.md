# Functional Specification Document: SOS Morse Signal

## 1. Project Description
The purpose of this project is to use the ESP32-C3 microcontroller to broadcast a visual "SOS" signal using the onboard LED. The system is connected to the Blynk IoT App to see SOS alert when activated.

## 2. System Block Diagram
+-----------------------+          +-----------------------+
|   Blynk Mobile App    | <------> |    Blynk IoT Cloud    |
+-----------------------+          +-----------+-----------+
                                               ^
                                               | Wi-Fi
                                               v
+-----------------------+          +-----------+-----------+
|    Serial Monitor     | <------  |       ESP32-C3        |
|    (115200 Baud)      |   UART   +-----------+-----------+                       
+-----------------------+                      |
                                               |
                                               | GPIO 12
                                               v  (led1)
                                   +-----------+-----------+
                                   |      Physical LED     |
                                   |    (SOS Morse Code)   |
                                   +-----------------------+

## 3. Hardware Specification
The program is designed for the LuatOS-ESP32C3 development board, utilizing its GPIO capabilities.
1. Microcontroller = ESP32-C3 
2. Primary Output = GPIO 12 (led1)
3. Secondary Output = Blynk App 
4. Communication =  UART (115200 Baud) 

## 4. Goals
1. To give visual SOS blinking code using ESP32
2. Use WiFi and OTA update to send SOS alert to a web/application
3. Minimal delay between the LED onboard and the application

## 3. Implementation
1. First 'S' = 
    - Toggles LED1 three times, synced with the virtual LED in the app.
    - 400ms ON / 400ms OFF.
    - Prints "S" to the console and application.

2.  The 'O' 
    - Toggles LED1 three times, synced with the virtual LED in the app. 
    - 1200ms ON / 1200ms OFF.
    - Prints "O" to the console and application.

3. The Second 'S' 
    - Toggles LED1 three times, synced with the virtual LED in the app.
    - 400ms ON / 400ms OFF.
    - Prints "S" to the console and application.

**Note that between each full "SOS" sent, the system enters an idle for 1000ms (1s) before restarting the sequence.

## 4. Deployment Instructions
1. Get the Blynk template ID and Authentication Key from the web console.
2. Make sure the WiFi SSID and Password is changed depending on the location of the ESP32.
3. Upload the code to the ESP32.
4. Connect the device to the Blynk IoT app.
