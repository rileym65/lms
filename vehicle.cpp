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
  throttle = 0;
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

Int8   Vehicle::Throttle() {
  return throttle;
  }

Int8   Vehicle::Throttle(Int8 i) {
  throttle = i;
  if (throttle > 100) throttle = 100;
  if (throttle < 0) throttle = 0;
  return throttle;
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
  fprintf(file,"  Throttle %d%s",throttle,LE);
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
    else if (startsWith(pline,"throttle ")) throttle = atoi(nw(pline));
    else if (SubLoad(pline) == 0) {
      printf("Unknown line found in save file: %s\n",pline);
      exit(1);
      }
    }
  }

void Vehicle::SetupPanel() {
  ClrScr();
  panel->Reset();
  panel->Display();
  }

void Vehicle::UpdatePanel() {
  panel->Update();
  }

void Vehicle::ProcessKey(Int32 key) {
  if (key == 'M') seq->MoveLm();
  }

