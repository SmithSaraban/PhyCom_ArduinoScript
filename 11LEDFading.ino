int yellowLED = 3;
int greenLED = 5;

void setup() {
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  for(int i = 0; i < 256; i++){
    analogWrite(yellowLED, i);
    delay(15);
  }
  for(int j = 0; j < 256; j+=2){
    analogWrite(greenLED, j);
    delay(15);
  }
  //ถ้าจะให้ติดหร้อมกันให้สร้างตัวแปร แยก 2 อัน แล้วค่อยๆบวกถ้าเกิน 255 ปรับเป็น 0
}
