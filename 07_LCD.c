#include <LiquidCrystal_I2C.h>
  LiquidCrystal_I2C lcd(0x27, 16, 2);

  byte heart[8] = {
    B00000,
    B01010,
    B11111,
    B11111,
    B01110,
    B00100,
    B00000,
    B00000 
    };

  byte celcius[8] = {
    B11100,
    B10100,
    B11100,
    B00000,
    B00000,
    B00000,
    B00000,
    B00000 
    };

void setup() {
    lcd.init();
    lcd.createChar(0, heart);
    lcd.createChar(1, celcius);
    lcd.backlight();
    lcd.setCursor(0, 6);
    lcd.print("I ");
    lcd.write(byte(0));
    lcd.print(" IT");
    lcd.setCursor(1,0);
    lcd.print("67070179 ");
}

void loop() {
    lcd.setCursor(0, 1);
    lcd.print(millis()/1000);
}