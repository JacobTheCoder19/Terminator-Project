#include <Wire.h>
#include <Servo.h>
#include <NewPing.h>
// Motor controlling the robot's head
Servo headMotor;     
// Motor controlling the ultrasonic sensor
Servo sensorMotor;

NewPing sonar(6, 5, 90);

int headMotorPin = 2;
int sensorMotorPin = 4;
int pirSensor = 3;
int lazer = 7;

bool tracking = false;
// Default to forward-facing
int lastKnownAngle = 107;  
int closestDistance = 200;
int smoothAngle;
int motorGradStartAngle = lastKnownAngle;

void setup() {
  headMotor.attach(headMotorPin);
  sensorMotor.attach(sensorMotorPin);
  pinMode(pirSensor, INPUT);
  pinMode(lazer, OUTPUT);
  Serial.begin(9600);
  // Sets head to middle and looking forward
  headMotor.write(lastKnownAngle);  
  // Aligns sensor to the middle position
  sensorMotor.write(lastKnownAngle);  
}

void loop() {
  int sensorValue = digitalRead(pirSensor);

  if (sensorValue == 1) {
    tracking = true;
  }

  if (tracking) {
    // Reset closest distance for each scan
    closestDistance = 200; 
    // Slow and steady scanning
    for (int i = 60; i <= 170; i += 5) {  
      // Move sensor to scan the area
      sensorMotor.write(i);  
      // Short delay for smoother readings
      delay(50);  
      int distance = sonar.ping_cm();
      Serial.println(distance);
      
      if (distance > 10 && distance < closestDistance) {
        closestDistance = distance;
        smoothAngle = i;
      }
    }

    // If a valid object is detected, move head smoothly to that angle
    if (closestDistance < 200) {
      if (lastKnownAngle < smoothAngle) {
        for (int j = lastKnownAngle; j <= smoothAngle; j++) {
          headMotor.write(j);
          delay(15);
        }
      } else {
        for (int j = lastKnownAngle; j >= smoothAngle; j--) {
          headMotor.write(j);
          delay(15);
        }
      }

      lastKnownAngle = smoothAngle;
    } else {
      // If no valid object is detected, keep the head in its last known position
      headMotor.write(lastKnownAngle);
    }

    delay(50);
  }
}
