/*
 Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.

 The circuit:
 * RX input is  pin 8   - goes to TX of connected device)
 * TX output is  pin 9  - goes to RX of connected device)
 * RTS output is pin 11 - goes to CTS of connected device)
 * CTS input is pin 12  - goes to RTS of connected device

  Not all pins on the Leonardo and Micro support change interrupts,
  so only the following can be used for RX: 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
*/

#include "FlowControlSoftSerial.h"

FlowControlSoftSerial softSerial;
uint8_t ledPin = 13;

void setup() {

  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,LOW);
  
  
  // open software serial communications port
  softSerial.begin(9600);     // although tested at 19200 bps, 9600 bps seems to work best
  Serial.begin(9600);
  delay(1000);
}

void loop() { // run over and over
   softSerial.println("Hello, software serial communications port!");
   Serial.println("Hello, software serial communications port!");     
   delay(10);

}

