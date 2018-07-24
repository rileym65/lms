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
  GroundVehicle::Init();
  panel = new Panel("plss.pnl",this);
  battery = 36000;
  oxygen = 36000;
  carrying = ' ';
  heading = 0;
  walked = 0;
  damageReportStep = 0;
  oxygenLeakage = 0;
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

Boolean Plss::AddToCart(Double v) {
  if (cart >= 10) return false;
  cart++;
  cartValue += v;
  return true;
  }

char Plss::Carrying() {
  return carrying;
  }

char Plss::Carrying(char c) {
  carrying = c;
  return carrying;
  }

UInt32 Plss::Cart() {
  return cart;
  }

UInt32 Plss::Cart(UInt32 i) {
  if (i > 10) i = 10;
  cart = i;
  return cart;
  }

Double Plss::CartValue() {
  return cartValue;
  }

Double Plss::CartValue(Double d) {
  cartValue = d;
  return cartValue;
  }

void Plss::Damage(Double dmg) {
  if (rng.Next(100) < dmg) batteryLeakage += ((Double)rng.Next(dmg) / 100.0);
  if (rng.Next(100) < dmg) oxygenLeakage += ((Double)rng.Next(dmg) / 100.0);
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

Double Plss::Walked(Double d) {
  walked = d;
  return walked;
  }

void Plss::Cycle() {
  oxygen -= oxygenLeakage;
  battery -= batteryLeakage;
  if (oxygen < 0) oxygen = 0;
  if (battery < 0) battery = 0;
  if (throttle > 30 && metabolicRate > 60) Throttle(30);
  GroundVehicle::Cycle();
  if (!isnan(velocity.Length())) walked += velocity.Length();
  if (throttle > 0) {
    metabolicRate += throttle * 0.0023;
    }
  if (damageReportStep != 0) {
    if (damageReportStep == 1) {
      if (seq->Time() > 0) return;
      seq->Message("   BATTERY:",batteryLeakage*100,5);
      damageReportStep = 2;
      }
    if (damageReportStep == 2) {
      if (seq->Time() > 1) return;
      seq->Message("    OXYGEN:",oxygenLeakage*100,5);
      damageReportStep = 0;
      }
    }
  }

Int8 Plss::SubLoad(char* pline) {
  if (startsWith(pline,"carrying ")) carrying = atoi(nw(pline));
  else if (startsWith(pline,"value ")) value = atof(nw(pline));
  else if (startsWith(pline,"walked ")) walked = atof(nw(pline));
  else if (startsWith(pline,"oxygenleakage ")) oxygenLeakage = atof(nw(pline));
  else if (startsWith(pline,"cart ")) cart = atoi(nw(pline));
  else if (startsWith(pline,"cartvalue ")) cartValue = atof(nw(pline));
  else return GroundVehicle::SubLoad(pline);
  return -1;
  }

void Plss::Save(FILE* file) {
  fprintf(file,"Plss {%s",LE);
  GroundVehicle::Save(file);
  fprintf(file,"  Carrying %d%s",carrying,LE);
  fprintf(file,"  Value %.18f%s",value,LE);
  fprintf(file,"  Walked %.18f%s",walked,LE);
  fprintf(file,"  OxygenLeakage %.18f%s",oxygenLeakage,LE);
  fprintf(file,"  Cart %d%s",cart,LE);
  fprintf(file,"  CartValue %.18f%s",cartValue,LE);
  fprintf(file,"  }%s",LE);
  }

void Plss::ProcessKey(Int32 key) {
  Double lmPos;
  Double lrvPos;
  lmPos = (position-lm->Position()).Length();
  if (lrv->IsSetup()) lrvPos = (position-lrv->Position()).Length();
    else lrvPos = 99999;
  if (throttle == 0) {
    if (key == 'E' && throttle == 0) {
      if (lmPos < 40) seq->EndEva();
      }
    if (key == 'M' && lrvPos < 100 && carrying == ' ') {
      seq->MoveLrv();
      }
    if (key == 'C') {
      if (carrying == ' ') seq->TakeSample();
      }
    if (key == 'D') {
      if (carrying == 'R') seq->DropSample();
      }
    if (key == 'S') {
      if (carrying == 'R' && lrvPos < 50) {
        if (lrv->Rock() < 30 && lrv->Boxes() > 0) seq->StoreSample();
        }
      if (carrying == 'B' && lmPos < 50 && lrv->Boxes() > 0)
        seq->BoxToLm();
      }
    if (key == 's' && carrying == 'R') {
      seq->SampleToCart();
      }
    if (key == 'T' && cart > 0 && lmPos < 50) seq->CartToLm();
    if (key == 't' && cart > 0 && lrvPos < 50) seq->CartToLrv();
    if (key == 'R' && carrying == 'B' && lrvPos < 100) seq->BoxToLrv();
    if (key == 'B' && carrying == ' ' && lrvPos < 40 && lrv->Boxes() > 0)
      seq->BoxToPlss();
    if (key == 'V' && (position - lm->Position()).Length() < 40 &&
        !lrv->IsSetup() && mission->Vehicle() != 1)
      seq->SetupLrv();
    if (key == 'F') {
      if (carrying == ' ' && lmPos <= 40 && flagPlanted == 0) seq->GetFlag();
      if (carrying == 'F' && lmPos >= 50) seq->PlantFlag();
      }
    if (key == 'f' && carrying == 'F' && lmPos <= 40) seq->PutFlag();
    if (key == 'L') {
      if (carrying == ' ' && lmPos <= 40 && laserSetup == 0) seq->GetLaser();
      if (carrying == 'L' && lmPos >= 50) seq->SetupLaser();
      }
    if (key == 'l' && carrying == 'L' && lmPos <= 40) seq->PutLaser();
    if (key == 'A') {
      if (carrying == ' ' && lmPos <= 40 && alsepSetup == 0) seq->GetAlsep();
      if (carrying == 'A' && lmPos >= 150) seq->PutAlsep();
      }
    }
  if (key == KEY_INSERT) Throttle(0);
  if (key == '0') Throttle(0);
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
  if (key == 'Z') damageReportStep = 1;
  panel->ProcessKey(key);
  }

