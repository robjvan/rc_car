# RC Car Project

## Planned Features

 - Arduino-powered, bluetooth-controlled toy car
 - Working headlights and brake lights
 - Horn with variable frequencies, can play melodies

## Hardware

 - Elegoo Nano v3
 - HC-06 BT module
 - L293d motor driver
 - SG90 servo (steering)
 - BLDC motor (drive wheels)
 - 7.4v 6000 mAh 2S2P Li-Ion battery pack
 - Passive buzzer
 - 4 x LEDs (2 x red, 2 x white)
 - BT-enabled controller
 - Android phone

## Software

[Ino file](https://github.com/robjvan/rc_car/blob/master/rc_car_ino/rc_car_ino.ino)  
[Android App](#)

---

## Versions

 ### v0.1 - Prototype

 <img src="/images/image_placeholder.png" align="center" height=400 width=400>

 This version required a makeshift "controller" to test the various circuits.  The controller consisted of 2 x PS2 joysticks to control throttle and steering with pushbuttons to sound the horn and toggle the headlights.  The objective was to confirm feasibility and create basic code to have all parts interact properly.

 ### v0.2 - Cutting the cords

 Planned for Sept/Oct 2020, waiting for parts from China.  A bluetooth receiver will allow wireless operation with a simple BT controller.

 ### Future Ideas

 - Hide the electronics inside a plastic model car (Revell/Monogram-style kit)
 - Flutter app for Android/iOS devices
 - Cameras for a video feed in mobile control app
 - More powerful motor
 - Bigger battery pack
 - Custom chassis with suspension
 - RC braking system
