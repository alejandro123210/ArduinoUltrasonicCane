#define sensorTrigPin    4
#define sensorEchoPin    2
int buzzpin = 8;
//int buttonApin = 9;
//int buttonBpin = 10;
const int SW_pin = 2; 
const int X_pin = 0;

void setup()
{
  Serial.begin(9600);  
  pinMode(sensorTrigPin, OUTPUT);
  pinMode(sensorEchoPin, INPUT);
  pinMode(buzzpin, OUTPUT);
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
}

int on = 2;
void loop()
{
  int pulseWidth = 0;

  digitalWrite(sensorTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTrigPin, LOW);

  pulseWidth = pulseIn(sensorEchoPin, HIGH);

  Serial.print("\nPulse Width: ");
  Serial.print(pulseWidth);
  delay(100);
    
  if (pulseWidth < 2500 && on == 1) {
    digitalWrite(buzzpin, HIGH);
    delay(1);
  } else {
    digitalWrite(buzzpin, LOW);
  }

  if (analogRead(X_pin) > 500){
    on = 1;
  } else if (analogRead(X_pin) < 100) {
    on = 0;
  }
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.print("\n\n");    
  delay(500);
}



