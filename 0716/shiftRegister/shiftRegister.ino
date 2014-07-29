const int DATA = 8;
const int LATCH = 9;
const int CLK = 10;

int seq[14] = {1,2,4,8,16,32,64,128,64,32,16,8,4,2};

void setup() {
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
  
  digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLK, MSBFIRST, B01010101);
  digitalWrite(LATCH, HIGH);
}

void loop() {
  for(int i =0;i< 14 ; i++) {
      digitalWrite(LATCH, LOW);
  shiftOut(DATA, CLK, MSBFIRST, seq[i]);
  digitalWrite(LATCH, HIGH);
    delay(100);
  }
}
