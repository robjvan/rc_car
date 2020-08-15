/*
  RC Car Arduino code
  Handles operations of RC toy vehicle

  created 15 Aug 2020
  by Rob Vandelinder
  rob@eastcoastdev.ca
*/

#include <Servo.h>

// input pins
const int brakeButtonPin = 4;
const int headlightButtonPin = 3;
const int hornButtonPin = 2;
const int joy1x = A0;
const int joy2y = A3;

// output pins
const int servoPin = 7;
const int motorPWM = 5;
const int motorPin1 = 12;
const int motorPin2 = 13;
const int brakeLedPin = 6;
const int headlightLedPin = 8;
const int hornPin = 11;

// globals
int initialPosition = 90;
int headlightState = 0;
int joy1x_pos, joy2y_pos;
int angle, throttleVal, newServoPosition;

Servo steeringServo;

void setup()
{
  //  Serial.begin(9600);
  steeringServo.attach(servoPin);

  // set steeringServo position to center
  steeringServo.write(initialPosition);

  // initialize pins
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

void loop()
{
  joy1x_pos = analogRead(joy1x); // controls drive motor
  joy2y_pos = analogRead(joy2y); // controls steering servo

  //  printJoystickPos(joy1x_pos, joy2y_pos);

  checkHornButton();
  checkHeadlightButton();

  // check drive joystick and move forward or backwards
  if (joy1x_pos > 530)
  {
    driveForward(joy1x_pos);
  }
  else if (joy1x_pos < 500)
  {
    driveBackwards(joy1x_pos);
  }
  else
  {
    stopCar();
  }

  // check steering joystick and turn wheels left or right
  if (joy2y_pos > 550)
  {
    steerLeft(joy2y_pos);
  }
  else if (joy2y_pos < 450)
  {
    steerRight(joy2y_pos);
  }
  else
  {
    // return to center
    steeringServo.write(90);
  }
}

void printJoystickPos(int joy1x, int joy2y)
{
  // print joystick coords for diagnostics
  Serial.print("joy1x_pos: ");
  Serial.print(joy1x);
  Serial.print("\njoy2y_pos: ");
  Serial.print(joy2y);
  Serial.print("\n\n");
}

void steerLeft(int joy_pos)
{
  // map joyPos to within 20 degree range
  newServoPosition = map(joy_pos, 550, 1023, 90, 110);
  // write new position to servo
  steeringServo.write(newServoPosition);
}

void steerRight(int joy_pos)
{
  newServoPosition = map(joy_pos, 450, 0, 90, 70);
  steeringServo.write(newServoPosition);
}

void driveForward(int throttlePosition)
{
  // turn off brake LEDs and control motor speed with throttle position
  digitalWrite(brakeLedPin, LOW);
  throttleVal = map(throttlePosition, 530, 1023, 0, 255);
  analogWrite(motorPWM, throttleVal);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
}

void driveBackwards(int throttlePosition)
{
  // turn off brake LEDs and control motor speed with throttle position
  digitalWrite(brakeLedPin, LOW);
  throttleVal = map(throttlePosition, 500, 0, 0, 255);
  analogWrite(motorPWM, throttleVal);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
}

void stopCar()
{
  // turn on brake LEDs and stop the motor
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(brakeLedPin, HIGH);
}

void checkHornButton()
{
  int buttonState = digitalRead(hornButtonPin);
  if (buttonState == LOW)
  {
    tone(hornPin, 250); // change this frequency to alter horn sound, add third parameter for duration
  }
  else
  {
    noTone(hornPin);
  }
}

void checkHeadlightButton()
{
  int buttonState = digitalRead(headlightButtonPin);
  // use debouncing to avoid flickering
  unsigned long lastDebounceTime = 0;
  unsigned long debounceDelay = 250;

  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (buttonState == LOW && headlightState == LOW)
    {
      // if button is pressed and headlights are off, turn 'em on!
      digitalWrite(headlightLedPin, HIGH);
      headlightState = HIGH;
      lastDebounceTime = millis();
    }
    else if (buttonState == LOW && headlightState == HIGH)
    {
      // if button is pressed and headlights are on, turn 'em off
      digitalWrite(headlightLedPin, LOW);
      headlightState = LOW;
      lastDebounceTime = millis();
    }
    //    else if (buttonState == HIGH && headlightState == HIGH)
    //    {
    //      // if button is NOT pressed and headlights are on, leave 'em on
    //      digitalWrite(headlightLedPin, HIGH);
    //      lastDebounceTime = millis();
    //    }
  }
}

void checkHeadlightState()
{
  if (headlightState == HIGH)
  {
    digitalWrite(headlightLedPin, HIGH);
  }
  else
  {
    digitalWrite(headlightLedPin, LOW);
  }
}
