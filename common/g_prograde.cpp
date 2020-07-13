#include <string.h>
#include <math.h>
#include "types.h"
#include "gauge.h"
#include "g_prograde.h"
#include "terminal.h"
#include "vehicle.h"
#include "common.h"

G_Prograde::G_Prograde(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 22;
  height = 4;
  }

G_Prograde::~G_Prograde() {
  }

void G_Prograde::Reset() {
  }

void G_Prograde::Display() {
  GotoXY(x,y+0); Write("    Elev     Norm     ");
  GotoXY(x,y+1); Write("U: -999.00  -999.99  +");
  GotoXY(x,y+2); Write("F: -999.00  -999.99  +");
  GotoXY(x,y+3); Write("L: -999.00  -999.99  +");
  }

void G_Prograde::Update() {
  Vector vel;
  Vector pos;
  Vector xVec;
  Vector yVec;
  Vector zVec;
  char buffer[40];
  char num1[16];
  char num2[16];
  Double dx,dy,dz;
  pos = (vehicle->Position() - vehicle->Orbiting()->Position()).Norm();
  vel = (vehicle->Velocity() - vehicle->Orbiting()->Velocity()).Norm();
  xVec = vel.Cross(pos).Norm();
  yVec = xVec.Cross(vel).Norm();
  zVec = vel;
  /* ***** Up ***** */
  dx = -asin(vehicle->FaceUp().Dot(xVec)) * 180 / PI;
  dy = asin(vehicle->FaceUp().Dot(yVec)) * 180 / PI;
  dz = asin(vehicle->FaceUp().Dot(zVec)) * 180 / PI;
  if (isnan(dy)) strcpy(num1," ---.--");
    else sprintf(num1,"%7.2f",dy);
  if (isnan(dx)) strcpy(num2," ---.--");
    else sprintf(num2,"%7.2f",dx);
  GotoXY(x+3,y+1); sprintf(buffer,"%7s  %7s  ",num1,num2); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  /* ***** Face ***** */
  dx = -asin(vehicle->FaceFront().Dot(xVec)) * 180 / PI;
  dy = asin(vehicle->FaceFront().Dot(yVec)) * 180 / PI;
  dz = asin(vehicle->FaceFront().Dot(zVec)) * 180 / PI;
  if (isnan(dy)) strcpy(num1," ---.--");
    else sprintf(num1,"%7.2f",dy);
  if (isnan(dx)) strcpy(num2," ---.--");
    else sprintf(num2,"%7.2f",dx);
  GotoXY(x+3,y+2); sprintf(buffer,"%7s  %7s  ",num1,num2); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  /* ***** Left ***** */
  dx = -asin(vehicle->FaceLeft().Dot(xVec)) * 180 / PI;
  dy = asin(vehicle->FaceLeft().Dot(yVec)) * 180 / PI;
  dz = asin(vehicle->FaceLeft().Dot(zVec)) * 180 / PI;
  if (isnan(dy)) strcpy(num1," ---.--");
    else sprintf(num1,"%7.2f",dy);
  if (isnan(dx)) strcpy(num2," ---.--");
    else sprintf(num2,"%7.2f",dx);
  GotoXY(x+3,y+3); sprintf(buffer,"%7s  %7s  ",num1,num2); Write(buffer);
  if (dz >= 0) Write("+"); else Write("-");
  }

