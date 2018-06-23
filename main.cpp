#define MAIN

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "terminal.h"
#include "computer.h"

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
  lm->EBattery(216000.0);
  lm->EOxygen(432000.0);
  lm->RcsFbMode(' ');
  lm->RcsLrMode(' ');
  lm->RcsUdMode(' ');
  lm->RcsFuel(FUEL_RCS);
  lm->RcsThrottle(1);
  lm->FaceFront(Vector(1,0,0));
  lm->FaceLeft(Vector(0,-1,0));
  lm->FaceUp(Vector(0,0,-1));
  lm->MaxBattery(LM_BATTERY);
  lm->MaxOxygen(LM_OXYGEN);
  plss->Battery(36000);
  plss->Oxygen(36000);
  plss->FaceFront(Vector(1,0,0));
  plss->FaceLeft(Vector(0,-1,0));
  plss->FaceUp(Vector(0,0,-1));
  plss->MaxSpeed(1.5);
  plss->MaxBattery(PLSS_BATTERY);
  plss->MaxOxygen(PLSS_OXYGEN);
  lrv->Battery(LRV_BATTERY);
  lrv->FaceFront(Vector(1,0,0));
  lrv->FaceLeft(Vector(0,-1,0));
  lrv->FaceUp(Vector(0,0,-1));
  lrv->Boxes(8);
  lrv->MaxSpeed(6.0);
  lrv->MaxBattery(LRV_BATTERY);
  cabinPressurized = -1;
  clockBu = 0;
  clockDk = 0;
  clockEv = 0;
  clockMi = 0;
  clockOr = 0;
  clockUt = (8 * 3600) + (30 * 60);
  clockUd = 0;
  clockTe = 0;
  evaCount = 0;
  longestEVA = 0;
  docked = -1;
  dockingRadarOn = 0;
  dsnOn = 0;
  efficiency = 99;
  injury = 0;
  insMode = INS_MODE_POS_ABS;
  landingRadarOn = 0;
  metabolicRate = 30.0;
  numSamples = 0;
  mission->TargetLatitude(0.0);
  mission->TargetLongitude(0.0);
  plssOn = 0;
  plssPacks = 4;
  spaceSuitOn = 0;
  sampleSmallRock = 0;
  sampleMediumRock = 0;
  sampleLargeRock = 0;
  sampleSmallCrater = 0;
  sampleMediumCrater = 0;
  sampleLargeCrater = 0;
  samplePlains = 0;
  sampleRise = 0;
  lrvSampleSmallRock = 0;
  lrvSampleMediumRock = 0;
  lrvSampleLargeRock = 0;
  lrvSampleSmallCrater = 0;
  lrvSampleMediumCrater = 0;
  lrvSampleLargeCrater = 0;
  lrvSamplePlains = 0;
  lrvSampleRise = 0;
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
  }

char* ClockToString(char* buffer, Int32 clock) {
  Int32 hours, minutes, seconds;
  hours = clock / 3600;
  clock -= (hours * 3600);
  minutes = clock / 60;
  seconds = clock - (minutes * 60);
  sprintf(buffer,"%3d:%02d:%02d",hours,minutes,seconds);
  return buffer;
  }

Boolean alignedForDocking() {
  Vector v;
  Double ax,ay,rx;
  v = ins->RelVel();
  dockingVel = v.Z();
  dockingLVel = sqrt(v.X()*v.X() + v.Y()*v.Y());
  if (dockingVel > -0.2) return false;
  if (dockingVel < -0.4) return false;
  if (dockingLVel >0.0283) return false;
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
    lm->Cycle();
    lm->Position(csm->Position() + Vector(0,0,19));
    lm->Velocity(csm->Velocity());
    lm->Altitude(csm->Altitude());
    lm->Latitude(csm->Latitude());
    lm->Longitude(csm->Longitude());
    lm->Radius(csm->Radius());
    }
  else lm->Cycle();
  plss->Cycle();
  if (lrv->IsSetup()) lrv->Cycle();
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
          WriteLn("Collision with the CSM destroyed both vehicles!!!");
          endReason = END_COLLISION;
          run = false;
//          ShowCursor();
//          CloseTerminal();
//          exit(0);
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
  if (metabolicRate > 99) metabolicRate = 99;
  softInjury += 0.000347222;
  if (softInjury > 100) softInjury = 100;
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

