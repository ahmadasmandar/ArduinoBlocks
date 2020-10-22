#include <Arduino.h>

#define RED 7
#define GREEN 6
#define BLUE 5

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void loop()
{
  digitalWrite(RED, HIGH);
  delay(2000);
  digitalWrite(RED, LOW);
  delay(2000);

  digitalWrite(GREEN, HIGH);
  delay(2000);
  digitalWrite(GREEN, LOW);
  delay(2000);

  digitalWrite(BLUE, HIGH);
  delay(2000);
  digitalWrite(BLUE, LOW);
  delay(2000);
}