int SENSOR = A0;
int MOTOR = 9;
int sensorValue = 0;
int motorValue = 0;

void setup() {
  pinMode(MOTOR, OUTPUT);
}

void loop() {
  sensorValue = analogRead(SENSOR);
  motorValue = map(sensorValue, 0, 1023, 0, 255);
  
  analogWrite(MOTOR, motorValue);
}
