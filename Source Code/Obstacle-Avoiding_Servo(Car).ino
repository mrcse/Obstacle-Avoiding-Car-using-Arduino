#include <NewPing.h>

#define trigPin 12
#define echoPin 11
#define motor1Back 2
#define motor1Forward 3
#define motor2Forward 4
#define DISTANCE 25

NewPing sonar(trigPin, echoPin, DISTANCE);

void setup(){
  Serial.begin(9600);
  pinMode(motor1Back, OUTPUT);
  pinMode(motor1Forward, OUTPUT);
  pinMode(motor2Forward, OUTPUT);
}

void loop(){
  uint8_t distance = sonar.ping_cm();
  Serial.print("J-> ");
  Serial.println(distance);
  

  if(distance<=10 && distance>0){
    
    Serial.println("Turn\n");
    //delay(100);
    digitalWrite(motor1Back, HIGH);
    digitalWrite(motor1Forward, LOW);
    digitalWrite(motor2Forward, HIGH);
  } else {
    digitalWrite(motor1Back, LOW);
    digitalWrite(motor1Forward, HIGH);
    digitalWrite(motor2Forward, HIGH);
  }
  delay(50);
}
