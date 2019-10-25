#define MAIN

#include <stdio.h>
#include <string.h>
#include "header.h"
#include "terminal.h"
#include "computer.h"
#include "lander.h"
#include "g_clockev.h"
#include "g_clockmi.h"
#include "g_clockte.h"
#include "g_clockut.h"
#include "common.h"

#ifdef MINGW
#include <windows.h>
#endif

void setup() {
Vector t;
  pilotLocation = PILOT_CSM;
  csm->Position(Vector(99810+1738300,100,100));
  csm->Velocity(Vector(0,-1634,0.0));
  csm->FaceFront(Vector(1,0,0));
  csm->FaceLeft(Vector(0,-1,0));
  csm->FaceUp(Vector(0,0,1));
  lm->RcsFbMode(' ');
  lm->RcsLrMode(' ');
  lm->RcsUdMode(' ');
  lm->RcsThrottle(1);
  lm->FaceFront(Vector(1,0,0));
  lm->FaceLeft(Vector(0,-1,0));
  lm->FaceUp(Vector(0,0,-1));
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
  clockGe = 0;
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
  }

void setupVehicle() {
  Double dry;
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
  switch (vehicle) {
    case VEHICLE_APOLLO:
//         lm->AscentFuel(2375.0);
//         lm->AscentBattery(10 * 3600);
//         lm->AscentOxygen(10 * 3600);
//         lm->AscentEOxygen(2 * 3600);
//         lm->AscentEBattery(2 * 3600);
//         lm->AscentDryWeight(2179.0);
//         lm->AscentIsp(311.0);
//         lm->AscentNewtons(14314.0);
//         lm->DescentFuel(8248.0);
//         lm->DescentBattery(45 * 3600);
//         lm->DescentOxygen(45 * 3600);
//         lm->DescentEOxygen(10 * 3600);
//         lm->DescentEBattery(10 * 3600);
//         lm->DescentDryWeight(2033.0);
//         lm->DescentIsp(311.0);
//         lm->DescentNewtons(43903.0);
//         lm->RcsFuel(287.0);
//         lm->RcsIsp(290.0);
//         lm->RcsNewtons(1780.0);
         break;
    case VEHICLE_APOLLO_J:
//         lm->AscentFuel(2375.0);
//         lm->AscentBattery(10 * 3600);
//         lm->AscentOxygen(10 * 3600);
//         lm->AscentEOxygen(2 * 3600);
//         lm->AscentEBattery(2 * 3600);
//         lm->AscentDryWeight(2127.0);
//         lm->AscentIsp(311.0);
//         lm->AscentNewtons(14345.0);
//         lm->DescentFuel(8872.5);
//         lm->DescentBattery(75 * 3600);
//         lm->DescentOxygen(75 * 3600);
//         lm->DescentEOxygen(10 * 3600);
//         lm->DescentEBattery(10 * 3600);
//         lm->DescentDryWeight(2802.0);
//         lm->DescentIsp(311.0);
//         lm->DescentNewtons(43903.0);
//         lm->RcsFuel(287.0);
//         lm->RcsIsp(290.0);
//         lm->RcsNewtons(1780.0);
         break;
    case VEHICLE_APOLLO_MKII:
//         lm->AscentFuel(2615.0);
//         lm->AscentBattery(10 * 3600);
//         lm->AscentOxygen(10 * 3600);
//         lm->AscentEOxygen(2 * 3600);
//         lm->AscentEBattery(2 * 3600);
//         lm->AscentDryWeight(2234.0);
//         lm->AscentIsp(344.0);
//         lm->AscentNewtons(16890.0);
//         lm->DescentFuel(9720.0);
//         lm->DescentBattery(110 * 3600);
//         lm->DescentOxygen(110 * 3600);
//         lm->DescentEOxygen(10 * 3600);
//         lm->DescentEBattery(10 * 3600);
//         lm->DescentDryWeight(2346.0);
//         lm->DescentIsp(334.0);
//         lm->DescentNewtons(49215.0);
//         lm->RcsFuel(316.0);
//         lm->RcsIsp(401.0);
//         lm->RcsNewtons(1970.0);
         break;
    case VEHICLE_APOLLO_MKIII:
//         lm->AscentFuel(3500.0);
//         lm->AscentBattery(10 * 3600);
//         lm->AscentOxygen(10 * 3600);
//         lm->AscentEOxygen(2 * 3600);
//         lm->AscentEBattery(2 * 3600);
//         lm->AscentDryWeight(2410.0);
//         lm->AscentIsp(462.0);
//         lm->AscentNewtons(18000.0);
//         lm->DescentFuel(13000.0);
//         lm->DescentBattery(110 * 3600);
//         lm->DescentOxygen(110 * 3600);
//         lm->DescentEOxygen(10 * 3600);
//         lm->DescentEBattery(10 * 3600);
//         lm->DescentDryWeight(2546.0);
//         lm->DescentIsp(462.0);
//         lm->DescentNewtons(53500.0);
//         lm->RcsFuel(325.0);
//         lm->RcsIsp(340.0);
//         lm->RcsNewtons(2150.0);
         break;
    }
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
  if (mission->Rover() == 0) lrv->MaxBattery(0.0);
  if (mission->Rover() == 1) lrv->MaxBattery(35000.0);
  if (mission->Rover() == 2) lrv->MaxBattery(200000.0);
  if (mission->Rover() == 3) lrv->MaxBattery(1000000.0);
  if (mission->Rover() == 1) lrv->MaxSpeed(4.0);
  if (mission->Rover() == 2) lrv->MaxSpeed(6.0);
  if (mission->Rover() == 3) lrv->MaxSpeed(12.0);
  if (mission->Rover() == 3) lrv->Oxygen(72 * 3600);
  lrv->MaxBattery(lrv->Battery());
  lrv->MaxOxygen(lrv->Oxygen());
  }

