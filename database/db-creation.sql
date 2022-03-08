/* Beschrijf de tabellen die je nodig hebt*/

/* Tabel voor de runs*/ 
CREATE TABLE runs (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  stamp DATETIME NOT NULL
);

/* Tabel met de data van de knikkerbaan*/
CREATE TABLE sensorData (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp DATETIME NOT NULL,
  aantalKnikkers INTEGER,                 /* Geeft het aantal knikkers aan */
  buttonState INTEGER,                    /* Geeft de status van de knop aan (0 = LOW, 1 = HIGH) */
  poortPositie INTEGER                    /* Geeft de richting aan van de poort (0 = de knikkers gaan naar links, 1 = de knikkers gaan naar rechts) */
);

/* Tabel met de instellingen */
CREATE TABLE instellingen (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  run INTEGER NOT NULL,
  stamp DATETIME NOT NULL,
  wachttijdPoort INTEGER NOT NULL         /* Hoe lang de poort moet wachten, dit kan niet 0 zijn */
);




/* Indien je standaard wat gegevens in de database wilt,
   voeg hieronder dan INSERT regels to */
INSERT INTO runs (stamp) VALUES (CURRENT_TIMESTAMP);
INSERT INTO sensorData (run, stamp, aantalKnikkers, buttonState, poortPositie) VALUES (1, CURRENT_TIMESTAMP, 21, 0, 0);
INSERT INTO instellingen (run, stamp, wachttijdPoort) VALUES (1, CURRENT_TIMESTAMP, 15);
