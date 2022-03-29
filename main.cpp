#include <Servo.h>
Servo lmotor;
Servo rmotor;

int ch1;
int ch2;

void setup()
{
       lmotor.attach(9);
       rmotor.attach(10);

       pinMode(6, INPUT);
       pinMode(5, INPUT);
}

void loop()
{

       ch1 = pulseIn(6, HIGH);
       ch2 = pulseIn(5, HIGH);

       // Going backwards
       if (ch1 >= 1500)
       {
              // turning right
              if (ch2 >= 1500)
              {
                     lmotor.write(80);
                     rmotor.write(65);
              }
              else if (ch2 <= 1450)
              {
                     lmotor.write(65);
                     rmotor.write(80);
              }
              // Straight backward
              else
              {
                     lmotor.write(60);
                     rmotor.write(60);
              }
       }

       // Straight backward
       else if (ch1 <= 1450)
       {
              if (ch2 >= 1500)
              {
                     lmotor.write(100);
                     rmotor.write(115);
              }
              else if (ch2 <= 1450)
              {
                     lmotor.write(115);
                     rmotor.write(100);
              }
              else
              {
                     lmotor.write(120);
                     rmotor.write(120);
              }
       }
       else
       {
              lmotor.write(90);
              rmotor.write(90);
       }
}