
<p align="center">
    <img src="/images/arduino.png" width=200>
</p>

# Arduino RC Car 

## Description

- Arduino-powered, bluetooth-controlled toy car
- Working headlights and brake lights
- Horn with variable frequencies, can play melodies

## Software

[Ino file](https://github.com/robjvan/rc_car/blob/master/rc_car_ino/rc_car_ino.ino)  
[Android App](#)

---

## Diagrams

<p align="center">
    <img src="/images/image_placeholder.png" width=450>
</p>
<p align="center">
    <i>Fritzing Diagram - WIP</i>
</p>
<p align="center">
    <img src="/images/image_placeholder.png" width=450>
</p>
<p align="center">
    <i>Schematic - WIP</i>
</p>

## Hardware Used

- Nano 33 IoT
- L298N DC motor driver
- SG90 servo motor
- BLDC motor
- 3.7v 3000 mAh Li-Ion battery pack
- 7.4v 6000 mAh 2S2P Li-Ion battery pack
- Passive buzzer
- 4 x LEDs (2 x red, 2 x white)
- BT-enabled controller
- Android phone


---

## To-Do List

- Swap to Nano 33 IoT for onboard BT
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


---

## Versions

### v0.1 COMPLETED - "First Prototype"
<p align="center">
 <img src="/images/prototype_v1.jpg" height=414 width=450>
</p>
<p align="center">
  <i>It wasn't the prettiest</i>
</p>
 This version requires a makeshift "controller" to test the various circuits.  The controller consists of 2 x PS2 joysticks to control throttle and steering with pushbuttons to sound the horn and toggle the headlights.  The objective was to confirm feasibility and create basic code to have all parts interact properly.

### v0.2 WIP - "Cutting the cords"

 Planned for Sept/Oct 2020, waiting for parts from China.  A bluetooth receiver will enable wireless operation and plastic gears will allow the motor to turn a drive axle.  
