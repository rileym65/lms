#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_amsdown.h"
#include "terminal.h"

G_AmsDown::G_AmsDown(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  width = 25;
  height = 14;
  Reset();
  }

G_AmsDown::~G_AmsDown() {
  }

void G_AmsDown::Reset() {
  }

void G_AmsDown::Display() {
  GotoXY(x,y+ 0); printf("    LOOKING   DOWN       ");
  GotoXY(x,y+ 1); printf(" +------west|----------+ ");
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
  GotoXY(x,y+13); printf(" +----------|east------+ ");
  }

void G_AmsDown::Update() {
  Boolean flag;
  Int8 i;
  Int32  dx[3], dy[3];
  Double d[3];
  char   c[3];
  char   tc;
  Int32  ti;
  Double td;
  Vector pos;
  Vector vel;
  Vehicle* vehicle;
  vehicle = currentVehicle;
  pos = vehicle->Position().Norm();
  vel = vehicle->Velocity().Norm();
  Vector xVec;
  Vector yVec;
  Vector zVec;
  xVec = Vector(0,0,1);
  yVec = vehicle->Velocity().Norm();
//  xVec = Vector(-pos.Z(),pos.Z(),1-fabs(pos.Z()));
  yVec = Vector(pos.Y(),-pos.X(),0);
  zVec = vehicle->Position().Norm();
  GotoXY(x+rightFaceX, y+rightFaceY); printf(" ");
  GotoXY(x+rightLeftX, y+rightLeftY); printf(" ");
  GotoXY(x+rightUpX, y+rightUpY); printf(" ");
  /* ***** Face ***** */
  rightFaceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  rightFaceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = -vehicle->FaceFront().Dot(zVec);
  /* ***** Left ***** */
  rightLeftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  rightLeftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = -vehicle->FaceLeft().Dot(zVec);
  /* ***** Up ***** */
  rightUpX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  rightUpY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = -vehicle->FaceUp().Dot(zVec);
  dx[0] = rightFaceX; dy[0] = rightFaceY; d[0] = faceD;
  c[0] = (faceD <= 0) ? 'F' : 'f';
  dx[1] = rightLeftX; dy[1] = rightLeftY; d[1] = leftD;
  c[1] = (leftD <= 0) ? 'L' : 'l';
  dx[2] = rightUpX; dy[2] = rightUpY; d[2] = upD;
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

