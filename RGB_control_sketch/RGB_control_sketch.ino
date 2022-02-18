//this sketch turns on and off the RGB LEDs
//RGB LED  ESP32
//R    ->  GPIO23
//G    ->  GPIO19
//B    ->  GPIO18


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

//instantiates the RGBLed object
RGBLed rgb;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  rgb.setRedLedState(true);
  delay(1000);
  rgb.setRedLedState(false);
  rgb.setGreenLedState(true);
  delay(1000);
  rgb.setGreenLedState(false);
  rgb.setBlueLedState(true);
  delay(1000);
  rgb.setBlueLedState(false);
}
