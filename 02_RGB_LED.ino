int red = 2; //ทุกขาที่ไม่ใช่ ขา cathode ต่อกับ resistor 220 โอห์ม(ส้ม ส้ม น้ำตาล ทอง)
int green = 3; //ขา cathode ต่อเข้า VCC
int blue = 4;

void setup(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
}

void loop(){
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
  delay(1000);

  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(1000);

  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  delay(1000);

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, HIGH);
  delay(1000);

  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  delay(1000);

  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, LOW);
  delay(1000);

  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  delay(1000);
}