int SENSOR_ROTATION = A0;

int sensorRotationValue = 0;
int serialRotationValue = 0;

String message = "";
String prev_message = "";

void setup() {
  Serial.begin(9600);  
}

void loop() {
  message = "";
  sensorRotationValue = analogRead(SENSOR_ROTATION);
  serialRotationValue = map(sensorRotationValue, 0, 1023, 0, 100);
  serialRotationValue = constrain(serialRotationValue, 0, 100);
  message = String(serialRotationValue);
  Serial.println(message);
}
