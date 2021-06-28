# ThunderCloud-LEDstrip
Arduino based thunder - lightning
Basically it's a hanging cloud of Hollowfibre Polyester with embedded LED strip, driven by software running on an Arduino Nano. 
The Youtube video below shows what it does.
https://youtu.be/gqbZ1yOpaiM

The Aurduino connects to a DFRobotDFPlayerMini which holds the mps sound files in its /mp3 directory. 
There are 7 files used in this build, chosen at ramdom.

Connections as per several examples already on the web but here are a few pointers.
1. Using the DFR Speaker output can produce a motorboat type noise, using the DAC outputs gets over this, 
and if there is still any digitisation noise it can easily be filtered out with an RC filter. 
To get maximum signal ration on the DFR output set the amplification factor to max (30)
2. The DFR unit can pick up deleted files and can produce noise before producing its output 
so best do a deep format on the SD card before loading the mp3 files.
3. The software limits the number of LEDS to about 40 so as not to produce power line glitches 
as I've used the Arduino's 5v for the strip. For more LEDS best use a separate PSU for the  LEDstrip.
4. LEd strip is secured to the back panel by drilling two small holes at various intervals along the strip,
 and either side of the strip, then inserting short lengths of U shaped stiff wire and bending the two ends
 on the rear of the panel. The strip can then easily be removed if required.
5. The cloud comprises holowfibre polyester, retained by thin cotton wrapped round the whole unit. 
(Some people use glue, but it didn't work for me.) The complete unit is then suspended from a skyhook! 
6. There's a lo/hi intensity/sound switch. Leave in lo position to plug into a laptop's USB for software 
mods and only switch to Hi when plugging into a mains powered USB socket.