void setupTargetData() {
  Vector L;
  Double hyp;
  Double x,y,z;
  Double c,s;
  c = -1680.226342 * cos(mission->TargetLongitude()*M_PI/180);
  s = -1680.226342 * sin(mission->TargetLongitude()*M_PI/180);
  z = sin(mission->TargetLatitude()*M_PI/180);
  x = sin(mission->TargetLongitude()*M_PI/180) *
      cos(mission->TargetLatitude()*M_PI/180);
  y = -cos(mission->TargetLongitude()*M_PI/180) *
       cos(mission->TargetLatitude()*M_PI/180);
  targetPos = Vector(x*GROUND,y*GROUND,z*GROUND).Norm();
  targetVel = Vector(c,s,0).Norm();
  L = targetVel.Cross(targetPos).Norm();
  hyp = sqrt(L.X() * L.X() + L.Y() * L.Y());
  targetMomEast = L.Y() / hyp;
  targetMomEast = asin(targetMomEast) * 180 / M_PI;
  if (L.X() < 0 && L.Y() < 0) targetMomEast = -180 - targetMomEast;
  if (L.X() < 0 && L.Y() >= 0) targetMomEast = 180 - targetMomEast;
  while (targetMomEast < -180) targetMomEast += 360;
  while (targetMomEast > 180) targetMomEast -= 360;
  hyp = sqrt(L.Z() * L.Z() + hyp * hyp);
  targetMomNorth = L.Z() / hyp;
  targetMomNorth = asin(targetMomNorth) * 180 / M_PI;

  L = csm->Velocity().Norm().Cross(csm->Position().Norm());
  hyp = sqrt(L.X() * L.X() + L.Y() * L.Y());
  csmMomEast = L.Y() / hyp;
  csmMomEast = asin(csmMomEast) * 180 / M_PI;
  if (L.X() < 0 && L.Y() < 0) csmMomEast = -180 - csmMomEast;
  if (L.X() < 0 && L.Y() >= 0) csmMomEast = 180 - csmMomEast;
  hyp = sqrt(L.Z() * L.Z() + hyp * hyp);
  csmMomNorth = L.Z() / hyp;
  csmMomNorth = asin(csmMomNorth) * 180 / M_PI;
  }

void test() {
  Vector v;
  Double h;
  Int32  i;
  Double lat;
  Double lng;
  char buffer[80];
  lng = 10;
  lat = 10;
  for (i=-180; i<180; i+=10) {
    h = i;
    v = Vector(sin(h*DR), 0, cos(h*DR));
    v = Vector( v.X(),
                -(v.Y()*cos(lat*DR) + v.Z()*-sin(lat*DR)),
                v.Y()*sin(lat*DR) + v.Z()*cos(lat*DR));
    v = Vector( v.X()*cos(lng*DR) + v.Y()*-sin(lng*DR),
                v.X()*sin(lng*DR) + v.Y()*cos(lng*DR),
                v.Z());
    printf(buffer,"H: %d  V: %f %f %f\n",i,v.X(),v.Y(),v.Z());
    Write(buffer);
    }
  }

