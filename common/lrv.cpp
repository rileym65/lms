#include <stdlib.h>
#include <math.h>
#include "vehicle.h"
#include "spacecraft.h"
#include "lrv.h"
#include "terminal.h"
#include "common.h"
#include "helpers.h"
#include "random.h"
#include "sequencer.h"

static Int32 samplePos;

Lrv::Lrv() {
  samplePos = 0;
  Init();
  type |= VT_ROVER;
  }

Lrv::~Lrv() {
  }

void Lrv::Init() {
  GroundVehicle::Init();
  panel = new Panel("lrv.pnl",this);
  battery = 0;
  maxBattery = 0.000001;
  isSetup = false;
  rock = 0;
  boxes = 8;
  driven = 0;
  damageReportStep = 0;
  }

void Lrv::AddSample(SAMPLE s) {
  if (rock >= 30) return;
  samples[rock++] = s;
  }

SAMPLE Lrv::TakeSample() {
  SAMPLE ret;
  if (rock > 0) {
    rock--;
    return samples[rock];
    }
  ret.type = 0;
  ret.value = 0;
  return ret;
  }

Boolean Lrv::DuplicateSample(SAMPLE s) {
  Int32 i;
  for (i=0; i<rock; i++)
    if (s.cellX == samples[i].cellX && s.cellY == samples[i].cellY) return true;
  return false;
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

void Lrv::Damage(Double dmg) {
  if (rng.Next(100) < dmg) batteryLeakage += ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) motorEfficiency -= ((Double)rng.Next(dmg) / 100.0);
  if (motorEfficiency < 0.0) motorEfficiency = 0.0;
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

Double Lrv::Value() {
  Int32 i;
  Double ret;
  ret = 0;
  for (i=0; i<rock; i++)
    ret += samples[i].value;
  return ret;
  }

void Lrv::Setup() {
  Vector p;
  Latitude(lm->Latitude());
  Longitude(lm->Longitude());
  Place(lm->Position() - lm->Orbiting()->Position());
  p = faceLeft.Norm().Scale(15);
  position = position + p;
//  position = position.Norm().Scale(Orbiting()->Radius());
  position = (position - Orbiting()->Position()).Norm().Scale(Orbiting()->Radius()) +
             Orbiting()->Position();
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
  position = u.Scale(Orbiting()->Radius());
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
  ShowCursor();
  CloseTerminal();
  exit(1);
  }

void Lrv::Cycle() {
  char cell;
  Double damage;
  Double d;
  battery -= batteryLeakage;
  if (battery < 0) battery = 0;
  if (battery <= 0) throttle = 0;
  GroundVehicle::Cycle();
  if (!isnan(velocity.Length())) {
    d = velocity.Length() / GRAN;
    driven += d;
    distanceTravelled += d;
    }
  if (throttle > 0) {
    battery -= ( (maxSpeed * ((Double)throttle / 100.0)) +
                 (maxSpeed * batteryLeakage) ) / GRAN;
    if (battery < 0) battery = 0;
    }
  if (damageReportStep != 0) {
    if (damageReportStep == 1) {
      if (seq->Time() > 0) return;
      seq->Message("   BATTERY:",batteryLeakage*100,5);
      damageReportStep = 2;
      }
    if (damageReportStep == 2) {
      if (seq->Time() > 1) return;
      seq->Message("     MOTOR:",(1.0 - motorEfficiency)*100,5);
      damageReportStep = 0;
      }
    }
  damage = 0;
  cell = map->Lurrain(lm->Longitude(), lm->Latitude());
  switch (cell) {
    case '.': if (velocity.Length() > 5.0) damage = 0.05; break;
    case 'o': if (velocity.Length() > 3.0) damage = 0.10; break;
    case 'O': if (velocity.Length() > 2.0) damage = 0.10; break;
    case ',': if (velocity.Length() > 5.0) damage = 0.05; break;
    case '+': if (velocity.Length() > 3.0) damage = 0.20; break;
    case '*': if (velocity.Length() > 2.0) damage = 0.20; break;
    case '^': if (velocity.Length() > 1.0) damage = 0.50; break;
    case '(': if (velocity.Length() > 1.0) damage = 0.50; break;
    case ')': if (velocity.Length() > 1.0) damage = 0.50; break;
    case 'u': if (velocity.Length() > 1.0) damage = 0.50; break;
    case ' ': break;
    case '=': if (velocity.Length() > 2.0) damage = 0.50; break;
    case '%': if (velocity.Length() > 2.0) damage = 0.50; break;
    case 'f': break;
    case '&': if (velocity.Length() > 2.0) damage = 0.50; break;
    case '/': if (velocity.Length() > 2.0) damage = 0.50; break;
    case '"': if (velocity.Length() > 2.0) damage = 0.50; break;
    case '_': break;
    default : if (velocity.Length() > 2.0) damage = 0.50; break;
    }
  if (damage > 0) {
    lrv->Damage(damage * 100.0);
    hardInjury += ((Double)rng.Next(damage * 100.0));
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
  position = position.Norm().Scale(Orbiting()->Radius());
  Radius(position.Length());
  hyp = sqrt(position.X() * position.X() + position.Y() * position.Y());
  longitude = position.X() / hyp;
  longitude = asin(longitude) * 180 / PI;
  if (position.X() < 0 && position.Y() >= 0) longitude = -180 - longitude;
  if (position.X() >= 0 && position.Y() >= 0) longitude = 180 - longitude;
  hyp = sqrt(position.Z() * position.Z() + hyp * hyp);
  latitude = position.Z() / hyp;
  latitude = asin(latitude) * 180 / PI;
  }
*/

Int8 Lrv::SubLoad(FILE* file, char* pline) {
  SAMPLE sample;
  if (startsWith(pline,"rock ")) rock = atoi(nw(pline));
  else if (startsWith(pline,"sampleboxes ")) boxes = atoi(nw(pline));
  else if (startsWith(pline,"issetup true")) isSetup = true;
  else if (startsWith(pline,"issetup false")) isSetup = false;
  else if (startsWith(pline,"driven ")) driven = atof(nw(pline));
  else if (startsWith(pline,"sample ")) {
    sample = ParseSample(nw(pline));
    samples[samplePos++] = sample;
    }
  else return GroundVehicle::SubLoad(file, pline);
  return -1;
  }

void Lrv::Save(FILE* file) {
  Int32 i;
  fprintf(file,"Lrv {%s",LE);
  GroundVehicle::Save(file);
  fprintf(file,"  Rock %d%s",rock,LE);
  fprintf(file,"  SampleBoxes %d%s",boxes,LE);
  if (isSetup)
    fprintf(file,"  IsSetup true%s",LE);
  else 
    fprintf(file,"  IsSetup false%s",LE);
  fprintf(file,"  Driven %.18f%s",driven,LE);
  for (i=0; i<rock; i++)
    fprintf(file,"  Sample %d,%d,%d,%f,%d%s",samples[i].cellX,samples[i].cellY,
            samples[i].clockGe,samples[i].value,samples[i].type,LE);

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
  if (key == 'Z') damageReportStep = 1;
  if (mission->Rover() == 3 && Throttle() == 0) {
    if (key == '*') seq->Rest();
    if (key == ')') seq->Sleep();
    }
  panel->ProcessKey(key);
  }

