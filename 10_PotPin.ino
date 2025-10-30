/* วิธีต่อ 1.ขาซ้าย GND ขากลาง A0 ขาขวา VCC */

void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  int voltage = analogRead(A0);
  voltage /= 4;
  analogWrite(3, voltage);
}
