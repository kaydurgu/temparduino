#include <LiquidCrystal.h>
#include <DHT.h>

#include "DHT.h"

#define DHTPIN A0     

#define DHTTYPE DHT11   // DHT 11


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  for (int DigitalPin = 7; DigitalPin <= 9; DigitalPin++) 
 {
  pinMode(DigitalPin, OUTPUT);
 }
  lcd.begin(16,2); //16 by 2 LCD
  
dht.begin();
}
 
void loop()
{
  delay(1000);
  
  
  float h = dht.readHumidity();
  // Read temperature as Celsius (default)
  float t = dht.readTemperature();

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("'C");
  
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(h);
  lcd.print("%");
  
  if (t<=22)
  {
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  }
  else if (t>22)
  {
  digitalWrite(8, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(9, LOW);
  }
  else if (t>=35)
  {
  digitalWrite(9, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  } 
  
}

 
