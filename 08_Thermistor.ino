/* วิธีต่อ 1.ขาซ้าย thermistor ต่อกับ resistor 10000 โอห์ม ด้านซ้ายของ resistor เข้า VCC ด้านขวาของ resistor เข้า pin arduino 
        2.ขาขวา thermistor ต่อ GND
*/    

void setup() {
  Serial.begin(9600);
}

void loop() {
  int vIn = analogRead(A0);
  float voltage = vIn*(5.0/1023.0);
  float Resistance = 10000 * (5.0 / voltage - 1.0);
  float temperatureK = 1.0/(1.0/(25+273.15)+(1.0/4050)*log(Resistance/10000));
  float temperatureC = temperatureK-273.15;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  delay(1000);
}