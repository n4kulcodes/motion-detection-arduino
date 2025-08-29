#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
int pirPin = 7;   
int buzzer = 8;   
int pirState = LOW;  
int val = 0;      

void setup() {
  lcd.begin(16, 2);       
  pinMode(pirPin, INPUT); 
  pinMode(buzzer, OUTPUT);
  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {
  val = digitalRead(pirPin);
  if (val == HIGH) {
    digitalWrite(buzzer, HIGH); 
    if (pirState == LOW) {
      lcd.clear();
      lcd.print("Motion Detected");
      pirState = HIGH;
    }
  } else {
    digitalWrite(buzzer, LOW); 
    if (pirState == HIGH) {
      lcd.clear();
      lcd.print("No Motion");
      pirState = LOW;
    }
  }
}
