#include <Arduino.h>
#include <SoftSerial.h>
#include <DHT.h>

#define DHT_TYPE    DHT21   // AM2301
#define DHT_PIN     PCINT1


SoftSerial MyDbgSerial(PCINT3, PCINT4); //true allows to connect to a regular RS232 without RS232 line driver
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    // write your initialization code here
    MyDbgSerial.begin(9600);
    MyDbgSerial.println("setup is called");
    dht.begin();
}

void loop() {

    MyDbgSerial.println("loop is called");
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    // check if returns are valid, if they are NaN (not a number) then something went wrong!
    if (isnan(t) || isnan(h))
    {
        MyDbgSerial.println("Failed to read from DHT");
    }
    else
    {
        MyDbgSerial.print("Humidity: ");
        MyDbgSerial.print(h);
        MyDbgSerial.print(" %\t");
        MyDbgSerial.print("Temperature: ");
        MyDbgSerial.print(t);
        MyDbgSerial.println(" *C");
        delay(2000);
    }
}