/* Sweep by BARRAGAN http://barraganstudio.com This example code is in the public domain.

  modified 8 Nov 2013 by Scott Fitzgerald http://www.arduino.cc/en/Tutorial/Sweep */

#include <Servo.h>

Servo myservo; // maakt object Servo
unsigned long servoTimer = 0;
boolean poort = false;

void setup() {
  Serial.begin(9600);
  Serial.println("setup");
  myservo.attach(9);
  myservo.write(0);
  servoTimer = millis() + 2000;
}

void loop() {
  Serial.println("loop");
  if (millis() > servoTimer) {
    if (poort == true) {
      myservo.write(0);
      servoTimer = millis() + 2000;
    }
    else {
      myservo.write(90);
      servoTimer = millis() + 4000;
    }
    poort = !poort;
  }
}
