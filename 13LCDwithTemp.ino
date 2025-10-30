/* วิธีต่อ LCD 1.ขา GND กับ VCC ตรงตามชื่อแต่ ขา SDA เข้า A4 SCL เข้า A5 */

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte heart[8] = {
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000,
};

byte celcius[8] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

void setup() {
  lcd.init();
    lcd.createChar(0, heart);
    lcd.backlight();
    lcd.setCursor(5, 0);
    lcd.print("I");
    lcd.setCursor(7, 0);
    lcd.write(byte(0));
    lcd.setCursor(9, 0);
    lcd.print("IT");
    lcd.setCursor(0, 1);
    lcd.print("67070179");
    lcd.createChar(1, celcius);
    Serial.begin(9600);
}

void loop() {
  lcd.setCursor(9,1);
  float value = analogRead(A0);
  float tempC = ((value * 5/1023)-0.6)*100;
  lcd.print(tempC);
  lcd.write(byte(1));
  delay(1000);
}
