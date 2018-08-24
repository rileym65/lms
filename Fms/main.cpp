#define MAIN

#include "header.h"
#include "g_clockbu.h"
#include "g_clockmi.h"
#include "g_clocktb.h"
#include "g_clockut.h"
#include "g_days.h"
#include "g_moon.h"
#include "g_position.h"

double mn,mx;

void mercuryRedstone() {
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
  booster->Diameter(1,1.78);
  booster->MaxFuel(1, booster->Fuel(1));
  csm->DryWeight(1341);
  csm->Diameter(1.78);
  csm->ParachuteDiameter(19.2);
  csm->RetroModuleDryWeight(32);
  csm->RetroModuleFuel(60);
  csm->RetroModuleIsp(230);
  csm->RetroModuleThrust(4450);
  csm->CommandModuleRcsFuel(25);
  csm->CommandModuleRcsIsp(167);
  csm->CommandModuleRcsThrust(107);
  csm->Oxygen(36 * 3600);
  csm->Battery(36 * 3600);
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void mercuryAtlas() {
  booster->NumStages(2);
  booster->Payload(1400);
  booster->Stage(1);

  booster->Diameter(1,1.78);
  booster->DryWeight(1, 3050);
  booster->Fuel(1, 90923);
  booster->NumEngines(1, 3);
  booster->IspVac(1, 1, 309);
  booster->IspVac(1, 2, 282);
  booster->IspVac(1, 3, 282);
  booster->IspSl(1, 1, 215);
  booster->IspSl(1, 2, 248);
  booster->IspSl(1, 3, 248);
  booster->ThrustVac(1, 1, 363220);
  booster->ThrustVac(1, 2, 758700);
  booster->ThrustVac(1, 3, 758700);
  booster->ThrustSl(1, 1, 252700);
  booster->ThrustSl(1, 2, 667200);
  booster->ThrustSl(1, 3, 667200);
  booster->Starts(1,1);

  booster->Diameter(2,1.78);
  booster->DryWeight(2, 2347);
  booster->Fuel(2, 19780);
  booster->NumEngines(2, 1);
  booster->IspVac(2, 1, 309);
  booster->IspSl(2, 1, 215);
  booster->ThrustVac(2, 1, 363220);
  booster->ThrustSl(2, 1, 252700);
  booster->Starts(2,1);

  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  csm->DryWeight(1341);
  csm->Diameter(1.78);
  csm->ParachuteDiameter(19.2);
  csm->RetroModuleDryWeight(32);
//  csm->RetroModuleFuel(205);
  csm->RetroModuleFuel(60);
  csm->RetroModuleIsp(230);
  csm->RetroModuleThrust(4450);
  csm->CommandModuleRcsFuel(25);
  csm->CommandModuleRcsIsp(167);
  csm->CommandModuleRcsThrust(107);
  csm->Oxygen(36 * 3600);
  csm->Battery(36 * 3600);
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void geminiTitan() {
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
  booster->Diameter(1, 3.05);
  booster->Diameter(2, 3.05);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  csm->DryWeight(1949);
  csm->Diameter(2.30);
  csm->ParachuteDiameter(25.66);
  csm->ServiceModuleDryWeight(956);
  csm->ServiceModuleFuel(0);
  csm->ServiceModuleIsp(230);
  csm->ServiceModuleThrust(710);
  csm->ServiceModuleRcsIsp(273);
  csm->ServiceModuleRcsThrust(444);
  csm->ServiceModuleRcsDThrust(756);
  csm->ServiceModuleRcsUThrust(888);
  csm->ServiceModuleRcsFuel(322);
  csm->RetroModuleDryWeight(491);
  csm->RetroModuleFuel(100);
  csm->RetroModuleIsp(255);
  csm->RetroModuleThrust(11120);
  csm->CommandModuleRcsFuel(33);
  csm->CommandModuleRcsIsp(283);
  csm->CommandModuleRcsThrust(111);
  csm->Oxygen(14 * 24 * 3600);
  csm->Battery(14 * 24 * 3600);
  csm->ServiceModuleMaxFuel(csm->ServiceModuleFuel());
  csm->ServiceModuleRcsMaxFuel(csm->ServiceModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void saturn1B() {
  booster->NumStages(2);
  booster->DryWeight(1, 42000);
  booster->DryWeight(2, 10600);
  booster->Fuel(1, 399400);
  booster->Fuel(2, 103600);
  booster->Payload(18000);
  booster->Stage(1);
  booster->NumEngines(1, 8);
  booster->NumEngines(2, 1);
  booster->IspSl(1, 1, 255);
  booster->IspSl(1, 2, 255);
  booster->IspSl(1, 3, 255);
  booster->IspSl(1, 4, 255);
  booster->IspSl(1, 5, 255);
  booster->IspSl(1, 6, 255);
  booster->IspSl(1, 7, 255);
  booster->IspSl(1, 8, 255);
  booster->IspVac(1, 1, 289);
  booster->IspVac(1, 2, 289);
  booster->IspVac(1, 3, 289);
  booster->IspVac(1, 4, 289);
  booster->IspVac(1, 5, 289);
  booster->IspVac(1, 6, 289);
  booster->IspVac(1, 7, 289);
  booster->IspVac(1, 8, 289);
  booster->IspSl(2, 1, 200);
  booster->IspVac(2, 1, 420);
  booster->ThrustVac(1, 1, 900000);
  booster->ThrustVac(1, 2, 900000);
  booster->ThrustVac(1, 3, 900000);
  booster->ThrustVac(1, 4, 900000);
  booster->ThrustVac(1, 5, 900000);
  booster->ThrustVac(1, 6, 900000);
  booster->ThrustVac(1, 7, 900000);
  booster->ThrustVac(1, 8, 900000);
  booster->ThrustVac(2, 1, 890000);
  booster->ThrustSl(1, 1, 900000);
  booster->ThrustSl(1, 2, 900000);
  booster->ThrustSl(1, 3, 900000);
  booster->ThrustSl(1, 4, 900000);
  booster->ThrustSl(1, 5, 900000);
  booster->ThrustSl(1, 6, 900000);
  booster->ThrustSl(1, 7, 900000);
  booster->ThrustSl(1, 8, 900000);
  booster->ThrustSl(2, 1, 445000);
  booster->Starts(1,1);
  booster->Starts(2,1);
  booster->Diameter(1, 6.53);
  booster->Diameter(2, 6.53);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  csm->DryWeight(5806);
  csm->Diameter(3.90);
  csm->ParachuteDiameter(42.26);
  csm->ServiceModuleDryWeight(6110);
  csm->ServiceModuleFuel(18413);
  csm->ServiceModuleIsp(314);
  csm->ServiceModuleThrust(91190);
  csm->ServiceModuleRcsIsp(290);
  csm->ServiceModuleRcsFuel(617.79);
  csm->ServiceModuleRcsThrust(1780);
  csm->CommandModuleRcsFuel(74);
  csm->CommandModuleRcsIsp(290);
  csm->CommandModuleRcsThrust(410);
  csm->Oxygen(14 * 24 * 3600);
  csm->Battery(14 * 24 * 3600);
  csm->ServiceModuleMaxFuel(csm->ServiceModuleFuel());
  csm->ServiceModuleRcsMaxFuel(csm->ServiceModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void saturnV() {
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
  booster->Diameter(1, 10.1);
  booster->Diameter(2, 10.1);
  booster->Diameter(3, 6.6);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  booster->MaxFuel(3, booster->Fuel(3));
  csm->DryWeight(5806);
  csm->Diameter(3.90);
  csm->ParachuteDiameter(42.26);
  csm->ServiceModuleDryWeight(6110);
  csm->ServiceModuleFuel(18413);
  csm->ServiceModuleIsp(314);
  csm->ServiceModuleRcsFuel(617.79);
  csm->ServiceModuleThrust(91190);
  csm->ServiceModuleRcsIsp(290);
  csm->ServiceModuleRcsThrust(1780);
  csm->CommandModuleRcsFuel(74);
  csm->CommandModuleRcsIsp(290);
  csm->CommandModuleRcsThrust(410);
  csm->Oxygen(14 * 24 * 3600);
  csm->Battery(14 * 24 * 3600);
  csm->ServiceModuleMaxFuel(csm->ServiceModuleFuel());
  csm->ServiceModuleRcsMaxFuel(csm->ServiceModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void init(Byte v) {
  clockMi = 0;
  clockUt = 8 * 3600;
  clockTb = 0;
  days = 0;
  engines = 0;
  launched = false;
  kscAngle = 0;
  if (v == 1) mercuryRedstone();
  if (v == 2) mercuryAtlas();
  if (v == 3) geminiTitan();
  if (v == 4) saturn1B();
  if (v == 5) saturnV();
  }

void cycle() {
  UInt32 i;
  Vector vu;
  Vector vl;
  Vector vf;
  Vector p,v;
  Double r1;
  Double r2;
  clockUt++;
  if (clockUt >= 86400) {
    clockUt = 0;
    days++;
    }
  kscAngle += 0.00417807464;
  if (kscAngle >= 180) kscAngle -= 360;
  if (!launched) {
    Moon->Cycle(1);
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
    csm->Position(booster->Position());
    csm->FaceUp(booster->FaceUp());
    csm->FaceLeft(booster->FaceLeft());
    csm->FaceFront(booster->FaceFront());
    booster->Ins();
    csm->Ins();
    csm->UpdatePanel();
    }
  else {
    clockMi++;
    if (csm->UseOxygen(1) == false) {
      GotoXY(1,25);
      printf("Astronauts died due to lack of oxygen\n");
      ShowCursor();
      CloseTerminal();
      exit(0);
      }
    if (csm->UseBattery(1) == false) {
      GotoXY(1,25);
      printf("Astronauts died due to lack of power\n");
      ShowCursor();
      CloseTerminal();
      exit(0);
      }
//    if (booster->EnginesLit() != 0) {
    if (csm->Throttle() != 0) {
      clockBu++;
      clockTb++;
      }
    r1 = (csm->Position() - csm->Orbiting()->Position()).Length();
    for (i=0; i<GRAN; i++) {
      Moon->Cycle(GRAN);
      if (!booster->Destroyed()) booster->Cycle();
      if (csm->LaunchVehicleJettisoned()) {
        csm->Cycle();
        if (csm->Radius() <= csm->Orbiting()->Radius()) {
          if (csm->RateOfClimb() <= -11) {
            GotoXY(1,25);
            printf("Vehicle destroyed due to high velocity impact\n");
            ShowCursor();
            CloseTerminal();
            exit(0);
            }
          else {
            GotoXY(1,25);
            printf("Vehicle has safely landed\n");
            ShowCursor();
            CloseTerminal();
            exit(0);
            }
          }
        }
      }
    r2 = (csm->Position() - csm->Orbiting()->Position()).Length();
    csm->RateOfClimb(r2-r1);
    if (!csm->LaunchVehicleJettisoned()) {
      csm->Position(booster->Position());
      csm->Velocity(booster->Velocity());
      csm->FaceUp(booster->FaceUp());
      csm->FaceLeft(booster->FaceLeft());
      csm->FaceFront(booster->FaceFront());
      csm->Latitude(booster->Latitude());
      csm->Longitude(booster->Longitude());
      }
    csm->UpdatePanel();
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
  Earth = new Body("Earth", 5.972e+24, 6378100);
  Moon = new Body("Moon", 7.34767309e+22, 1738300);
  Moon->Position(Vector(325266766, 0, 177193935));
  Moon->Velocity(Vector(0,1060,0));
  Moon->Orbiting(Earth);
  Moon->CalculateOrbit();
  booster = new Booster();
  csm = new CommandModule();
  csm->LaunchVehicle(booster);
  if (load("launch.sav") == 0) {
    printf("1. Mercury/Redstone\n");
    printf("2. Mercury/Atlas\n");
    printf("3. Gemini/Titan\n");
    printf("4. Apollo/Saturn IB\n");
    printf("5. Apollo/Saturn V\n");
    printf("   Vehicle: ");
    fgets(buffer,31,stdin);
    v = atoi(buffer);
    init(v);
    }
  csm->Orbiting(Earth);
  csm->SetupPanel();
  booster->Orbiting(Earth);
  simSpeed = 1000000;
  OpenTerminal();
  HideCursor();
  flag = true;
  while (flag) {
    while (KeyPressed()) {
      key = Inkey();
      if (key == '!') simSpeed = 1000000;
      if (key == '@') simSpeed = 10000;
      if (key == '#') simSpeed = 1000;
      if (key == '$') simSpeed = 100;
      if (key == '%') simSpeed = 10;
      if (key == 'Q') flag = false;
      if (key == 'I' && launched) booster->Ignition();
      if (key == 'L' && !launched) Launch();
      if (key == 'S' && launched) booster->NextStage();
      csm->ProcessKey(key);
      }
    cycle();
    usleep(simSpeed);
    }
  save();
  GotoXY(1,25);
  ShowCursor();
  CloseTerminal();
  return 0;
  }

