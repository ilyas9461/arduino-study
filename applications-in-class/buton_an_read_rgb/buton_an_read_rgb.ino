
const int redPin = 5;     //sabit değer tanımlama
const int greenPin = 3;

#define  bluePin  6
bool buttonDurumu=false;
int butonPin=8;
int renk_sec=0;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
   pinMode(butonPin, INPUT);

}

void loop() {
  // Buton durumunu oku
  if (digitalRead(butonPin)==LOW) {
    delay(250);
    renk_sec++;
    //digitalWrite(ledPin, HIGH);
  } 
  else {
      //digitalWrite(ledPin, LOW);
  }

  
  if(renk_sec==1) digitalWrite(redPin, HIGH);
  if(renk_sec==2) digitalWrite(greenPin, LOW);
  if(renk_sec==3) digitalWrite(bluePin, HIGH);
  if(renk_sec==4){
    digitalWrite(bluePin, LOW);
     digitalWrite(redPin, LOW);
     digitalWrite(greenPin, LOW);
     renk_sec=0;
  }
  
}
