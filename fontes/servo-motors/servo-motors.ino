#include <Servo.h>
 
#define SERVO_MOTOR 6
 
Servo s;
int p;
 
void setup () {
  Serial.begin(9600);
  
  s.attach(SERVO_MOTOR);
  s.write(0);
}
 
void loop() {
  //Gira servo motor para direita
  for(p = 0; p < 90; p++) {
    s.write(p);
    delay(50);
  }
  
  delay(1000);
  
  //Gira servo motor para esquerda
  for(p = 90; p >= 0; p--) {
    s.write(p);
    delay(50);
  }
  
  delay(1000);
}
