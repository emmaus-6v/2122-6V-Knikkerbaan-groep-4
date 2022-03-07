#include <Arduino_JSON.h>

KnikkerPoort poortBoven = KnikkerPoort();
KnikkerPoort poortMidden = KnikkerPoort();
WiFiCommunicator wifi = WiFiCommunicator(WIFI_NETWERK, WIFI_WACHTWOORD, SERVER_DOMEINNAAM);
Teller tellerA = Teller(TELLER_A_PIN);
Teller tellerB = Teller(TELLER_B_PIN);
Teller tellerC = Teller(TELLER_C_PIN);
Buzzer buzzerA = Buzzer();


int serverContactInterval = 15;                // 15 seconden
unsigned long tijdVoorContactMetServer = 0;
//int poortOpen = false;

void setup() {
  Serial.begin(9600);
  poortBoven.begin(BOVEN_POORT_PIN, 10, 90);
  poortMidden.begin(MIDDEN_POORT_PIN, 10, 90);
  buzzerA.begin(BUZZER_A_PIN, 1000, 500);


  wifi.begin();

  wifi.stuurVerzoek("/api/set/nieuwerun", "");

  poortBoven.open();
  poortMidden.open();
}


void loop() {
  // laat de teller detecteren:
  tellerA.update();
  tellerB.update();
  tellerC.update();

  bool switchState = digitalRead(switchPin);
  if (switchState == HIGH) {
    if (switchState != previousSwitchState) {
      Serial.println("knop wordt ingedrukt");
      if (poortMidden.getOpen() == true) {
        poortMidden.sluit();
        buzzerA.start();
      }
      else {
        poortMidden.open();
      }
    }
  }
  previousSwitchState = switchState;

//  Serial.println(switchState);


  // pauzeer de knikkerbaan als het tijd is voor contact met server
  if (millis() > tijdVoorContactMetServer && poortBoven.getOpen()) {
    poortBoven.sluit();
  }

  // knikkerbaan is leeggelopen, er zijn geen sensors dit iets moeten meten
  // nu is het tijd om contact te leggen met de server:
  if (millis() > tijdVoorContactMetServer + LEEGLOOP_TIJD) {
    // contact met server houdt in:
    //   * nieuw totaal aantal knikkers versturen
    //   * instellingen ophalen

    // maak de reeks variabelen voor achter de URL:
    String data = "knikkers=";
    data = tellerA.getAantal();
    data = tellerB.getAantal();
    data = tellerC.getAantal();
    data += "andereVariabele";
    data += 5;


    // stuur deze data naar het juiste adres
    wifi.stuurVerzoek("/api/set/sensordata", data.c_str());
/*
    // vraag bij de server de nieuwe instellingen op:
    String serverAntwoord = wifi.stuurVerzoek("/api/get/instellingen", "");

    // om een beeld te geven van het antwoord: print in seriële monitor:
    Serial.println(serverAntwoord);

    // om de instellingen gemakkelijk uit te kunnen lezen
    JSONVar ontvangenInstellingen = JSON.parse(serverAntwoord);                      // deze regel hoef je niet te begrijpen

    // check of de instellingen goed zijn binnengekomen
    // indien ja: pas instellingen op Arduino aan
    // indien nee: geef een foutmelding in de seriële monitor
    if (JSON.typeof(ontvangenInstellingen) != "undefined") {                         // je hoeft deze voorwaarde niet te begrijpen
      // stel de wachttijd (opnieuw) in:
      serverContactInterval = ontvangenInstellingen["wachttijdPoort"];
    }
    else {
      // evt. foutmelding:
      Serial.println("FOUT: serverAntwoord kon niet worden verwerkt");
    }
*/
    // servercommunicatie is afgerond
    // bepaal nu op welke tijd de knikkerbaan
    // opnieuw contact moet zoeken
    tijdVoorContactMetServer = millis() + (unsigned long)serverContactInterval * 1000;

    // en zet nu het poortje weer open:
    poortBoven.open();
  }


  bool aantalKnikkersB = tellerB.getAantal();
  int aantalKnikkersBTijd = 0;
  if (aantalKnikkersB != previousaantalKnikkersB) {
    Serial.println("knikker komt voorbij B");
    aantalKnikkersBTijd = millis();
  }

  previousaantalKnikkersB = aantalKnikkersB;

  bool aantalKnikkersC = tellerC.getAantal(); 
  int aantalKnikkersCTijd = 0;
  if (aantalKnikkersC != previousaantalKnikkersC) {
    Serial.println("knikker komt voorbij C");
    aantalKnikkersCTijd = millis();
  }

  previousaantalKnikkersC = aantalKnikkersC;
  
  snelheidKnikker = lengteKnikkerbaan / (aantalKnikkersCTijd - aantalKnikkersBTijd)
  

}
