## Sol(enoid)MakerMarkII
### About
Included in this package is all (I hope) the necessary components to build a copy of the Sol-MakerMKII solenoid control 'robot'.

This device was designed as a shield for an Arduino Uno R3 and you will, therefore, need to get one if you don't already have it. The circuit size (and cost) could be easily reduced by scaling the whole circuit to fit an Arduino Mini (the code should be cross compatible).

The basic principle of the device is this: electrical power is input into the device. This power is gated by twelve transistors which are closed. Each transistor is an output for a device which operates with applied electrical current (solenoids, for example). These transistor gates are controlled by the 12 digital output pins from the Ardunio Uno. By sending a signal to the Arduino, via the serial bus, the Arduino is able to open any/all of these transistor gates. Thus, if you attach a solenoid (electro-mechanical piston) to a gate, and open it with the Arduino, you can send electricity to the device and cause it to move.

Solenoids are not the only device for which this circuit will work. Anything which operated using a DC power supply (which matches the input voltage from your selected power supply) can be controlled. Example: Electric motors from tape machines.

**CAUTION**: This device will operate without issue if nothing is connected to the outputs. BUT if the outputs from the transistors are crossed, THE TRANSISTORS WILL BLOW UP. Furthermore, if the power supply voltage polarity is switched (+ and ground switched) THE TRANSISTORS WILL (also) BLOW UP. It would be a good idea to attach a diode to the power supply input to prevent this from happening by mistake.

The LEDs on this device act as indicators of the Arduino pins' activity. They will operate without the external power supply connected. They are helpful for troubleshooting connection problems and have the added benefit of looking very cool.
 
Included in this package:
	
	* Fritzing and Gerber file for PCB ('solMakerMKII_circuit' directory).

	* Code for the Arduino and a Max/MSP patch to allow direct use of MIDI 
	devices ('solMakerMKII_code' directory).

	* Diagrams ('solMakerMKII_diagrams' directory).
	
	* More elaborate documentation (.pdf file and the latex files needed to
	edit it; 'solMakerMKII_documentation' directory).

For contribution ideas, please check the .pdf documentation. There is a list at the end of the document. 

### Development Status
This project is effectively deprecated. The code will be ported to be used as part of another project--[dreamIO](https://github.com/sabjorn/dreamio). This will allow for control of solenoids over WiFi using OSC.