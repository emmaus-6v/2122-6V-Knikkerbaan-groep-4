
// globale variabelen
var aantalKnikkersBoven = 0;    // aantal knikkers dat bovenin is binnengekomen
var wachttijd = 15;             // wachttijd voor het poortje in seconden
const UPDATE_INTERVAL = 5000;   // tijd in milliseconden tussen het door widget opvragen van gegevens
var button;
var teller;
var wachtijdInput;


/**
 * setup
 * de code in deze functie wordt eenmaal uitgevoerd,
 * als p5js wordt gestart
 */
function setup() {
  // Maak het canvas van je widget
  createCanvas(300, 600);

  teller = new Teller(150, 50);

  // maak een button en stel deze in
  button = createButton('verstuur');
  button.position(200,625);
  button.mouseClicked(stuurNieuweInstellingen);

  wachtijdInput = createInput();
  wachtijdInput.position(250,625);
  wachtijdInput.size(50);



  // om de ... milliseconden wordt 'vraagSensorData' uitgevoerd
  setInterval(vraagSensorData, UPDATE_INTERVAL);
}



/**
 * draw
 * de code in deze functie wordt meerdere keren per seconde
 * uitgevoerd door de p5 library, nadat de setup functie klaar is
 */
function draw() {
  // achtergrond: houtkleur, kies gerust iets anders
  background(0, 158, 150);

  // de lijnen die ook op onze knikkerbaan zitten
  stroke(0, 0, 0);
  strokeWeight(10);
  line(100,20,220,40); // wachtlijn
  line(80,100,260,80); // 1e lijn
  line(40,140,220,160); // 2e lijn
  line(200,200,260,190); // mini lijn
  line(100,230,200,220); // val lijn
  line(40,230,130,280); // snelheidslijn
  line(60,330,150,310); // lijn naar links
  line(150,310,240,330); // lijn naar rechts
  line(40,550,135,580); // opvanglijn links
  line(165,580,260,550); // opvanglijn rechts

  // zigzag rechter kant
  line(260, 350, 170, 380);
  line(150, 400, 240, 440);
  line(260, 460, 170, 480);
  line(150, 510, 240, 530);


  var poort = new Poort(225, 25); // object code voor de poortjes
  poort.update();
  poort.display();

  var poort = new Poort(150,300);
  poort.update();
  poort.display();

  for (var iets = 0; iets < 20; iets ++) {  // nog aanpassen: bloemmetje staat vast wanneer muis klinkt en los laat en de kleir moet random zijn alke ker dat je klikt
    fill(50,200,random(0, 255));   //(random(140, 220), random(140, 220), random(140, 220));  
    push();
    translate(50, 50);
    noStroke();
    for (let i = 0; i < 10; i ++) {
      ellipse(0, 1, 8, 40);
      rotate(PI/random(3,7));
    }
  pop();
  };

  teller.show();
}


// stuurt een verzoek aan de server dat alle
// sensordata opvraagt
function vraagSensorData() {
  var request = new XMLHttpRequest();

  // maak een http-verzoek
  request.open('GET', '/api/get/sensordata', true)

  // wat uitvoeren als het antwoord teruggegeven wordt?
  request.onload = function () {
    var data = JSON.parse(request.response);

    if (request.status == 200) {
      console.log("Dit geeft de server terug:" + data);
      teller.aantal = data.aantalKnikkers;
    }
    else {
      console.log("server reageert niet zoals gehoopt");
      console.log(request.response);
    }
  }

  // verstuur het request
  request.send()
}


// stuurt een http-verzoek aan de server met de
// nieuwe instellingen
function stuurNieuweInstellingen() {
  var request = new XMLHttpRequest();

  // maak een http-verzoek
  request.open('GET', '/api/set/instellingen?wachttijd=' + wachtijdInput.value(), true)

  // wat uitvoeren als het antwoord teruggegeven wordt?
  request.onload = function () {
    if (request.status == 200) {
      console.log("server accepteerde instellingen");
    }
    else {
      console.log("server reageert niet zoals gehoopt");
      console.log(request.response);
    }
  }

  // verstuur het request
  request.send()
}