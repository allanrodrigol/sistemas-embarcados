#include <Ultrasonic.h>
 
#define HC_SR04_TRIGGER 4
#define HC_SR04_ECHO 5
 
Ultrasonic ultrasonic(HC_SR04_TRIGGER, HC_SR04_ECHO);
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  //Coleta tempo de eco em milisegundos
  long ms = ultrasonic.timing();
  
  //Converte tempo de eco em centímetros
  float cm = ultrasonic.convert(ms, Ultrasonic::CM);

  //Exibe distância em centímetros
  Serial.print("Distância: %f\n",cm);
  
  delay(1000);
}