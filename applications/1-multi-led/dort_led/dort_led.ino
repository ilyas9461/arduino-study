int led_1=10;
int led_2=11;
int led_3=12;
int led_4=13;
int sure=100;
int ledler[]={10,11,12,13};

void setup() {
  // put your setup code here, to run once:
pinMode (ledler[0],OUTPUT);
pinMode (ledler[1],OUTPUT);
pinMode (ledler[2],OUTPUT);
pinMode (ledler[3],OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(ledler[0],HIGH);
delay(sure);
digitalWrite(ledler[0],LOW);
delay(sure);
digitalWrite(ledler[1],HIGH);
delay(sure);
digitalWrite(ledler[1],LOW);
delay(sure);
digitalWrite(ledler[2],HIGH);
delay(sure);
digitalWrite(ledler[2],LOW);
delay(sure);
digitalWrite(ledler[3],HIGH);
delay(sure);
digitalWrite(ledler[3],LOW);
delay(sure);
digitalWrite(ledler[2],HIGH);
delay(sure);
digitalWrite(ledler[2],LOW);
delay(sure);
digitalWrite(ledler[1],HIGH);
delay(sure);
digitalWrite(ledler[1],LOW);
delay(sure);
digitalWrite(ledler[0],HIGH);
delay(sure);

}
