/*********
  This sketch sends temperature values to the Serial client in the Android phone.
  The Android phone sends commands to this uC and the RGBs turn on and off.
*********/

// Load libraries
#include "BluetoothSerial.h"
#include <Adafruit_BMP085.h>

// Check if Bluetooth configs are enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

//RGB class
//class created to handle the RGB LED
class RGBLed {
  private:
    const int redLedPin = 23;
    const int greenLedPin = 19;
    const int blueLedPin = 18;

    bool redLedState;
    bool greenLedState;
    bool blueLedState;
  public:
    //constructor method without parameters
    RGBLed() {
      redLedState = false;
      greenLedState = false;
      blueLedState = false;

      pinMode(redLedPin, OUTPUT);
      pinMode(greenLedPin, OUTPUT);
      pinMode(blueLedPin, OUTPUT);

      digitalWrite(redLedPin, LOW);
      digitalWrite(greenLedPin, LOW);
      digitalWrite(blueLedPin, LOW);
    }
    //constructor method with parameters
    RGBLed(bool r, bool g, bool b) {
      pinMode(redLedPin, OUTPUT);
      pinMode(greenLedPin, OUTPUT);
      pinMode(blueLedPin, OUTPUT);

      setRedLedState(r);
      setGreenLedState(g);
      setBlueLedState(b);
    }
    //setters
    void setRedLedState(bool s) {
      if (s) {
        redLedState = s;
        digitalWrite(redLedPin, HIGH);
      } else {
        redLedState = s;
        digitalWrite(redLedPin, LOW);
      }
    }

    void setGreenLedState(bool s) {
      if (s) {
        greenLedState = s;
        digitalWrite(greenLedPin, HIGH);
      } else {
        greenLedState = s;
        digitalWrite(greenLedPin, LOW);
      }
    }

    void setBlueLedState(bool s) {
      if (s) {
        blueLedState = s;
        digitalWrite(blueLedPin, HIGH);
      } else {
        blueLedState = s;
        digitalWrite(blueLedPin, LOW);
      }
    }
    //getters
    bool getRedLedState() {
      return redLedState;
    }

    bool getGreenLedState() {
      return greenLedState;
    }

    bool getBlueLedState() {
      return blueLedState;
    }

};

// Bluetooth Serial object
BluetoothSerial SerialBT;

// Handle received and sent messages
String message = "";
char incomingChar;
String temperatureString = "";

// Timer: auxiliar variables
unsigned long previousMillis = 0;    // Stores last time temperature was published
const long interval = 10000;         // interval at which to publish sensor readings

//instantiates the RGBLed object
RGBLed rgb;
//instantiates the BMP180 sensor
Adafruit_BMP085 bmp;

void setup() {


  //starts serial monitor
  Serial.begin(115200);
  // Bluetooth device name
  SerialBT.begin("ESP32 RGS");
  Serial.println("The device started, now you can pair it with bluetooth!");

  //initiates the sensor object
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
  }
}
void loop() {
  unsigned long currentMillis = millis();
  // Send temperature readings
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    temperatureString = String(bmp.readTemperature());
    SerialBT.println(temperatureString);
  }
  // Read received messages (LED control command)
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n') {
      message += String(incomingChar);
    }
    else {
      message = "";
    }
    Serial.write(incomingChar);
  }
  // Check received message and control output accordingly
  if (message == "red_on") {
    Serial.println("Red LED on");
    rgb.setRedLedState(true);
  }
  else if (message == "red_off") {
    Serial.println("Red LED off");
    rgb.setRedLedState(false);
  }
  if (message == "blue_on") {
    Serial.println("Blue LED on");
    rgb.setBlueLedState(true);
  }
  else if (message == "blue_off") {
    Serial.println("Blue LED off");
    rgb.setBlueLedState(false);
  }
  if (message == "green_on") {
    Serial.println("Green LED on");
    rgb.setGreenLedState(true);
  }
  else if (message == "green_off") {
    Serial.println("Green LED off");
    rgb.setGreenLedState(false);
  }
  delay(20);
}
