#include <math.h>
#include "header.h"
#include "vehicle.h"
#include "terminal.h"

Vehicle::Vehicle() {
  velocityAltitude = 0;
  thrust = Vector(0,0,0);
  orientation = Matrix::Identity();
  Init();
  }

Vehicle::~Vehicle() {
  }

void Vehicle::Init() {
  panel = new Panel("csm.pnl");
  }

Double Vehicle::Altitude() {
  return altitude;
  }

Double Vehicle::Altitude(Double d) {
  altitude = d;
  radius = altitude + 1738300;
  return altitude;
  }

Vector Vehicle::FaceFront() {
  return faceFront;
  }

Vector Vehicle::FaceFront(Vector v) {
  faceFront = v;
  baseFront = v;
  return faceFront;
  }

Vector Vehicle::FaceLeft() {
  return faceLeft;
  }

Vector Vehicle::FaceLeft(Vector v) {
  faceLeft = v;
  baseLeft = v;
  return faceLeft;
  }

Vector Vehicle::FaceUp() {
  return faceUp;
  }

Vector Vehicle::FaceUp(Vector v) {
  faceUp = v;
  baseUp = v;
  return faceUp;
  }

Double Vehicle::Latitude() {
  return latitude;
  }

Double Vehicle::Latitude(Double d) {
  latitude = d;
  return latitude;
  }

Double Vehicle::Longitude() {
  return longitude;
  }

Double Vehicle::Longitude(Double d) {
  longitude = d;
  return longitude;
  }

Vector Vehicle::Position() {
  return position;
  }

Vector Vehicle::Position(Vector v) {
  position = v;
  Radius(position.Length());
  return position;
  }

Double Vehicle::Radius() {
  return radius;
  }

Double Vehicle::Radius(Double d) {
  velocityAltitude = d - radius;;
  radius = d;
  altitude = radius - 1738300;
  return radius;
  }

Vector Vehicle::Thrust() {
  return thrust;
  }

Vector Vehicle::Thrust(Vector t) {
  thrust = t;
  return thrust;
  }

Vector Vehicle::Velocity() {
  return velocity;
  }

Vector Vehicle::Velocity(Vector v) {
  velocity = v;
  return velocity;
  }

void Vehicle::Cycle() {
  Vector a;
  Double alt3;
  Double hyp;
  alt3 = radius * radius * radius;
  a = position.Scale(-4.9075e12);
  a = a.Scale(1/alt3);
  velocity = velocity + a;
  velocity = velocity + thrust;
  position = position + velocity;
  Radius(position.Length());
  hyp = sqrt(position.X() * position.X() + position.Y() * position.Y());
  longitude = position.X() / hyp;
  longitude = asin(longitude) * 180 / M_PI;
  if (position.X() < 0 && position.Y() >= 0) longitude = -180 - longitude;
  if (position.X() >= 0 && position.Y() >= 0) longitude = 180 - longitude;
  hyp = sqrt(position.Z() * position.Z() + hyp * hyp);
  latitude = position.Z() / hyp;
  latitude = asin(latitude) * 180 / M_PI;
  }

Double Vehicle::VelocityAltitude() {
  return velocityAltitude;
  }

Double Vehicle::VelocityEast() {
  Double vel;
  vel = sqrt(velocity.X() * velocity.X() + velocity.Y() * velocity.Y());
  if (sgn(velocity.X()) == sgn(position.Y())) vel = -vel;
  return vel;
  }

Double Vehicle::VelocityNorth() {
  return velocity.Z();
  }

Int8 Vehicle::SubLoad(char* line) {
  return 0;
  }

