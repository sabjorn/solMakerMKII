/*
solMakerMKII
Copyright September 2014, Steven A. Bjornson

Based on code by Chris Vecchio, 2010 (http://www.noisemantra.com/Physical%20Computing/arduino-MaxMSP%20communications%2011.pdf).

Distributed under the terms of the GNU General Public License.

This file is part of SolMakerMKII, an open source solenoid control system.

SolMakerMII is free software (and hardware): you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

SolMakerMKII is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with SolMakerMKII.  If not, see <http://www.gnu.org/licenses/>.
distributed under the terms of the GNU General Public License.

This code will allow user to send data to Arduino over USB to active 12 of the digital output pins. 
When connected to the solMakerMKII board, these 12 outputs will control the flow of an external power supply in order to turn ON and OFF solenoids.
*/

// used to set the OFF state of arduino pin output register
uint8_t out_mask[8] = 
{
	B00000001,
	B00000010,
	B00000100,
	B00001000,
	B00010000,
	B00100000,
	B01000000,
	B10000000
};
// used to set the OFF state of arduino pin output register
uint8_t out_mask_clear[8] = 
{
	B11111110,
	B11111101,
	B11111011,
	B11110111,
	B11101111,
	B11011111,
	B10111111,
	B01111111
};

unsigned long current; // location to store current time (ms)

uint8_t check_serial = 0; // serialEvent() function (runs when serial message exists) and turns this flag HIGH if new message.

char buffer[40]; // used to store Serial data.
uint8_t index = 0; // used by Serial.read to keep track of buffer[] location.

// a data structure to keep track of information for each output.
struct sol
{
  uint8_t ascii; // stores channel code for output (range is 'a' through 'l')
  uint16_t velocity; // amount of time output is held HIGH (ms)
  long oldtime; // used to keep track of when the output was turned on.
};

// array of sol struct objects, one for each output.
struct sol solenoids[12];

void setup() {
	Serial.begin(115200);

	for(int n = 0; n < 12; n++) // fills struct arrays.
  	{
    	solenoids[n].ascii = n+97;
    	solenoids[n].velocity, solenoids[n].oldtime = 0;
  	}

  	// set GPIO resgisters to output
    DDRD = B11111111;
    DDRB = B11111111;

}

void loop() {
	uint8_t tempB, tempD = B00000000; // place to store temp register values

	for(int i = 0; i < 12; i++)
	{
		current = millis();
		if(long(solenoids[i].velocity) > (current - solenoids[i].oldtime)) //turn output on if the amount of time that is is supposed to be on has not completed
		{
			// 'port manipulation' is used instead of digitalWrite() because it is 50 - 100 times faster.
			if(i < 6)
			{
				tempD = tempD | out_mask[i+2];
			}
			else
			{
				tempB = tempB | out_mask[(i+2)%8];
			}
		}
		else // turn outputs off if enough time has elapsed (velocity vs. current time - time when outputs recieved ON message)
		{
			if(i < 6)
			{
				tempD = tempD & out_mask_clear[i+2];
			}
			else
			{
				tempB = tempB & out_mask_clear[(i+2)%8];
			}			
			solenoids[i].velocity = 0;
		}
	}

	// change state of GPIOs
	PORTB = tempB;
	PORTD = tempD;

	// if check_serial flag is high, get data from Serial.
	if(check_serial)
	{
		current = millis();

		index = 0;
		do
		{
			buffer[index] = Serial.read();  // get a byte from the serial port
			if (buffer[index]!=-1)
			{
				index = index+1;    // -1 if no byte is present
			}
			else if (buffer[index-1] == solenoids[0].ascii) // checks for ASCII code 'a'
			{
			  	solenoids[0].velocity = check_length(atoi(buffer)); // if 'a' convert input to int
			  	solenoids[0].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[1].ascii) // checks for ASCII code 'b'
			{
			  	solenoids[1].velocity = check_length(atoi(buffer)); // if 'b' convert input to int
			  	solenoids[1].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[2].ascii) // checks for ASCII code 'c'
			{
			  	solenoids[2].velocity = check_length(atoi(buffer)); // if 'c' convert input to int
			  	solenoids[2].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[3].ascii) // checks for ASCII code 'd'
			{
			  	solenoids[3].velocity = check_length(atoi(buffer)); // if 'd' convert input to int
			  	solenoids[3].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[4].ascii) // checks for ASCII code 'e'
			{
			  	solenoids[4].velocity = check_length(atoi(buffer)); // if 'e' convert input to int
			  	solenoids[4].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[5].ascii) // checks for ASCII code 'f'
			{
			  	solenoids[5].velocity = check_length(atoi(buffer)); // if 'f' convert input to int
			  	solenoids[5].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[6].ascii) // checks for ASCII code 'g'
			{
			  	solenoids[6].velocity = check_length(atoi(buffer)); // if 'g' convert input to int
			  	solenoids[6].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[7].ascii) // checks for ASCII code 'h'
			{
			  	solenoids[7].velocity = check_length(atoi(buffer)); // if 'h' convert input to int
			  	solenoids[7].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[8].ascii) // checks for ASCII code 'i'
			{
			  	solenoids[8].velocity = check_length(atoi(buffer)); // if 'i' convert input to int
			  	solenoids[8].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[9].ascii) // checks for ASCII code 'j'
			{
			  	solenoids[9].velocity = check_length(atoi(buffer)); // if 'j' convert input to int
			  	solenoids[9].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[10].ascii) // checks for ASCII code 'k'
			{
			  	solenoids[10].velocity = check_length(atoi(buffer)); // if 'k' convert input to int
			  	solenoids[10].oldtime = current;
			}
			else if (buffer[index-1] == solenoids[11].ascii) // checks for ASCII code 'l'
			{
			  	solenoids[11].velocity = check_length(atoi(buffer)); // if 'l' convert input to int
			  	solenoids[11].oldtime = current;
			}
		} while (buffer[index-1] != 13);
		check_serial = 0;
	}

}

void serialEvent()
{
	// Set check_serial flag high if Serial message recieved
	check_serial = 1;
}

// makes sure 'velocity' does not go past 30,000ms (prevent solenoid burnout)
uint16_t check_length(int input)
{
	if(input < 30000)
	{
		return input;
	}
	else
		return 30000;
}