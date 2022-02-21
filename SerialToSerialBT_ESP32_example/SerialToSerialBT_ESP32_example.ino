//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

//Creates BT object
BluetoothSerial SerialBT;

void setup() {
  //initializes serial monitor
  Serial.begin(115200);
  //initializes 
  SerialBT.begin("ESP32 Test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  //check if there are bytes being received in the serial port
  if (Serial.available()) {
    //sends that information via Bluetooth to the connected device
    SerialBT.write(Serial.read());
  }

  //checks if there are bytes available to read in the Bluetooth Serial port
  if (SerialBT.available()) {
    //writes those bytes in the Serial Monitor
    Serial.write(SerialBT.read());
  }
  delay(20);
}
