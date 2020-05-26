#include "header.h"
#include "computer.h"
#include "csmcomputer.h"
#include "common.h"
#include "flight.h"

Int8 Flight::alignedForDocking() {
  Vector pos;
  Vector vel;
  Double px,py;
  if (lm == NULL) return 0;
  if (csm->FaceUp().Dot(lm->FaceUp()) >= 0) return 0;
  if (fabs(csm->FaceFront().Dot(lm->FaceUp())) > 0.150) return 0;
  if (fabs(csm->FaceLeft().Dot(lm->FaceUp())) > 0.150) return 0;
  if (fabs(csm->FaceFront().Dot(lm->FaceLeft())) > 0.150) return 0;
  pos = csm->Position() - lm->Position();
  px = pos.Norm().Dot(lm->FaceLeft()) * pos.Length();
  py = pos.Norm().Dot(lm->FaceFront()) * pos.Length();
  if (fabs(px) > 0.5) return 0;
  if (fabs(py) > 0.5) return 0;
  vel = csm->Velocity() - lm->Velocity();
  if (vel.Length() < 0.2) return 0;
  if (vel.Length() > 0.4) return 0;
  return -1;
  }

void Flight::cycle() {
  UInt32 i;
  Vector vu;
  Vector vl;
  Vector vf;
  Vector p,v;
  Vector p1,p2;
  Vector lp1, lp2;
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
    vf = Vector(-vu.Y(), vu.X(), 0).Norm();
    vl = vf.Cross(vu);
    booster->FaceUp(vu);
    booster->FaceLeft(vl);
    booster->FaceFront(vf);
    booster->Position(pos);
    csm->Position(booster->Position()+booster->FaceUp().Scale(booster->Height() + booster->CmOffset()));
    csm->FaceUp(booster->FaceUp());
    csm->FaceLeft(booster->FaceLeft());
    csm->FaceFront(booster->FaceFront());
    if (lm != NULL) {
      lm->Position(booster->Position()+booster->FaceUp().Scale(booster->Height()));
      lm->FaceUp(booster->FaceUp());
      lm->FaceLeft(booster->FaceLeft());
      lm->FaceFront(booster->FaceFront());
      }
    booster->Ins();
    csm->Ins();
    csm->UpdatePanel();
    }
  else {
    clockGe++;
    if (pilotLocation == PILOT_LM && !docked) clockMi++;
    if (pilotLocation == PILOT_LRV || pilotLocation == PILOT_EVA) {
      clockEv++;
      clockTe++;
      clockMi++;
      }
    if (!lm->Landed() && lm->DescentJettisoned() && !docked &&
        pilotLocation == PILOT_LM) clockDk++;
    if (pilotLocation == PILOT_LM && plssOn == 0) {
      if (lm->UseOxygen(1) == false) {
        GotoXY(1,25);
        printf("Astronauts died due to lack of oxygen\n");
        ShowCursor();
        CloseTerminal();
        exit(0);
        }
      if (lm->UseBattery(1) == false) {
        GotoXY(1,25);
        printf("Astronauts died due to lack of power\n");
        ShowCursor();
        CloseTerminal();
        exit(0);
        }
      }
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
    if (pilotLocation == PILOT_LM || pilotLocation == PILOT_CSM) {
      if (currentVehicle->Throttle() != 0) {
        clockBu++;
        clockTb++;
        }
      }
    p1 = csm->Position();
    for (i=0; i<GRAN; i++) {
      Moon->Cycle(GRAN);
      if (!booster->Destroyed()) {
        if (lmExtracted == 0 && docked) {
          }
        else booster->Cycle();
        }
      csm->Cycle();
      if (lm != NULL) {
        if (docked) {
          if (currentVehicle == lm) {
            lp1 = lm->Position() - lm->Orbiting()->Position();
            }
          lm->Position(csm->Position()+csm->FaceUp().Scale(5.275));
          lm->Velocity(csm->Velocity());
          lm->FaceUp(csm->FaceUp().Neg());
          lm->FaceLeft(csm->FaceLeft());
          lm->FaceFront(csm->FaceFront());
          lm->Latitude(csm->Latitude());
          lm->Longitude(csm->Longitude());
          lm->Orbiting(csm->Orbiting());
          if (currentVehicle == lm) {
            lp2 = lm->Position() - lm->Orbiting()->Position();
            lm->AddDistance((lp2-lp1).Length());
            }
          }
        else if (lmExtracted == 0) {
          lm->Position(booster->Position()+booster->FaceUp().Scale(booster->Height()+3.5));
          lm->Velocity(booster->Velocity());
          lm->FaceUp(booster->FaceUp());
          lm->FaceLeft(booster->FaceLeft());
          lm->FaceFront(booster->FaceFront());
          lm->Latitude(booster->Latitude());
          lm->Longitude(booster->Longitude());
          lm->Orbiting(booster->Orbiting());
          }
        else lm->Cycle();
        }
      csm->Computer()->Cycle();
      if (pilotLocation == PILOT_EVA) plss->Cycle();
      if (pilotLocation == PILOT_LRV) lrv->Cycle();
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
          printf("Vehicle has safely landed%s",LE);
          endReason = END_MISSION;
          return;
          }
        }
      if (lm->Comp() != NULL) lm->Comp()->PCycle();
      csm->GetIns()->FastCycle();
      if (lm != NULL) lm->GetIns()->FastCycle();

      }
    if (pilotLocation == PILOT_EVA || pilotLocation == PILOT_LRV) {
      plss->UseOxygen(1);
      plss->UseBattery(1);
      if (plss->Oxygen() + plss->EOxygen() <= 0) injury += 0.3;
      if (plss->Battery() + plss->EBattery() <= 0) injury += 0.1;
      }
    if (!booster->Destroyed()) booster->Ins();
    csm->Ins();
    seq->Cycle();
    if (lm != NULL) {
      lm->Ins();
      if (lm->Comp() != NULL) {
        lm->Comp()->SCycle();
        lm->Comp()->VnCycle();
        }
      }
    if (mission->Vehicle() < 5 && !docked && lm != NULL) {
      if ((csm->Position() - lm->Position()).Length() < 5.275) {
        if (alignedForDocking()) {
          docked = -1;
          seq->Dock();
          if (currentVehicle == csm && clockLmDk == 0)
            clockLmDk = clockGe;
          if (currentVehicle == lm) {
            dockingXAlign = lm->GetIns()->TarDockX();
            dockingYAlign = lm->GetIns()->TarDockY();
            dockingVel = lm->GetIns()->TarDockVelZ();
            dockingLVel = sqrt(
              lm->GetIns()->TarDockVelX() * lm->GetIns()->TarDockVelX() +
              lm->GetIns()->TarDockVelY() * lm->GetIns()->TarDockVelY()
              );
            }
          }
        else {
          v = csm->Velocity() - csm->TargetVehicle()->Velocity();
          csm->Velocity(csm->Velocity() - v);
          csm->Velocity(csm->Velocity() - v.Scale(0.5));
          lm->Velocity(lm->Velocity() + v.Scale(0.5));
          csm->Position(csm->Position() - v);
          lm->Position(lm->Position() + v);
          if (lmExtracted == 0) {
            booster->Velocity(booster->Velocity() + v.Scale(0.5));
            booster->Position(booster->Position() + v);
            }
          }
        }
      }
    
 
    p2 = csm->Position();
    distanceTravelled += (p1 - p2).Length();
    if (metabolicRate > 99) metabolicRate = 99;
    if (pilotLocation != PILOT_CSM) {
      softInjury += 0.000347222;
      if (softInjury > 100) softInjury = 100;
      }
    else
      softInjury = 0;
    injury = softInjury + hardInjury;
    if (metabolicRate > 30.0) metabolicRate -= 0.1;
    if (metabolicRate < 30.0) metabolicRate = 30.0;
    efficiency = 99.0;
    if (metabolicRate < 40) efficiency -= (metabolicRate - 30) / 3;
    else if (metabolicRate < 50) efficiency -= (metabolicRate - 30) / 2;
    else if (metabolicRate < 60) efficiency -= (metabolicRate - 30);
    else efficiency -= ((metabolicRate - 30) * 1.5);
    efficiency -= (injury / 2.0);
    if (efficiency < 20) efficiency = 20;
    currentVehicle->UpdatePanel();
    }
  if (injury >= 100) {
    run = false;
    endReason = END_DEAD;
    }
  }

