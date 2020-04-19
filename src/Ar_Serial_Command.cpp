#include <Arduino.h>
#define led 13
String name;
void setup()
{
    Serial.begin(115200);
    pinMode(led, OUTPUT);
}

void loop()
{
    /* we need to put our functions or commands in this if
     TODO please note to make your command as short as possible
     avoid excute it repeatedly*/

    if (Serial.available())
    {
        delay(10);
        name = String(Serial.readString());
        // Remove the white Spaces and the new Line from the command String to make ready to compare
        name.trim();
        // Deal with the first command
        if (name == "first")
        {
            Serial.println("the first command ");

            digitalWrite(led,HIGH);
        }
        // Deal with the second command
        else if (name == "second")
        {
            Serial.println("the second command ");
            digitalWrite(led,LOW);
        }
    }
}
