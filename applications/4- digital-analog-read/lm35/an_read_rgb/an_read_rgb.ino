//Buton okuma uygulaması
#define redPin    5    //sabit değer tanımlama
#define greenPin  3
#define bluePin   6
#define butonPin  8

bool buttonDurumu = false;
int pot, an1=0;
float lm35_deg=0.0, sicaklik=0.0 ,Vpot=0.0;

void setup() {
  // Seri Haberleşmeyi başlat
  Serial.begin(9600);
  Serial.println("LM35");

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  pot = analogRead(A0); //pot
  pot=map(pot,0,1023,0,150);
  an1=analogRead(A1);
  
  lm35_deg = (an1 / 1023.0) * 5000.0;   // 5V=5000mV
  //Vpot= (pot / 1023.0) * 5000.0; 
  sicaklik= lm35_deg /10.0;
  
  Serial.print("pot:"); Serial.println(pot);
  Serial.print("lm35:"); Serial.print(lm35_deg);  Serial.println(" mV");
  Serial.print("Sicaklik:"); Serial.print(sicaklik);  Serial.println(" C");

  if( sicaklik>(pot)){
    digitalWrite(greenPin,LOW);
  }else{
    digitalWrite(greenPin,HIGH);
  }
  delay(1000); // Bir saniye bekle
}
