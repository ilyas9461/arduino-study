//Seri monitör ve LDR ile ışık kontrolü
#define AN_AYAR_PIN A0
#define AN_LDR_PIN  A1

#define LED_PIN   10
#define R_LED_PIN 3
#define G_LED_PIN 5
#define B_LED_PIN 6

#define ORANSAL_CARPAN  0.5    //kp

int ayar_deger = 0;
int an_ldr = 0;
int fark = 0, pwm_cikis = 0;

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
  pinMode(R_LED_PIN, OUTPUT);
  pinMode(G_LED_PIN, OUTPUT);
  pinMode(G_LED_PIN, OUTPUT);

  Serial.println("basla...");

}

void loop() {

  ayar_deger = analogRead(AN_AYAR_PIN);
  ayar_deger = map(ayar_deger, 0, 1023, 0, 255); //değişken değerini 0-255 değer aralığına göre
  //düzenle.
  analogWrite(LED_PIN, ayar_deger);         //ayar değer parlaklığını led ile göster.

  an_ldr = analogRead(AN_LDR_PIN);        // Ortam ışık değerini oku.
  fark = ((ayar_deger) * 4)- an_ldr ;           // olması gereken değer ile arasındaki farkı bul.
  pwm_cikis = (unsigned int)(ORANSAL_CARPAN * fark); // Çıkış ledlerine uyuglanacak değer.
  pwm_cikis = map(pwm_cikis, 0, 1023, 0, 255); //0-255 değer aralığına göre düzenle
  // Çıkış ledlerine değeri yaz.

  if (pwm_cikis >= 0){
    pwm_cikis=128+pwm_cikis;
  }
  if (pwm_cikis<0){
    pwm_cikis=128+pwm_cikis;
  }
  if (pwm_cikis >= 0) 
  {
    analogWrite(R_LED_PIN, pwm_cikis);
    analogWrite(G_LED_PIN, pwm_cikis);
    analogWrite(B_LED_PIN, pwm_cikis);
  }
  //Elde edilen ve hesaplanan değerleri seri monitörde göster.
  Serial.print("Ayar Deger:"); Serial.println(ayar_deger);
  Serial.print("LDR:"); Serial.println(an_ldr);
  Serial.print("Fark:"); Serial.println(fark);
  Serial.print("PWM:"); Serial.println(pwm_cikis);

  delay(1000);   //işlem peryodu

}
