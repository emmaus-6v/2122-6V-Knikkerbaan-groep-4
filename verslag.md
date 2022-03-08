# Verslag eindopdracht 6V
### Gemaakt door *Frédérique Keijzer*, *Fé Laar*, *Naomi Lubeek* en *Luuk Roelofs*

---

## Inleiding
Voor onze eindopdracht hebben wij een knikkerbaan gemaakt. Het thema van onze knikkerbaan is waterval. Door middel van poortjes en andere obstakels worden de knikkers mee met de waterval naar beneden genomen waar ze door allerlei opstakels worden opgevangen. Hierdoor worden op het einde bijvoorbeeld de knikkers in 2 banen geleid, waardoor de knikker dus niet één, maar twee routes kan bevaren. De poortjes worden door de Arduino aangestuurd. Daarnaast heeft de knikkerbaan een widget. Hieronder lees je welke features onze knikkerbaan heeft, een technische verantwoording, en kun je lezen hoe wij zelf de opdracht ervaren hebben.


## Features
Beschrijf hier de eigenschappen van jullie knikkerbaan (gebruik gerust plaatjes) kijk in map fotos naar KnikkerBaan.png . De eerste paar zijn voorgegeven:

### feature 1: Opvangen van knikkers
De knikkerbaan kan knikkers bovenin correct opvangen. De binnenkomende knikkers worden geteld en een poortje bepaalt of knikkers mogen doorrollen of worden tegengehouden.

### feature 2: Doorgeven van gegevens aan server
De knikkerbaan zendt de hoeveelheid getelde knikkers naar een server die de gegevens opslaat in een database. Deze server kan per 'run' (d.w.z. een nieuwe keer aangaan) gegevens bijhouden.

### feature 3: Widget wisselt info uit met knikkerbaan
In de browser kan met een URL een widget worden geladen. Deze geeft de knikkerbaan schematisch weer in een frame van 600x300px. De getelde knikkers en duur dat de poort openstaat worden hierin getoond. De duur dat de poort openstaat kan hierin worden veranderd. De knikkerbaan kan deze wachttijd van de server ontvangen en zijn werking erop aanpassen.

### feature 4: Eerste poortje
Het eerste poortje kan de knikkers tegenhouden zodat er genoeg tijd is om te verbinden met de server en alle gegevens te verzamelen en te verzenden. Terwijl het poortje dicht is gaan er dus geen knikkers door de baan, waardoor de doorgegeven waardes kloppend zijn. 

### feature 5: Tweede poortje
Het tweede poortje bij de splitsing van de baan zorgt ervoor dat de knikkers naar rechts of naar links worden gestuurd. Dit kan je zelf bepalen door middel van een knop. De gegevens over de richting van het poortje, worden doorgegeven aan de widet.

### feature 6: De buzzer
De buzzer gaat af wanneer er op de knop gedrukt wordt. Zo zie je niet alleen iets veranderen, je hoort het ook.

## Evaluaties van scrumplanningen:
In het begin hadden we een beetje moeite met het begrijpen van de opdracht. Dit probleem hebben we opgelost door veel uitleg te vragen, de opdracht met elkaar te bespreken en hebben we de video's bespreken. Vervolgens hebben we onze ideeën uitgewerkt in een ontwerp. Na de code te hebben geschreven en het bord te hebben gebouwd kwam alles bij elkaar. 

We hebben veel gebruik gemaakt van onze planning en het scrumboard. Door de kolommen van taken die gedaan moetn worden, bezig zijn en klaar zijn, was het heel overzichtelijk waar we nu precies mee bezig waren. We hebben deze grote opdracht in veel kleine stukken verdeeld, waardoor het veel overzichterlijker werd en iedereen wat kon doen. 


## Technische verantwoording

