//değişkenler
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;

int ledler[8] = {13, 12, 11, 10, 9, 8, 7, 6};

int sure = 100; //mili saniye (mS)
int x = 0;

void setup() {

  for (int x = 0; x < 8; x++) {
    pinMode(ledler[x], OUTPUT);
  }
}

void loop() {
  while (x < 16) {
    if (x < 8) {
      digitalWrite(ledler[x], HIGH);
      delay(sure);
//      digitalWrite(ledler[x], LOW);
//      delay(sure);
    }
    
    //if(x==10) continue;// donguyu gerı ilk durum dondurur
    //if(x==10) break;   // donguden çıkr.
    
    if (x > 7) {
//      digitalWrite(ledler[15 - x], HIGH);
//      delay(sure);
      digitalWrite(ledler[15-x], LOW);
      delay(sure);
    }
    x++;    //x=x+1 analamındadır.
  }//while
  x = 0;    //değişkeni sıfırla
}