void Vehicle::Save(FILE* file) {
  fprintf(file,"  Altitude %.18f%s",altitude,LE);
  fprintf(file,"  Latitude %.18f%s",latitude,LE);
  fprintf(file,"  Longitude %.18f%s",longitude,LE);
  fprintf(file,"  Radius %.18f%s",radius,LE);
  fprintf(file,"  BaseFront %.18f %.18f %.18f%s",baseFront.X(),baseFront.Y(),baseFront.Z(),LE);
  fprintf(file,"  BaseUp %.18f %.18f %.18f%s",baseUp.X(),baseUp.Y(),baseUp.Z(),LE);
  fprintf(file,"  BaseLeft %.18f %.18f %.18f%s",baseLeft.X(),baseLeft.Y(),baseLeft.Z(),LE);
  fprintf(file,"  FaceFront %.18f %.18f %.18f%s",faceFront.X(),faceFront.Y(),faceFront.Z(),LE);
  fprintf(file,"  FaceUp %.18f %.18f %.18f%s",faceUp.X(),faceUp.Y(),faceUp.Z(),LE);
  fprintf(file,"  FaceLeft %.18f %.18f %.18f%s",faceLeft.X(),faceLeft.Y(),faceLeft.Z(),LE);
  fprintf(file,"  Position %.18f %.18f %.18f%s",position.X(),position.Y(),position.Z(),LE);
  fprintf(file,"  Velocity %.18f %.18f %.18f%s",velocity.X(),velocity.Y(),velocity.Z(),LE);
  fprintf(file,"  Thrust %.18f %.18f %.18f%s",thrust.X(),thrust.Y(),thrust.Z(),LE);
  fprintf(file,"  Orientation %.18f %.18f %.18f %.18f %.18f %.18f %.18f %.18f %.18f%s",
    orientation.Cell(0,0), orientation.Cell(0,1), orientation.Cell(0,2),
    orientation.Cell(1,0), orientation.Cell(1,1), orientation.Cell(1,2),
    orientation.Cell(2,0), orientation.Cell(2,1), orientation.Cell(2,2),LE);
  }

void Vehicle::Load(FILE* file) {
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"altitude ")) altitude = atof(nw(pline));
    else if (startsWith(pline,"latitude ")) latitude = atof(nw(pline));
    else if (startsWith(pline,"longitude ")) longitude = atof(nw(pline));
    else if (startsWith(pline,"radius ")) radius = atof(nw(pline));
    else if (startsWith(pline,"basefront ")) baseFront = atov(nw(pline));
    else if (startsWith(pline,"baseup ")) baseUp = atov(nw(pline));
    else if (startsWith(pline,"baseleft ")) baseLeft = atov(nw(pline));
    else if (startsWith(pline,"facefront ")) faceFront = atov(nw(pline));
    else if (startsWith(pline,"faceup ")) faceUp = atov(nw(pline));
    else if (startsWith(pline,"faceleft ")) faceLeft = atov(nw(pline));
    else if (startsWith(pline,"position ")) position = atov(nw(pline));
    else if (startsWith(pline,"velocity ")) velocity = atov(nw(pline));
    else if (startsWith(pline,"thrust ")) thrust = atov(nw(pline));
    else if (startsWith(pline,"orientation ")) orientation = atom(nw(pline));
    else if (SubLoad(pline) == 0) {
      printf("Unknown line found in save file: %s\n",pline);
      ShowCursor();
      CloseTerminal();
      exit(1);
      }
    }
  }

