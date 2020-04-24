// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.
#define SLAVEADDRESS 8

#define ANSWERSIZE 5

byte rd=0;
int br=0;
#include <Wire.h>

void setup() {
  Wire.begin(SLAVEADDRESS); // join i2c bus (address optional for master)
  Wire.onReceive(changeValue);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  
  
}

void changeValue(){
  
    rd=Wire.read();
    Serial.println(rd);

  
}

void loop() {
  br=map(rd,1,255,10,1000);
  digitalWrite(9, OUTPUT);
  delay(br);
  digitalWrite(9, LOW);
  delay(br);
}
