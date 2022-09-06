#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ADDRESS 0x27

#define CHARS 20      // 20 for 2004
#define LINES 4       //  4 for 2004

#define SDA D3        // I2C port på mikrokontroller du anvender
#define SCL D4        // I2C port på mikrokontroller du anvender

LiquidCrystal_I2C lcd(ADDRESS, CHARS, LINES);

char Buffer[20];
int Seconds;

void setup() {

  Serial.begin(9600);
  Wire.begin(SDA, SCL);
  lcd.begin(CHARS, LINES);
  lcd.init();
  lcd.backlight();
  Seconds = 0;

}

void loop() {

#if LINES == 2

  lcd.setCursor(1, 0);
  lcd.print("Demo program");
  lcd.setCursor(0, 1);
  lcd.print("www.eBits.dk");

#elif LINES == 4

  lcd.setCursor(3, 0);
  lcd.print("Demo program");

  Seconds = int(millis() / 1000);
  while (Seconds >= 9999) {
     Seconds = Seconds - 9999;
  }
  
  sprintf(Buffer, "--==[%04d]==--", Seconds);

  lcd.setCursor(3, 1);
  lcd.print(Buffer);

  lcd.setCursor(2, 2);
  lcd.print("LCD char display");
  
  lcd.setCursor(2, 3);
  lcd.print("www.eBits.dk");

#else

  lcd.setCursor(0, 0);
  lcd.print("ERROR!");

#endif

  delay(100);

}
