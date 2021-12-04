#include <Servo.h>
//SG950 mikro Servo  kırmız +5V, kahve gnd, turuncu kontrol
Servo m;  

void setup() {
  Serial.begin(9600);
  m.attach(9);  // pin 9 üzerindeki servoyu servo nesnesine bağlar.
}

void loop() {
  int inputValue=analogRead(A1);
  int pos=map(inputValue,100,500,16,180);

  Serial.print("input:"); Serial.println(inputValue);
  Serial.print("pos:"); Serial.println(pos);
  
   m.write(pos);

   delay(500);

   
//  for (int pos = 0; pos <= 180; pos += 1) { 
//    myservo.write(pos);              
//    delay(15);                       
//  }
//  delay(1000);
//  for (int pos = 180; pos >= 0; pos -= 1) { 
//    myservo.write(pos);              
//    delay(15);                       
//  }
  
 
}
