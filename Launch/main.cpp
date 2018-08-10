#define MAIN

#include "header.h"

void mercuryRedstone() {
  booster = new Booster();
  booster->NumStages(1);
  booster->DryWeight(1, 6178);
  booster->Fuel(1, 23821);
  booster->Payload(1400);
  booster->Stage(1);
  booster->NumEngines(1, 1);
  booster->IspVac(1, 1, 215);
  booster->IspSl(1, 1, 215);
  booster->ThrustVac(1, 1, 350000);
  booster->ThrustSl(1, 1, 350000);
  booster->Starts(1,1);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->SetupPanel();
  }

void geminiTitan() {
  booster = new Booster();
  booster->NumStages(2);
  booster->DryWeight(1, 8532);
  booster->DryWeight(2, 1870);
  booster->Fuel(1, 117950);
  booster->Fuel(2, 25847);
  booster->Payload(3790);
  booster->Stage(1);
  booster->NumEngines(1, 1);
  booster->NumEngines(2, 1);
  booster->IspSl(1, 1, 258);
  booster->IspVac(1, 1, 296);
  booster->IspSl(2, 1, 160);
  booster->IspVac(2, 1, 316);
  booster->ThrustVac(1, 1, 1913000);
  booster->ThrustVac(2, 1, 445000);
  booster->ThrustSl(1, 1, 1913000);
  booster->ThrustSl(2, 1, 445000);
  booster->Starts(1,1);
  booster->Starts(2,1);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  booster->SetupPanel();
  }

void saturnV() {
  booster = new Booster();
  booster->NumStages(3);
  booster->DryWeight(1, 130342 + 2447 + 4524);
  booster->DryWeight(2, 36479 + 423 + 3637);
  booster->DryWeight(3, 11357 + 752 + 2027 + 1796);
  booster->Fuel(1, 649508 + 1503381);
  booster->Fuel(2, 382874 + 72779);
  booster->Fuel(3, 19845 + 88738);
  booster->Payload(16448 + 30364);
  booster->Stage(1);
  booster->NumEngines(1, 5);
  booster->NumEngines(2, 5);
  booster->NumEngines(3, 1);
  booster->IspVac(1, 1, 304);
  booster->IspVac(1, 2, 304);
  booster->IspVac(1, 3, 304);
  booster->IspVac(1, 4, 304);
  booster->IspVac(1, 5, 304);
  booster->IspVac(2, 1, 421);
  booster->IspVac(2, 2, 421);
  booster->IspVac(2, 3, 421);
  booster->IspVac(2, 4, 421);
  booster->IspVac(2, 5, 421);
  booster->IspVac(3, 1, 421);
  booster->IspSl(1, 1, 263);
  booster->IspSl(1, 2, 263);
  booster->IspSl(1, 3, 263);
  booster->IspSl(1, 4, 263);
  booster->IspSl(1, 5, 263);
  booster->IspSl(2, 1, 200);
  booster->IspSl(2, 2, 200);
  booster->IspSl(2, 3, 200);
  booster->IspSl(2, 4, 200);
  booster->IspSl(2, 5, 200);
  booster->IspSl(3, 1, 200);
  booster->ThrustVac(1, 1, 7770000);
  booster->ThrustVac(1, 2, 7770000);
  booster->ThrustVac(1, 3, 7770000);
  booster->ThrustVac(1, 4, 7770000);
  booster->ThrustVac(1, 5, 7770000);
  booster->ThrustVac(2, 1, 1033100);
  booster->ThrustVac(2, 2, 1033100);
  booster->ThrustVac(2, 3, 1033100);
  booster->ThrustVac(2, 4, 1033100);
  booster->ThrustVac(2, 5, 1033100);
  booster->ThrustVac(3, 1, 1033100);
  booster->ThrustSl(1, 1, 6770000);
  booster->ThrustSl(1, 2, 6770000);
  booster->ThrustSl(1, 3, 6770000);
  booster->ThrustSl(1, 4, 6770000);
  booster->ThrustSl(1, 5, 6770000);
  booster->ThrustSl(2, 1, 486200);
  booster->ThrustSl(2, 2, 486200);
  booster->ThrustSl(2, 3, 486200);
  booster->ThrustSl(2, 4, 486200);
  booster->ThrustSl(2, 5, 486200);
  booster->ThrustSl(3, 1, 486200);
  booster->Starts(1,1);
  booster->Starts(2,1);
  booster->Starts(3,2);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  booster->MaxFuel(3, booster->Fuel(3));
  booster->SetupPanel();
  }

void init(Byte v) {
  clockMi = 0;
  clockUt = 8 * 3600;
  clockTb = 0;
  engines = 0;
  launched = false;
  kscAngle = 0;
  simSpeed = 1000000;
  if (v == 1) mercuryRedstone();
  if (v == 2) geminiTitan();
  if (v == 3) saturnV();
  booster->Gravitation(3.9857605e14);
  booster->SetupPanel();
  }

void cycle() {
Vector vu;
Vector vl;
Vector vf;
  clockUt++;
  kscAngle += 0.00417807464;
  if (kscAngle >= 180) kscAngle -= 360;
  if (!launched) {
    pos = Vector(sin(kscAngle*DR)*0.878817113,
                -cos(kscAngle*DR)*0.878817113, 0.477158760).Norm();
    pos = pos.Scale(6378100);
  vu = booster->Position().Norm();
  vl = Vector(vu.Y(), -vu.X(), 0).Norm();
  vf = vu.Cross(vl);
  booster->FaceUp(vu);
  booster->FaceLeft(vl);
  booster->FaceFront(vf);
    booster->Position(pos);
    booster->UpdatePanel();
    }
  else {
    clockMi++;
    if (booster->EnginesLit() != 0) {
      clockBu++;
      clockTb++;
      }
    booster->Cycle();
    booster->UpdatePanel();
    }
  }

void Launch() {
  Vector vu;
  Vector vl;
  Vector vf;
  booster->Ignition();
  vu = booster->Position().Norm();
  vl = Vector(vu.Y(), -vu.X(), 0).Norm();
  vf = vu.Cross(vl);
//GotoXY(1,26); printf("U: %.4f %.4f %.4f\n",vu.X(),vu.Y(),vu.Z());
//GotoXY(1,27); printf("L: %.4f %.4f %.4f\n",vl.X(),vl.Y(),vl.Z());
//GotoXY(1,28); printf("F: %.4f %.4f %.4f\n",vf.X(),vf.Y(),vf.Z());
  booster->FaceUp(vu);
  booster->FaceLeft(vl);
  booster->FaceFront(vf);
  booster->Velocity(vl.Neg().Scale(408));
  launched = true;
  }

int main(int argc, char** argv) {
  char buffer[32];
  UInt32 v;
  Boolean flag;
  UInt32  key;
  printf("1. Mercury/Redstone\n");
  printf("2. Gemini/Titan\n");
  printf("3. Apollo/Saturn V\n");
  printf("   Vehicle: ");
  fgets(buffer,31,stdin);
  v = atoi(buffer);

  init(v);
  OpenTerminal();
  HideCursor();
  flag = true;
  while (flag) {
    while (KeyPressed()) {
      key = Inkey();
      if (key == 'Q') flag = false;
      if (key == 'I' && launched) booster->Ignition();
      if (key == 'L' && !launched) Launch();
      if (key == 'S' && launched) booster->NextStage();
      booster->ProcessKey(key);
      }
    cycle();
    usleep(simSpeed);
    }
  ShowCursor();
  CloseTerminal();
  return 0;
  }

