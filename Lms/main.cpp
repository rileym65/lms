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


int main(int argc, char** argv) {
  char buffer[32];
  UInt32 v;
  Int32 i;
  mission = NULL;
  plog = false;
  vnlog = false;
  for (i=0; i<argc; i++) {
    if (strcmp(argv[i], "-plog") == 0) plog = true;
    if (strcmp(argv[i], "-vnlog") == 0) vnlog = true;
    }
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
  if (load("fms.sav") == 0) {
    ClrScr();
    printf("1. Mercury/Redstone\n");
    printf("2. Mercury/Atlas\n");
    printf("3. Gemini/Titan\n");
    printf("4. Apollo/Saturn IB\n");
    printf("5. Apollo/Saturn V\n");
    printf("6. Apollo/LM/Saturn V\n");
    printf("7. Apollo/LM-J/Saturn V\n");
    printf("8. Apollo/LM-MkII/Saturn V\n");
    printf("   Vehicle: ");
    fgets(buffer,31,stdin);
    v = atoi(buffer);
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
    flight->Init();
    csm->Orbiting(Earth);
    csm->SetupPanel();
    booster->Orbiting(Earth);
    currentVehicle = csm;
    plss->Orbiting(Moon);
    lrv->Orbiting(Moon);
    }
  else {
    csm->TargetVehicle(lm);
    if (lm != NULL) lm->TargetVehicle(csm);
    plss->TargetVehicle(lm);
    }
  simSpeed = 100000;
  OpenTerminal();
  HideCursor();
  flight->Fly();
  GotoXY(1,25);
  ShowCursor();
  CloseTerminal();
  return 0;
  }

