
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int message = '0';
int LED_ARRAY[] = {LED1, LED2, LED3, LED4};
int LED_ARRAY_SIZE;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  LED_ARRAY_SIZE = sizeof(LED_ARRAY) / sizeof(int);
  randomSeed(10);
}

void onLED(int number) {
  writeLED(LED_ARRAY[number], HIGH);
}

void offLED(int number) {
  writeLED(LED_ARRAY[number], LOW);
}

void writeLED(int LED, int level) {
  digitalWrite(LED, level);
}

void offAllLED() {
 for(int i=0 ; i< LED_ARRAY_SIZE ; ++i) {
   offLED(i);
 } 
}

void onAllLED() {
 for(int i=0 ; i< LED_ARRAY_SIZE ; ++i) {
   onLED(i);
 } 
}

void shuffleArray() {
  int randomNumber = 0;
  int temp = 0;
  int i,j;
  for (int i = 0; i < LED_ARRAY_SIZE - 1; i++) 
  {
    j = random(i+1, LED_ARRAY_SIZE);
    temp = LED_ARRAY[j];
    LED_ARRAY[j] = LED_ARRAY[i];
    LED_ARRAY[i] = temp;
  }
}

void onRandomLED(int ledNumber) {
  offAllLED();
  shuffleArray();
  
//  for(int i=0 ; i < LED_ARRAY_SIZE ; ++i) {
//    Serial.println(LED_ARRAY[i]);
//  }
  for(int i=0 ; i < ledNumber ; ++i) {
    onLED(i);    
  }
}

void loop() 
{  
  if (Serial.available()) {
    message = Serial.read();
  }
  
  if (message == '0') {
    offAllLED();  
  } else if (message == '1') {
    Serial.println("Sparkle 1 LED randomly at the same time");
    onRandomLED(1); 
  } else if (message == '2') {
    Serial.println("Sparkle 2 LED randomly at the same time");
    onRandomLED(2);
  } else if (message == '3') {    
    Serial.println("Sparkle 3 LED randomly at the same time");
    onRandomLED(3);
  } else if (message == '4') {
    Serial.println("Sparkle All LED");
    onRandomLED(4);
  }
  
  delay(200);
}
