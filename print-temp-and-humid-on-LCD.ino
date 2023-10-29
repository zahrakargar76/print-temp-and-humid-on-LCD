#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
float data;
float temp;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  // put your main code here, to run repeatedly:
  data = dht.readHumidity();
  temp = dht.readTemperature();
  lcd.print("temp: ");
  lcd.print(temp);
  lcd.print(" *C");
  lcd.setCursor(0, 1);
  lcd.print("humid: ");
  lcd.print(data);
  lcd.print("%");
  Serial.print("temp: ");
  Serial.print(temp);
  Serial.println(" *C");
  Serial.print("Humid: ");
  Serial.print(data);
  Serial.println(" %");
  if (temp > 30)
  {
    digitalWrite(10, HIGH);
    digitalWrite(9, LOW);
  }
  else
  {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
  }
  delay(2000);
  lcd.clear();
}