int main(int argc, char** argv) {
  int i;
  int key;
  char buffer[128];
  Double d;
  FILE* file;
  simSpeed = 100000;
  WriteLn(""); WriteLn(""); WriteLn(""); WriteLn("");
  WriteLn(TITLE);
  WriteLn(""); WriteLn(""); WriteLn(""); WriteLn("");
  csm = new CSM();
  lm = new LunarModule();
  lm->Comp(new Computer(lm));
  plss = new Plss();
  lrv = new Lrv();
  ins = new INS();
  seq = new Sequencer();
  map = new Map();
  mission = new Mission();
  setup();
  if (load((char*)"lms.sav") == 0) {
    d = -9999.99;
    while (d <-90 || d > 90) {
      Write("Target latitude: ");
      fgets(buffer,64,stdin);
      sscanf(buffer,"%lf",&d);
      }
    mission->TargetLatitude(d);
    d = -9999.99;
    while (d <-180 || d > 180) {
      Write("Target longitude: ");
      fgets(buffer,64,stdin);
      sscanf(buffer,"%lf",&d);
      }
    mission->TargetLongitude(d);
    Write("Mission Title: ");
    fgets(buffer,128,stdin);
    for (i=0; i<strlen(buffer); i++)
      if (buffer[i] >0 && buffer[i] < 32) buffer[i] = 0;
    mission->Name(buffer);
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
  if (pilotLocation == PILOT_LRV) {
    ins->Spacecraft(lrv);
    ins->Target(lm);
    currentVehicle = lrv;
    }
  currentVehicle->SetupPanel();
  run = true;
  ticks = 10;
  keyDelay = 0;
  currentVehicle->UpdatePanel();
  while (run) {
    if (ticks >= 10) {
      clockUt++;
      while (clockUt >= 86400) clockUt -= 86400;
      if (lm->Throttle() != 0) clockBu++;
      if (!docked) {
        clockMi++;
        if (pilotLocation == PILOT_LM) lm->UseBattery(1);
          else lm->UseBattery(0.3);
        if (pilotLocation == PILOT_LM && cabinPressurized) {
          lm->UseOxygen(1);
          if (!lm->Landed() && lm->DescentJettisoned() && !docked) clockDk++;
          if (lm->Oxygen() + lm->EOxygen() <= 0) injury += 0.3;
          if (lm->Battery() + lm->EBattery() <= 0) injury += 0.1;
          }
        else if (pilotLocation == PILOT_LM && cabinPressurized == 0) {
          plss->UseOxygen(1);
          plss->UseBattery(1);
          if (plss->Oxygen() + plss->EOxygen() <= 0) injury += 0.3;
          if (plss->Battery() + plss->EBattery() <= 0) injury += 0.1;
          }
        }
      if (pilotLocation == PILOT_EVA || pilotLocation == PILOT_LRV) {
        clockEv++;
        clockTe++;
        plss->UseOxygen(1);
        plss->UseBattery(1);
        if (plss->Oxygen() + plss->EOxygen() <= 0) injury += 0.3;
        if (plss->Battery() + plss->EBattery() <= 0) injury += 0.1;
        }
      cycle();
      ticks = 0;
      seq->Cycle();
      if (injury >= 100) {
        run = false;
        endReason = END_DEAD;
        }
      }
    else ticks++;
    if (keyDelay > 0) keyDelay--;
    usleep(simSpeed);
    if (KeyPressed() && keyDelay == 0) {
      keyDelay = (99 - efficiency) / 2;
      metabolicRate += 0.3;
      if (metabolicRate > 90) metabolicRate = 90;
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
        if (key == 'Q') { run = false; endReason = END_QUIT; }
        currentVehicle->ProcessKey(key);
        }
      }
    }
  save();
  GotoXY(1,25);
  ShowCursor();
  CloseTerminal();
  if (endReason == END_CRASHED) {
    ClrScr();
    WriteLn("Crash!!!!");
    WriteLn("You hit the lunar surface with a vertial velocity");
    sprintf(buffer,"of %.1f m/s and a horizontal velocity of %.1f m/s",
            landedVVel,landedHVel);
    WriteLn(buffer);
    WriteLn("");
    WriteLn("This exceeds the tolerance of the spacecraft.  As a");
    WriteLn("result the spacecraft has been destroyed.");
    WriteLn("");
    file = fopen("userref.txt","a+");
    fprintf(file,"Feature Wreckage,       %10.4f, %10.4f, 0, &%s",
      lm->Latitude(), lm->Longitude(),LE);
    fclose(file);
    }
  if (endReason == END_MISSION) {
    Score();
    MissionReport();
    file = fopen("userref.txt","a+");
    fprintf(file,"Feature Descent Module, %10.4f, %10.4f, 0, =%s",
      landedLatitude, landedLongitude,LE);
    if (lrv->IsSetup()) 
      fprintf(file,"Feature Rover,          %10.4f, %10.4f, 0, %%%s",
        lrv->Latitude(), lrv->Longitude(),LE);
    if (flagPlanted) 
      fprintf(file,"Feature Flag,           %10.4f, %10.4f, 0, f%s",
        flagLatitude, flagLongitude,LE);
    if (laserSetup) 
      fprintf(file,"Feature Laser Refl.,    %10.4f, %10.4f, 0, _%s",
        laserLatitude, laserLongitude,LE);
    if (alsepSetup) 
      fprintf(file,"Feature ALSEP,    %10.4f, %10.4f, 0, \"%s",
        alsepLatitude, alsepLongitude,LE);
    fclose(file);
    }
  delete(csm);
  delete(lm);
  delete(seq);
  delete(mission);
  return 0;
  }

