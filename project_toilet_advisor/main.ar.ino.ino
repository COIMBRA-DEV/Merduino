//required new liquid crystal library


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

  
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
const int buzzer = 9;

#define ledPin 6
#define sensorPin A0

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  pinMode(buzzer, OUTPUT);
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("O TIAGO E GAY!");  
}

void loop() {
  lcd.clear();
  lcd.print(readSensor());
  lcd.setCursor(0,1);
  lcd.print("O TIAGO E GAY!");  
  delay(1000);
}


int readSensor() {

  unsigned int sensorValue = analogRead(sensorPin);  // Read the analog value from sensor

  unsigned int outputValue = map(sensorValue, 0, 1023, 0, 255); // map the 10-bit data to 8-bit data


  if (outputValue > 65){
    
      tone(buzzer, 500); // Send 1KHz sound signal...

    analogWrite(ledPin, outputValue); // generate PWM signal

    }
    
  else
  {
    digitalWrite(ledPin, LOW);
    noTone(buzzer);     // Stop sound...

    }

    
  return outputValue;             // Return analog moisture value

}
