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
    GotoXY(x,y+ 0); Write("    LOOKING   DOWN       ");
    GotoXY(x,y+ 1); Write(" +======west|==========+ ");
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
    GotoXY(x,y+13); Write(" +==========|east======+ ");
    }
  if (mode == MODE_WEST) {
    GotoXY(x,y+ 0); Write("    LOOKING   WEST       ");
    GotoXY(x,y+ 1); Write(" +========up|==========+ ");
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
    GotoXY(x,y+13); Write(" +==========|down======+ ");
    }
  if (mode == MODE_ABS) {
    GotoXY(x,y+ 0); Write("    LOOKING   -X         ");
    GotoXY(x,y+ 1); Write(" +========-Y|==========+ ");
    GotoXY(x,y+ 2); Write(" |                     | ");
    GotoXY(x,y+ 3); Write(" |                     | ");
    GotoXY(x,y+ 4); Write(" |                     | ");
    GotoXY(x,y+ 5); Write(" |                     |+");
    GotoXY(x,y+ 6); Write(" |                     |Z");
    GotoXY(x,y+ 7); Write("--                     --");
    GotoXY(x,y+ 8); Write("-|                     | ");
    GotoXY(x,y+ 9); Write("Z|                     | ");
    GotoXY(x,y+10); Write(" |                     | ");
    GotoXY(x,y+11); Write(" |                     | ");
    GotoXY(x,y+12); Write(" |                     | ");
    GotoXY(x,y+13); Write(" +==========|+Y========+ ");
    }
  if (mode == MODE_PRO) {
    GotoXY(x,y+ 0); Write("    LOOKING   PROGRADE   ");
    GotoXY(x,y+ 1); Write(" +===outside|==========+ ");
    GotoXY(x,y+ 2); Write(" |                     | ");
    GotoXY(x,y+ 3); Write(" |                     |n");
    GotoXY(x,y+ 4); Write(" |                     |o");
    GotoXY(x,y+ 5); Write(" |                     |r");
    GotoXY(x,y+ 6); Write(" |                     |m");
    GotoXY(x,y+ 7); Write("--                     --");
    GotoXY(x,y+ 8); Write("a|                     | ");
    GotoXY(x,y+ 9); Write("n|                     | ");
    GotoXY(x,y+10); Write("o|                     | ");
    GotoXY(x,y+11); Write("r|                     | ");
    GotoXY(x,y+12); Write("m|                     | ");
    GotoXY(x,y+13); Write(" +==========|inside====+ ");
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
  GotoXY(x+faceX, y+faceY); Write(" ");
  GotoXY(x+leftX, y+leftY); Write(" ");
  GotoXY(x+upX, y+upY); Write(" ");
  /* ***** Face ***** */
  faceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  faceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = -vehicle->FaceFront().Dot(zVec);
  if (faceX > 22) faceX = 22;
  if (faceX < 2) faceX = 2;
  /* ***** Left ***** */
  leftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = -vehicle->FaceLeft().Dot(zVec);
  if (leftX > 22) leftX = 22;
  if (leftX < 2) leftX = 2;
  /* ***** Up ***** */
  upX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  upY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = -vehicle->FaceUp().Dot(zVec);
  if (upX > 22) upX = 22;
  if (upX < 2) upX = 2;
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
  yVec = vehicle->Velocity().Norm();
  yVec = Vector(pos.Y(),-pos.X(),0);
  zVec = vehicle->Position().Norm();
  xVec = yVec.Cross(zVec).Norm();
  GotoXY(x+faceX, y+faceY); Write(" ");
  GotoXY(x+leftX, y+leftY); Write(" ");
  GotoXY(x+upX, y+upY); Write(" ");
  /* ***** Face ***** */
  faceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  faceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = -vehicle->FaceFront().Dot(zVec);
  if (faceX > 22) faceX = 22;
  if (faceX < 2) faceX = 2;
  /* ***** Left ***** */
  leftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = -vehicle->FaceLeft().Dot(zVec);
  if (leftX > 22) leftX = 22;
  if (leftX < 2) leftX = 2;
  /* ***** Up ***** */
  upX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  upY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = -vehicle->FaceUp().Dot(zVec);
  if (upX > 22) upX = 22;
  if (upX < 2) upX = 2;
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
  GotoXY(x+faceX, y+faceY); Write(" ");
  GotoXY(x+leftX, y+leftY); Write(" ");
  GotoXY(x+upX, y+upY); Write(" ");
  /* ***** Face ***** */
  faceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  faceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = vehicle->FaceFront().Dot(zVec);
  if (faceX > 22) faceX = 22;
  if (faceX < 2) faceX = 2;
  /* ***** Left ***** */
  leftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = vehicle->FaceLeft().Dot(zVec);
  if (leftX > 22) leftX = 22;
  if (leftX < 2) leftX = 2;
  /* ***** Up ***** */
  upX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  upY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = vehicle->FaceUp().Dot(zVec);
  if (upX > 22) upX = 22;
  if (upX < 2) upX = 2;
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
  GotoXY(x+faceX, y+faceY); Write(" ");
  GotoXY(x+leftX, y+leftY); Write(" ");
  GotoXY(x+upX, y+upY); Write(" ");
  /* ***** Face ***** */
  faceX = 12.5 + ((vehicle->FaceFront().Dot(xVec)) * 10.5);
  faceY = 7.5 - ((vehicle->FaceFront().Dot(yVec)) * 5.5);
  faceD = vehicle->FaceFront().Dot(zVec);
  if (faceX > 22) faceX = 22;
  if (faceX < 2) faceX = 2;
  /* ***** Left ***** */
  leftX = 12.5 + ((vehicle->FaceLeft().Dot(xVec)) * 10.5);
  leftY = 7.5 - ((vehicle->FaceLeft().Dot(yVec)) * 5.5);
  leftD = vehicle->FaceLeft().Dot(zVec);
  if (leftX > 22) leftX = 22;
  if (leftX < 2) leftX = 2;
  /* ***** Up ***** */
  upX = 12.5 + ((vehicle->FaceUp().Dot(xVec)) * 10.5);
  upY = 7.5 - ((vehicle->FaceUp().Dot(yVec)) * 5.5);
  upD = vehicle->FaceUp().Dot(zVec);
  if (upX > 22) upX = 22;
  if (upX < 2) upX = 2;
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

void G_MultiAxis::Load(FILE* file,char* firstLine) {
  char* pline;
  if (!startsWith(firstLine,"multiaxis ")) return;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"mode ")) mode = atoi(nw(pline));
    else {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
    }
  }

void G_MultiAxis::Save(FILE* file) {
  fprintf(file,"    MultiAxis {%s",LE);
  fprintf(file,"      Mode %d%s",mode,LE);
  fprintf(file,"      }%s",LE);
  }

