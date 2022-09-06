#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ADDRESS 0x27

#define CHARS 20      // 20 for 2004
#define LINES 4       //  4 for 2004

#define SDA D3        // I2C port på mikrokontroller du anvender
#define SCL D4        // I2C port på mikrokontroller du anvender

LiquidCrystal_I2C lcd(ADDRESS, CHARS, LINES);

void setup() {

  Serial.begin(9600);
  Wire.begin(SDA, SCL);
  lcd.begin(CHARS, LINES);
  lcd.init();
  lcd.backlight();


  lcd.setCursor(0,0);           
  lcd.print("Hello!");

  lcd.setCursor(0,1);             
  lcd.print("Funny!");

  lcd.setCursor(3,2);            
  lcd.print("Enjoy!");

  lcd.setCursor(8,3);             
  lcd.print("Arduino!");

}

void loop() {
          

}
