class Buzzer {    // dit is de class voor de buzzer
  private:        // de gegevens pin, frequentie en tijdsduur hebben we private gehouden
    int pin;      // omdat je niet wilt dat anderen dit kunnen aanpassen
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
