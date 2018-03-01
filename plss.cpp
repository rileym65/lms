#include <math.h>
#include "header.h"
#include "plss.h"
#include "terminal.h"

Plss::Plss() {
  Init();
  }

Plss::~Plss() {
  }

void Plss::Init() {
  panel = new Panel("plss.pnl",this);
  battery = 36000;
  oxygen = 36000;
  carrying = ' ';
  heading = 0;
  }

void Plss::BeginEva(Vehicle* from) {
  Vector p;
  Place(from->Position());
  p = faceFront.Norm().Scale(15);
  position = position + p;
  position = position.Norm().Scale(GROUND);
  carrying = ' ';
  Heading(0);
  return;

  Vector f;
  Vector l;
  Vector u;
  Vector fp;
  Double dist;
  fp = from->Position();
  u = from->Position().Norm();
  position = u.Scale(GROUND);
  velocity = Vector(0,0,0);
  thrust = Vector(0,0,0);
  Radius(position.Length());

  f = Vector(position.Y(), -position.X(), position.Z()).Norm();
  l = u.Cross(f).Norm();
  f = l.Cross(u).Norm();

  faceFront = f;
  faceLeft = l;
  faceUp = u;

  carrying = ' ';
  return;

  dist = (position - fp).Length();
  ClrScr();
  printf("Pos: %.18f %.18f %.18f\n",position.X(),position.Y(),position.Z());
  printf("Lm:  %.18f %.18f %.18f\n",fp.X(),
                                    fp.Y(),
                                    fp.Z());
  printf("  F: %.18f %.18f %.18f\n",f.X(),f.Y(),f.Z());
  printf("  U: %.18f %.18f %.18f\n",u.X(),u.Y(),u.Z());
  printf("  L: %.18f %.18f %.18f\n",l.X(),l.Y(),l.Z());
  printf("Dst: %.18f\n",dist);
printf("Len: %.18f\n",f.Length());
  ShowCursor();
  CloseTerminal();
  exit(1);
  }

char Plss::Carrying() {
  return carrying;
  }

char Plss::Carrying(char c) {
  carrying = c;
  return carrying;
  }

Double Plss::Value() {
  return value;
  }

Double Plss::Value(Double d) {
  value = d;
  return value;
  }

/*
void Plss::Cycle() {
  Vector a;
  Double alt3;
  Double hyp;
//  alt3 = radius * radius * radius;
//  a = position.Scale(-4.9075e12);
//  a = a.Scale(1/alt3);
//  velocity = velocity + a;
//  velocity = velocity + thrust;
  thrust = frontFace.Norm().Scale(maxthrust * ((Double)throttle / 100.0));
  velocity = thrust;
  position = position + velocity;
GotoXY(1,26); printf("%f %f %f\n",position.X(),position.Y(),position.Z());
  position = position.Norm().Scale(GROUND);
  Radius(position.Length());
  hyp = sqrt(position.X() * position.X() + position.Y() * position.Y());
  longitude = position.X() / hyp;
  longitude = asin(longitude) * 180 / M_PI;
  if (position.X() < 0 && position.Y() >= 0) longitude = -180 - longitude;
  if (position.X() >= 0 && position.Y() >= 0) longitude = 180 - longitude;
  hyp = sqrt(position.Z() * position.Z() + hyp * hyp);
  latitude = position.Z() / hyp;
  latitude = asin(latitude) * 180 / M_PI;
  }
*/

Int8 Plss::SubLoad(char* pline) {
  if (startsWith(pline,"carrying ")) carrying = atoi(nw(pline));
  else if (startsWith(pline,"value ")) value = atof(nw(pline));
  else return GroundVehicle::SubLoad(pline);
  return -1;
  }

void Plss::Save(FILE* file) {
  fprintf(file,"Plss {%s",LE);
  GroundVehicle::Save(file);
  fprintf(file,"  Carrying %d%s",carrying,LE);
  fprintf(file,"  Value %.18f%s",value,LE);
  fprintf(file,"  }%s",LE);
  }

void Plss::ProcessKey(Int32 key) {
  Double lmPos;
  Double lrvPos;
  lmPos = (position-lm->Position()).Length();
  if (lrv->IsSetup()) lrvPos = (position-lrv->Position()).Length();
    else lrvPos = 99999;
  if (key == 'm') {
    if (lmPos < 40) seq->EndEva();
    }
  if (key == 'M' && lrvPos < 40 && carrying == ' ') {
    seq->MoveLrv();
    }
  if (key == 'R') {
    if (carrying == ' ') seq->TakeSample();
    if (carrying == 'B' && lrvPos < 40) seq->BoxToLrv();
    if (carrying == 'R' && lrvPos < 40 && lrv->Rock() < 30 && lrv->Boxes() > 0)
       seq->StoreSample();
    }
  if (key == 'B') {
    if (carrying == ' ' && lrvPos < 40 && lrv->Boxes() > 0) seq->BoxToPlss();
    if (carrying == 'B' && lmPos < 40 && lrv->Boxes() > 0) seq->BoxToLm();
    if (carrying == 'R') seq->DropSample();
    }
  if (key == 'L' &&
      (position - lm->Position()).Length() < 40 &&
      !lrv->IsSetup())
    seq->SetupLrv();
  if (key == KEY_PGDN) Throttle(Throttle()+10);
  if (key == KEY_END) Throttle(Throttle()-10);
  if (key == KEY_KP_END) Throttle(Throttle()-10);
  if (key == KEY_RIGHT_ARROW) TurnRate(TurnRate()+15);
  if (key == KEY_LEFT_ARROW) TurnRate(TurnRate()-15);

  }

