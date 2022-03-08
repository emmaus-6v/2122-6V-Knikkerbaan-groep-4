// Knikkerpoort is een klasse die de functionaliteit
// verzorgt van een servo die knikkers doorlaat / tegenhoudt

#include "Servo.h"


class KnikkerPoort {
  private:
    Servo poortServo;
    int pin;
    int gradenOpen;
    int gradenDicht;
    bool isOpen = false;
    int richting = 0; /* Richting van het middelste poortje (0 = knikkers gaan naar links, 1 = knikkers gaan naar rechts */

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
  
     void veranderRichting() { /*  functie die de waarde van de variabele "richting" verandert, wanneer het aangeroepen wordt */
      if(richting == 0) {
        richting = 1;
      } else if (richting == 1) {
        richting = 0;
      }    
    }

    bool getOpen() {
      return isOpen;
    }

     bool getRichting() { /* geeft de richting van het poortje */
      return richting;
    }
};
