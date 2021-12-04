//Buton okuma uygulaması
#define redPin    5    //sabit değer tanımlama
#define greenPin  3
#define bluePin   6
#define butonPin  8

bool buttonDurumu = false;
int analogGiris = 0;
float gerilimDegeri=0.0;

void setup() {
  // Seri Haberleşmeyi başlat
  Serial.begin(9600);
  Serial.println("Basla...");

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  analogGiris = analogRead(A0);
  gerilimDegeri = (analogGiris / 1023.0) * 5.0;
  Serial.print("Analog deger:");
  Serial.println(analogGiris);
  Serial.print("Gerilim: ");
  Serial.print(gerilimDegeri);
  Serial.println(" V");
  delay(1000); // Bir saniye bekle
}
