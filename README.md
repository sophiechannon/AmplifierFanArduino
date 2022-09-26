# Temperature Response Fan

I originally designed this to control the temperature of an amplifier, but it can be easily adapted for any purpose - the temperature threshold values can easily be modified in the code. I plan to use it as a desk fan in the summer months :)

To be connected to a computer fan and works with 3 LEDs: red, amber, green. 

This is my first Arduino project and I've guessed a lot of the syntax based on Java, so it might be quite inelegant. I wrote a blog with some more information about it [here](https://medium.com/@sophiechannon/my-first-hardware-project-arduino-powered-fan-with-temperature-sensor-and-led-warning-lights-713c3afe40ff). Mockup with thermometer stub in  Kotlin [here](https://github.com/sophiechannon/AmpFanPrototype).

## Hardware (for prototyping)

- breadboard
- various jumper wires
- 4 x 220ohm resistors
- 1 diode
- 1 T92222 transistor
- 3 pin computer fan
- red, yellow and green LEDs
- MAX6675 thermocouple
- Arduino (I used Uno)

## Diagram

![Wiring diagram](./Screenshot%202022-09-23%20at%2011.46.04.png)

## Features (software)

- Reads the current temperature of the amp
- Knows when to turn on/off the fan
- Knows when to turn on/off each LED

## Features (hardware)

- Built on arduino board
- Temperature sensor
- Fan that comes on based on temperature sensor readings
- Fan is on a digital output (on/off)
- Green LED to indicate that amp is below threshold
- Amber LED to indicate that fan is on
- Red LED to indicate that fan is not working well enough and the amp is overheating