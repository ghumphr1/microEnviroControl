#include <Arduino.h>
#include <LiquidCrystal.h>
#include <math.h>

//int pinOut = 10; //relay
int ThermistorPin = 0;
int Vo;
float R1 = 100000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
   Serial.begin(9600);
    lcd.begin(16, 4);
    lcd.clear();
    lcd.print("Current room");

//    pinMode(10, OUTPUT)

}

void loop() {
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;

  lcd.setCursor(0, 1);

  lcd.print("Temp = ");
  lcd.print(T);
  lcd.print(" C");
 //if (temp >= TempReq){
//   digitalWrite(pinOut, LOW);
// }
// else {
//   digitalWrite(pinOut, HIGH);
 //}
 delay(500);
 //lcd.clear();
}
