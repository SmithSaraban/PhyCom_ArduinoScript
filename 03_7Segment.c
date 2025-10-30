int num[10][7]{
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,0,0,1,1},
};

const int seg_a = 2;
const int seg_b = 3;
const int seg_c = 4;
const int seg_d = 5;
const int seg_e = 6;
const int seg_f = 7;
const int seg_g = 8;

void setup(){
  pinMode(seg_a, OUTPUT);
  pinMode(seg_b, OUTPUT);
  pinMode(seg_c, OUTPUT);
  pinMode(seg_d, OUTPUT);
  pinMode(seg_e, OUTPUT);
  pinMode(seg_f, OUTPUT);
  pinMode(seg_g, OUTPUT);
}

void loop(){
  for(int i = 0; i < 10; i++){
    printNum(i);
    delay(1000);
  }
}

void printNum(int i){
  digitalWrite(seg_a, num[i][0]);
  digitalWrite(seg_b, num[i][1]);
  digitalWrite(seg_c, num[i][2]);
  digitalWrite(seg_d, num[i][3]);
  digitalWrite(seg_e, num[i][4]);
  digitalWrite(seg_f, num[i][5]);
  digitalWrite(seg_g, num[i][6]);
}
