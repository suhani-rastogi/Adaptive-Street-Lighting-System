0const int sensorPin1 = 8;
const int sensorPin2 = 9; 
const int buzzerPin = 13; 
#include <LiquidCrystal.h> 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

const float threshold = 0.05; 
const float distanceBetweenSensors = 20.0; 

void setup() {
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(buzzerPin, OUTPUT); 
  lcd.begin(16, 2); 
}

void loop() {
  int sensorValue1 = digitalRead(sensorPin1);
  int sensorValue2 = digitalRead(sensorPin2);

  float speed = calculateSpeed(); 

  if (sensorValue1 == LOW && sensorValue2 == LOW) { 
    lcd.clear(); 
    lcd.setCursor(0,0); 
    lcd.print("No Car Detected");
    lcd.setCursor(0,1); 
    lcd.print("Searching...");
    delay(500); 
  }
 
  else {
    lcd.clear(); 
    lcd.setCursor(0,0); 
    lcd.print("Speed: ");
    lcd.print(speed);
    lcd.print(" km/h"); 

    if (speed > threshold) { 
      lcd.setCursor(0,1); 
      lcd.print("Over Speeding!");
      tone(buzzerPin, 1000); 
      delay(1000); 
      noTone(buzzerPin); 
    }
    else {
      lcd.setCursor(0,1); 
      lcd.print("Normal Speed");
    }
   
    delay(2000); 
  }
}

float calculateSpeed() {
  long time1 = micros(); 
 
  while (digitalRead(sensorPin1) == HIGH || digitalRead(sensorPin2) == HIGH); 
 
  long time2 = micros(); 
 
  long timeDiff = time2 - time1; 
 
  float speed = distanceBetweenSensors / ((timeDiff / 1000000.0) *3600.0); 
 
  return speed;
}
