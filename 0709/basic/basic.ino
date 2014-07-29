int LED = 9;
int BUTTON = 7;
int msg;
boolean ONOFF = false;


void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop()
{ 
    if (digitalRead(BUTTON) == HIGH) 
    {
      Serial.write("Press Button!!\n");  
    }

  if (Serial.available()) {
   
    msg = Serial.read();
    if (msg == '1') { 
      Serial.write("I turn on my LED.\n");
      ONOFF = true;
    } else {
      Serial.write("I turn off my LED.\n"); 
      ONOFF = false;
    } 
  }

  if (ONOFF) {
    digitalWrite(LED,HIGH);
  } else {
    digitalWrite(LED,LOW);
  } 
}
