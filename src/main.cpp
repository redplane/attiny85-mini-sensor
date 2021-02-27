#include <Arduino.h>
#include <SoftSerial.h>

SoftSerial MyDbgSerial(2, 3); //true allows to connect to a regular RS232 without RS232 line driver


void setup() {
    // write your initialization code here
    MyDbgSerial.begin(9600);
}

void loop() {
    // write your code here


    MyDbgSerial.println("Hello world");
    delay(2000);
}