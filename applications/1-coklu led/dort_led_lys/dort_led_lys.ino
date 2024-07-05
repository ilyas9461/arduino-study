//değişkenler
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;

int sure = 500; //mili saniye (mS)

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);

}

void loop() {
  //  digitalWrite(led1, LOW);
  //  delay(sure);
  //  digitalWrite(led1, HIGH);
  //  delay(sure);
  //
  //  digitalWrite(led2, LOW);
  //  delay(sure);
  //  digitalWrite(led2, HIGH);
  //  delay(sure);
  //
  //  digitalWrite(led3, LOW);
  //  delay(sure);
  //  digitalWrite(led3, HIGH);
  //  delay(sure);
  //
  //  digitalWrite(led4, HIGH);
  //  delay(sure);

  digitalWrite(led1, HIGH);
  delay(sure);
  digitalWrite(led1, HIGH);
  delay(sure);
  digitalWrite(led2, HIGH);
  delay(sure);
  digitalWrite(led3, HIGH);
  delay(sure);
  digitalWrite(led4, HIGH);
  delay(sure);

  digitalWrite(led1, LOW);
  delay(sure);
  digitalWrite(led2, LOW);
  delay(sure);
  digitalWrite(led3, LOW);
  delay(sure);
  digitalWrite(led4, LOW);
  delay(sure);

}
