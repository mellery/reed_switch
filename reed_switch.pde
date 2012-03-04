int ReedPin =  7;


int laststate = 0;
int curstate = 0;
unsigned long lasttime = 0;

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
  {
    Serial.print(tickcount++, DEC);  
    Serial.print(",");
    Serial.println(millis()-lasttime, DEC);
    lasttime = millis();
  }
  laststate = curstate;
  
}
