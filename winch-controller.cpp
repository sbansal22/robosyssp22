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
       
      // Driving forward
      if (ch1 <= 1000)
      {
        rmotor.write(140);
      }
      
      // Driving backward
      else if (ch1 >= 1900)
      {
        rmotor.write(60);
      }
      
      // Stop driving
      else
      {
        rmotor.write(95);
      }
        
}
