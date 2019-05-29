# NeoPixel_Arduino
This project contains the code for the Arduino Uno to drive NeoPixel RGB Strips and the desktop GUI to control it. 

## Arduino Code
The arduino is capable of playing multiple animations on an LED strip, and can accept input over Serial USB or a Bluetooth LE 
to change various parameters on the fly such as the animation, color, animation speed, and animation direction.

## Desktop GUI App
The desktop app was written in Qt to be able to easily communicate with the Arduino over serial USB. It allows you configure all
parameters that the arduino code will accept and allows you to select a COM port if multiple COM ports are opened. Only works for Windows 10.


![qt_gui](https://user-images.githubusercontent.com/49374040/58524124-32913c80-8195-11e9-9685-b5d33898cfc6.png)
