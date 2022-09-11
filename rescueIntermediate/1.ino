/*
   analog(0) = Left
   analog(1) = Middle
   analog(2) = Right
   analog(3) = BackLeft
   analog(4) = BackRight

   motor(1) = Left
   motor(2) = Right
*/
void runInTrack(int powerL, int powerR)
{
  while (true)
  {
    if (analog(1) <= refM)
    {
      ao();
      break;
    }
    else if (analog(0) <= refL)
    {
      tr(20);
    }
    else if (analog(2) <= refR)
    {
      tl(20);
    }
    else if (analog(1) > refM)
    {
      fd2(powerL, powerR);
    }
  }
  ao();
  delay(100);
  bk(30);
  delay(250);
  ao();
  delay(100);
}

void turn(char t, int ms)
{
  if (t == 'L')
    sl(50);
  else
    sr(50);
  delay(ms);
  ao();
  delay(30);
}

void backwardTrack(int powerL, int powerR)
{
  while (true)
  {
    bk2(powerL, powerR);
    if (analog(3) <= refBL || analog(4) <= refBR)
    {
      break;
    }
  }
  if (analog(3) < refBL)
  {
    while (analog(4) > refBR)
    {
      tl(20);
    }
  }
  else if (analog(4) < refBR)
  {
    while (analog(3) > refBL)
    {
      tr(20);
    }
  }
  delay(30);
  ao();
  delay(200);
  fd2(powerL, powerR);
  delay(200);
  ao();
}

void moveBlock(char d, int powerL, int powerR, int ms)
{
  if (d == 'F')
    fd2(powerL, powerR);
  else
    bk2(powerL, powerR);
  delay(ms);
  ao();
  delay(30);
}
