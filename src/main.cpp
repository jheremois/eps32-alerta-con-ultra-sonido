#include <Arduino.h>

int TRIG = 15;
int EHCO = 4;
int BIB = 14;
int ELLED = 13;
int DURACION;
int DISTANCIA;

void setup(){

  pinMode(TRIG, OUTPUT);
  pinMode(EHCO, INPUT);
  pinMode(BIB, OUTPUT);
  pinMode(ELLED, OUTPUT);
  Serial.begin(9600);

}

void loop(){
  
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  
  DURACION = pulseIn(EHCO, HIGH);
  DISTANCIA = DURACION / 58.2;
  Serial.println(DISTANCIA);
  delay(200);

  if (DISTANCIA <= 15 && DISTANCIA >= 0){
    digitalWrite(ELLED, HIGH);
    digitalWrite(BIB, HIGH);
  }else{
    digitalWrite(ELLED, LOW);
    digitalWrite(BIB, LOW);
  }
   
}