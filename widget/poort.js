class Poort { // dit is de class met de code voor de poortjes in de widget
  
  constructor(newX, newY) {
    this.x = newX;
    this.y = newY;
  }

  update(){ // deze moet leeg blijven anders doet het het niet

  }
  
  display() {
    fill(82, 191, 126, 127);
    stroke(127,63,120);
    push();
    translate(this.x, this.y);
    noStroke();
    for (let i = 0; i < 10; i ++) {
      ellipse(0, 1, 10, 60);
      rotate(PI/5);
    }
    pop();    // door het gebruik van push en pop kun je meerdere poorten tekenen
  }


}
