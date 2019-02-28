#include <kipr/botball.h>
#include "header.h"
//goal is to have both sensors on a white value
//analog(0) is the right sensor, analog(1) is the left sensor
//motor(0) is the right motor, motor(3) is the left motor
int main()
{
    //moveForward (2000);
    int blackValue= 800;	//x > black value means that the sensor is on black
    int whiteValue = 500;  // x < whiteValue means that the sensor is on white
    int speed = 50;
    while(digital(8) == 0) {
       
        //case 1: both white -- move forward
        if(analog(0) < whiteValue && analog(1) < whiteValue) {
            motor(0, speed);
            motor(3, speed);
            msleep(1);
            printf("both white");
        }

        //case 2: right sens is black, left sens is white -- turn left
        if(analog(0) > blackValue && analog(1) < whiteValue) { // turn left because left sensor is black
            motor(0, 0);
            motor(3, speed);
            msleep(1);
            printf("right black");
        }
        
        //case 3: right sens is white, left sens is black -- turn right
        if(analog(0) < whiteValue && analog(1) > blackValue)	{// turn right because right sensor is black
            motor(0, speed);
        	motor(3, 0);
        	msleep(1);
            printf("left black");
        }
        //case 4: both black -- move forward
         if(analog(0) > blackValue && analog(1) > blackValue) {
            motor(0, speed);
            motor(3, speed);
            msleep(1);
            printf("both black");
        }
        
        
    //    printf(analog(0));
      //  printf("\n");
    }

    return 0;
}
