
const int redPin = 5;     //sabit değer tanımlama
const int greenPin = 3;

#define  bluePin  6                       // sabit olarak tanımlama
#define rgb_led(r,g,b) setColor(r,g,b)    //makro tanımlama

byte r_deger=0,g_deger=0,b_deger=0;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  

  randomSeed(analogRead(0));
}

void loop()
{
//  setColor(0, 255, 0);  // green
//  delay(1000);
//  setColor(0, 0, 255);  // blue
//  delay(1000);
//  setColor(255, 255, 0);  // yellow
//  delay(1000);  
//  setColor(80, 0, 80);  // purple
//  delay(1000);
//  setColor(0, 255, 255);  // aqua
//  delay(1000);
//  rgb_led(255, 255, 255);  // beyaz
//  delay(1000);

  //2.işlem
  r_deger=random(0,255);
  g_deger=random(0,255);
  b_deger=random(0,255);
  rgb_led(r_deger, g_deger, b_deger);
  delay(250);
}
// Dönüş değeri olmayan bir fonksiyon
void setColor(int red, int green, int blue)
{ 
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}




//rgb_led(renk+10,renk+10, renk);  // red
//  renk+=10;                           
//  delay(100);
