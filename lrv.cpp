#include <math.h>
#include "header.h"
#include "lrv.h"
#include "terminal.h"

Lrv::Lrv() {
  Init();
  }

Lrv::~Lrv() {
  }

void Lrv::Init() {
  panel = new Panel("lrv.pnl",this);
  battery = LRV_BATTERY;
  isSetup = false;
  rock = 0;
  boxes = 8;
  driven = 0;
  }

Int8 Lrv::Boxes() {
  return boxes;
  }

Int8 Lrv::Boxes(Int8 i) {
  boxes = i;
  if (boxes < 0) boxes = 0;
  if (boxes > 8) boxes = 8;
  return boxes;
  }

Double Lrv::Driven() {
  return driven;
  }

Boolean Lrv::IsSetup() {
  return isSetup;
  }

Int8 Lrv::Rock() {
  return rock;
  }

Int8 Lrv::Rock(Int8 i) {
  rock = i;
  if (rock > 30) rock = 30;
  return rock;
  }

Double Lrv::Value() {
  return value;
  }

Double Lrv::Value(Double d) {
  value = d;
  return value;
  }

void Lrv::Setup() {
  Vector p;
  latitude = lm->Latitude();
  longitude = lm->Longitude();
  Place(lm->Position());
  p = faceLeft.Norm().Scale(15);
  position = position + p;
  position = position.Norm().Scale(GROUND);
  isSetup = true;
  Heading(-90);
  return;

  Vector f;
  Vector l;
  Vector u;
  Vector fp;
  Double dist;
  fp = lm->Position();
  u = lm->Position().Norm();
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

  isSetup = true;
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

void Lrv::Cycle() {
  if (battery <= 0) throttle = 0;
  GroundVehicle::Cycle();
  if (!isnan(velocity.Length())) driven += velocity.Length();
  if (throttle > 0) {
    battery -= (maxSpeed * ((Double)throttle / 100.0));
    if (battery < 0) battery = 0;
    }
  }

/*
  Vector a;
  Double alt3;
  Double hyp;
//  alt3 = radius * radius * radius;
//  a = position.Scale(-4.9075e12);
//  a = a.Scale(1/alt3);
//  velocity = velocity + a;
//  velocity = velocity + thrust;
  velocity = thrust;
  position = position + velocity;
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

Int8 Lrv::SubLoad(char* pline) {
  if (startsWith(pline,"value ")) value = atof(nw(pline));
  else if (startsWith(pline,"rock ")) rock = atoi(nw(pline));
  else if (startsWith(pline,"sampleboxes ")) boxes = atoi(nw(pline));
  else if (startsWith(pline,"issetup true")) isSetup = true;
  else if (startsWith(pline,"issetup false")) isSetup = false;
  else if (startsWith(pline,"driven ")) driven = atof(nw(pline));
  else return GroundVehicle::SubLoad(pline);
  return -1;
  }

void Lrv::Save(FILE* file) {
  fprintf(file,"Lrv {%s",LE);
  GroundVehicle::Save(file);
  fprintf(file,"  Rock %d%s",rock,LE);
  fprintf(file,"  Value %.18f%s",value,LE);
  fprintf(file,"  SampleBoxes %d%s",boxes,LE);
  if (isSetup)
    fprintf(file,"  IsSetup true%s",LE);
  else 
    fprintf(file,"  IsSetup false%s",LE);
  fprintf(file,"  Driven %.18f%s",driven,LE);
  fprintf(file,"  }%s",LE);
  }

void Lrv::ProcessKey(Int32 key) {
  if (key == KEY_PGDN) Throttle(Throttle()+10);
  if (key == KEY_END) Throttle(Throttle()-10);
  if (key == KEY_KP_END) Throttle(Throttle()-10);
  if (key == KEY_RIGHT_ARROW) TurnRate(TurnRate()+15);
  if (key == KEY_LEFT_ARROW) TurnRate(TurnRate()-15);
  if (key == KEY_INSERT) Throttle(0);
  if (key == '0') Throttle(0);
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
  if (key == 'M' && throttle == 0) seq->ExitLrv();
  panel->ProcessKey(key);
  }

