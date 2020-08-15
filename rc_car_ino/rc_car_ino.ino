#include <Servo.h>

//input pins
const int brakeButtonPin = 4;
const int headlightButtonPin = 3;
const int hornButtonPin = 2;
const int joy1x = A0;
const int joy2y = A3;

//output pins
const int servoPin = 7;
const int motorPWM = 5;
const int motorPin1 = 12;
const int motorPin2 = 13;
const int brakeLedPin = 6;
const int headlightLedPin = 8;
const int hornPin = 11;

//globals
int initialPosition = 90;
int headlightState = 0;
int joy1x_pos, joy2y_pos;
int angle, throttleVal;

Servo steeringServo;

void setup() {  
//  Serial.begin(9600);
  steeringServo.attach(servoPin);
  steeringServo.write(initialPosition);
  
  pinMode(joy1x, INPUT);
  pinMode(joy2y, INPUT);
  pinMode(brakeButtonPin, INPUT_PULLUP);
  pinMode(hornButtonPin, INPUT_PULLUP);
  pinMode(headlightButtonPin, INPUT_PULLUP);
  pinMode(motorPWM, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(brakeLedPin, OUTPUT);
  pinMode(hornPin, OUTPUT);
  pinMode(headlightLedPin, OUTPUT);

}

void loop() {
  joy1x_pos = analogRead(joy1x); // drive motor
  joy2y_pos = analogRead(joy2y); // steering servo
//  printPos(joy1x_pos, joy2y_pos);
  checkHornButton();
  checkHeadlightButton();
  if (joy1x_pos > 550) {
    driveForward(joy1x_pos);
  } else if (joy1x_pos < 400) {
    driveBackwards(joy1x_pos);
  } else {
    stopCar();
  }
  
}

void printPos(int joy1x, int joy2y) {
  Serial.print("joy1x_pos: "); 
  Serial.print(joy1x);
  Serial.print("\njoy2y_pos: ");
  Serial.print(joy2y);
  Serial.print("\n\n");
}

void steerCar(int joy_pos) {
  int newServoPosition = joy_pos;
  newServoPosition = map(joy_pos, 0, 1023, 0, 255);
  steeringServo.write(newServoPosition);
}

void driveForward(int throttlePosition) {
  digitalWrite(brakeLedPin, LOW);
  throttleVal = map(throttlePosition, 550, 1023, 0, 255);
  analogWrite(motorPWM, throttleVal);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}

void driveBackwards(int throttlePosition) {
  digitalWrite(brakeLedPin, LOW);
  throttleVal = map(throttlePosition, 450, 0, 0, 255);
  analogWrite(motorPWM, throttleVal);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  
}

void stopCar() {
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(brakeLedPin, HIGH);
}


void checkHornButton() {
  int buttonState = digitalRead(hornButtonPin);
  if (buttonState == LOW) {
  tone(hornPin, 150);
  } else {
    noTone(hornPin);
  }
}

void checkHeadlightButton() {
  int buttonState = digitalRead(headlightButtonPin);
  unsigned long lastDebounceTime = 0;
  unsigned long debounceDelay = 250;

  if ((millis() - lastDebounceTime) > debounceDelay) {
      if (buttonState == LOW && headlightState == LOW) {  
        digitalWrite(headlightLedPin, HIGH);
        headlightState = HIGH;
        lastDebounceTime = millis();
      } else if (buttonState == LOW && headlightState == HIGH) {
        digitalWrite(headlightLedPin, LOW);
        headlightState = LOW;
        lastDebounceTime = millis();
      } else if (buttonState == HIGH && headlightState == HIGH) {
        digitalWrite(headlightLedPin, HIGH);
        lastDebounceTime = millis();
      }
  }
  
}
