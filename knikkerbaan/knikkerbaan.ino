/* Globale constanten van de knikkerbaan */

const int BOVEN_POORT_PIN = 7;    // pin van servo die bovenste poort regelt
const int LEEGLOOP_TIJD = 5000;   // tijd die knikkers nodig hebben om na het
                                  // sluiten van de poort langs alle sensors te komen

char WIFI_NETWERK[] = "";
char WIFI_WACHTWOORD[] = "";
char SERVER_DOMEINNAAM[] = "3000-emmaus6v-21226vknikkerba-yqpzi287bof.ws-eu32.gitpod.io";    // domeinnaam van gitpod-server, zoals 3000-lavendel-bla-bla.gitpod.io

const int TELLER_A_PIN = 5;       // pin waarop IR-sensor voor Teller A is aangesloten
const int TELLER_B_PIN = 4;       // pin waarop IR_sensor voor Teller B is aangesloten
const int TELLER_C_PIN = 3;       // pin waarop IR-sensor voor Teller C is aangesloten
const int BUZZER_A_PIN = 2;       // pin waar de buzzer op aangesloten zit

const int MIDDEN_POORT_PIN = 8;   // pin van servo die de poort in het midden van de knikkerbaan regelt
int switchPin = 12;               // pin waarop de knop is aangesloten 
int previousSwitchState = LOW;    // in het begin is de status LOW omdat de knop nog niet in is gedrukt

int previousaantalKnikkersB = 0;  // Aan het begin zijn deze aantallen 0,
int previousaantalKnikkersC = 0;  // want je begint natuurlijk zonder knikkers.
int snelheidKnikker = 0;          
const int lengteKnikkerbaan = 2; 
