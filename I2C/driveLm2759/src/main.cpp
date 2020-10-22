#include <Arduino.h>
/*
I2C Scanner for Arfuino 
*/

// Include Arduino Wire library for I2C
#include <Wire.h>

#define ADRRES_WRITE 0x53
#define General_Purpose_Register 0x10
#define Flash_Current_Register 0xB0
#define Torch_Current_Register 0xA0
#define Flash_Timeout_Duration_Register 0xC0

void setup()
{

  // Initialize I2C communications as Master
  Wire.begin();
  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
}

void loop()
{
  byte error;

  Serial.println("Scanning...");
  // The i2c_scanner uses the return value of
  // the Write.endTransmisstion to see if
  // a device did acknowledge to the address.
  Wire.beginTransmission(ADRRES_WRITE);
  Wire.write(General_Purpose_Register);
  Wire.write(0b0001);
  error = Wire.endTransmission();

  Wire.beginTransmission(ADRRES_WRITE);
  Wire.write(Torch_Current_Register);
  Wire.write(0x05);
  error = Wire.endTransmission();

  delay(2000);
  Wire.beginTransmission(ADRRES_WRITE);
  Wire.write(General_Purpose_Register);
  Wire.write(0b0000);
  error = Wire.endTransmission();

  if (error == 0)
  {
    Serial.println("Success");
  }
  else
  {
    Serial.println("Error");
  }
  delay(2000); // wait 5 seconds for next scan
}