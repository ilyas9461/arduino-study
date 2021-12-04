const int redPin = 5;     //sabit değer tanımlama
const int greenPin = 3;

#define  bluePin  6

/* A0 girişindeki gerilim okunuyor */
int analogGiris=0;
float gerilimDegeri=0.0;
void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // Seri Haberleşmeyi başlat
  Serial.begin(9600);
  Serial.println("basla...");
  delay(1000);
}
void loop() {
  analogGiris = analogRead(A0);
  gerilimDegeri = (analogGiris / 1023.0) * 5.0;
  Serial.print("Analog deger:");
  Serial.println(analogGiris);
  Serial.print("Gerilim degeri:");
  Serial.println(gerilimDegeri);
  
  analogWrite(bluePin,analogGiris/4);
  delay(100); // Bir saniye bekle
}
