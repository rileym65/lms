#include "types.h"
#include "header.h"
#include "spacecraft.h"
#include "matrix.h"

Spacecraft::Spacecraft() {
  rcsFbMode = ' ';
  rcsLrMode = ' ';
  rcsUdMode = ' ';
  rcsThrottle = 1;
  rcsRotThrottle = 100;
  rcsPropellant = 0;
  rcsThrust = 0;
  rcsIsp = 0;
  rateOfClimb = 0;
  rcsFuel = 0;
  maxRcsFuel = 0;
  }

Spacecraft::~Spacecraft() {
  }

Double Spacecraft::Altitude() {
  return altitude;
  }

Double Spacecraft::Altitude(Double d) {
  altitude = d;
  radius = altitude + orbiting->Radius();
  return altitude;
  }

Double Spacecraft::Apoapsis() {
  return apoapsis;
  }

Double Spacecraft::AscendingNode() {
  return ascendingNode;
  }

Double Spacecraft::Inclination() {
  return inclination;
  }

Double Spacecraft::MaxRcsFuel() {
  return maxRcsFuel;
  }

Double Spacecraft::MaxRcsFuel(Double d) {
  maxRcsFuel = d;
  return maxRcsFuel;
  }

Double Spacecraft::Periapsis() {
  return periapsis;
  }

Vector Spacecraft::Position() {
  return position;
  }

Vector Spacecraft::Position(Vector v) {
  Radius(v.Length());
  return Vehicle::Position(v);
  }

Double Spacecraft::Radius() {
  return radius;
  }

Double Spacecraft::Radius(Double d) {
  radius = d;
  altitude = radius - orbiting->Radius();
  return radius;
  }

Double Spacecraft::RateOfClimb() {
  return rateOfClimb;
  }

char   Spacecraft::RcsFbMode() {
  return rcsFbMode;
  }

char   Spacecraft::RcsFbMode(char c) {
  rcsFbMode = c;
  return rcsFbMode;
  }

Double Spacecraft::RcsFuel() {
  return rcsFuel;
  }

Double Spacecraft::RcsFuel(Double d) {
  rcsFuel = d;
  return rcsFuel;
  }

Double Spacecraft::RcsIsp() {
  return rcsIsp;
  }

Double Spacecraft::RcsIsp(Double d) {
  rcsIsp = d;
  return rcsIsp;
  }

char   Spacecraft::RcsLrMode() {
  return rcsLrMode;
  }

char   Spacecraft::RcsLrMode(char c) {
  rcsLrMode = c;
  return rcsLrMode;
  }

Double Spacecraft::RcsPropellant() {
  return rcsPropellant;
  }

Double Spacecraft::RcsPropellant(Double d) {
  rcsPropellant = d;
  return rcsPropellant;
  }

Int8   Spacecraft::RcsRotThrottle() {
  return rcsRotThrottle;
  }

Int8   Spacecraft::RcsRotThrottle(Int8 i) {
  rcsRotThrottle = i;
  return rcsRotThrottle;
  }

Int8   Spacecraft::RcsThrottle() {
  return rcsThrottle;
  }

Double Spacecraft::RcsThrust() {
  return rcsThrust;
  }

Double Spacecraft::RcsThrust(Double d) {
  rcsThrust = d;
  return rcsThrust;
  }

Int8   Spacecraft::RcsThrottle(Int8 i) {
  if (i < 10) i = 1;
  else if (i < 25) i = 10;
  else i = 100;
  rcsThrottle = i;
  return rcsThrottle;
  }

char   Spacecraft::RcsUdMode() {
  return rcsUdMode;
  }

char   Spacecraft::RcsUdMode(char c) {
  rcsUdMode = c;
  return rcsUdMode;
  }


