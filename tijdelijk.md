/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // maakt object Servo
// twelve servo objects can be created on most boards

void setup() {
  myservo.attach(9);  //servo aangesloten op pin 9
}

void loop() {
  myservo.write(0);
  delay(2000);
    myservo.write(90);
  delay(10000);
}
