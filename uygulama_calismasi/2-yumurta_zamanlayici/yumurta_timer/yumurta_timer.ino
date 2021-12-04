//Yumurta Zamanlayıcısı
// Yumurta pişme türü secimi
const char RAFADAN = 'R';
const char ORTA_PISMIS = 'O';
const char COK_PISMIS = 'C';
// yumurta pişme süreleri
int rafadan_sure = 3000;
int orta_sure = 1000;
int cok_sure = 7500;

//Pişme zaman durumunu ve alarm durumunu göstermek için.
int ledler[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int led_index = 0;

char secim = 0;   //secimi tutan değişken

bool gaz_sensoru = true; //Gaz yoksa false varsa true değerini alır,
bool alev_sensoru = true; // Alev yoksa false, varsa true değerini alır.
bool basla = true;        // işleme başlama
long zaman_deg = 0;

void setup() {
  for (int x = 0; x < 8; x++) {
    pinMode(ledler[x], OUTPUT);
  }
  secim = ORTA_PISMIS;
  //secim=RAFADAN; 
  gaz_sensoru = true;
  alev_sensoru=true;
  basla=true;
}

void loop() {

  if (basla && gaz_sensoru && alev_sensoru) 
  {
    if (secim == RAFADAN) 
    {
      if (zaman_deg > rafadan_sure) 
      {
        delay(1000);
        for (int x = 0; x < 8; x++) digitalWrite(ledler[x], LOW);
        //basla = false;
        zaman_deg = 0;
      }
      if (zaman_deg >= ((rafadan_sure / 8)*led_index)) {
        led_index++;
      }
    }
    if (secim == ORTA_PISMIS) 
    {
      if (zaman_deg > orta_sure) 
      {
        delay(1000);
        for (int x = 0; x < 8; x++) digitalWrite(ledler[x], LOW);
        basla = false;
        zaman_deg = 0;
      }
      if (zaman_deg >= ((orta_sure / 8)*led_index)) {
        led_index++;
      }
    }
    
    digitalWrite(ledler[led_index-1], HIGH);
    
  } else if (!gaz_sensoru || !alev_sensoru) //alarm durumu gaz veya alev yoksa
  {
      for (int x = 0; x < 8; x++) digitalWrite(ledler[x], HIGH);
      delay(100);
      for (int x = 0; x < 8; x++) digitalWrite(ledler[x], LOW);
      delay(100);
  }

  zaman_deg++;  // zaman_deg değikeninin her 1 mS de 1 arttır...
  delay(1);// 1 mS(mili saniye) aralıklarla işlem yap...

}//
