/* วิธีต่อ 1)หันด้านที่เป็นสี่เหลี่ยมเข้าหาตัว
        2)ขาซ้าย VCC ขากลาง A0 ขาขวา GND
*/

void setup() {
  Serial.begin(9600); // เริ่มต้น Serial Monitor
}

void loop() {
  int sensorValue = analogRead(A0); // อ่านค่าเซนเซอร์
  float voltage = sensorValue * (5.0 / 1023.0); // แปลงค่า Analog เป็น Voltage
  float temperatureC = (voltage-0.6) * 100; // แปลง Voltage เป็น อุณหภูมิ (Celsius)
  
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");
  
  delay(1000); // หน่วงเวลา 1 วินาที
}
