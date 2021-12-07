#include <Arduino_JSON.h>

KnikkerPoort poortEen = KnikkerPoort();
KnikkerPoort poortTwee = KnikkerPoort();
WiFiCommunicator wifi = WiFiCommunicator(WIFI_NETWERK, WIFI_WACHTWOORD, SERVER_DOMEINNAAM);
Teller tellerA = Teller(TELLER_A_PIN);

int serverContactInterval = 15;                // 15 seconden
unsigned long tijdVoorContactMetServer = 0;

void setup() {
  Serial.begin(9600);
  poortEen.begin(POORT_EEN_PIN, 0, 90);
  poortTwee.begin(POORT_TWEE_PIN, 0, 90);

  wifi.begin();

  wifi.stuurVerzoek("/api/set/nieuwerun", "");

  poortEen.open();
  poortTwee.open();
}


void loop() {
  // laat de teller detecteren:
  tellerA.update();

  
  // pauzeer de knikkerbaan als het tijd is voor contact met server
  if (millis() > tijdVoorContactMetServer && poortEen.getOpen()) {
    poortEen.sluit();
    poortTwee.sluit();
  }

  // knikkerbaan is leeggelopen, er zijn geen sensors dit iets moeten meten
  // nu is het tijd om contact te leggen met de server:
  if (millis() > tijdVoorContactMetServer + LEEGLOOP_TIJD) {
    Serial.print("Er zijn nu zoveel knikkers geteld: ");
    Serial.println(tellerA.getAantal());

    
    // bereken de nieuwe tijd waarop er weer met de server gecommuniceerd moet worden
    tijdVoorContactMetServer = millis() + (unsigned long)serverContactInterval * 1000;
    // en zet nu het poortje weer open:
    poortEen.open();
    poorTwee.open();
  }
}