Boolean alignedForDocking() {
  Vector v;
  Double ax,ay,rx;
  v = lm->RelVel();
  dockingVel = v.Z();
  dockingLVel = sqrt(v.X()*v.X() + v.Y()*v.Y());
  dockingXAlign = lm->RelPos().X();
  dockingYAlign = lm->RelPos().Y();
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
  UInt32 i;
  Vector v,v1;
  for (i=0; i<GRAN; i++) {
    csm->Cycle();
    lm->Cycle();
    if (docked) {
      lm->Position(csm->Position() + Vector(0,0,5.3));
      lm->Velocity(csm->Velocity());
      ((Spacecraft*)lm)->Altitude(((Spacecraft*)csm)->Altitude());
      lm->Latitude(csm->Latitude());
      lm->Longitude(csm->Longitude());
      ((Spacecraft*)lm)->Radius(((Spacecraft*)csm)->Radius());
      }
    plss->Cycle();
    if (lrv->IsSetup()) lrv->Cycle();
    if (!docked && pilotLocation == PILOT_LM) {
      if (lm->RelPos().Length() < 5.275) {
        if (alignedForDocking()) {
          lm->Velocity(csm->Velocity());
          docked = -1;
          seq->Dock();
          }
        else {
          v = lm->RelVel();
          if (v.Length() > 2) {
            ClrScr();
            WriteLn("Collision with the CSM destroyed both vehicles!!!");
            endReason = END_COLLISION;
            run = false;
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
    if (lm->Comp() != NULL) lm->Comp()->PCycle();
    if (lm != NULL) lm->GetIns()->FastCycle();
    }
  csm->Ins();
  seq->Cycle();
  if (lm != NULL) {
    lm->Ins();
    if (lm->Comp() != NULL) {
      lm->Comp()->SCycle();
      lm->Comp()->VnCycle();
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
  if (pilotLocation == PILOT_CSM && clockMi > 0) {
    endReason = END_MISSION;
    run = false;
    }
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
  int missionPos;
  Boolean newGame;;
  char buffer[128];
  Double d;
  FILE* file;
  newGame = false;
  simSpeed = 100000;
  vehicle = VEHICLE_APOLLO;
  WriteLn(""); WriteLn(""); WriteLn(""); WriteLn("");
  WriteLn(TITLE);
  WriteLn(""); WriteLn(""); WriteLn(""); WriteLn("");
  Earth = NULL;
  Moon = new Body("Moon", 7.34767309e+22, 1738300);
  csm = new CommandModule();
  lm = new LunarModule();
  lm->Comp(new Computer(lm,"core.lm"));
  plss = new Plss();
  lrv = new Lrv();
  seq = new Sequencer();
  csm->Orbiting(Moon);
  lm->Orbiting(Moon);
  plss->Orbiting(Moon);
  lrv->Orbiting(Moon);
  csm->TargetVehicle(lm);
  lm->TargetVehicle(csm);
  lrv->TargetVehicle(lm);
  plss->TargetVehicle(lm);
  map = new Map();
  mission = new Mission();
  missionPos = -1;
  for (i=1; i<argc; i++) {
    if (strcmp(argv[i],"-n") == 0) newGame = true;
    else if (argv[i][0] != '-') missionPos = i;
    }
  setup();
  if (missionPos > 0) {
    strcpy(buffer,argv[missionPos]);
    if (strchr(buffer,'.') == NULL) strcat(buffer,".msn");
    file = fopen(buffer,"r");
    if (file == NULL) {
      printf("\n\n");
      printf("Mission profile \"%s\" could not be found\n\n",buffer);
      exit(1);
      }
    mission->Load(file);
    fclose(file);
    vehicle = mission->Vehicle();
    setupVehicle();
    }
  else if (!newGame) {
    if (load((char*)"lms.sav") == 0) newGame = true;
    }
  if (newGame) {
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
    for (i=0; (UInt32)i<strlen(buffer); i++)
      if (buffer[i] >0 && buffer[i] < 32) buffer[i] = 0;
    mission->Name(buffer);
    vehicle = 0;
    while (vehicle < 1 || vehicle > 4) {
      WriteLn("Vehicle:");
      WriteLn("  1. Apollo");
      WriteLn("  2. Apollo-J");
      WriteLn("  3. Apollo Mk II");
      WriteLn("  4. Apollo Mk III");
      fgets(buffer,20,stdin);
      sscanf(buffer,"%d",&i);
      vehicle = i;
      }
    mission->Vehicle(vehicle);
    setupVehicle();
    }
  setupTargetData();
  OpenTerminal();
  HideCursor();
  if (pilotLocation == PILOT_CSM) {
    currentVehicle = csm;
    }
  if (pilotLocation == PILOT_LM) {
    currentVehicle = lm;
    }
  if (pilotLocation == PILOT_EVA) {
    currentVehicle = plss;
    }
  if (pilotLocation == PILOT_LRV) {
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
      if (!lm->Landed() && lm->DescentJettisoned() && !docked) clockDk++;
      if (lm->Throttle() != 0) clockBu++;
      if (!docked) {
        clockMi++;
        clockGe = clockMi;
        if (pilotLocation == PILOT_LM) lm->UseBattery(1);
          else lm->UseBattery(0.3);
        if (pilotLocation == PILOT_LM && cabinPressurized) {
          lm->UseOxygen(1);
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
        if (pilotLocation == PILOT_LRV && mission->Rover() == 3) {
          if (lrv->UseOxygen(1) == false) {
            plss->UseOxygen(1);
            plss->UseBattery(1);
            }
          }
        else {
          plss->UseOxygen(1);
          plss->UseBattery(1);
          }
        if (plss->Oxygen() + plss->EOxygen() <= 0) injury += 0.3;
        if (plss->Battery() + plss->EBattery() <= 0) injury += 0.1;
        }
      cycle();
      ticks = 0;
      if (injury >= 100) {
        run = false;
        endReason = END_DEAD;
        }
      }
    else ticks++;
    if (keyDelay > 0) keyDelay--;
#ifdef MINGW
    Sleep(simSpeed / 1000);
#else
    usleep(simSpeed);
#endif
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
    fprintf(file,"Manmade Wreckage,       %10.4f, %10.4f, 0, 0.00, &%s",
      lm->Latitude(), lm->Longitude(),LE);
    fclose(file);
    unlink("lms.sav");
    }
  if (endReason == END_MISSION) {
    Score();
    MissionReport();
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
    unlink("lms.sav");
    }
  delete(csm);
  delete(lm);
  delete(seq);
  delete(mission);
  return 0;
  }

