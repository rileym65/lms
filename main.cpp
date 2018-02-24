#define MAIN

#include "header.h"
#include "terminal.h"

void setup() {
Vector t;
  pilotLocation = PILOT_CSM;
  csm->Position(Vector(99810+1738300,0,100));
  csm->Velocity(Vector(0,-1634,0.0));
  csm->FaceFront(Vector(0,0,1));
  csm->FaceLeft(Vector(0,-1,0));
  csm->FaceUp(Vector(1,0,0));
  lm->AscentFuel(FUEL_ASC);
  lm->DescentFuel(FUEL_DES);
  lm->Battery(432000.0);
  lm->Oxygen(432000.0);
  lm->RcsFbMode(' ');
  lm->RcsLrMode(' ');
  lm->RcsUdMode(' ');
  lm->RcsFuel(FUEL_RCS);
  lm->RcsThrottle(1);
  lm->FaceFront(Vector(1,0,0));
  lm->FaceLeft(Vector(0,-1,0));
  lm->FaceUp(Vector(0,0,-1));
  plss->Battery(36000);
  plss->Oxygen(36000);
  plss->FaceFront(Vector(1,0,0));
  plss->FaceLeft(Vector(0,-1,0));
  plss->FaceUp(Vector(0,0,-1));
  lrv->Battery(LRV_BATTERY);
  lrv->FaceFront(Vector(1,0,0));
  lrv->FaceLeft(Vector(0,-1,0));
  lrv->FaceUp(Vector(0,0,-1));
  lrv->Boxes(8);
  cabinPressurized = -1;
  clockBu = 0;
  clockDk = 0;
  clockEv = 0;
  clockMi = 0;
  clockOr = 0;
  clockUt = (8 * 3600) + (30 * 60);
  docked = -1;
  dockingRadarOn = 0;
  dsnOn = 0;
  efficiency = 75;
  injury = 0;
  insMode = INS_MODE_POS_ABS;
  landingRadarOn = 0;
  lrvBattery = LRV_BATTERY;
  metabolicRate = 30.0;
  targetLatitude = 0.0;
  targetLongitude = 0.0;
  plssOn = 0;
  plssPacks = 4;
  spaceSuitOn = 0;
  }

Boolean alignedForDocking() {
  Vector v;
  Double ax,ay,rx;
  v = ins->RelVel();
  if (v.Z() > -0.2) return false;
  if (v.Z() < -0.4) return false;
  ax = asin(lm->FaceUp().Y()) * 180 / M_PI;
  ay = asin(lm->FaceUp().X()) * 180 / M_PI;
  rx = asin(lm->FaceLeft().X()) * 180 / M_PI;
  if (fabs(ax) <= 0.5 && fabs(ay) <= 0.5 && fabs(rx) <= 0.5) return true;
  return false;
  }

void cycle() {
  Vector v,v1;
  csm->Cycle();
  if (docked) {
    lm->Position(csm->Position() + Vector(0,0,19));
    lm->Velocity(csm->Velocity());
    lm->Altitude(csm->Altitude());
    lm->Latitude(csm->Latitude());
    lm->Longitude(csm->Longitude());
    lm->Radius(csm->Radius());
    }
  else lm->Cycle();
  plss->Cycle();
  ins->Cycle();
  if (!docked && pilotLocation == PILOT_LM) {
    if (ins->RelPos().Length() < 19) {
      if (alignedForDocking()) {
        lm->Velocity(csm->Velocity());
        docked = -1;
        seq->Dock();
        }
      else {
        v = ins->RelVel();
        if (v.Length() > 2) {
          ClrScr();
          printf("Collision with the CSM destroyed both vehicles!!!\n");
          ShowCursor();
          CloseTerminal();
          exit(0);
          }
        else {
          lm->Position(lm->Position() - v);
          lm->Velocity(lm->Velocity() - v);
          v = v.Scale(0.5);
          csm->Velocity(csm->Velocity() + v);
          lm->Velocity(lm->Velocity() - v);
          }
        }
      }
    }
  currentVehicle->UpdatePanel();
  }

