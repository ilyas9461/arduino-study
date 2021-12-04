//değişkenler
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;

int ledler[8] = {13, 12, 11, 10, 9, 8, 7, 6};

int sure = 40; //mili saniye (mS)
int x=0;

bool kontrol=false;
String sifre="ben124";
void setup() {

  //  pinMode(led1, OUTPUT);
  //  pinMode(led2, OUTPUT);
  //  pinMode(led3, OUTPUT);
  //  pinMode(led4, OUTPUT);

  for (int x = 0; x < 8; x++) {
    pinMode(ledler[x], OUTPUT);
  }

}

void loop() {
 
  
  for ( x = 0; x < 8; x++) {
    digitalWrite(ledler[x], HIGH);
    delay(sure);
  }
  
  delay(sure);
  
  for ( x = 4; x >= 0; x--) {
    digitalWrite(ledler[x], LOW);
    delay(sure);
  }
}
