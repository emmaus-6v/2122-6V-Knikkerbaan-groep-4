class Decoratie { // dit is de class met de code voor de decoratie bloemen in de widget
  
  constructor(newX, newY) {
    this.x = newX;
    this.y = newY;
  }

  update(){ // deze moet leeg blijven anders doet het het niet

  }
  
  display() {
    fill(32, 89, 47, 127);
    stroke(127,63,120);
    push();
    translate(this.x, this.y);
    noStroke();
    for (let i = 0; i < 10; i ++) {
      ellipse(0, 1, 12, 60);
      rotate(PI/7);
    }
    pop();
  }


}
