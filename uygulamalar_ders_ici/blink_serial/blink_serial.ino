void setup() {
 // kurulum kodunuzu bir kez çalıştırmak için buraya yerleştirin:
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop() {
  int inValue;
  // tekrar tekrar çalıştırmak için ana kodunuzu buraya yazın:      

  Serial.println("LED'in kaç kez yanıp sönmesini istiyorsunuz?");
  while(!Serial.available()) ;
  inValue=Serial.parseInt();
  if(inValue==100){
    inValue=0;
    Serial.println("Çıkış...");
    while(1);
  }
  Serial.read();
  Serial.print(" Yanıp sönen yerleşik LED, ");
  Serial.print(inValue);
  Serial.println(" defa yanıp söner…");
  for(int i=0; i<inValue; i++) {
    digitalWrite(13,HIGH);
    delay(200);
    digitalWrite(13,LOW);
    delay(200);
  }
}
