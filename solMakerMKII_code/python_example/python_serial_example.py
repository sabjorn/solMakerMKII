# solMakerMKII::python_serial_example.py
# Copyright September 2014, Steven A. Bjornson

# Based on code by Chris Vecchio, 2010 (http://www.noisemantra.com/Physical%20Computing/arduino-MaxMSP%20communications%2011.pdf).

# Distributed under the terms of the GNU General Public License.

# This file is part of SolMakerMKII, an open source solenoid control system.

# SolMakerMII is free software (and hardware): you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

# SolMakerMKII is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

# See the GNU General Public License for more details.

# You should have received a copy of the GNU General Public License along with SolMakerMKII.  If not, see <http://www.gnu.org/licenses/>.
# distributed under the terms of the GNU General Public License.

# This code works with solMakerMKII.ino (for Arduino) as an example of how to active 12 the digital outputs of the Arduino.
# When connected to the solMakerMKII board, these 12 outputs will control the flow of an external power supply in order to turn ON and OFF solenoids.

from serial import Serial
import time
import sys

velocity = 60 #Length of time solenoids are turned on for (ms).
t = 500 #time between note hits (ms).
cycles = 4 #Number of times code will loop
#port = '/dev/tty.usbmodemfa131'
baud = 115200

port = raw_input("Enter Port Location (e.g. /dev/tty.usbmodemfa131):")

arduino = Serial(port, baud)

for steps in range(cycles):
	for hits in range(12):
		sent = arduino.write(str(velocity)+chr(hits+97)+'\r') # message follows order Velocity (as string) + Output (range from 97 to 108) + Carriage Return
		time.sleep(t/1000.) # Sleep until next hit
