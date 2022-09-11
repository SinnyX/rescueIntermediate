#include <pop7HH.h>
/*
   analog(0) = Left
   analog(1) = Middle
   analog(2) = Right
   analog(3) = BackLeft
   analog(4) = BackRight

   motor(1) = Left
   motor(2) = Right
*/
int L, M, R, BL, BR;
int refL = 500, refM = 500, refR = 500, refBL = 500, refBR = 500;

void runInTrack(int powerL, int powerR);
void backwardTrack(int powerL, int powerR);
void turn(char t, int ms);
void moveBlock(char d, int powerL, int powerR, int ms);

void servoUp();
void servoKick();
void servoSet(int p);
void sensorSet(int ref);

void setup()
{
  /*
    servoUp();
    OK();
    //ออกจากจุด Start
    moveBlock('F', 50, 50, 300);
  */
  /*
    runInTrack(50, 50);
    turn('R', 300);
    backwardTrack(20, 20);
  */
}

void loop()
{
}