void Flight::Launch() {
  csm->Launch();
  }

void Flight::geminiTitan() {
  booster->Height(33.2);
  booster->CmOffset(4);
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
  csm->LaunchVehicle(booster);
  }

void Flight::mercuryAtlas() {
  booster->NumStages(2);
  booster->Payload(1400);
  booster->Stage(1);
  booster->Height(28.7);
  booster->CmOffset(2.15);
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
  csm->LaunchVehicle(booster);
  }

void Flight::mercuryRedstone() {
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
  booster->Height(25.41);
  booster->CmOffset(2.15);
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
  csm->LaunchVehicle(booster);
  }

void Flight::saturn1B() {
  csm->DryWeight(5806);
  csm->Diameter(3.90);
  csm->ParachuteDiameter(42.26);
  csm->ServiceModuleDryWeight(6110);
  csm->ServiceModuleFuel(2785);
  csm->ServiceModuleIsp(314);
  csm->ServiceModuleThrust(91190);
  csm->ServiceModuleRcsIsp(290);
  csm->ServiceModuleRcsFuel(617.79);
  csm->ServiceModuleRcsThrust(890);
  csm->ServiceModuleRcsDThrust(1780);
  csm->ServiceModuleRcsUThrust(1780);
  csm->CommandModuleRcsFuel(74);
  csm->CommandModuleRcsIsp(290);
  csm->CommandModuleRcsThrust(410);
  csm->Oxygen(14 * 24 * 3600);
  csm->Battery(14 * 24 * 3600);
  csm->ServiceModuleMaxFuel(18413);
  csm->ServiceModuleRcsMaxFuel(csm->ServiceModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  booster->Payload(csm->Mass());
  booster->Height(42.25);
  booster->CmOffset(17.25);
  booster->NumStages(2);
  booster->DryWeight(1, 42000);
  booster->DryWeight(2, 10600);
  booster->Fuel(1, 399000);
  booster->Fuel(2, 103700);
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
  booster->IspVac(2, 1, 421);
  booster->ThrustVac(1, 1, 900000);
  booster->ThrustVac(1, 2, 900000);
  booster->ThrustVac(1, 3, 900000);
  booster->ThrustVac(1, 4, 900000);
  booster->ThrustVac(1, 5, 900000);
  booster->ThrustVac(1, 6, 900000);
  booster->ThrustVac(1, 7, 900000);
  booster->ThrustVac(1, 8, 900000);
  booster->ThrustVac(2, 1, 1033100);
  booster->ThrustSl(1, 1, 900000);
  booster->ThrustSl(1, 2, 900000);
  booster->ThrustSl(1, 3, 900000);
  booster->ThrustSl(1, 4, 900000);
  booster->ThrustSl(1, 5, 900000);
  booster->ThrustSl(1, 6, 900000);
  booster->ThrustSl(1, 7, 900000);
  booster->ThrustSl(1, 8, 900000);
  booster->ThrustSl(2, 1, 486200);
  booster->Starts(1,1);
  booster->Starts(2,1);
  booster->Diameter(1, 6.53);
  booster->Diameter(2, 6.53);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  csm->LaunchVehicle(booster);
  }

void Flight::saturnV(UInt8 lem) {
  Double pl;
  pl = 30364;
  switch (lem) {
    case      VEHICLE_APOLLO: pl += 15122; break;
    case    VEHICLE_APOLLO_J: pl += 16411; break;
    case VEHICLE_APOLLO_MKII: pl += 17231; break;
    }
  if (lem != 0) {
    lm = new LunarModule();
    lm->Comp(new Computer(lm,"core.lm"));
    }
  booster->Height(85.9);
  booster->CmOffset(17.25);
  booster->NumStages(3);
  booster->DryWeight(1, 130342 + 2447 + 4524);
  booster->DryWeight(2, 36479 + 423 + 3637);
  booster->DryWeight(3, 11357 + 752 + 2027 + 1796);
  booster->Fuel(1, 649508 + 1503381);
  booster->Fuel(2, 382874 + 72779);
  booster->Fuel(3, 19845 + 88738);
  booster->Payload(pl);
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
  booster->Ceco(1, 139);
  booster->Ceco(2, 297);
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
  csm->ServiceModuleRcsThrust(890);
  csm->ServiceModuleRcsDThrust(1780);
  csm->ServiceModuleRcsUThrust(1780);
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
  csm->LaunchVehicle(booster);
  }

void Flight::saturnVb(UInt8 lem) {
  Double pl;
  pl = 30364;
  switch (lem) {
    case      VEHICLE_APOLLO: pl += 15122; break;
    case    VEHICLE_APOLLO_J: pl += 16411; break;
    case VEHICLE_APOLLO_MKII: pl += 17231; break;
    }
  if (lem != 0) {
    lm = new LunarModule();
    lm->Comp(new Computer(lm,"core.lm"));
    }
  booster->Height(85.9);
  booster->CmOffset(17.25);
  booster->NumStages(3);
  booster->DryWeight(1, 130342 + 2447 + 4524);
  booster->DryWeight(2, 36479 + 423 + 3637);
  booster->DryWeight(3, 11357 + 752 + 2027 + 1796);
  booster->Fuel(1, (649508 + 1503381) * 1.05);
  booster->Fuel(2, (382874 + 72779) * 1.025);
  booster->Fuel(3, (19845 + 88738) * 1.02);
  booster->Payload(pl);
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
  booster->Ceco(1, 139);
  booster->Ceco(2, 297);
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
  csm->ServiceModuleFuel(18413 * 1.05);
  csm->ServiceModuleIsp(314);
  csm->ServiceModuleRcsFuel(617.79);
  csm->ServiceModuleThrust(91190);
  csm->ServiceModuleRcsIsp(290);
  csm->ServiceModuleRcsThrust(890);
  csm->ServiceModuleRcsDThrust(1780);
  csm->ServiceModuleRcsUThrust(1780);
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
  csm->LaunchVehicle(booster);
  }

void Flight::Init() {
  Double dry;
  cabinPressurized = -1;
  clockAbort = 0;
  clockBu = 0;
  clockBsp = 0;
  clockDk = 0;
  clockEv = 0;
  clockGe = 0;
  clockMi = 0;
  clockOr = 0;
  clockPara = 0;
  clockUt = (8 * 3600) + (30 * 60);
  clockUd = 0;
  clockMaxQ = 0;
  clockSmJt = 0;
  clockRent = 0;
  clockRmJt = 0;
  clockTb = 0;
  clockTe = 0;
  clockLo = 0;
  clockTli = 0;
  clockTei = 0;
  clockLoi = 0;
  clockMSoi = 0;
  clockESoi = 0;
  clockLmDk = 0;
  clockLExt = 0;
  clockLmJt = 0;
  ignitionApoapsis = 0;
  ignitionPeriapsis = 0;
  ignitionEccentricity = 0;
  lmExtracted = 0;
  evaCount = 0;
  longestEVA = 0;
  docked = 0;
  dockingRadarOn = 0;
  dsnOn = 0;
  efficiency = 99;
  farthestFromEarth = 0;
  highestVelocity = 0;
  inAtmosphere = 0xff;
  injury = 0;
  landingRadarOn = 0;
  maxQ = 0;
  metabolicRate = 30.0;
  plssOn = 0;
  plssPacks = 4;
  rendezvousDistance = 0;
  spaceSuitOn = 0;
  sampleSmallRock = 0;
  sampleMediumRock = 0;
  sampleLargeRock = 0;
  sampleSmallCrater = 0;
  sampleMediumCrater = 0;
  sampleLargeCrater = 0;
  samplePlains = 0;
  sampleRise = 0;
  sampleCraterWall = 0;
  landedMet = 0;
  liftoffMet = 0;
  landedLongitude = 0;
  landedLatitude = 0;
  farthest = 0;
  flagPlanted = 0;
  flagLongitude = 0;
  flagLatitude = 0;
  alsepSetup = 0;
  alsepLongitude = 0;
  alsepLatitude = 0;
  landedHVel = 0;
  landedVVel = 0;
  evas[0].start = 0;
  clockDOI = 0;
  clockPDI = 0;
  numBurns = 0;
  laserSetup = 0;
  laserLongitude = 0;
  laserLatitude = 0;
  mode_abo = 0;
  mode_arm = 0;
  mode_jet = 0;
  mode_kil = 0;
  mode_lif = 0;
  days = 0;
  engines = 0;
  launched = (mission->StartLocation() == 'M') ? true : false;
  kscAngle = 0;
  distanceTravelled = 0;
  if (mission->Vehicle() == VEHICLE_MERCURY_REDSTONE) mercuryRedstone();
  if (mission->Vehicle() == VEHICLE_MERCURY_ATLAS) mercuryAtlas();
  if (mission->Vehicle() == VEHICLE_GEMINI_TITAN) geminiTitan();
  if (mission->Vehicle() == VEHICLE_APOLLO_SATURN_IB) saturn1B();
  if (mission->Vehicle() == VEHICLE_APOLLO_SATURN_V) saturnV(0);
  if (mission->Vehicle() == VEHICLE_APOLLO) saturnV(VEHICLE_APOLLO);
  if (mission->Vehicle() == VEHICLE_APOLLO_J) saturnV(VEHICLE_APOLLO_J);
  if (mission->Vehicle() == VEHICLE_APOLLO_MKII) saturnVb(VEHICLE_APOLLO_MKII);
  pilotLocation = PILOT_CSM;
  csm->TargetVehicle(lm);
  if (lm != NULL) {
    dry = mission->Model()->DescentEmptyWeight();
    if (mission->Laser() != 0) dry += LASER_WEIGHT;
    if (mission->Lsep() == 1) dry += ELSEP_WEIGHT;
    if (mission->Lsep() == 2) dry += ALSEP_WEIGHT;
    if (mission->Rover() == 1) dry += ROVER_MKI_WEIGHT;
    if (mission->Rover() == 2) dry += ROVER_MKII_WEIGHT;
    if (mission->Rover() == 3) dry += ROVER_MKIII_WEIGHT;
    dry += (mission->Consumables() / 3600.0 * 0.060666);
    dry += (mission->Consumables() / 3600.0 * 0.308333);
    dry += (mission->Consumables() / 3600.0 * 0.205833);
    lm->Orbiting(Earth);
    lm->RcsFbMode(' ');
    lm->RcsLrMode(' ');
    lm->RcsUdMode(' ');
    lm->RcsThrottle(1);
    lm->AscentFuel(mission->Model()->AscentFuel());
    lm->AscentDryWeight(mission->Model()->AscentEmptyWeight());
    lm->AscentIsp(mission->Model()->AscentIsp());
    lm->AscentNewtons(mission->Model()->AscentThrust());
    lm->DescentFuel(mission->Model()->DescentFuel());
    lm->DescentBattery(mission->Model()->Consumables());
    lm->DescentOxygen(mission->Model()->Consumables());
    lm->DescentDryWeight(dry);
    lm->DescentIsp(mission->Model()->DescentIsp());
    lm->DescentNewtons(mission->Model()->DescentThrust());
    lm->RcsFuel(mission->Model()->RcsFuel());
    lm->RcsIsp(mission->Model()->RcsIsp());
    lm->RcsNewtons(mission->Model()->RcsThrust());
    lm->AscentBattery(mission->Model()->AscentConsumables());
    lm->AscentOxygen(mission->Model()->AscentConsumables());
    lm->AscentEBattery(mission->Model()->AscentEConsumables());
    lm->AscentEOxygen(mission->Model()->AscentEConsumables());
    lm->DescentEBattery(mission->Model()->EConsumables());
    lm->DescentEOxygen(mission->Model()->EConsumables());
    lm->MaxAscentFuel(lm->AscentFuel());
    lm->MaxDescentFuel(lm->DescentFuel());
    lm->MaxRcsFuel(lm->RcsFuel());
    lm->MaxBattery(lm->AscentBattery() + lm->DescentBattery());
    lm->MaxOxygen(lm->AscentOxygen() + lm->DescentOxygen());
    lm->MaxAscentBattery(lm->AscentBattery());
    lm->MaxAscentEBattery(lm->AscentEBattery());
    lm->MaxAscentOxygen(lm->AscentOxygen());
    lm->MaxAscentEOxygen(lm->AscentEOxygen());
    lm->MaxDescentBattery(lm->DescentBattery());
    lm->MaxDescentEBattery(lm->DescentEBattery());
    lm->MaxDescentOxygen(lm->DescentOxygen());
    lm->MaxDescentEOxygen(lm->DescentEOxygen());
    lm->MaxBattery(lm->MaxAscentBattery() + lm->MaxDescentBattery());
    lm->MaxBattery(lm->MaxAscentOxygen() + lm->MaxDescentOxygen());
    lm->TargetVehicle(csm);
    }
  plss->Battery(36000);
  plss->Oxygen(36000);
  plss->FaceFront(Vector(1,0,0));
  plss->FaceLeft(Vector(0,-1,0));
  plss->FaceUp(Vector(0,0,-1));
  plss->MaxSpeed(3.0);
  plss->MaxBattery(PLSS_BATTERY);
  plss->MaxOxygen(PLSS_OXYGEN);
  lrv->FaceFront(Vector(1,0,0));
  lrv->FaceLeft(Vector(0,-1,0));
  lrv->FaceUp(Vector(0,0,-1));
  lrv->Boxes(8);
  if (mission->Rover() == 1) {
    lrv->MaxSpeed(4.0);
    lrv->Battery(35000);
    lrv->MaxBattery(35000);
    }
  if (mission->Rover() == 2) {
    lrv->MaxSpeed(6.0);
    lrv->Battery(200000);
    lrv->MaxBattery(200000);
    }
  if (mission->Rover() == 3) {
    lrv->MaxSpeed(12.0);
    lrv->Battery(2000000);
    lrv->MaxBattery(2000000);
    }
  if (mission->StartLocation() == 'M') {
    csm->LaunchVehicleJettisoned(true);
    docked = true;
    lmExtracted = -1;
    inAtmosphere = 0;
    lm->Orbiting(Moon);
    csm->Orbiting(Moon);
    csm->Position(Moon->Position()+Vector(99810+1738300,100,100));
    csm->Velocity(Moon->Velocity()+Vector(0,-1634,0.0));
    csm->FaceFront(Vector(1,0,0));
    csm->FaceLeft(Vector(0,-1,0));
    csm->FaceUp(Vector(0,0,1));
    csm->GetPanel()->ResetPanel("csms.pnl");
    }
  }

UInt32 Flight::Fly() {
  UInt32 key;
  FILE *file;
  run = true;
  ticks = 10;
  keyDelay = 0;
  endReason = 0;
  while (run) {
    if (ticks >= 10) {
      ticks = 0;
      cycle();
      }
    else ticks++;
    usleep(simSpeed);
    while (KeyPressed()) {
      key = Inkey();
      if (key == '!') simSpeed = 100000;
      if (key == '@') simSpeed = 10000;
      if (key == '#') simSpeed = 1000;
      if (key == '$') simSpeed = 100;
      if (key == '%') simSpeed = 10;
      if (key == '^') simSpeed = 1;
      if (key == 'Q') {
        run = false;
        endReason = END_QUIT;
        }
      if (key == 'L' && !launched) Launch();
      if (key == 'S' && launched && !csm->LaunchVehicleJettisoned())
        booster->NextStage();
      currentVehicle->ProcessKey(key);
      }
    if (endReason != 0) run = false;
    }
  if (endReason == END_QUIT) {
    save();
    return FLIGHT_SAVE;
    }
  if (endReason == END_MISSION) {
    Score();
    MissionReport();
    if (landedMet > 0) {
      file = fopen("userref.txt","a+");
      fprintf(file,"Manmade Descent Module, %10.4f, %10.4f, 0, 0.00, =%s",
        landedLatitude, landedLongitude,LE);
      if (lrv->IsSetup())
        fprintf(file,"Manmade Rover,          %10.4f, %10.4f, 0, 0.00, %%%s",
          lrv->Latitude(), lrv->Longitude(),LE);
      if (flagPlanted)
        fprintf(file,"Manmade Flag,           %10.4f, %10.4f, 0, 0.00, f%s",
          flagLatitude, flagLongitude,LE);
      if (laserSetup)
        fprintf(file,"Manmade Laser Refl.,    %10.4f, %10.4f, 0, 0.00, _%s",
          laserLatitude, laserLongitude,LE);
      if (alsepSetup)
        fprintf(file,"Manmade ALSEP,          %10.4f, %10.4f, 0, 0.00, \"%s",
          alsepLatitude, alsepLongitude,LE);
      fclose(file);
      }
    unlink("lms.sav");
    return FLIGHT_COMPLETE;
    }

  return 0;
  }

