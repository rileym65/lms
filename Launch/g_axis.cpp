#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsdown.h"
#include "terminal.h"

G_Axis::G_Axis(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 25;
  height = 14;
  Reset();
  }

G_Axis::~G_Axis() {
  }

void G_Axis::Reset() {
  }

void G_Axis::Display() {
  }

void G_Axis::Update() {
  }

void G_Axis::draw(Int32 fx,Int32 fy,Double fd,
                  Int32 lx,Int32 ly,Double ld,
                  Int32 ux,Int32 uy,Double ud) {
  char buffer[32];
  Boolean flag;
  UInt8 i;
  Int32  dx[3], dy[3];
  Double d[3];
  char   c[3];
  char   tc;
  Int32  ti;
  Double td;
  if (fx > 22) fx = 22;
  if (fx < 2) fx = 2;
  if (fy > 12) fy = 12;
  if (fy < 2) fy = 2;
  if (lx > 22) lx = 22;
  if (lx < 2) lx = 2;
  if (ly > 12) ly = 12;
  if (ly < 2) ly = 2;
  if (ux > 22) ux = 22;
  if (ux < 2) ux = 2;
  if (uy > 12) uy = 12;
  if (uy < 2) uy = 2;
  dx[0] = fx; dy[0] = fy; d[0] = fd;
  c[0] = (fd <= 0) ? 'F' : 'f';
  dx[1] = lx; dy[1] = ly; d[1] = ld;
  c[1] = (ld <= 0) ? 'L' : 'l';
  dx[2] = ux; dy[2] = uy; d[2] = ud;
  c[2] = (ud <= 0) ? 'U' : 'u';
  flag = true;
  while (flag) {
    flag = false;
    for (i=0; i<2; i++)
      if (d[i] < d[i+1]) {
        ti = dx[i]; dx[i] = dx[i+1]; dx[i+1] = ti;
        ti = dy[i]; dy[i] = dy[i+1]; dy[i+1] = ti;
        tc = c[i]; c[i] = c[i+1]; c[i+1] = tc;
        td = d[i]; d[i] = d[i+1]; d[i+1] = td;
        flag = true;
        }
    }
  for (i=0; i<3; i++) {
    GotoXY(x+dx[i], y+dy[i]);
    sprintf(buffer,"%c",c[i]);
    Write(buffer);
    }


  }