void Vehicle::SetupPanel() {
  ClrScr();
  INST_DR_X = 42;
  INST_DR_Y = 5;
  INST_ATT_X = 2;
  INST_ATT_Y = 17;
  INST_DOCK_X = 41;
  INST_DOCK_Y = 4;
  INST_DOWN_X = 55;
  INST_DOWN_Y = 2;
  INST_IND_X = 2;
  INST_IND_Y = 22;
  INST_LAND_X = 28;
  INST_LAND_Y = 4;
  INST_WEST_X = 2;
  INST_WEST_Y = 2;
  INST_SPIN_X = 10;
  INST_SPIN_Y = 17;
  INST_CONS_X = 17;
  INST_CONS_Y = 17;
  INST_STAT_X = 53;
  INST_STAT_Y = 17;
  INST_CLCK_X = 68;
  INST_CLCK_Y = 17;
  INST_INS_X = 25;
  INST_INS_Y = 17;
  INST_PILOT_X = 32;
  INST_PILOT_Y = 2;
  INST_PLSS_X = 29;
  INST_PLSS_Y = 12;
  INST_LM_X = 48;
  INST_LM_Y = 12;
  INST_LRV_X = 37;
  INST_LRV_Y = 12;
  INST_SEQ_X = 37;
  INST_SEQ_Y = 23;
  panel->Display();
/*
  printf("+-------------------------+--------------------------+-------------------------+\n");
  printf("|                         |   |                   |  |                         |\n");
  printf("|                         +--------------------------+                         |\n");
  printf("|                         |                          |                         |\n");
  printf("|                         |                          |                         |\n");
  printf("|                         |                          |                         |\n");
  printf("|                         |                          |                         |\n");
  printf("|                         |                          |                         |\n");
  printf("|                         |                          |                         |\n");
  printf("|                         |                          |                         |\n");
  printf("|                         |                          |                         |\n");
  printf("|                         |       |       | --|      |                         |\n");
  printf("|                         |       |       | --|      |                         |\n");
  printf("|                         |       |       | --|      |                         |\n");
  printf("|                         |       |       | --|      |                         |\n");
  printf("+-------------------------+--------------------------+-------------------------+\n");
  printf("|       |      |       |                           |              |            |\n");
  printf("|       |      |       |                           |              |            |\n");
  printf("|       |      |       |                           |              |            |\n");
  printf("|       |      |       |                           |              |            |\n");
  printf("|--------------|       |                           |              |            |\n");
  printf("|              |       |           +---------------+              |            |\n");
  printf("|              |       |           |          :    |              |            |\n");
  printf("+------------------------------------------------------------------------------+\n");
  console->Reset();
  console->DrawAtt(INST_ATT_X, INST_ATT_Y);
  console->DrawClocks(INST_CLCK_X, INST_CLCK_Y);
  console->DrawCons(INST_CONS_X, INST_CONS_Y);
  console->DrawDockingRadar(INST_DOCK_X, INST_DOCK_Y);
  console->DrawDownAxis(INST_DOWN_X, INST_DOWN_Y);
  console->DrawInd(INST_IND_X, INST_IND_Y);
  console->DrawIns(INST_INS_X, INST_INS_Y);
  console->DrawLandingRadar(INST_LAND_X, INST_LAND_Y);
  console->DrawLm(INST_LM_X, INST_LM_Y);
  console->DrawLrv(INST_LRV_X, INST_LRV_Y);
  console->DrawPilot(INST_PILOT_X, INST_PILOT_Y);
  console->DrawPlss(INST_PLSS_X, INST_PLSS_Y);
  console->DrawSpin(INST_SPIN_X, INST_SPIN_Y);
  console->DrawStatus(INST_STAT_X, INST_STAT_Y);
  console->DrawWestAxis(INST_WEST_X, INST_WEST_Y);
*/
  }

void Vehicle::UpdatePanel() {
  panel->Update();
/*
  console->DisplayAtt(INST_ATT_X, INST_ATT_Y);
  console->DisplayClocks(INST_CLCK_X, INST_CLCK_Y);
  console->DisplayCons(INST_CONS_X, INST_CONS_Y);
  console->DisplayLm(INST_LM_X, INST_LM_Y);
  console->DisplayLrv(INST_LRV_X, INST_LRV_Y);
  console->DisplayPilot(INST_PILOT_X, INST_PILOT_Y);
  console->DisplayPlss(INST_PLSS_X, INST_PLSS_Y);
  console->DisplaySeq(INST_SEQ_X, INST_SEQ_Y);
  console->DisplaySpin(INST_SPIN_X, INST_SPIN_Y);
  console->DisplayStatus(INST_STAT_X, INST_STAT_Y);
  console->DisplayIns(INST_INS_X, INST_INS_Y);
  console->DisplayDockingRadar(INST_DR_X, INST_DR_Y);
  if (pilotLocation == PILOT_CSM) {
    console->DisplayWestAxis(INST_WEST_X, INST_WEST_Y, csm);
    console->DisplayDownAxis(INST_DOWN_X, INST_DOWN_Y, csm);
    }
  if (pilotLocation == PILOT_LM) {
    console->DisplayWestAxis(INST_WEST_X, INST_WEST_Y, lm);
    console->DisplayDownAxis(INST_DOWN_X, INST_DOWN_Y, lm);
    }
*/
  fflush(stdout);
  }

void Vehicle::ProcessKey(Int32 key) {
  if (key == 'M') seq->MoveLm();
  }

