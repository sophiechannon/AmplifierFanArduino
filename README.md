# Amp Fan

Arduino thermostat software designed to work with hardware to control the temperature of an amplifier, or anything you like really, the temperature threshold values can easily be modified in the code.

To be connected to a computer fan and works with 3 LEDs: red, amber, green. 

_currently set up to work with a pot for testing purposes until I have a suitable fan_

This is my first Arduino project and I've guessed a lot of the syntax based on Java, so it might be quite inelegant. Mockup with thermometer stub in  Kotlin [here](https://github.com/sophiechannon/AmpFanPrototype)

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
- Override button (set fan to max / set back to automatic)