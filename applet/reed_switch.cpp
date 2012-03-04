#include "WProgram.h"
void setup();
void loop();
int ReedPin =  7;


int laststate = 0;
int curstate = 0;



// The setup() method runs once, when the sketch starts

void setup()   {            
  Serial.begin(57600);  
  pinMode(ReedPin, INPUT);   
  Serial.println("start");  
}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()                     
{
  static long unsigned int tickcount = 0;
  curstate = digitalRead(7);
  if (curstate & !laststate)
    Serial.println(tickcount++, DEC);  
  laststate = curstate;
  
}

int main(void)
{
	init();

	setup();
    
	for (;;)
		loop();
        
	return 0;
}

