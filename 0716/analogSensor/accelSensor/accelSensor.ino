int xAxis = A2; 
int yAxis = A1; 
int zAxis = A0;

int xSensorValue = 0; 
int ySensorValue = 0; 
int zSensorValue = 0;

int RED_LED = 9;
int GREEN_LED = 10; 
int BLUE_LED = 11;
float redValue = 0; 
float greenValue = 0; 
float blueValue = 0;

void setup()
{ 
  Serial.begin(9600);
}

void loop()
{
  xSensorValue = analogRead(xAxis); 
  ySensorValue = analogRead(yAxis); 
  zSensorValue = analogRead(zAxis);
  Serial.print(" X AXIS: "); 
  Serial.print(xSensorValue); 
  
  Serial.print(" Y AXIS: "); 
  Serial.print(ySensorValue); 
  
  Serial.print(" Z AXIS: "); 
  Serial.println(zSensorValue);
  
  redValue = map(xSensorValue,70,270,0,255); 
  greenValue = map(ySensorValue,70,270,0,255); 
  blueValue = map(zSensorValue,70,270,0,255);

//  Serial.print(" RED: "); 
//  Serial.print(redValue); 
//  
//  Serial.print(" GREEN: "); 
//  Serial.print(greenValue); 
//  
//  Serial.print(" BLUE: "); 
//  Serial.println(blueValue);

  analogWrite(RED_LED, redValue); 
  analogWrite(GREEN_LED, greenValue); 
  analogWrite(BLUE_LED, blueValue);
  delay(30); 
}
