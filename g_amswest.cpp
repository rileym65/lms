#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amswest.h"
#include "terminal.h"

G_AmsWest::G_AmsWest(Int8 x,Int8 y,Boolean f) :
  Gauge(x, y, f) {
  width = 25;
  height = 14;
  Reset();
  }

G_AmsWest::~G_AmsWest() {
  }

void G_AmsWest::Reset() {
  }

void G_AmsWest::Display() {
  GotoXY(x,y+ 0); printf("    LOOKING   WEST       ");
  GotoXY(x,y+ 1); printf(" +--------up|----------+ ");
  GotoXY(x,y+ 2); printf(" |                     |n");
  GotoXY(x,y+ 3); printf(" |                     |o");
  GotoXY(x,y+ 4); printf(" |                     |r");
  GotoXY(x,y+ 5); printf(" |                     |t");
  GotoXY(x,y+ 6); printf(" |                     |h");
  GotoXY(x,y+ 7); printf("--                     --");
  GotoXY(x,y+ 8); printf("s|                     | ");
  GotoXY(x,y+ 9); printf("o|                     | ");
  GotoXY(x,y+10); printf("u|                     | ");
  GotoXY(x,y+11); printf("t|                     | ");
  GotoXY(x,y+12); printf("h|                     | ");
  GotoXY(x,y+13); printf(" +----------|down------+ ");
  }

void G_AmsWest::Update() {
  Int8 i;
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
  Vehicle* vehicle;
  vehicle = currentVehicle;
  vel = vehicle->Velocity().Norm();
  xVec = Vector(0,0,1);
  yVec = vehicle->Position().Norm();
//GotoXY(1,27); printf("%f %f %f\n",yVec.X(),yVec.Y(),yVec.Z());
//  xVec = Vector(yVec.Z(),-yVec.Z(),1-fabs(yVec.Z()));
  zVec = Vector(yVec.Y(), -yVec.X(), yVec.Z()).Norm();
  GotoXY(x+leftFaceX, y+leftFaceY); printf(" ");
  GotoXY(x+leftLeftX, y+leftLeftY); printf(" ");
  GotoXY(x+leftUpX, y+leftUpY); printf(" ");
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
    printf("%c",c[i]);
    }

  }

