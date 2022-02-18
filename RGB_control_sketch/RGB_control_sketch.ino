//this sketch turns on and off the RGB LEDs
//RGB LED  ESP32
//R    ->  GPIO23
//G    ->  GPIO19
//B    ->  GPIO18



class RGBLed {
  private:
    int const redLedPin = 23;
    int const greenLedPin = 19;
    int const blueLedPin = 18;

    bool redLedState;
    bool greenLedState;
    bool blueLedState;
  public:
    RGBLed() {
      redLedState = false;
      greenLedState = false;
      blueLedState = false;
    }

};


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