void Spacecraft::Cycle() {
  Vector L;
  Double E;
  Double e;
  Double s;
  Double v1,v2;
  Matrix m;
  Double alt3;
  Double g;
  Vector a;
  Double hyp;
  if (rollRate != 0) {
    m = Matrix::Rotate(faceUp, rollRate / GRAN);
    faceLeft = m.Transform(faceLeft).Norm();
    faceFront = m.Transform(faceFront).Norm();
    }
  if (yawRate != 0) {
    m = Matrix::Rotate(faceFront, yawRate / GRAN);
    faceUp = m.Transform(faceUp).Norm();
    faceLeft = m.Transform(faceLeft).Norm();
    }
  if (pitchRate != 0) {
    m = Matrix::Rotate(faceLeft, pitchRate / GRAN);
    faceUp = m.Transform(faceUp).Norm();
    faceFront = m.Transform(faceFront).Norm();
    }
  if (rollRate != 0) {
    roll += rollRate;
    if (roll > 180) roll -= 360;
    if (roll < -180) roll += 360;
    }
  if (pitchRate != 0) {
    pitch += pitchRate;
    if (pitch > 180) pitch -= 360;
    if (pitch < -180) pitch += 360;
    }
  if (yawRate != 0) {
    yaw += yawRate;
    if (yaw > 180) yaw -= 360;
    if (yaw < -180) yaw += 360;
    }
  alt3 = radius * radius * radius;
//  g = orbiting->Gravitation();
  g = Earth->Gravitation();
  a = position.Scale(-g);
  a = a.Scale(1/alt3);
GotoXY(1,31); printf("G Earth: %.8f\n",a.Length());
  velocity = velocity + a.Scale(1/GRAN);

  alt3 = (position - Moon->Position()).Length();
  alt3 = alt3 * alt3 * alt3;
  g = Moon->Gravitation();
  a = position - Moon->Position();
  a = a.Scale(-g);
  a = a.Scale(1/alt3);
GotoXY(1,32); printf("G Moon : %.8f\n",a.Length());
  velocity = velocity + a.Scale(1/GRAN);

  g = Earth->Gravitation();

  velocity = velocity + thrust.Scale(1/GRAN);
  velocity = velocity + drag.Scale(1/GRAN);
  position = position + velocity.Scale(1/GRAN);
  rateOfClimb = (position.Length() - radius) * GRAN;
  Radius(position.Length());

  Vehicle::Cycle();

  L = velocity.Cross(position);
  v1 = velocity.Length();
  v2 = position.Length();
  E = ((v1 * v1) / 2) - (g/ v2);
//  E = velocity.Length() * velocity.Length() / 2 - g/ position.Length();
  s = -g/ (2 * E);
  v1 = L.Length();
  v2 = g* g;
  e = sqrt(1+2*E*(v1 * v1)/(v2));
//  e = sqrt(1+2*E*(L.Length()*L.Length())/(g*g));
  apoapsis = s * (1 + e);
  periapsis = s * (1 - e);
  orbitTime = sqrt(4*(M_PI*M_PI)*(s*s*s)/g);
  if (thrust.Length() > 0) {
    hyp = sqrt(L.X() * L.X() + L.Y() * L.Y());
    ascendingNode = L.Y() / hyp;
    ascendingNode = asin(ascendingNode) * 180 / M_PI;
    if (L.X() < 0 && L.Y() < 0) ascendingNode = -180 - ascendingNode;
    if (L.X() < 0 && L.Y() >= 0) ascendingNode = 180 - ascendingNode;
    hyp = sqrt(L.Z() * L.Z() + hyp * hyp);
    inclination = L.Z() / hyp;
    inclination = asin(inclination) * 180 / M_PI;
    }

  }

void Spacecraft::Save(FILE* file) {
  Vehicle::Save(file);
  fprintf(file,"  Altitude %.18f%s",altitude,LE);
  fprintf(file,"  Apoapsis %.18f%s",apoapsis,LE);
  fprintf(file,"  AscendingNode %.18f%s",ascendingNode,LE);
  fprintf(file,"  Inclination %.18f%s",inclination,LE);
  fprintf(file,"  Periapsis %.18f%s",periapsis,LE);
  fprintf(file,"  Radius %.18f%s",radius,LE);
  fprintf(file,"  RcsThrottle %d%s",rcsThrottle,LE);
  fprintf(file,"  RcsThrust %.18f%s",rcsThrust,LE);
  fprintf(file,"  RcsPropellant %.18f%s",rcsPropellant,LE);
  fprintf(file,"  RcsIsp %.18f%s",rcsIsp,LE);
  fprintf(file,"  RcsRotThrottle %d%s",rcsRotThrottle,LE);
  fprintf(file,"  RcsFbMode %d%s",rcsFbMode,LE);
  fprintf(file,"  RcsLrMode %d%s",rcsLrMode,LE);
  fprintf(file,"  RcsUdMode %d%s",rcsUdMode,LE);
  }

Int8 Spacecraft::SubLoad(FILE* file, char* line) {
  if (startsWith(line,"altitude ")) altitude = atof(nw(line));
  else if (startsWith(line,"apoapsis ")) apoapsis = atof(nw(line));
  else if (startsWith(line,"ascendingnode ")) ascendingNode = atof(nw(line));
  else if (startsWith(line,"inclination ")) inclination = atof(nw(line));
  else if (startsWith(line,"periapsis ")) periapsis = atof(nw(line));
  else if (startsWith(line,"radius ")) radius = atof(nw(line));
  else if (startsWith(line,"rcsthrottle ")) rcsThrottle = atoi(nw(line));
  else if (startsWith(line,"rcsthrust ")) rcsThrust = atof(nw(line));
  else if (startsWith(line,"rcspropellant ")) rcsPropellant = atof(nw(line));
  else if (startsWith(line,"rcsisp ")) rcsIsp = atof(nw(line));
  else if (startsWith(line,"rcsrotthrottle ")) rcsRotThrottle = atoi(nw(line));
  else if (startsWith(line,"rcsfbmode ")) rcsFbMode = atoi(nw(line));
  else if (startsWith(line,"rcslrmode ")) rcsLrMode = atoi(nw(line));
  else if (startsWith(line,"rcsudmode ")) rcsUdMode = atoi(nw(line));
  else return Vehicle::SubLoad(file, line);
  return -1;
  }


