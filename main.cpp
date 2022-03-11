#include <Servo.h>
Servo motor1;
Servo motor2;

int pwm_value;

void setup()
{
       motor1.attach(9);
       motor2.attach(10);

       pinMode(6, INPUT);
}

void loop()
{

       pwm_value = pulseIn(6, HIGH);

       if (pwm_value >= 1500)
       {

              motor1.write(60);
              motor2.write(60);
       }
       else if (pwm_value <= 1450)
       {
              motor1.write(120);
              motor2.write(120);
       }

       else
       {
              motor1.write(90);
              motor2.write(90);
       }
}
