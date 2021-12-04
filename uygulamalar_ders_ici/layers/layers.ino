//#define HATA_AYIKLA
const int redLED = 3;
const int greenLED = 5;
const int blueLED = 6;
const int inputPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  Serial.println("basla...");
}

void loop() {

  int redVal, greenVal, blueVal;
  int inputValue = analogRead(inputPin); // Analog giriş al…

  redVal = map(inputValue, 0, 1023, 0, 255); // Giriş değeri işle…
  greenVal = map(inputValue, 0, 1023, 255, 0); // Tekrar yeni değer oluştur…
  //blueVal = map(inputValue, 0, 1023, 100, 200);;
  blueVal = inputValue % 255;
  
#if defined HATA_AYIKLA
  Serial.print("input:"); Serial.println(inputValue);
  Serial.print("red:"); Serial.println(redVal);
  Serial.print("green:"); Serial.println(greenVal);
  Serial.print("blue:"); Serial.println(blueVal);
#endif

  analogWrite(redLED, redVal);  // Oluşan değerleri analog (PWM) olarak çıkışlara
  analogWrite(greenLED, greenVal);  // yaz…
  analogWrite(blueLED, blueVal);

  delay(100);
}
