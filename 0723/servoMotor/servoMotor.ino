#include <Servo.h>

Servo servoMotor;

int SERVO = 9;
int SENSOR = A0;

int sensorValue = 0;
int motorValue = 0;

void setup() {
  servoMotor.attach(SERVO);
  Serial.begin(9600); 
}

void loop() {
  sensoorValue = analogRead(SENSOR);
  motorValue = map(sensorValue, 0, 1023, 0, 179);
 
  Serial.print("Sensor Value : ");
  Serial.print(sensorValue);
  Serial.print("Angle Value : ");
  servoMotor.write(motorValue);
 
  delay(15); 
}
