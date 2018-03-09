#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_axis.h"
#include "g_multiaxis.h"
#include "terminal.h"

#define MODE_DOWN 1
#define MODE_WEST 2
#define MODE_PRO  3
#define MODE_ABS  4
#define MODE_LAST 4

G_MultiAxis::G_MultiAxis(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  G_Axis(x, y, f, v) {
  width = 25;
  height = 14;
  mode = MODE_DOWN;
  Reset();
  }

G_MultiAxis::~G_MultiAxis() {
  }

void G_MultiAxis::Reset() {
  }

void G_MultiAxis::Display() {
  if (mode == MODE_DOWN) {
    GotoXY(x,y+ 0); printf("    LOOKING   DOWN       ");
    GotoXY(x,y+ 1); printf(" +======west|==========+ ");
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
    GotoXY(x,y+13); printf(" +==========|east======+ ");
    }
  if (mode == MODE_WEST) {
    GotoXY(x,y+ 0); printf("    LOOKING   WEST       ");
    GotoXY(x,y+ 1); printf(" +========up|==========+ ");
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
    GotoXY(x,y+13); printf(" +==========|down======+ ");
    }
  if (mode == MODE_ABS) {
    GotoXY(x,y+ 0); printf("    LOOKING   -X         ");
    GotoXY(x,y+ 1); printf(" +========-Y|==========+ ");
    GotoXY(x,y+ 2); printf(" |                     | ");
    GotoXY(x,y+ 3); printf(" |                     | ");
    GotoXY(x,y+ 4); printf(" |                     | ");
    GotoXY(x,y+ 5); printf(" |                     |+");
    GotoXY(x,y+ 6); printf(" |                     |Z");
    GotoXY(x,y+ 7); printf("--                     --");
    GotoXY(x,y+ 8); printf("-|                     | ");
    GotoXY(x,y+ 9); printf("Z|                     | ");
    GotoXY(x,y+10); printf(" |                     | ");
    GotoXY(x,y+11); printf(" |                     | ");
    GotoXY(x,y+12); printf(" |                     | ");
    GotoXY(x,y+13); printf(" +==========|+Y========+ ");
    }
  if (mode == MODE_PRO) {
    GotoXY(x,y+ 0); printf("    LOOKING   PROGRADE   ");
    GotoXY(x,y+ 1); printf(" +===outside|==========+ ");
    GotoXY(x,y+ 2); printf(" |                     | ");
    GotoXY(x,y+ 3); printf(" |                     |n");
    GotoXY(x,y+ 4); printf(" |                     |o");
    GotoXY(x,y+ 5); printf(" |                     |r");
    GotoXY(x,y+ 6); printf(" |                     |m");
    GotoXY(x,y+ 7); printf("--                     --");
    GotoXY(x,y+ 8); printf("a|                     | ");
    GotoXY(x,y+ 9); printf("n|                     | ");
    GotoXY(x,y+10); printf("o|                     | ");
    GotoXY(x,y+11); printf("r|                     | ");
    GotoXY(x,y+12); printf("m|                     | ");
    GotoXY(x,y+13); printf(" +==========|inside====+ ");
    }
  }

void G_MultiAxis::modeAbs() {
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
  yVec = Vector(0,-1,0);
  zVec = Vector(1,0,0);
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

void G_MultiAxis::modeDown() {
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

void G_MultiAxis::modePrograde() {
  Vector vel;
  Vector pos;
  Vector xVec;
  Vector yVec;
  Vector zVec;
  Vehicle* vehicle;
  vehicle = currentVehicle;
  pos = vehicle->Position().Norm();
  vel = vehicle->Velocity().Norm();
  xVec = vel.Cross(pos).Norm();
  yVec = xVec.Cross(vel);
  zVec = vel;
  GotoXY(x+faceX, y+faceY); printf(" ");
  GotoXY(x+leftX, y+leftY); printf(" ");
  GotoXY(x+upX, y+upY); printf(" ");
  /* ***** Face ***** */
  faceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  faceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = vehicle->FaceFront().Dot(zVec);
  /* ***** Left ***** */
  leftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = vehicle->FaceLeft().Dot(zVec);
  /* ***** Up ***** */
  upX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  upY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = vehicle->FaceUp().Dot(zVec);
  draw(faceX,faceY,faceD,leftX,leftY,leftD,upX,upY,upD);
  }

void G_MultiAxis::modeWest() {
  Vector vel;
  Vector xVec;
  Vector yVec;
  Vector zVec;
  Vehicle* vehicle;
  vehicle = currentVehicle;
  vel = vehicle->Velocity().Norm();
  xVec = Vector(0,0,1);
  yVec = vehicle->Position().Norm();
  zVec = Vector(yVec.Y(), -yVec.X(), yVec.Z()).Norm();
  GotoXY(x+faceX, y+faceY); printf(" ");
  GotoXY(x+leftX, y+leftY); printf(" ");
  GotoXY(x+upX, y+upY); printf(" ");
  /* ***** Face ***** */
  faceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  faceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = vehicle->FaceFront().Dot(zVec);
  /* ***** Left ***** */
  leftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = vehicle->FaceLeft().Dot(zVec);
  /* ***** Up ***** */
  upX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  upY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = vehicle->FaceUp().Dot(zVec);
  draw(faceX,faceY,faceD,leftX,leftY,leftD,upX,upY,upD);
  }

void G_MultiAxis::Update() {
  if (mode == MODE_ABS)  modeAbs();
  if (mode == MODE_DOWN) modeDown();
  if (mode == MODE_PRO)  modePrograde();
  if (mode == MODE_WEST) modeWest();
  }

void G_MultiAxis::ProcessKey(Int32 key) {
  if (key == ']') {
    if (++mode > MODE_LAST) mode = 1;
    }
  if (key == '[') {
    if (--mode < 1) mode = MODE_LAST;
    }
  Display();
  Update();
  }

