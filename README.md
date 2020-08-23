
<p align="center">
    <img src="/images/arduino.png" width=200>
</p>

# Arduino RC Car 

## Status: ON HOLD (Waiting for parts)

## Description

- Arduino-powered, bluetooth-controlled toy car
- Working headlights and brake lights
- Horn with variable frequencies, can play melodies

## Current Version

### v0.1 COMPLETED - "First Prototype"
<p align="center">
 <img src="/images/prototype_v1.jpg" height=414 width=450>
</p>
<p align="center">
  <i>It wasn't the prettiest</i>
</p>
 This version requires a makeshift "controller" to test the various circuits.  The controller consists of 2 x PS2 joysticks to control throttle and steering with pushbuttons to sound the horn and toggle the headlights.  The objective was to confirm feasibility and create basic code to have all parts interact properly.

## Hardware Used

- Arduino Uno R3
- L293D DC motor driver
- SG90 servo motor
- BLDC motor
- 9v NiMh battery for Arduino
- 7.4v 6000 mAh 2S2P Li-Ion battery pack for drive motors
- Passive buzzer
- 4 x LEDs (2 x red, 2 x white)
- 4 x 220 ohm resistors
- BT-enabled controller
- Android phone

## Diagrams

<p align="center">
    <img src="/images/fritzing_prototype.png" width=1024>
</p>
<p align="center">
    <i>Prototype v1 with wired "controller"</i>
</p>
<p align="center">
    <img src="/images/fritzing_bt_nano.png" width=1024>
</p>
<p align="center">
    <i>Prototype with Nano & BT</i>
</p>

## To-Do List

- Swap to Nano 33 IoT for onboard BT
- Swap to L298N DC motor driver
- Servo-powered steering rack for front wheels
- Plastic crown gears attaching motor to rear axle
- Hide the electronics inside a plastic model car (Revell/Monogram-style kit)
- Flutter app for Android/iOS devices
- Cameras for video feed in mobile control app
- More powerful motor
- Bigger battery pack
- Custom chassis with suspension
- RC braking system
- *GPS tracking?*
- *OpenCV/Obstacle avoidance?*

<!-- ## Versions -->

