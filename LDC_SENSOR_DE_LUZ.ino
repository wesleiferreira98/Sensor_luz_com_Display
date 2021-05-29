#include <LiquidCrystal_I2C.h>
#include <DHT_U.h>
#include <DHT.h>

#define pinSen 8
#define DHTTYPE DHT11
#define sensorLuz 7

LiquidCrystal_I2C lcd(0x27,16, 2);
DHT sensor(pinSen,DHTTYPE);





unsigned long previousMillis = 0;
const long intervalo = 10000;
bool es=false;

void setLCD();
void setup() {
  // put your setup code here, to run once:
  lcd.begin();
  pinMode(sensorLuz,INPUT);
  sensor.begin();
  float h = sensor.readHumidity();
  float t = sensor.readTemperature();

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int info=digitalRead(sensorLuz);
  unsigned long currentMillis = millis();
  setLCD();
  if(es==false){
    setLCD();
    es=true;
  }
 
  if (currentMillis - previousMillis >= intervalo){
    previousMillis = currentMillis;
    lcd.clear();
    es=false;
    delay(700);
  }
  if(info==1){
    lcd.backlight(); 
  }else{
    lcd.noBacklight(); 
  }
  

}

void setLCD(){

  float h = sensor.readHumidity();
  float t = sensor.readTemperature();

  lcd.setCursor(0,0);
  lcd.print("TEMP");
  lcd.setCursor(5,0);
  lcd.print(t);
  lcd.setCursor(0,1);
  lcd.print("HUMI");
  lcd.setCursor(5,1);
  lcd.print(h);
}
