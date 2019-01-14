#include <stdlib.h>
#include <math.h>
#include "groundvehicle.h"
#include "terminal.h"
#include "helpers.h"
#include "common.h"

GroundVehicle::GroundVehicle() {
  Init();
  }

GroundVehicle::~GroundVehicle() {
  }

void GroundVehicle::Init() {
  heading = 0;
  maxSpeed = 1;
  turnRate = 0;
  motorEfficiency = 1.0;
  batteryLeakage = 0.0;
  }

Double GroundVehicle::Radius() {
  return radius;
  }

Double GroundVehicle::Radius(Double d) {
  radius = d;
  altitude = radius - orbiting->Radius();
  return radius;
  }


void GroundVehicle::Cycle() {
  Vector a;
//  Double alt3;
  Double hyp;
//  alt3 = radius * radius * radius;
//  a = position.Scale(-4.9075e12);
//  a = a.Scale(1/alt3);
//  velocity = velocity + a;
//  velocity = velocity + thrust;
  position = position - orbiting->Position();
  if (turnRate != 0) {
    heading += (turnRate / GRAN);
    if (heading > 180) heading -= 360;
    if (heading < -180) heading += 360;
    Heading(heading);
    }
  thrust = faceFront.Norm().Scale(motorEfficiency * maxSpeed * ((Double)throttle / 100.0));
  velocity = thrust;
  position = position + velocity.Scale(1/GRAN);
  position = position.Norm().Scale(orbiting->Radius());
  Radius(position.Length());
  hyp = sqrt(position.X() * position.X() + position.Y() * position.Y());
  longitude = position.X() / hyp;
  longitude = asin(longitude) * 180 / M_PI;
  if (position.X() < 0 && position.Y() >= 0) longitude = -180 - longitude;
  if (position.X() >= 0 && position.Y() >= 0) longitude = 180 - longitude;
  hyp = sqrt(position.Z() * position.Z() + hyp * hyp);
  latitude = position.Z() / hyp;
  latitude = asin(latitude) * 180 / M_PI;
  position = position + orbiting->Position();
  hyp = (position - lm->Position()).Length();
  if (pilotLocation == PILOT_EVA || pilotLocation == PILOT_LRV) {
    if (hyp > farthest) {
      farthest = hyp;
      }
    if (hyp > evas[evaCount-1].farthest)
      evas[evaCount-1].farthest = hyp;
    }
  }

Double GroundVehicle::Heading() {
  return heading;
  }

Double GroundVehicle::Heading(Double d) {
  Vector v;
  Double s,c;
  heading = d;
  v = Vector(sin(heading*DR), 0, cos(heading*DR));
  c = cos(latitude * DR);
  s = sin(latitude * DR);
  v = Vector( v.X(),
              -(v.Y()*c + v.Z()*-s),
              v.Y()*s + v.Z()*c);
  c = cos(longitude * DR);
  s = sin(longitude * DR);
  v = Vector( v.X()*c + v.Y()*-s,
              v.X()*s + v.Y()*c,
              v.Z());
  faceFront = v.Norm();
  faceLeft = faceUp.Cross(faceFront).Norm();
  return heading;
  }

Double GroundVehicle::MaxSpeed() {
  return maxSpeed;
  }

Double GroundVehicle::MaxSpeed(Double d) {
  maxSpeed = d;
  return maxSpeed;
  }

void GroundVehicle::Place(Vector pos) {
  Vector f;
  Vector l;
  Vector u;
  Vector fp;
  Double dist;
  fp = pos;
  u = pos.Norm();
  position = u.Scale(orbiting->Radius());
  velocity = Vector(0,0,0);
  thrust = Vector(0,0,0);
  Radius(position.Length());

  f = Vector(position.Y(), -position.X(), position.Z()).Norm();
  l = u.Cross(f).Norm();
  f = l.Cross(u).Norm();

  faceFront = f;
  faceLeft = l;
  faceUp = u;

  position = position + orbiting->Position();
  return;

  dist = (position - fp).Length();
  ClrScr();
  printf("Pos: %.18f %.18f %.18f\n",position.X(),position.Y(),position.Z());
  printf("Lm:  %.18f %.18f %.18f\n",fp.X(),
                                    fp.Y(),
                                    fp.Z());
  printf("  F: %.18f %.18f %.18f\n",f.X(),f.Y(),f.Z());
  printf("  U: %.18f %.18f %.18f\n",u.X(),u.Y(),u.Z());
  printf("  L: %.18f %.18f %.18f\n",l.X(),l.Y(),l.Z());
  printf("Dst: %.18f\n",dist);
  ShowCursor();
  CloseTerminal();
  exit(1);
  }

Int8 GroundVehicle::SubLoad(FILE* file, char* pline) {
  if (startsWith(pline,"heading ")) Heading(atof(nw(pline)));
  else if (startsWith(pline,"turnrate ")) turnRate = atoi(nw(pline));
  else if (startsWith(pline,"batteryleakage ")) batteryLeakage = atof(nw(pline));
  else if (startsWith(pline,"motorefficiency ")) motorEfficiency = atof(nw(pline));
  else if (startsWith(pline,"maxspeed ")) maxSpeed = atof(nw(pline));
  else return Vehicle::SubLoad(file, pline);
  return -1;
  }

void GroundVehicle::Save(FILE* file) {
  Vehicle::Save(file);
  fprintf(file,"  Heading %.18f%s",heading,LE);
  fprintf(file,"  TurnRate %d%s",turnRate,LE);
  fprintf(file,"  MotorEfficiency %.18f%s",motorEfficiency,LE);
  fprintf(file,"  BatteryLeakage %.18f%s",batteryLeakage,LE);
  fprintf(file,"  MaxSpeed %.18f%s",maxSpeed,LE);
  }

Int8 GroundVehicle::TurnRate() {
  return turnRate;
  }

Int8 GroundVehicle::TurnRate(Int8 i) {
  if (i > 15) i = 15;
  if (i < -15) i = -15;
  turnRate = i;
  return turnRate;
  }

