/*
solMakerMKII
Copyright 2013, Steven A. Bj�rnson

based on code by Chris Vecchio, 2010 (http://www.noisemantra.com/Physical%20Computing/arduino-MaxMSP%20communications%2011.pdf).

distributed under the terms of the GNU General Public License.

This file is part of SolMakerMKII.

SolMakerMII is free software (and hardware): you can redistribute i t and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

SolMakerMKII is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with SolMakerMKII.  If not, see <http://www.gnu.org/licenses/>.
distributed under the terms of the GNU General Public License.

This code will allow user to send data from Max/MSP to Arduino over USB (coupled with sol-MakerIIMidiControl.maxpat).
*/

char buffer[40]; // stores data from serial.
int index = 0;

// channels represent HIGH/LOW state of each output
int channelA, channelB, channelC, channelD, channelE, channelF, channelG, channelH, channelI, channelJ, channelK, channelL;

void setup()   
{                
  Serial.begin(115200);
  for(int n = 2; n <  14; n++) //sets pins 2 to 13 to output mode
  {
    pinMode(n, OUTPUT);
  }
}

void loop()                     
{
  index = 0;
  do
  {
    buffer[index] = Serial.read();  // get a byte from the serial port
    if (buffer[index]!=-1)
    {
    index = index+1;    // -1 if no byte is present
    }
    else if (buffer[index-1] == 97) // checks for ASCII code 'a'
    {
      channelA = atoi(buffer); // if 'a' convert input to int
    }
    else if (buffer[index-1] == 98)
    {
      channelB = atoi(buffer);
    }
    else if (buffer[index-1] == 99)
    {
      channelC = atoi(buffer);
    }
    else if (buffer[index-1] == 100)
    {
      channelD = atoi(buffer);
    }
    else if (buffer[index-1] == 101)
    {
      channelE = atoi(buffer);
    }
    else if (buffer[index-1] == 102)
    {
      channelF = atoi(buffer);
    }
    else if (buffer[index-1] == 103)
    {
      channelG = atoi(buffer);
    }
    else if (buffer[index-1] == 104)
    {
      channelH = atoi(buffer);
    }
    else if (buffer[index-1] == 105)
    {
      channelI = atoi(buffer);
    }
    else if (buffer[index-1] == 106)
    {
      channelJ = atoi(buffer);
    }
    else if (buffer[index-1] == 107)
    {
      channelK = atoi(buffer);
    }
    else if (buffer[index-1] == 108)
    {
      channelL = atoi(buffer);
    }
    
  } while (buffer[index-1] != 32);
    
    // Solenoids turned on/off
    digitalWrite(2, channelA); 
    digitalWrite(3, channelB);
    digitalWrite(4, channelC);
    digitalWrite(5, channelD);
    digitalWrite(6, channelE);
    digitalWrite(7, channelF);
    digitalWrite(8, channelG);
    digitalWrite(9, channelH);
    digitalWrite(10, channelI);
    digitalWrite(11, channelJ);
    digitalWrite(12, channelK);
    digitalWrite(13, channelL);
}