De knikkers komen eerst langs een ir-sensor, die moet bijhouden hoeveel knikkers er voorbijkomen. Dan houdt de eerste knikkerpoort de knikkers tegen voor bepaald aantal seconden. Vervolgens komen de knikkers langs de tweede ir-sensor en derde ir-sensor, die de tijd bijhouden van de gepasseerde knikker. De afgelegde weg wordt gedeeld door het verschil van de tijd en zo krijg je de snelheid. Daarna komt de knikker bij een splitsing links of rechts. Door op de rode knop te drukken, draait het middelste poortje. Dit zorgt ervoor dat de knikker de andere kant op kan. Ook gaat er een buzzer af wanneer er op de knop wordt gedrukt. De knikkers gaan via de linker- of rechterroute naar beneden en komen uiteindelijk weer bijeen. De knikkerbaan wisselt met de widget bepaalde data uit, zoals het aantal knikkers en de richting van het middelste poortje.

Uitdagingen die we tegenkwamen: Het werken met de widget bleek een probleem te zijn, zo is het niet geheel gelukt om de gegevens van de knikkerbaan te tonen in de widget. Ook hadden we moeite met onze ideeën uit te werken in de realiteit. We waren vrij lang bezig met de opstart en het opbouwen van de baan, waardoor we bijvoorbeeld niet meer iets hebben kunnen doen met de gegevens van de snelheidssensor. 


## Reflectie op opdracht
#### --Frédérique Keijzer--
*Ik vond het leuk dat er verschillende dingen gecombineerd werden, die we de afgelopen jaren hadden geleerd. Dit maakte het meteen ook een grote opdracht en wat lastiger. Gelukkig werkte je in een groepje en konden we zo elkaar vaak aanvullen. Verder heb ik tijdens deze opdracht meer begrip gekregen van object geörienteerd programmeren en kon ik het werken met arduino herhalen. Tot slot was het grappig om, na al die jaren, weer is bezig te zijn in het handvaardigheidlokaal!*

#### --Fé Laar--
*Tijdens de eerste uitleg van deze opdracht dacht ik bij mezelf: help wat een moeilijke opdracht. Dat viel echter wel mee, omdat we de opdracht verdeelden in stukjes. Dat moet ik ook meenemen voor andere opdrachten. Ik ben nu wel zelfverzekerder geworden als het gaat over mijn programmeer vaardigheden. Een master ben ik nog lang niet, maar na 3 jaar het vak informatica gevolgd te hebben, weet ik al een stuk meer dan ik ooit gedacht zou hebben. Door deze opdracht ben ik beter geworden in het programmeren in JavaScript en het herhalen van de Arduino was ook fijn. Ook heb ik nu een veel beter beeld wat object georiënteerd programmeren in de praktijk doet. Informatica kan wel eens verwarrend zijn, maar zodra dat opgelost is, heb je echt wat bereikt. *

#### --Naomi Lubeek--
*Ondanks dat ik tijdens deze opdracht voor een groot gedeelte ziek ben geweest, heb ik er toch veel van geleerd. Ik snap nu veel beter hoe servers en communicatie werken en hoe je gebruik maakt van verschillende programmeertalen voor één project. Het belangrijkste wat ik heb geleerd is de toepassing van object georiënteerd programmeren in de praktijk. Tijdens deze opdacht hebben we er echt wat aan gehad. Ook heb ik kennisgemaakt met scrum plannen, wat erg handig bleek. Het leerpunt wat ik meeneem is dat het verstanding is om gelijk van al je waardes variabelen te maken, zodat het later makkelijker is om deze aan te passen.*

#### --Luuk Roelofs--
*Ik heb geleerd hoe je gebruikt maakt van meerdere programmeertalen in 1 project. Ook heb ik geleerd hoe je dit in de realiteit toepast, om zo een mooie knikkerbaan te krijgen die fysieke als digitale functies heeft. Het belangrijkste punt dat ik meeneem is hoe je zowel digitale als fysieke functies met elkaar combineert. Ook vond ik het werken met scrumboard fijn zodat je duidelijk ziet wat je te wachten staat en het overzicht behoudt.*

## Slot
Over het algemeen zijn we erg blij met de knikkerbaan die we gemaakt hebben. Hij is erg mooi geworden en we zijn blij met hoe hij werkt. De samenwerking verliep prima en over het algemeen was het vooral een leuk, leerzaam en interessant project. We zijn blij met de dingen die we geleerd/verbeterd hebben en kijken positief terug op de opdracht.
