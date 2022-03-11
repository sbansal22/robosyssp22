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
       pinMode(7, INPUT);
}

void loop()
{

       ch1 = pulseIn(6, HIGH);
       ch2 = pulseIn(7, HIGH);

       if (ch1 >= 1500)
       {
              if (ch2 >= 1500)
              {
                     lmotor.write(120);
                     rmotor.write(60);
              }
              else if (ch2 <= 1450)
              {
                     lmotor.write(60);
                     rmotor.write(120);
              }
              else
              {
                     lmotor.write(60);
                     rmotor.write(60);
              }
       }
       else if (ch1 <= 1450)
       {
              if (ch2 >= 1500)
              {
                     lmotor.write(120);
                     rmotor.write(60);
              }
              else if (ch2 <= 1450)
              {
                     lmotor.write(60);
                     rmotor.write(120);
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
