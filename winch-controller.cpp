#include <Servo.h>
Servo lmotor;
Servo rmotor;

int ch1;

void setup()
{
      Serial.begin(9600);
      
      // Servo signal pin 10
       rmotor.attach(10);

      // RC input pin - connected to the RadioLink LHSWB toggle input
       pinMode(6, INPUT);
}

void loop()
{

       ch1 = pulseIn(6, HIGH);
       
      if (ch1 <= 1000)
      {
        Serial.println("driving forward");
        rmotor.write(140);
        
      }
      
      else if (ch1 >= 1900)
      {
        Serial.println("driving backward");
        rmotor.write(60);
      }
      
      else
      {
        Serial.println("Stop");
        rmotor.write(95);
      }
        
}
