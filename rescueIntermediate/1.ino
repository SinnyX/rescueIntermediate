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
      tr(50);
    }
    else if (analog(2) <= refR)
    {
      tl(50);
    }
    else if (analog(1) > refM)
    {
      fd2(powerL, powerR);
    }
  }
  ao();
  delay(200);
  bk(50);
  delay(200);
  ao();
  delay(200);
}

void runInTimer(int powerL, int powerR, unsigned long period)
{
  timer0_millis = 0;
  while (true)
  {
    if (analog(1) <= refM)
    {
      ao();
      break;
    }
    else if (analog(0) <= refL)
    {
      tr(50);
    }
    else if (analog(2) <= refR)
    {
      tl(50);
    }
    else if (analog(1) > refM)
    {
      fd2(powerL, powerR);
    }
    if (timer_robot(period))
    {
      break;
    }
  }
  bk2(powerL, powerR);
  delay(200);
  ao();
  delay(200);
}

void forwardTrack(int ms)
{
  while (true)
  {
    fd2(10, 10);
    if (analog(0) <= refL || analog(2) <= refR)
    {
      break;
    }
  }
  if (analog(0) < refL)
  {
    while (analog(2) > refR)
    {
      tl(20);
    }
  }
  else if (analog(2) < refR)
  {
    while (analog(0) > refL)
    {
      tr(20);
    }
  }
  ao();
  delay(200);
  bk(50);
  delay(ms);
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
      motor(1, 0);
      motor(2, -20);
    }
  }
  else if (analog(4) < refBR)
  {
    while (analog(3) > refBL)
    {
      motor(1, -20);
      motor(2, 0);
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
  delay(300);
}

bool timer_robot(unsigned long period)
{
  if (millis() - last_time > period)
  {
    last_time = 0;
    timer0_millis = 0;
    return true;
  }
  return false;
}