void setupTargetData() {
  Vector L;
  Double hyp;
  Double x,y,z;
  Double c,s;
  c = -1680.226342 * cos(targetLongitude*M_PI/180);
  s = -1680.226342 * sin(targetLongitude*M_PI/180);
  z = sin(targetLatitude*M_PI/180);
  x = sin(targetLongitude*M_PI/180) * cos(targetLatitude*M_PI/180);
  y = -cos(targetLongitude*M_PI/180) * cos(targetLatitude*M_PI/180);
  targetPos = Vector(x*GROUND,y*GROUND,z*GROUND);
  targetVel = Vector(c,s,0);
  L = targetVel.Cross(targetPos).Norm();
  hyp = sqrt(L.X() * L.X() + L.Y() * L.Y());
  targetMomEast = L.X() / hyp;
  targetMomEast = acos(targetMomEast) * 180 / M_PI;
  if (targetMomEast <= -180) targetMomEast += 360;
  if (targetMomEast >= 180) targetMomEast -= 360;
  targetMomNorth = asin(L.Z()) * 180 / M_PI;
  }

int main(int argc, char** argv) {
  int key;
  char buffer[64];
  simSpeed = 100000;
  csm = new CSM();
  lm = new LunarModule();
  plss = new Plss();
  lrv = new Lrv();
  ins = new INS();
  seq = new Sequencer();
  setup();
  if (load((char*)"lms.sav") == 0) {
    targetLatitude = -9999.99;
    while (targetLatitude <-90 || targetLatitude > 90) {
      printf("Target latitude: ");
      fgets(buffer,64,stdin);
      sscanf(buffer,"%lf",&targetLatitude);
      }
    targetLongitude = -9999.99;
    while (targetLongitude <-180 || targetLongitude > 180) {
      printf("Target longitude: ");
      fgets(buffer,64,stdin);
      sscanf(buffer,"%lf",&targetLongitude);
      }
    }
  setupTargetData();
  OpenTerminal();
  HideCursor();
  if (pilotLocation == PILOT_CSM) {
    ins->Spacecraft(csm);
    ins->Target(lm);
    currentVehicle = csm;
    }
  if (pilotLocation == PILOT_LM) {
    ins->Spacecraft(lm);
    ins->Target(csm);
    currentVehicle = lm;
    }
  if (pilotLocation == PILOT_EVA) {
    ins->Spacecraft(plss);
    ins->Target(lm);
    currentVehicle = plss;
    }
  currentVehicle->SetupPanel();
  run = true;
  ticks = 10;
  currentVehicle->UpdatePanel();
  while (run) {
    if (ticks >= 10) {
      clockUt++;
      while (clockUt >= 86400) clockUt -= 86400;
      if (lm->Throttle() != 0) clockBu++;
      if (!docked) {
        clockMi++;
        lm->Battery(lm->Battery() - 1);
        if (pilotLocation == PILOT_LM) {
          lm->Oxygen(lm->Oxygen() - 1);
          if (!lm->Landed() && lm->DescentJettisoned() && !docked) clockDk++;
          }
        }
      if (pilotLocation == PILOT_EVA || pilotLocation == PILOT_LRV) {
        clockEv++;
        plss->Oxygen(plss->Oxygen() - 1);
        plss->Battery(plss->Battery() - 1);
        }
      cycle();
      ticks = 0;
      seq->Cycle();
      }
    else ticks++;
    usleep(simSpeed);
    if (KeyPressed()) {
      key = Inkey();
      if (key == '!') simSpeed = 100000;
      if (key == '@') simSpeed = 10000;
      if (key == '#') simSpeed = 1000;
      if (key == '$') simSpeed = 100;
      if (key == '%') simSpeed = 10;
      if (seq->Time() == 0) {
        if (key == '1') { insMode = INS_MODE_POS_ABS; ins->Mode(insMode); }
        if (key == '2') { insMode = INS_MODE_POS_TAR; ins->Mode(insMode); }
        if (key == '3') { insMode = INS_MODE_POS_REL; ins->Mode(insMode); }
        if (key == '4') { insMode = INS_MODE_ORB_ABS; ins->Mode(insMode); }
        if (key == '5') { insMode = INS_MODE_ORB_TAR; ins->Mode(insMode); }
        if (key == 'Q') run = false;
        currentVehicle->ProcessKey(key);
        }
      }
    }
  save();
  GotoXY(1,25);
  ShowCursor();
  CloseTerminal();
  delete(csm);
  delete(lm);
  delete(seq);
  return 0;
  }

