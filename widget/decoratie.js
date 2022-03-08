/* Class voor de opmaak vand de widget. Wordt gebruikt voor het tekenen van de groene 'planten'. */

class Decoratie { 
  
  constructor(newX, newY) { // de grootte van de 'bloemen' zijn hetzelfde, maar je kunt met het object
    this.x = newX;          // telkens een nieuwe toevoegen op een coördinaat
    this.y = newY;
  }

  update(){ // deze moet leeg blijven anders doet het het niet

  }
  
  /* dit tekent de 'bloem' */
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
    pop(); // dmv push en pop kun je meerdere 'bloemen' tekenen
  }


}
