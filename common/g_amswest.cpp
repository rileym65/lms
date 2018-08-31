#include "types.h"
#include "gauge.h"
#include "g_amswest.h"
#include "terminal.h"
#include "vehicle.h"

G_AmsWest::G_AmsWest(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 25;
  height = 14;
  Reset();
  }

G_AmsWest::~G_AmsWest() {
  }

void G_AmsWest::Reset() {
  }

void G_AmsWest::Display() {
  GotoXY(x,y+ 0); Write("    LOOKING   WEST       ");
  GotoXY(x,y+ 1); Write(" +--------up|----------+ ");
  GotoXY(x,y+ 2); Write(" |                     |n");
  GotoXY(x,y+ 3); Write(" |                     |o");
  GotoXY(x,y+ 4); Write(" |                     |r");
  GotoXY(x,y+ 5); Write(" |                     |t");
  GotoXY(x,y+ 6); Write(" |                     |h");
  GotoXY(x,y+ 7); Write("--                     --");
  GotoXY(x,y+ 8); Write("s|                     | ");
  GotoXY(x,y+ 9); Write("o|                     | ");
  GotoXY(x,y+10); Write("u|                     | ");
  GotoXY(x,y+11); Write("t|                     | ");
  GotoXY(x,y+12); Write("h|                     | ");
  GotoXY(x,y+13); Write(" +----------|down------+ ");
  }

void G_AmsWest::Update() {
  UInt8 i;
  Int32  dx[3], dy[3];
  Double d[3];
  char   c[3];
  char   tc;
  Int32  ti;
  Double td;
  Boolean flag;
  Vector pos;
  Vector vel;
  Vector xVec;
  Vector yVec;
  Vector zVec;
  char buffer[32];
  vel = vehicle->Velocity().Norm();
  xVec = Vector(0,0,1);
  yVec = vehicle->Position().Norm();
  zVec = Vector(yVec.Y(), -yVec.X(), yVec.Z()).Norm();
  GotoXY(x+leftFaceX, y+leftFaceY); Write(" ");
  GotoXY(x+leftLeftX, y+leftLeftY); Write(" ");
  GotoXY(x+leftUpX, y+leftUpY); Write(" ");
  /* ***** Face ***** */
  leftFaceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  leftFaceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = vehicle->FaceFront().Dot(zVec);
  /* ***** Left ***** */
  leftLeftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftLeftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = vehicle->FaceLeft().Dot(zVec);
  /* ***** Up ***** */
  leftUpX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  leftUpY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = vehicle->FaceUp().Dot(zVec);
  dx[0] = leftFaceX; dy[0] = leftFaceY; d[0] = faceD;
  c[0] = (faceD <= 0) ? 'F' : 'f';
  dx[1] = leftLeftX; dy[1] = leftLeftY; d[1] = leftD;
  c[1] = (leftD <= 0) ? 'L' : 'l';
  dx[2] = leftUpX; dy[2] = leftUpY; d[2] = upD;
  c[2] = (upD <= 0) ? 'U' : 'u';
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

