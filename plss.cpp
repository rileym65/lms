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
  walked = 0;
  }

void Plss::BeginEva(Vehicle* from) {
  Vector p;
  latitude = from->Latitude();
  longitude = from->Longitude();
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

Double Plss::Walked() {
  return walked;
  }

void Plss::Cycle() {
  GroundVehicle::Cycle();
  if (!isnan(velocity.Length())) walked += velocity.Length();
  }

Int8 Plss::SubLoad(char* pline) {
  if (startsWith(pline,"carrying ")) carrying = atoi(nw(pline));
  else if (startsWith(pline,"value ")) value = atof(nw(pline));
  else if (startsWith(pline,"walked ")) walked = atof(nw(pline));
  else return GroundVehicle::SubLoad(pline);
  return -1;
  }

void Plss::Save(FILE* file) {
  fprintf(file,"Plss {%s",LE);
  GroundVehicle::Save(file);
  fprintf(file,"  Carrying %d%s",carrying,LE);
  fprintf(file,"  Value %.18f%s",value,LE);
  fprintf(file,"  Walked %.18f%s",walked,LE);
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
  if (key == 'F') {
    if (carrying == ' ' && lmPos <= 40 && flagPlanted == 0) seq->GetFlag();
    if (carrying == 'F' && lmPos >= 50) seq->PlantFlag();
    }
  if (key == 'f' && carrying == 'F' && lmPos <= 40) seq->PutFlag();
  if (key == KEY_PGDN) Throttle(Throttle()+10);
  if (key == KEY_END) Throttle(Throttle()-10);
  if (key == KEY_F1) Throttle(10);
  if (key == KEY_F2) Throttle(20);
  if (key == KEY_F3) Throttle(30);
  if (key == KEY_F4) Throttle(40);
  if (key == KEY_F5) Throttle(50);
  if (key == KEY_F6) Throttle(60);
  if (key == KEY_F7) Throttle(70);
  if (key == KEY_F8) Throttle(80);
  if (key == KEY_F9) Throttle(90);
  if (key == KEY_F10) Throttle(100);
  if (key == KEY_KP_END) Throttle(Throttle()-10);
  if (key == KEY_RIGHT_ARROW) TurnRate(TurnRate()+15);
  if (key == KEY_LEFT_ARROW) TurnRate(TurnRate()-15);

  }

