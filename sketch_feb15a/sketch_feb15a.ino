  #include "Servo.h"
  #include <Arduino_JSON.h>
  
  const int BOVEN_POORT_PIN = 8;    // pin van servo die bovenste poort regelt
  int switchPin = 12;
  int switchState = LOW;

  class KnikkerPoort {
  private:
    Servo poortServo;
    int pin;
    int gradenOpen;
    int gradenDicht;
    bool isOpen = false;

  public:
    KnikkerPoort(){}
  
    void begin(int _pin, int _gradenOpen, int _gradenDicht) {
      pin = _pin;
      pinMode(pin, OUTPUT);
      poortServo.attach(pin);
      gradenOpen = _gradenOpen;
      gradenDicht = _gradenDicht;
      sluit();
    }

    void sluit() {
      poortServo.write(gradenDicht);
      isOpen = false;
    }

    void open() {
      poortServo.write(gradenOpen);
      isOpen = true;
    }

    bool getOpen() {
      return isOpen;
    }
};


KnikkerPoort poortBoven = KnikkerPoort();
  
  void setup() {
  Serial.begin(9600);
  pinMode(BOVEN_POORT_PIN, OUTPUT);
  pinMode(switchPin, INPUT);

  poortBoven.begin(BOVEN_POORT_PIN, 0, 90);
  poortBoven.open();

}
    
void loop() {
      switchState = digitalRead(switchPin);

Serial.println(switchState);

    if (switchState == HIGH) {
        //Serial.println("aan");
        poortBoven.open();
   } else {
        // Serial.println("uit");
         poortBoven.sluit();
         
         }    

}
