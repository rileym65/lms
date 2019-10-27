#define MAIN

#include "header.h"
#include "computer.h"
#include "g_clockbu.h"
#include "g_clockev.h"
#include "g_clockmi.h"
#include "g_clocktb.h"
#include "g_clockte.h"
#include "g_clockut.h"
#include "g_days.h"
#include "g_moon.h"
#include "g_position.h"
#include "mission.h"
#include "common.h"
#include "csmcomputer.h"

double mn,mx;

void title() {
  ClrScr();
  GotoXY(25,1); printf("*******************************%s",LE);
  GotoXY(25,2); printf("*** Lunar Mission Simulator ***%s",LE);
  GotoXY(25,3); printf("***           by            ***%s",LE);
  GotoXY(25,4); printf("***      Mike H. Riley      ***%s",LE);
  GotoXY(25,5); printf("*******************************%s",LE);
  printf("\n");
  }

void startFromEarth() {
  UInt32 i;
  UInt32 v;
  char buffer[32];
  mission->StartLocation('E');
  mission->TargetLatitude(0.0);
  mission->TargetLongitude(0.0);
  for (i=6; i<20; i++) {
    GotoXY(1,i);
    printf("%75s"," ");
    }
  v = 0;
  while (v<1 || v > 8) {
    GotoXY(27,  7); printf("1. Mercury/Redstone");
    GotoXY(27,  8); printf("2. Mercury/Atlas");
    GotoXY(27,  9); printf("3. Gemini/Titan");
    GotoXY(27, 10); printf("4. Apollo/Saturn IB");
    GotoXY(27, 11); printf("5. Apollo/Saturn V");
    GotoXY(27, 12); printf("6. Apollo/LM/Saturn V");
    GotoXY(27, 13); printf("7. Apollo/LM-J/Saturn V");
    GotoXY(27, 14); printf("8. Apollo/LM-MkII/Saturn V");
    GotoXY(27, 16); printf("                     ");
    GotoXY(27, 16); printf("   Vehicle: ");
    fgets(buffer,31,stdin);
    v = atoi(buffer);
    }
  if (v == 1) {
    mission->Name("Mercury");
    mission->Description("Mercury/Redstone");
    mission->Vehicle(VEHICLE_MERCURY_REDSTONE);
    mission->Rover(0);
    mission->Lsep(0);
    mission->Laser(0);
    mission->AscentFuel(0);
    mission->DescentFuel(0);
    mission->RcsFuel(0);
    }
  if (v == 2) {
    mission->Name("Mercury");
    mission->Description("Mercury/Atlas");
    mission->Vehicle(VEHICLE_MERCURY_ATLAS);
    mission->Rover(0);
    mission->Lsep(0);
    mission->Laser(0);
    mission->AscentFuel(0);
    mission->DescentFuel(0);
    mission->RcsFuel(0);
    }
  if (v == 3) {
    mission->Name("Gemini");
    mission->Description("Gemini/Titan");
    mission->Vehicle(VEHICLE_GEMINI_TITAN);
    mission->Rover(0);
    mission->Lsep(0);
    mission->Laser(0);
    mission->AscentFuel(0);
    mission->DescentFuel(0);
    mission->RcsFuel(0);
    }
  if (v == 4) {
    mission->Name("Apollo");
    mission->Description("Apollo/Saturn IB");
    mission->Vehicle(VEHICLE_APOLLO_SATURN_IB);
    mission->Rover(0);
    mission->Lsep(0);
    mission->Laser(0);
    mission->AscentFuel(0);
    mission->DescentFuel(0);
    mission->RcsFuel(0);
    }
  if (v == 5) {
    mission->Name("Apollo");
    mission->Description("Apollo/Saturn V");
    mission->Vehicle(VEHICLE_APOLLO_SATURN_V);
    mission->Rover(0);
    mission->Lsep(0);
    mission->Laser(0);
    mission->AscentFuel(0);
    mission->DescentFuel(0);
    mission->RcsFuel(0);
    }
  if (v == 6) {
    mission->Name("Apollo");
    mission->Description("Apollo/Saturn V");
    mission->Vehicle(VEHICLE_APOLLO);
    }
  if (v == 7) {
    mission->Name("Apollo");
    mission->Description("Apollo/Saturn V");
    mission->Vehicle(VEHICLE_APOLLO_J);
    }
  if (v == 8) {
    mission->Name("Apollo");
    mission->Description("Apollo/Saturn V");
    mission->Vehicle(VEHICLE_APOLLO_MKII);
    }
  csm->Orbiting(Earth);
  flight->Init();
  csm->SetupPanel();
  booster->Orbiting(Earth);
  currentVehicle = csm;
  plss->Orbiting(Moon);
  lrv->Orbiting(Moon);
  }

