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
  GotoXY(x,y+ 0); Write("    LOOKING   DOWN       ");
  GotoXY(x,y+ 1); Write(" +------west|----------+ ");
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
  GotoXY(x,y+13); Write(" +----------|east------+ ");
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
  yVec = vehicle->Velocity().Norm();
  yVec = Vector(pos.Y(),-pos.X(),0).Norm();
  zVec = vehicle->Position().Norm();
  xVec = yVec.Cross(zVec).Norm();
  if (faceX > 22) faceX = 22;
  if (faceX < 2) faceX = 2;
  if (faceY > 12) faceY = 12;
  if (faceY < 2) faceY = 2;
  if (leftX > 22) leftX = 22;
  if (leftX < 2) leftX = 2;
  if (leftY > 12) leftY = 12;
  if (leftY < 2) leftY = 2;
  if (upX > 22) upX = 22;
  if (upX < 2) upX = 2;
  if (upY > 12) upY = 12;
  if (upY < 2) upY = 2;
  GotoXY(x+faceX, y+faceY); Write(" ");
  GotoXY(x+leftX, y+leftY); Write(" ");
  GotoXY(x+upX, y+upY); Write(" ");
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

