//declareer hier je globale constanten:

const int BOVEN_POORT_PIN = 7;    // pin van servo die bovenste poort regelt
const int LEEGLOOP_TIJD = 5000;   // tijd die knikkers nodig hebben om na het
                                  // sluiten van de poort langs alle sensors te komen

char WIFI_NETWERK[] = "";
char WIFI_WACHTWOORD[] = "";
char SERVER_DOMEINNAAM[] = "3000-emmaus6v-21226vknikkerba-yqpzi287bof.ws-eu32.gitpod.io";    // domeinnaam van gitpod-server, zoals 3000-lavendel-bla-bla.gitpod.io

const int TELLER_A_PIN = 5;       // pin waarop IR-sensor voor Teller A is aangesloten
const int TELLER_B_PIN = 4;
const int TELLER_C_PIN = 3;

const int MIDDEN_POORT_PIN = 8;    // pin van servo die bovenste poort regelt
int switchPin = 12;
int previousSwitchState = LOW;

int previousaantalKnikkersB = 0;
int previousaantalKnikkersC = 0;
int snelheidKnikker = 0;
const int lengteKnikkerbaan = 2; // in meters
