void setup() {
    Serial.begin(9600);
}

void loop() {
    int vIn = analogRead(A0);
    float voltage = vIn*(5.0/1023.0);
    float Resistance = 10000 * (5.0 / voltage - 1.0);
    float temperatureK = 1.0/(1.0/(25+273.15)+(1.0/3950)*log(Resistance/10000));
    float temperatureC = temperatureK-273.15;

    Serial.print("Temperature: ");
    Serial.print(temperatureC);
    Serial.println(" C");

    delay(1000);
}