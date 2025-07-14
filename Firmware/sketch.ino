#include <Servo.h>
#define AIN1 5
#define AIN2 6
#define BIN1 9
#define BIN2 10
#define TRIG_PIN 8
#define ECHO_PIN 7
#define TRIG2_PIN 12
#define ECHO2_PIN 11
Servo servo1;
Servo servo2;
bool objectClose = false;
void setup() {
  Serial.begin(9600); 
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG2_PIN, OUTPUT);
  pinMode(ECHO2_PIN, INPUT);
  servo1.attach(3);
  servo2.attach(2);
  servo1.writeMicroseconds(950);
  servo2.write(0);
}
void loop() {
  float distance1 = readDistance(TRIG_PIN, ECHO_PIN);
  float distance2 = readDistance(TRIG2_PIN, ECHO2_PIN);
  Serial.print("D1: "); Serial.print(distance1);
  Serial.print(" D2: "); Serial.print(distance2);
  Serial.print(" Object: "); Serial.println(objectClose);
  if (!objectClose && ((distance1 > 0 && distance1 < 40) || (distance2 > 0 && distance2 < 40))) {
    objectClose = true;
  }
  else if (objectClose && (distance1 > 50 && distance2 > 50)) {
    objectClose = false;
  }
  if (objectClose) {
    
    runMotorsForward(80);
    servo1.write(15);  
    servo2.write(15);
    Serial.println("TURNING");
  } else {

    runMotorsForward(153);
    servo1.write(0);
    servo2.write(0);
    Serial.println("STRAIGHT");
  }
  delay(10); 
}
float readDistance(int trigPin, int echoPin) {
  long duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH, 10000); 
  if (duration == 0) return 0;
  return duration * 0.034 / 2;
}
void runMotorsForward(int speed) {
  analogWrite(AIN1, speed);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, speed);
  analogWrite(BIN2, 0);
}  
