#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_axis.h"
#include "g_precaxis.h"
#include "terminal.h"

#define MODE_DOWN 1
#define MODE_WEST 2
#define MODE_PRO  3
#define MODE_ABS  4
#define MODE_LAST 4

G_PrecAxis::G_PrecAxis(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  G_Axis(x, y, f, v) {
  width = 25;
  height = 9;
  mode = MODE_DOWN;
  Reset();
  }

G_PrecAxis::~G_PrecAxis() {
  }

void G_PrecAxis::Reset() {
  }

void G_PrecAxis::Display() {
  if (mode == MODE_DOWN) {
    GotoXY(x,y+ 0); Write("    LOOKING   DOWN       ");
    GotoXY(x,y+ 1); Write(" +---------------------+ ");
    GotoXY(x,y+ 2); Write(" |     E/W     N/S     | ");
    GotoXY(x,y+ 3); Write(" |F:                   | ");
    GotoXY(x,y+ 4); Write(" |                     | ");
    GotoXY(x,y+ 5); Write(" |U:                   | ");
    GotoXY(x,y+ 6); Write(" |                     | ");
    GotoXY(x,y+ 7); Write(" |L:                   | ");
    GotoXY(x,y+ 8); Write(" +---------------------+ ");
    }
  if (mode == MODE_WEST) {
    GotoXY(x,y+ 0); Write("    LOOKING   WEST       ");
    GotoXY(x,y+ 1); Write(" +---------------------+ ");
    GotoXY(x,y+ 2); Write(" |     U/D     N/S     | ");
    GotoXY(x,y+ 3); Write(" |F:                   | ");
    GotoXY(x,y+ 4); Write(" |                     | ");
    GotoXY(x,y+ 5); Write(" |U:                   | ");
    GotoXY(x,y+ 6); Write(" |                     | ");
    GotoXY(x,y+ 7); Write(" |L:                   | ");
    GotoXY(x,y+ 8); Write(" +---------------------+ ");
    }
  if (mode == MODE_ABS) {
    GotoXY(x,y+ 0); Write("    LOOKING   -X         ");
    GotoXY(x,y+ 1); Write(" +---------------------+ ");
    GotoXY(x,y+ 2); Write(" |      Y       Z      | ");
    GotoXY(x,y+ 3); Write(" |F:                   | ");
    GotoXY(x,y+ 4); Write(" |                     | ");
    GotoXY(x,y+ 5); Write(" |U:                   | ");
    GotoXY(x,y+ 6); Write(" |                     | ");
    GotoXY(x,y+ 7); Write(" |L:                   | ");
    GotoXY(x,y+ 8); Write(" +---------------------+ ");
    }
  if (mode == MODE_PRO) {
    GotoXY(x,y+ 0); Write("    LOOKING   PROGRADE   ");
    GotoXY(x,y+ 1); Write(" +---------------------+ ");
    GotoXY(x,y+ 2); Write(" |    Elev     Norm    | ");
    GotoXY(x,y+ 3); Write(" |F:                   | ");
    GotoXY(x,y+ 4); Write(" |                     | ");
    GotoXY(x,y+ 5); Write(" |U:                   | ");
    GotoXY(x,y+ 6); Write(" |                     | ");
    GotoXY(x,y+ 7); Write(" |L:                   | ");
    GotoXY(x,y+ 8); Write(" +---------------------+ ");
    }
  }

void G_PrecAxis::modeAbs() {
  Double dx,dy,dz;
  Vector pos;
  Vector vel;
  Vehicle* vehicle;
  char buffer[40];
  vehicle = currentVehicle;
  pos = vehicle->Position().Norm();
  vel = vehicle->Velocity().Norm();
  Vector xVec;
  Vector yVec;
  Vector zVec;
  xVec = Vector(0,0,1);
  yVec = Vector(0,-1,0);
  zVec = Vector(1,0,0);
  /* ***** Face ***** */
  dx = asin(vehicle->FaceFront().Dot(xVec)) * 180 / M_PI;
  dy = -asin(vehicle->FaceFront().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceFront().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+3); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  /* ***** Left ***** */
  dx = asin(vehicle->FaceLeft().Dot(xVec)) * 180 / M_PI;
  dy = -asin(vehicle->FaceLeft().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceLeft().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+7); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  /* ***** Up ***** */
  dx = asin(vehicle->FaceUp().Dot(xVec)) * 180 / M_PI;
  dy = -asin(vehicle->FaceUp().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceUp().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+5); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  }

void G_PrecAxis::modeDown() {
  Vector pos;
  Vector vel;
  char buffer[40];
  Vehicle* vehicle;
  vehicle = currentVehicle;
  Double dx,dy,dz;
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
  /* ***** Face ***** */
  dx = asin(vehicle->FaceFront().Dot(xVec)) * 180 / M_PI;
  dy = asin(vehicle->FaceFront().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceFront().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+3); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  /* ***** Left ***** */
  dx = asin(vehicle->FaceLeft().Dot(xVec)) * 180 / M_PI;
  dy = asin(vehicle->FaceLeft().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceLeft().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+7); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  /* ***** Up ***** */
  dx = asin(vehicle->FaceUp().Dot(xVec)) * 180 / M_PI;
  dy = asin(vehicle->FaceUp().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceUp().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+5); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  }

void G_PrecAxis::modePrograde() {
  Vector vel;
  Vector pos;
  Vector xVec;
  Vector yVec;
  Vector zVec;
  char buffer[40];
  Double dx,dy,dz;
  Vehicle* vehicle;
  vehicle = currentVehicle;
  pos = vehicle->Position().Norm();
  vel = vehicle->Velocity().Norm();
  xVec = vel.Cross(pos).Norm();
  yVec = xVec.Cross(vel);
  zVec = vel;
  /* ***** Face ***** */
  dx = asin(vehicle->FaceFront().Dot(xVec)) * 180 / M_PI;
  dy = asin(vehicle->FaceFront().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceFront().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+3); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  /* ***** Left ***** */
  dx = asin(vehicle->FaceLeft().Dot(xVec)) * 180 / M_PI;
  dy = asin(vehicle->FaceLeft().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceLeft().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+7); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  /* ***** Up ***** */
  dx = asin(vehicle->FaceUp().Dot(xVec)) * 180 / M_PI;
  dy = asin(vehicle->FaceUp().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceUp().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+5); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  }

void G_PrecAxis::modeWest() {
  Vector vel;
  Vector xVec;
  Vector yVec;
  Vector zVec;
  char buffer[40];
  Double dx,dy,dz;
  Vehicle* vehicle;
  vehicle = currentVehicle;
  vel = vehicle->Velocity().Norm();
  xVec = Vector(0,0,1);
  yVec = vehicle->Position().Norm();
  zVec = Vector(yVec.Y(), -yVec.X(), yVec.Z()).Norm();
  /* ***** Face ***** */
  dx = asin(vehicle->FaceFront().Dot(xVec)) * 180 / M_PI;
  dy = asin(vehicle->FaceFront().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceFront().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+3); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz < 0) Write("+"); else Write("-");
  /* ***** Left ***** */
  dx = asin(vehicle->FaceLeft().Dot(xVec)) * 180 / M_PI;
  dy = asin(vehicle->FaceLeft().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceLeft().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+7); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz < 0) Write("+"); else Write("-");
  /* ***** Up ***** */
  dx = asin(vehicle->FaceUp().Dot(xVec)) * 180 / M_PI;
  dy = asin(vehicle->FaceUp().Dot(yVec)) * 180 / M_PI;
  dz = asin(vehicle->FaceUp().Dot(zVec)) * 180 / M_PI;
  GotoXY(x+5,y+5); sprintf(buffer,"%7.2f %7.2f  ",dy,dx); Write(buffer);
  if (dz < 0) Write("+"); else Write("-");
  }

void G_PrecAxis::Update() {
  if (mode == MODE_ABS)  modeAbs();
  if (mode == MODE_DOWN) modeDown();
  if (mode == MODE_PRO)  modePrograde();
  if (mode == MODE_WEST) modeWest();
  }

void G_PrecAxis::ProcessKey(Int32 key) {
  if (key == '.') {
    if (++mode > MODE_LAST) mode = 1;
    }
  if (key == ',') {
    if (--mode < 1) mode = MODE_LAST;
    }
  Display();
  Update();
  }

void G_PrecAxis::Load(FILE* file,char* firstLine) {
  char* pline;
  if (!startsWith(firstLine,"precaxis ")) return;
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

void G_PrecAxis::Save(FILE* file) {
  fprintf(file,"    PrecAxis {%s",LE);
  fprintf(file,"      Mode %d%s",mode,LE);
  fprintf(file,"      }%s",LE);
  }

