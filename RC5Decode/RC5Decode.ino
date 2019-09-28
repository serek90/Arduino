/*
 *  Wiring notes:
 *  
 *  Using IR sensor like this:
 *    http://www.adafruit.com/products/157
 *  wired as follows:
 *   pin1 - arduino pin 7 
 *   pin2 - ground
 *   pin3 - 5V
 *  
 *  This code will display address, command and toggle for decoded sequences.
 *  Pressing the power button twice gives this result:
 *     a:0 c:12 t:0  <- first press, a:0 => TV1, c:12 => Standby command.
 *     a:0 c:12 t:0
 *     a:0 c:12 t:0
 *     a:0 c:12 t:1  <- second press, toggle changes
 *     a:0 c:12 t:1
 *
 */
 
#include <RC5.h>

const int IR_PIN = 7;
unsigned long t0;
RC5 rc5(IR_PIN);
const int analogOutPin = 9;
int outputValue = 1;
void setup() {                
  Serial.begin(9600);
  Serial.println("Starting");
}

void loop() {
  unsigned char toggle;
  unsigned char address;
  unsigned char command;
  if (rc5.read(&toggle, &address, &command))
  {
    Serial.print("a:");
    Serial.print(address);
    Serial.print(" c:");
    Serial.print(command);
    Serial.print(" t:");
    Serial.println(toggle);
    Serial.println(outputValue);

   
    if( command == 0)outputValue = 0;
    if( command == 1 & outputValue < 255)outputValue = outputValue ++;
    if( command == 10 & outputValue > 0)outputValue = outputValue +10 ;

delay(10);
  }

analogWrite(analogOutPin, outputValue);
  
}
