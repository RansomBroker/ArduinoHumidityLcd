#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#define DHTPIN A0
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);

}

void loop() {
  // put your main code here, to run repeatedly:
  /**
     for DHT session

  */
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("RansomBroker");
  lcd.setCursor(0, 1);
  lcd.print("Project");
  lcd.noDisplay();
  delay(1000);
  lcd.display();
  delay(2000);
  lcd.clear();
  delay(2000);
  float celcius = dht.readTemperature();


  //cek if have wrong session
  if (isnan(celcius)) {
    //write code to warning have wrong proccess
    lcd.setCursor(0, 1);
    lcd.print("");
    lcd.setCursor(0, 1);
    lcd.print("Device failed");
    lcd.noDisplay();
    delay(500);
    lcd.display();
    delay(500);
    lcd.clear();
    return;
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("");
  lcd.setCursor(0, 1);
  lcd.print("");
  lcd.setCursor(0, 0);
  lcd.print("suhu : ");

  int i = 1;
  while (i) {
    float celcius = dht.readTemperature();
    lcd.setCursor(7, 0);
    lcd.print(celcius);
    Serial.print(celcius);
    lcd.print("");
    delay(1000);
    i++;
  }




  /**
     for LCD
  */


}
