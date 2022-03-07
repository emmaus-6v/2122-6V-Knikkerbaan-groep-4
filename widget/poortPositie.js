class Poortpositie {
  x;
  y;
  richting;

  constructor(_x, _y) {
    this.x = _x;
    this.y = _y;
    this.richting = "links";
  }

  show() {
    noStroke();               // geen rand
    fill(255, 255, 255);      // wit
    textSize(14);
    // print aantal knikkers bovenin
    text(this.richting, this.x, this.y);
  }
}
