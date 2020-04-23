#include <Arduino.h>
#define anInput A0
int in_value=0;
byte out_value=0;
byte duty_cycle=0;


void setup() {
  Serial.begin(9600);

  // put your setup code here, to run once:
}

void loop() {

  // put your main code here, to run repeatedly:

  /*
  the first section is automatic pwm generator to control dutycycle from 0 to 100% 
  with tow for loops 
  */
  for (int i=0; i<255;i++)
  {
    analogWrite(5,i);
    delay(10);
  }
  for (int j=255; j>=0;j--)
  {
    analogWrite(5,j);
    delay(10);
  }
/**
  the second section is manual pwm generator to control dutycycle from 0 to 100% 
  using Potentionmeter Resistor.
  The function analogRead() return digital value between 0 and 1023 so we need to 
  convert it using the map function (0 , 255)
  map(value, from low, from hight, to low, to hight)
  * ! this section will be excute after the tow for loops above execut
  **/
  in_value=analogRead(anInput);
  in_value=map(in_value,0,1023,0,255);
  duty_cycle=map(in_value,0,255,0,100);
  analogWrite(6,in_value);
  // ! here this function will control if the input value have been changed and print it
  // and to print the dutycycle also
  if (in_value!= out_value)
  {
    Serial.print("The analog input Value (maped): ");
    Serial.println(in_value);
    Serial.print("Dutycycle : ");
    Serial.print(duty_cycle);
    Serial.println("%");
    out_value=in_value;
  }
  delay(10);

}