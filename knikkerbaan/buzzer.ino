class Buzzer {
  private:
    int pin;
    int frequentie;
    int tijdsduur;

  public:
    Buzzer(){}
  
    void begin(int _pin, int _frequentie, int _tijdsduur) {
      pin = _pin;
      pinMode(pin, OUTPUT);
      frequentie = _frequentie;
      tijdsduur = _tijdsduur;
    }

    void start() {
      tone(pin, frequentie, tijdsduur);
    }
 
};
