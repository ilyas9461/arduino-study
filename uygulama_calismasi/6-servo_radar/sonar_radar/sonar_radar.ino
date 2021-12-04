//Sonar Radar 
//SG90 mikro Servo  
//kırmız +5V, kahve gnd, turuncu kontrol
#include <Servo.h>
Servo  servo;

#define _sol 1
#define sag 0
#define _var 1
#define _yok 0

#define buzzer  9 

//Notalarla ilgili tanımlamalar
const int Do = 262;
const int re = 294;
const int mi = 330;
const int fa = 349;
const int sol = 392;
const int la = 440;
const int si = 494;
const int doi = 523;
const int notalar[] = {Do, re, mi, fa, sol, la, si, doi};

int uzaklik = 0;

byte aci = 15;
bool yon = _sol;
boolean dur=false;
long zaman_print=0;

void setup() {

  servo.attach(3);
  Serial.begin(9600);
  zaman_print=millis();
   
}

void loop() {

  uzaklik = sonarSensOku();
 
  if(!dur){
    servo.write(aci);
  }
  if(uzaklik<150){
    sonar_ses(uzaklik);
    dur=true;
  }else dur=false;
 
  if (yon == _sol&&!dur){
    aci += 5;
   }
  if (yon == sag&&!dur ) {
    aci -= 5;
  }
  if (aci > 165) {
    yon = sag;

  }
  if (aci < 15) {
    yon = _sol;
  }

  if(millis()-zaman_print>1000){
    Serial.println(uzaklik);
    zaman_print=millis();
  }

}//loop

int sonarSensOku() {

  const int trigPin = 6;
  const int echoPin = 7 ;

  long duration = 0;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return (duration / 29 / 2); //cm
}

int buzzer_b()
{
  int uz = sonarSensOku();

  Serial.println(uz);
  pinMode(buzzer, OUTPUT);
  int deger = uz;
  int pitch = 50 + deger * 3;
  tone(buzzer, pitch, 100); ;
  Serial.println(uz);

}

void sonar_ses(int yap) {
  if (yap < 50) {

    Serial.println(yap);
    tone(buzzer, Do);
    delay(10);
    noTone(buzzer);
  }
  if (yap > 50 && yap < 100) {

    Serial.println(yap);
    tone(buzzer, re);
    delay(10);
    noTone(buzzer);
  }
  if (yap > 100 && yap < 150) {
    Serial.println(yap);

    tone(buzzer, mi);
    delay(10);
    noTone(buzzer);
  }
  if (yap > 150 && yap  < 200) {
    tone(buzzer, fa);
    delay(10);
    noTone(buzzer);
  }
  if (yap > 200) noTone(buzzer);

}//

void servo_test() {
  byte x = 0;

  for (x = 0; x < 180; x += 3) {
    servo.write(x);
    delay(17);
  }
  delay(500);
  for (x = 180; x > 5; x -= 3) {
    servo.write(x);
    delay(17);
  }
  servo.write(180);
  delay(1500);
}
