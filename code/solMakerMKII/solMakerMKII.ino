char buffer[40]; // stores data from serial.
int index = 0;

// channels represent HIGH/LOW state of each output
int channelA, channelB, channelC, channelD, channelE, channelF, channelG, channelH, channelI, channelJ, channelK, channelL;

int highLowDeterm(int x) // converts int into HIGH or LOW for digitalWrite
{
  int returnValue;
  
  if(x > 0)
  {
    returnValue = 0x1;
  }
  else
  {
    returnValue = 0x0;
  } 
  
  return returnValue;
}

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
      channelA = highLowDeterm(atoi(buffer)); // if 'a' convert input to int and convert to HIGH/LOW
    }
    else if (buffer[index-1] == 98)
    {
      channelB = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 99)
    {
      channelC = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 100)
    {
      channelD = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 101)
    {
      channelE = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 102)
    {
      channelF = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 103)
    {
      channelG = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 104)
    {
      channelH = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 105)
    {
      channelI = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 106)
    {
      channelJ = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 107)
    {
      channelK = highLowDeterm(atoi(buffer));
    }
    else if (buffer[index-1] == 108)
    {
      channelL = highLowDeterm(atoi(buffer));
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