void startFromMoon() {
  UInt32 i;
  UInt32 v;
  Double d;
  char buffer[32];
  mission->StartLocation('M');
  for (i=6; i<20; i++) {
    GotoXY(1,i);
    printf("%75s"," ");
    }
  v = 0;
  while (v<1 || v > 4) {
    GotoXY(33,  7); printf("1. Apollo");
    GotoXY(33,  8); printf("2. Apollo-J");
    GotoXY(33,  9); printf("3. Apollo Mk II");
    GotoXY(33, 10); printf("4. Apollo Mk III");
    GotoXY(33, 12); printf("                     ");
    GotoXY(33, 12); printf("   Vehicle: ");
    fgets(buffer,31,stdin);
    v = atoi(buffer);
    }
  mission->Vehicle(v);
  d = -9999;
  while (d < -180 || d > 180) {
    GotoXY(30, 14); printf("                              ");
    GotoXY(30, 14); printf("Target Longitude: ");
    fgets(buffer,10,stdin);
    sscanf(buffer,"%lf",&d);
    }
  mission->TargetLongitude(d);
  d = -9999;
  while (d < -90 || d > 90) {
    GotoXY(30, 16); printf("                              ");
    GotoXY(30, 16); printf("Target Latitude: ");
    fgets(buffer,10,stdin);
    sscanf(buffer,"%lf",&d);
    }
  mission->TargetLatitude(d);
  flight->Init();
  csm->Orbiting(Moon);
  csm->SetupPanel();
  booster->Orbiting(Earth);
  currentVehicle = csm;
  plss->Orbiting(Moon);
  lrv->Orbiting(Moon);
  }

void startFromMission() {
  printf("Start from Mission not yet supported%s",LE);
  exit(1);
  }

void startFromFile() {
  if (load("lms.sav") == 0) {
    printf("Error:  Could not load save file%s",LE);
    exit(1);
    }
  csm->TargetVehicle(lm);
  if (lm != NULL) lm->TargetVehicle(csm);
  plss->TargetVehicle(lm);
  }

int init() {
  UInt32 v;
  char buffer[32];
  FILE* file;
  mission = NULL;
  Earth = new Body("Earth", 5.972e+24, 6378100);
  Moon = new Body("Moon", 7.34767309e+22, 1738300);
  Moon->Position(Vector(325266766, 0, 177193935));
  Moon->Velocity(Vector(0,1060,0));
  Moon->Orbiting(Earth);
  Moon->CalculateOrbit();
  booster = new Booster();
  csm = new CommandModule();
  lm = new LunarModule();
  lrv = new Lrv();
  plss = new Plss();
  flight = new Flight();
  lm->Orbiting(Earth);
  lrv->Orbiting(Earth);
  plss->Orbiting(Earth);
  mission = new Mission();
  mission->TargetLatitude(0);
  mission->TargetLongitude(0);
  mission->Name((char*)"Default");
  seq = new Sequencer();
  map = new Map();
  file = fopen("lms.sav","r");
  if (file != NULL) {
    fclose(file);
    return 4;
    }
  v = 0;
  while (v<1 || v > 3) {
    GotoXY(26,  7); printf("1. Start from Earth%s",LE);
    GotoXY(26,  8); printf("2. Start from the Moon%s",LE);
    GotoXY(26,  9); printf("3. Start from mission profile%s",LE);
    GotoXY(26, 11); printf("                   ");
    GotoXY(26, 11); printf("   Option ? ");
    fgets(buffer,31,stdin);
    v = atoi(buffer);
    }
  return v;
  }


int main(int argc, char** argv) {
  Int32 i;
  plog = false;
  vnlog = false;
  for (i=0; i<argc; i++) {
    if (strcmp(argv[i], "-plog") == 0) plog = true;
    if (strcmp(argv[i], "-vnlog") == 0) vnlog = true;
    }
  title();
  i = init();
  if (i == 1) startFromEarth();
  if (i == 2) startFromMoon();
  if (i == 3) startFromMission();
  if (i == 4) startFromFile();
  simSpeed = 100000;
  OpenTerminal();
  HideCursor();
  flight->Fly();
  GotoXY(1,25);
  ShowCursor();
  CloseTerminal();
  return 0;
  }

