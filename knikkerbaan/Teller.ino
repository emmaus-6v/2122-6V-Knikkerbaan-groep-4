/* Class voor de IR-sensors die fungeren als tellers */

class Teller {
  private:            // deze gegevens mogen anderen niet kunnen zien
    int pin;
    bool wasOnderbroken;
    unsigned long laatstOnderbroken = 0;
    const int DEBOUNCE_TIME = 10;

    bool isOnderbroken() {
      return !digitalRead(pin);
    }

    bool wordtOnderbroken() {
      return (wasOnderbroken == false && isOnderbroken() == true);
    }

    int aantal = 0;

  public:
    Teller(int _pin) {
      pinMode(_pin, INPUT_PULLUP);
      pin = _pin;
      wasOnderbroken = false;
    }

    void update() {
      //Serial.println(digitalRead(pin));
      if (wordtOnderbroken()) {
        if (millis() - laatstOnderbroken > DEBOUNCE_TIME) {
          verhoogAantal();
          //Serial.println(aantal);
        } 
      }

      wasOnderbroken = isOnderbroken();
    }

    void verhoogAantal() {
      aantal++;
    }

    int getAantal() {
      return aantal;
    }
};
