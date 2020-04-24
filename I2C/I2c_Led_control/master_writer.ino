// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.
#define SLAVEADDRESS 8


byte value=0;
int temp=0;
#include <Wire.h>

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  temp=analogRead(A0);
  value=map(temp,0,1023,1,255);
  Wire.beginTransmission(SLAVEADDRESS); // transmit to device #8
  Wire.write(value);              // sends one byte
  Wire.endTransmission();    // stop transmitting

  delay(50);
}
