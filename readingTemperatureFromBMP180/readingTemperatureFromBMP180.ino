#include <Adafruit_BMP085.h>

/*************************************************** 
  This is an example for the BMP085 Barometric Pressure & Temp Sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> https://www.adafruit.com/products/391

  These pressure and temperature sensors use I2C to communicate, 2 pins
  are required to interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

// Connect VCC of the BMP085 sensor to 3.3V (NOT 5.0V!)
// Connect GND to Ground
// Connect SCL to i2c clock - on ESP GPIO 22
// Connect SDA to i2c data - on ESP GRIO 21

//creates the BMP 180 sensor object
Adafruit_BMP085 bmp;
  
void setup() {
  //Starts the serial monitor
  Serial.begin(9600);
  if (!bmp.begin()) {
  Serial.println("Could not find a valid BMP180 sensor, check wiring!");
  while (1) {}
  }
}
  
void loop() {
    Serial.print("Temperature = ");
    //reads the temperature value and prints it to the serial monitor
    Serial.print(bmp.readTemperature());
    Serial.println(" *C");
    
    delay(500);
}
