int btnRed = 2;
int btnGreen = 3;
int btnBlue = 4;
int red = 5;
int green = 6;
int blue = 7;

boolean redStat = true;
boolean greenStat = true;
boolean blueStat = true;

void setup(){
  pinMode(btnRed, INPUT);
  pinMode(btnGreen, INPUT);
  pinMode(btnBlue, INPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);

  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}

void loop(){
  change(btnRed, red, &redStat);
  change(btnGreen, green, &greenStat);
  change(btnBlue, blue, &blueStat);
  delay(5);
}

void change(int btn, int color, boolean* stat){
  if(digitalRead(btn) == LOW) 
  {
    *stat = !(*stat);
    if(*stat) digitalWrite(color, LOW);
    else digitalWrite(color, HIGH);
    delay(300);
  }
}
