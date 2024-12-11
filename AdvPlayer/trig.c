#include "temp\target.h"

#include "..\\include\Types.h"
#include "..\\include\Function.h"

#include "trig.h"

int sin(int i)
{
  return sintable[i % MAX_DEGREES];
}

int cos(int i)
{
  return sin(i + 90);
}

int tan(int i)
{
  int cosine = cos(i);
  if (cosine == 0)
    return 0;
  return sin(i) / cosine;
}

int sec(int i)
{
  int cosine = cos(i);
  if (cosine == 0)
    return 0;
  return 1 / cosine;
}

int csc(int i)
{
  int sine = sin(i);
  if (sine == 0)
    return 0;
  return 1 / sine;
}

int cot(int i)
{
  int sine = sin(i);
  if (sine == 0)
    return 0;
  return cos(i) / sine;
}

int getangle(int a)
{
  a = a % 360;
  if (a > 180)
    a -= 360;
  if (a < -180)
    a += 360;
  return a;
}

void rotate3d(const int ax, const int ay, int &x, int &y, int &z)
{
  int x1 = x;
  int y1 = y * cos(ax) / SINE_RESOLUTION + z * sin(ax) / SINE_RESOLUTION;
  int z1 = z * cos(ax) / SINE_RESOLUTION - y * sin(ax) / SINE_RESOLUTION;

  x = x1 * cos(ay) / SINE_RESOLUTION + z1 * sin(ay) / SINE_RESOLUTION;
  y = y1;
  z = z1 * cos(ay) / SINE_RESOLUTION - x1 * sin(ay) / SINE_RESOLUTION;
}

void rotate(const int az, int &x, int &y)
{
  int x1 = x * cos(az) / SINE_RESOLUTION + y * sin(az) / SINE_RESOLUTION;
  int y1 = y * cos(az) / SINE_RESOLUTION - x * sin(az) / SINE_RESOLUTION;

  x = x1;
  y = y1;
}

void translate_point(const POINT *frame, POINT &ret)
{
  int x11 = (frame[1].x - frame[0].x) * ret.x / SINE_RESOLUTION + frame[0].x;
  int x22 = (frame[2].x - frame[3].x) * ret.x / SINE_RESOLUTION + frame[3].x;

  int xn = (x22 - x11) * ret.y / SINE_RESOLUTION + x11;

  int y11 = (frame[1].y - frame[0].y) * ret.x / SINE_RESOLUTION + frame[0].y;
  int y22 = (frame[2].y - frame[3].y) * ret.x / SINE_RESOLUTION + frame[3].y;

  int yn = (y22 - y11) * ret.y / SINE_RESOLUTION + y11;

  ret.x = xn;
  ret.y = yn;
}

void rotate_x(POINT3D *p, int angle)
{
  int cos_a = cos(angle);
  int sin_a = sin(angle);

  int y_new = p->y * cos_a - p->z * sin_a;
  int z_new = p->y * sin_a + p->z * cos_a;

  p->y = y_new;
  p->z = z_new;
}

void rotate_y(POINT3D *p, int angle)
{
  int cos_a = cos(angle);
  int sin_a = sin(angle);

  int x_new = p->x * cos_a + p->z * sin_a;
  int z_new = -p->x * sin_a + p->z * cos_a;

  p->x = x_new;
  p->z = z_new;
}

void rotate_z(POINT3D *p, int angle)
{
  int cos_a = cos(angle);
  int sin_a = sin(angle);

  int x_new = p->x * cos_a - p->y * sin_a;
  int y_new = p->x * sin_a + p->y * cos_a;

  p->x = x_new;
  p->y = y_new;
}
