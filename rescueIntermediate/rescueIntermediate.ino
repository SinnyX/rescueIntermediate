#include <pop7.h>
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
int refL = 300, refM = 300, refR = 300, refBL = 300, refBR = 300;

extern volatile unsigned long timer0_millis;
unsigned long last_time = 0;

void runInTrack(int powerL, int powerR);
void runInTimer(int powerL, int powerR, unsigned long period);
void backwardTrack(int powerL, int powerR);
void turn(char t, int ms);
void moveBlock(char d, int powerL, int powerR, int ms);

void servoUp();
void servoKick();
void servoSet(int p);
void sensorSet(int ref);

void setup()
{
  servoKick();
}

void loop()
{
  OK();
  runInTrack(35, 30);
  turn('R', 200);
  backwardTrack(25, 20);
  backwardTrack(25, 20);

  runInTrack(35, 30);
  turn('R', 200);
  backwardTrack(25, 20);
  backwardTrack(25, 20);

  runInTrack(35, 30);
  turn('R', 200);
  backwardTrack(25, 20);

  runInTrack(35, 30);
  turn('L', 200);
  backwardTrack(25, 20);
  backwardTrack(25, 20);

  runInTrack(35, 30);
  forwardTrack(100);
  servoUp();
  servoKick();
  beep();
  moveBlock('B', 35, 30, 400);
  turn('L', 200);
  backwardTrack(25, 20);
  backwardTrack(25, 20);
  //////////////////////////
  runInTrack(35, 30);
  turn('R', 250);
  runInTrack(35, 30);
  turn('R', 250);
  backwardTrack(25, 20);
  backwardTrack(25, 20);
  runInTrack(35, 30);
  forwardTrack(100);
  forwardTrack(100);
  servoUp();
  servoKick();
  beep();

  moveBlock('B', 25, 20, 600);
  turn('R', 250);
  backwardTrack(25, 20);
  backwardTrack(25, 20);

  runInTimer(35, 30, 1600);
  turn('R', 300);
  // backwardTrack(25, 20);
  // backwardTrack(25, 20);

  runInTrack(35, 30);
  forwardTrack(100);
  turn('R', 300);
  runInTrack(35, 30);

  forwardTrack(100);
  servoUp();
  servoKick();
  beep();
}
