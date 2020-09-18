#include <IRremote.h>

IRsend irsend;

void setup()
{ 
	Serial.begin(9600);
}

void loop() {

    while (Serial.available() > 0) 
    {

	int signal = Serial.parseInt();
	irsend.sendRC5(000, 12);
   	
	delay(20);
   
	int a = signal/10;
   	int b = signal%10;
   
	for( int i = 0; i < a; i++)
	{
            irsend.sendRC5(010, 12);
            delay(20);
        }
	    
        for( int i=0; i< b; i++)
	{
	    irsend.sendRC5(001, 12);
            delay(20);
        }
    } 
}

