# ThunderCloud-LEDstrip
Arduino based thunder - lightning
Basically it's a hanging cloud of Hollowfibre Polyester with embedded LED strip, driven by software running on an Arduino. The Youtube video below shows what it does.
https://youtu.be/gqbZ1yOpaiM

The Aurduino connects to a DFRobotDFPlayerMini which hols mps sound files in its /mp3 directory.
Connections as per several examples already on the web but here are a few pointers.
1. Using the DFR Speaker output can produce a motorboat type noise, using the DAC outputs gets over this, 
and if there is still any digitisation noise it can easily be filtered out with an RC filter.
2. The DFR unit can pick up deleted files and can produce noise before producing its output 
so best do a deep format on the SD card before loading the mp3 files.
3. The software limits the number of LEDS to about 40 so as not to produce power line glitches 
as I've used the Arduino's 5v for the strip. For more LEDS best use a separate PSU for the  LEDstrip.
4. 
