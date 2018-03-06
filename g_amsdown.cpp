#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_axis.h"
#include "g_amsdown.h"
#include "terminal.h"

G_AmsDown::G_AmsDown(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  G_Axis(x, y, f, v) {
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
  GotoXY(x+faceX, y+faceY); printf(" ");
  GotoXY(x+leftX, y+leftY); printf(" ");
  GotoXY(x+upX, y+upY); printf(" ");
  /* ***** Face ***** */
  faceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  faceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = -vehicle->FaceFront().Dot(zVec);
  /* ***** Left ***** */
  leftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = -vehicle->FaceLeft().Dot(zVec);
  /* ***** Up ***** */
  upX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  upY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = -vehicle->FaceUp().Dot(zVec);
  draw(faceX,faceY,faceD,leftX,leftY,leftD,upX,upY,upD);
  }

