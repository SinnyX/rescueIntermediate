void servoUp()
{
  servo(1, 60);
  delay(300);
}

void servoKick()
{
  servo(1, 95);
  delay(300);
}

void servoSet(int p)
{
  glcdClear();
  glcdMode(2);
  setTextSize(2);
  while (true) {
    int x = knob(0, 180);
    glcd(1, 2, "Servo%d", p);
    glcd(2, 2, "= %d   ", x);
    servo(p, x);
    if (sw_OK()) {
      break;
    }
  }
}

void sensorSet(int ref)
{
  glcdClear();
  glcdMode(2);
  setTextSize(2);
  while (true)
  {
    L = analog(0);
    M = analog(1);
    R = analog(2);
    BL = analog(3);
    BR = analog(4);
    if (L < ref) glcd(6, 3, "B"); else glcd(6, 3, "W");
    if (M < ref) glcd(6, 4, "B"); else glcd(6, 4, "W");
    if (R < ref) glcd(6, 5, "B"); else glcd(6, 5, "W");
    if (BL < ref) glcd(6, 6, "B"); else glcd(6, 6, "W");
    if (BR < ref) glcd(6, 7, "B"); else glcd(6, 7, "W");
    glcd(1, 2, "L = %d    ", L);
    glcd(2, 2, "M = %d    ", M);
    glcd(3, 2, "R = %d    ", R);
    glcd(4, 1, "BL = %d    ", BL);
    glcd(5, 1, "BR = %d    ", BR);
    if (sw_OK())
    {
      break;
    }
  }
}
