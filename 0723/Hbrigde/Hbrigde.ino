int SENSOR = A0;

int motorEnable = 9;
int motorControl1 = 2;
int motorControl2 = 3;

int sensorValue = 0;
int motorValue = 0;

void setup() {
  pinMode(motorEnable, OUTPUT);
  pinMode(motorControl1, OUTPUT);
  pinMode(motorControl2, OUTPUT);
  
  digitalWrite(motorEnable, LOW);
 
  Serial.begin(9600); 
}

void loop()
{
  sensorValue = analogRead(SENSOR);
  motorValue = map(sensorValue, 0, 1023, -200, 200);
  Serial.println(motorValue);
 
  if (motorValue < -30) {
    digitalWrite(motorEnable, LOW);
    digitalWrite(motorControl1, HIGH); 
    digitalWrite(motorControl2, LOW);
    analogWrite(motorEnable, motorValue*(-1));
  } else if (motorValue > 30) {
    digitalWrite(motorEnable, LOW);
    digitalWrite(motorControl1, LOW);
    digitalWrite(motorControl2, HIGH);
    analogWrite(motorEnable, motorValue);
  } else {
    digitalWrite(motorEnable, LOW);
    digitalWrite(motorControl1, LOW);
    digitalWrite(motorEnable, LOW);
    digitalWrite(motorEnable, HIGH);
  }
}
