#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int sensorPin = A0;

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);

  lcd.print("Temp Monitor");
  delay(2000);
  lcd.clear();
}

void loop()
{
  int reading = analogRead(sensorPin);

  float voltage = reading * (5.0 / 1024.0);

  float temperatureC = (voltage - 0.5) * 100.0;

  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C");

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  delay(1000);
}