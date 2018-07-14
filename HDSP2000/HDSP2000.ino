/*
  Display HDSP2000
  Destroyed one when connected upside down!
  managed to make light from one at 2010.04.24
  MODDED TO ATTINY84 BY TINLΞTHΛX.
 */
 
void shiftlong(long); 
// The setup() method runs once, when the sketch starts
void setup()   {                

  pinMode(0, OUTPUT); // Col 1
  pinMode(1, OUTPUT); // Col 2
  pinMode(2, OUTPUT); // Col 3
  pinMode(3, OUTPUT);  // Col 4
  pinMode(7, OUTPUT); // Col 5
  
  pinMode(10, OUTPUT);  // DataIn Display
  pinMode(9, OUTPUT);  // Clock
  pinMode(8, OUTPUT);  // VB
        
}

// the loop() method runs over and over again,
// as long as the Arduino has power
//long lovetxt[]={0xfcf307e0L,0x0508c520L,0x05083520L,0x0508c420L,0x04f30420L};
//long txt0123[]={0x7c010c20L,0x82861c10L,0x83fe2d10L,0x82064e90L,0x7c018c60L};
long txt[]={0x385039c0L,0x44886350L,0x448af5e0L,0x2871a8c0L,0x1000e070L};

void loop()                     
{
  while(1){
    for (int i=12;i>7;i--){
      switch(i) {
       case 12:
          digitalWrite(5,LOW);   // Blank
          shiftlong(txt[0]);
          digitalWrite(8,LOW);  // off previous
          digitalWrite(i,HIGH);  // on current
          digitalWrite(5,HIGH);  // stop blank
          break;
       case 11:
          digitalWrite(5,LOW);   // Blank
          shiftlong(txt[1]);
          digitalWrite(i+1,LOW);  // off previous
          digitalWrite(i,HIGH);  // on current
          digitalWrite(5,HIGH);  // stop blank
          break;
       case 10:
          digitalWrite(5,LOW);   // Blank
          shiftlong(txt[2]);
          digitalWrite(i+1,LOW);  // off previous
          digitalWrite(i,HIGH);  // on current
          digitalWrite(5,HIGH);  // stop blank
          break;
       case 9:
          digitalWrite(5,LOW);   // Blank
          shiftlong(txt[3]);
          digitalWrite(i+1,LOW);  // off previous
          digitalWrite(i,HIGH);  // on current
          digitalWrite(5,HIGH);  // stop blank
          break;
       case 8:
          digitalWrite(5,LOW);   // Blank
          shiftlong(txt[4]);
          digitalWrite(i+1,LOW);  // off previous
          digitalWrite(i,HIGH);  // on current
          digitalWrite(5,HIGH);  // stop blank
          break;
      }
      delay(2);
    }
  }
}

void shiftlong(long val) {
{
	digitalWrite(6, LOW);
	for (int i = 0; i < 32; i++)  {
		digitalWrite(7, !!(val & (1L << i)));
		digitalWrite(6, HIGH);
		digitalWrite(6, LOW);		
	}
}
}
