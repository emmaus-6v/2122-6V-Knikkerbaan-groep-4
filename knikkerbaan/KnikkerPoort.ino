/* Class van de poortjes */

#include "Servo.h"


class KnikkerPoort {
  private:                // van deze gegevens willen we niet dat andere mensen er zomaar bij kunnen 
    Servo poortServo;
    int pin;
    int gradenOpen;
    int gradenDicht;
    bool isOpen = false;  // het begint als false, want de poort begint dicht
    int richting = 0;     // Richting van het middelste poortje (0 = knikkers gaan naar links, 1 = knikkers gaan naar rechts

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

    /* code voor het sluiten van de poort */ 
    void sluit() {                
      poortServo.write(gradenDicht);
      isOpen = false;
    }

    /* code voor het openen van de poort */
    void open() {
      poortServo.write(gradenOpen);
      isOpen = true;
    }
  
    /*  functie die de waarde van de variabele "richting" verandert, wanneer het aangeroepen wordt */
    void veranderRichting() { 
      if(richting == 0) {
        richting = 1;
      } else if (richting == 1) {
        richting = 0;
      }    
    }

    bool getOpen() {
      return isOpen;
    }

     bool getRichting() { // geeft de richting van het poortje 
      return richting;
    }
};
