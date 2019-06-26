#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "vehicle.h"
#include "spacecraft.h"
#include "matrix.h"
#include "helpers.h"
#include "common.h"
#include "body.h"
#include "mission.h"

Spacecraft::Spacecraft() {
  isp = 0;
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
  type |= VT_SPACECRAFT;
  }

Spacecraft::~Spacecraft() {
  }

Double Spacecraft::Altitude() {
  return ins->Altitude();
  }

Double Spacecraft::Altitude(Double d) {
  return ins->Altitude(d);
  }

Double Spacecraft::Apoapsis() {
  return ins->Apoapsis();
  }

Double Spacecraft::Apoapsis(Double d) {
  return ins->Apoapsis(d);
  }

Double Spacecraft::ArgOfPeriapsis() {
  return ins->ArgOfPeriapsis();
  }

Double Spacecraft::AscendingNode() {
  return ins->AscendingNode();
  }

Int32 Spacecraft::ClockAp() {
  return ins->ClockAp();
  }

Int32 Spacecraft::ClockPe() {
  return ins->ClockPe();
  }

Double Spacecraft::DeltaV() {
  return deltaV;
  }

Double Spacecraft::EarthG() {
  return earthG;
  }

Double Spacecraft::EccentricAnomaly() {
  return ins->EccentricAnomaly();
  }

Double Spacecraft::FuelUsed() {
  return fuelUsed;
  }

Double Spacecraft::Inclination() {
  return ins->Inclination();
  }

Double Spacecraft::Isp() {
  return isp;
  }

Double Spacecraft::MaxRcsFuel() {
  return maxRcsFuel;
  }

Double Spacecraft::MaxRcsFuel(Double d) {
  maxRcsFuel = d;
  return maxRcsFuel;
  }

Double Spacecraft::MoonG() {
  return moonG;
  }

Double Spacecraft::MeanAnomaly() {
  return ins->MeanAnomaly();
  }

Double Spacecraft::Periapsis() {
  return ins->Periapsis();
  }

Double Spacecraft::Periapsis(Double d) {
  return ins->Periapsis(d);
  }

Vector Spacecraft::Position() {
  return position;
  }

Vector Spacecraft::Position(Vector v) {
  Radius((v - Orbiting()->Position()).Length());
  return Vehicle::Position(v);
  }

Double Spacecraft::Radius() {
  return ins->Radius();
  }

Double Spacecraft::Radius(Double d) {
  return ins->Radius(d);
  }

Double Spacecraft::RateOfClimb() {
  return rateOfClimb;
  }

Double Spacecraft::RateOfClimb(Double d) {
  rateOfClimb = d;
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

Double Spacecraft::RelAltitude() {
  Vector v1,v2;
  if (targetVehicle == NULL) return 0;
  v1 = position - Orbiting()->Position();
  v2 = targetVehicle->Position() - targetVehicle->Orbiting()->Position();
  return v1.Length() - v2.Length();
  }

Vector Spacecraft::RelPos() {
  if (targetVehicle == NULL) return Vector(0,0,0);
  return position - targetVehicle->Position();
  }

Vector Spacecraft::RelVel() {
  if (targetVehicle == NULL) return Vector(0,0,0);
  return velocity - targetVehicle->Velocity();
  }

Double Spacecraft::RelLongitude() {
  Double ret;
  if (targetVehicle == NULL) return 0;
  ret = Longitude() - targetVehicle->Longitude();
  while (ret < -180) ret += 360;
  while (ret > 180) ret -= 360;
  return ret;
  }

Double Spacecraft::RelLatitude() {
  Double ret;
  if (targetVehicle == NULL) return 0;
  ret = Latitude() - targetVehicle->Latitude();
  return ret;
  }

Double Spacecraft::RelOrbitTime() {
  if (targetVehicle == NULL) return 0;
  return ins->OrbitTime() - ((Spacecraft*)targetVehicle)->OrbitTime();
  }

Double Spacecraft::RelMomEast() {
  Double ret;
  if (targetVehicle == NULL) return 0;
  ret = ins->AscendingNode() - ((Spacecraft*)targetVehicle)->AscendingNode();
  while (ret < -180) ret += 360;
  while (ret > 180) ret -= 360;
  return ret;
  }

Double Spacecraft::RelMomNorth() {
  Double ret;
  if (targetVehicle == NULL) return 0;
  ret = ins->Inclination() - ((Spacecraft*)targetVehicle)->Inclination();
  while (ret < -180) ret += 360;
  while (ret > 180) ret -= 360;
  return ret;
  }

char   Spacecraft::RcsUdMode() {
  return rcsUdMode;
  }

char   Spacecraft::RcsUdMode(char c) {
  rcsUdMode = c;
  return rcsUdMode;
  }

Double Spacecraft::TargetLongitude() {
  return ins->TarLongitude();
  }

Double Spacecraft::TargetLatitude() {
  return ins->TarLatitude();
  }

Double Spacecraft::TargetMomEast() {
  return ins->TarMomEast();
  }

Double Spacecraft::TargetMomNorth() {
  return ins->TarMomNorth();
  }

Double Spacecraft::TrueAnomaly() {
  return ins->TrueAnomaly();
  }

Double Spacecraft::TrueLongitude() {
  return ins->TrueLongitude();
  }

double toDegrees(double theta) {
  double d;
  d = 180 * theta / M_PI;
  while (d >= 180) d -= 360;
  while (d <= -180) d += 360;
  return d;
  }

double toRadians(double theta) {
  return M_PI*theta/180;
  }

double arctan2(double Ey, double Ex) {
  double u;
  if (Ex != 0) {
    u = atan(Ey / Ex);
    if (Ex < 0) u = u + M_PI;
    if (Ex > 0 && Ey < 0) u = u + 2 * M_PI;
    }
  else {
    if (Ey < 0) u = -M_PI / 2;
    if (Ey == 0) u = 0;
    if (Ey > 0) u = M_PI / 2;
    }
  return u;
  }

void Spacecraft::Prograde(Double maxRate) {
  Vector crs;
  Vector vel;
  Double d;
  Matrix m;
  vel = (velocity - Orbiting()->Velocity()).Norm();
  d = 180 - (acos(faceUp.Dot(vel)) * 180 / M_PI);
  if (isnan(d)) return;
  if (d > 0) d = -d;
  if (d > -0.001) return;
  if (d > maxRate) d = maxRate;
  if (d < -maxRate) d = -maxRate;
  crs = vel.Cross(faceUp).Norm();
  m = Matrix::Rotate(crs, d / GRAN);
  faceUp = m.Transform(faceUp).Norm();
  faceLeft = m.Transform(faceLeft).Norm();
  faceFront = m.Transform(faceFront).Norm();
  }

void Spacecraft::Retrograde(Double maxRate) {
  Vector crs;
  Vector vel;
  Double d;
  Matrix m;
  vel = (velocity - Orbiting()->Velocity()).Norm();
  d = 180 - (acos(faceUp.Dot(vel)) * 180 / M_PI);
  if (isnan(d)) return;
  if (d < 0) d = -d;
  if (d < 0.001) return;
  if (d > maxRate) d = maxRate;
  if (d < -maxRate) d = -maxRate;
  crs = vel.Cross(faceUp).Norm();
  m = Matrix::Rotate(crs, d / GRAN);
  faceUp = m.Transform(faceUp).Norm();
  faceLeft = m.Transform(faceLeft).Norm();
  faceFront = m.Transform(faceFront).Norm();
  }

void Spacecraft::Anorm(Double maxRate) {
  Vector crs;
  Vector pos;
  Vector vel;
  Double d;
  Matrix m;
  pos = (position - Orbiting()->Position()).Norm();
  vel = (velocity - Orbiting()->Velocity()).Norm();
  crs = vel.Cross(pos).Norm();
  d = 180 - (acos(faceUp.Dot(crs)) * 180 / M_PI);
  if (isnan(d)) return;
  if (d < 0) d = -d;
  if (d < 0.001) return;
  if (d > maxRate) d = maxRate;
  if (d < -maxRate) d = -maxRate;
  crs = crs.Cross(faceUp).Norm();
  m = Matrix::Rotate(crs, d / GRAN);
  faceUp = m.Transform(faceUp).Norm();
  faceLeft = m.Transform(faceLeft).Norm();
  faceFront = m.Transform(faceFront).Norm();
  }

void Spacecraft::Norm(Double maxRate) {
  Vector crs;
  Vector pos;
  Vector vel;
  Double d;
  Matrix m;
  pos = (position - Orbiting()->Position()).Norm();
  vel = (velocity - Orbiting()->Velocity()).Norm();
  crs = vel.Cross(pos).Neg().Norm();
  d = 180 - (acos(faceUp.Dot(crs)) * 180 / M_PI);
  if (isnan(d)) return;
  if (d < 0) d = -d;
  if (d < 0.001) return;
  if (d > maxRate) d = maxRate;
  if (d < -maxRate) d = -maxRate;
  crs = crs.Cross(faceUp).Norm();
  m = Matrix::Rotate(crs, d / GRAN);
  faceUp = m.Transform(faceUp).Norm();
  faceLeft = m.Transform(faceLeft).Norm();
  faceFront = m.Transform(faceFront).Norm();
  }

void Spacecraft::Inside(Double maxRate) {
  Vector crs;
  Vector pos;
  Vector vel;
  Double d;
  Matrix m;
  pos = (position - Orbiting()->Position()).Norm();
  vel = (velocity - Orbiting()->Velocity()).Norm();
  crs = vel.Cross(pos).Norm();
  crs = crs.Cross(vel).Norm();
  d = 180 - (acos(faceUp.Dot(crs)) * 180 / M_PI);
  if (isnan(d)) return;
  if (d < 0) d = -d;
  if (d < 0.001) return;
  if (d > maxRate) d = maxRate;
  if (d < -maxRate) d = -maxRate;
  crs = crs.Cross(faceUp).Norm();
  m = Matrix::Rotate(crs, d / GRAN);
  faceUp = m.Transform(faceUp).Norm();
  faceLeft = m.Transform(faceLeft).Norm();
  faceFront = m.Transform(faceFront).Norm();
  }

void Spacecraft::Outside(Double maxRate) {
  Vector crs;
  Vector pos;
  Vector vel;
  Double d;
  Matrix m;
  pos = (position - Orbiting()->Position()).Norm();
  vel = (velocity - Orbiting()->Velocity()).Norm();
  crs = vel.Cross(pos).Norm();
  crs = crs.Cross(vel).Neg().Norm();
  d = 180 - (acos(faceFront.Dot(crs)) * 180 / M_PI);
  if (isnan(d)) return;
  if (d < 0) d = -d;
  if (d < 0.001) return;
  if (d > maxRate) d = maxRate;
  if (d < -maxRate) d = -maxRate;
  crs = crs.Cross(faceUp).Norm();
  m = Matrix::Rotate(crs, d / GRAN);
  faceUp = m.Transform(faceUp).Norm();
  faceLeft = m.Transform(faceLeft).Norm();
  faceFront = m.Transform(faceFront).Norm();
  }

void Spacecraft::Ins() {
  ins->Cycle();
/*
  Vector L;
  Double hyp;
  Vector pos;
  Vector vel;
  Double tmp;
  Double Rx,Ry,Rz;
  Double Vx,Vy,Vz;
  Double Hx,Hy,Hz;
  Double H;
  Double TAx;
  Double TAy;
  Double Cw;
  Double Sw;
  Double Mu;
  Double PlusMinus;
  Double R;
  Double V;
  Double a;
  Double p;
  Double q;
  Double Ex;
  Double Ey;
  Double d;
  Double spd;
  pos = position - Orbiting()->Position();
  vel = velocity - Orbiting()->Velocity();
  Altitude(pos.Length() - Orbiting()->Radius());

  hyp = sqrt(pos.X() * pos.X() + pos.Y() * pos.Y());
  Longitude(pos.X() / hyp);
  Longitude(asin(Longitude()) * 180 / M_PI);
  if (pos.X() < 0 && pos.Y() >= 0) Longitude(-180 - Longitude());
  if (pos.X() >= 0 && pos.Y() >= 0) Longitude(180 - Longitude());
  hyp = pos.Length();
  Latitude(pos.Z() / hyp);
  Latitude(asin(Latitude()) * 180 / M_PI);
  Rx = -pos.Y();
  Ry = pos.X();
  Rz = pos.Z();
  Vx = -vel.Y();
  Vy = vel.X();
  Vz = vel.Z();
  Mu = G * Orbiting()->Mass();
  R = sqrt(Rx*Rx + Ry*Ry + Rz*Rz);
  V = sqrt(Vx*Vx + Vy*Vy + Vz*Vz);
  a = 1/(2/R - V*V / Mu);
  Hx = Ry*Vz - Rz*Vy;
  Hy = Rz*Vx - Rx*Vz;
  Hz = Rx*Vy - Ry*Vx;
  H = sqrt(Hx*Hx + Hy*Hy + Hz*Hz);
  p = H*H / Mu;
  q = Rx*Vx + Ry*Vy + Rz*Vz;
  ins->Eccentricity(sqrt(1 - p/a));
  Ex = 1 - R/a;
  Ey = q / sqrt(a * Mu);
  ins->Inclination(acos(Hz / H));
  ins->AscendingNode(0);
  if (ins->Inclination() != 0) ins->AscendingNode(arctan2(Hx, -Hy));
  TAx = H*H / (R*Mu) - 1;
  TAy = H*q / (R*Mu);
  ins->TrueAnomaly(arctan2(TAy, TAx));
  Cw = (Rx * cos(ins->AscendingNode()) + Ry * sin(ins->AscendingNode())) / R;
  Sw = 0;
  if (ins->Inclination() ==0 || ins->Inclination() == M_PI)
    Sw = (Ry * cos(ins->AscendingNode()) - Rx * sin(ins->AscendingNode())) / R;
  else
    Sw = Rz / (R * sin(ins->Inclination()));
  ins->ArgOfPeriapsis(arctan2(Sw, Cw) - ins->TrueAnomaly());
  if (ins->ArgOfPeriapsis() < 0) ins->ArgOfPeriapsis(2*M_PI+ins->ArgOfPeriapsis());
  ins->EccentricAnomaly(arctan2(Ey, Ex));
  ins->MeanAnomaly(ins->EccentricAnomaly()-ins->Eccentricity() * sin(ins->EccentricAnomaly()));
  ins->TrueLongitude(ins->ArgOfPeriapsis() + ins->TrueAnomaly() + ins->AscendingNode());
  while (ins->TrueLongitude() >= 2*M_PI)
    ins->TrueLongitude(ins->TrueLongitude() - 2*M_PI);
  PlusMinus = a * ins->Eccentricity();
  ins->Periapsis(a - PlusMinus);
  ins->Apoapsis(a + PlusMinus);
  orbitTime = 2 * M_PI * sqrt(a*a*a / Mu);
  ins->Inclination(toDegrees(ins->Inclination()));
  ins->AscendingNode(toDegrees(ins->AscendingNode()));
  ins->EccentricAnomaly(toDegrees(ins->EccentricAnomaly()));
  ins->MeanAnomaly(toDegrees(ins->MeanAnomaly()));
  ins->TrueAnomaly(toDegrees(ins->TrueAnomaly()));
  ins->TrueLongitude(toDegrees(ins->TrueLongitude()));
  ins->ArgOfPeriapsis(toDegrees(ins->ArgOfPeriapsis()));

  spd = orbitTime / 360;
  d = 180 - ins->MeanAnomaly();
  while (d<0) d += 360;
  while (d > 360) d -= 360;
  d *= spd;
  ins->ClockAp(d);
  d = 360 - ins->MeanAnomaly();
  while (d<0) d += 360;
  while (d > 360) d -= 360;
  d *= spd;
  ins->ClockPe(d);

  if (mission != NULL) {
    ins->TarLatitude(Latitude() - mission->TargetLatitude());
    ins->TarLongitude(Longitude() - mission->TargetLongitude());
    while (ins->TarLongitude() < -180) ins->TarLongitude(ins->TarLongitude() + 360);
    while (ins->TarLongitude() > 180) ins->TarLongitude(ins->TarLongitude() - 360);
    ins->TarMomNorth(ins->Inclination() - mission->TargetMomNorth());
    ins->TarMomEast(ins->AscendingNode() - mission->TargetMomEast());
    while (ins->TarMomNorth() < -180) ins->TarMomNorth(ins->TarMomNorth() + 360);
    while (ins->TarMomNorth() > 180) ins->TarMomNorth(ins->TarMomNorth() - 360);
    while (ins->TarMomEast() < -180) ins->TarMomEast(ins->TarMomEast() + 360);
    while (ins->TarMomEast() > 180) ins->TarMomEast(ins->TarMomEast() - 360);
    }
  tmp = Latitude() - ins->LastLatitude();
  if (tmp <= -180) tmp += 360;
  if (tmp >= 180) tmp -= 360;
  latitudeVel = tmp * Orbiting()->Meters();
  latitudeAcc = latitudeVel - lastLatitudeVel;

  ins->LastLatitude(Latitude());
  ins->LastLongitude(Longitude());
  lastLatitudeVel = latitudeVel;
*/
  }

void Spacecraft::Cycle() {
  Matrix m;
  Double alt3;
  Double g;
  Vector a;
  Vector p1,p2;
  Double r1;

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
//  if (rollRate != 0) {
//    roll += (rollRate /GRAN);
//    if (roll > 180) roll -= 360;
//    if (roll < -180) roll += 360;
//    }
//  if (pitchRate != 0) {
//    pitch += (pitchRate /GRAN);
//    if (pitch > 180) pitch -= 360;
//    if (pitch < -180) pitch += 360;
//    }
//  if (yawRate != 0) {
//    yaw += (yawRate /GRAN);
//    if (yaw > 180) yaw -= 360;
//    if (yaw < -180) yaw += 360;
//    }
  if (Earth != NULL) {
    alt3 = (position - Earth->Position()).Length();
    alt3 = alt3 * alt3 * alt3;
    g = Earth->Gravitation();
    a = position - Earth->Position();
    a = a.Scale(-g);
    a = a.Scale(1/alt3);
    earthG = a.Length();
    velocity = velocity + a.Scale(1/GRAN);
    } else earthG = 0;

  if (Moon != NULL) {
    alt3 = (position - Moon->Position()).Length();
    alt3 = alt3 * alt3 * alt3;
    g = Moon->Gravitation();
    a = position - Moon->Position();
    a = a.Scale(-g);
    a = a.Scale(1/alt3);
    moonG = a.Length();
    velocity = velocity + a.Scale(1/GRAN);
    } else moonG = 0;

  p1 = position - Orbiting()->Position();
  velocity = velocity + thrust.Scale(1/GRAN);
  deltaV += thrust.Scale(1/GRAN).Length();

  velocity = velocity + drag.Scale(1/GRAN);
  position = position + velocity.Scale(1/GRAN);
  r1 = Radius();
  Radius((position - Orbiting()->Position()).Length());
  rateOfClimb = (Radius() - r1) * GRAN;

  if (currentVehicle == this ||
      this == csm->LaunchVehicle()) {
    p2 = position - Orbiting()->Position();
    distanceTravelled += ((p1-p2).Length());
    }

  if (this == csm && Orbiting() == Earth && moonG > earthG) {
    Orbiting(Moon);
    simSpeed = 100000;
    }
  if (this == csm && Orbiting() == Moon && earthG > moonG) {
    Orbiting(Earth);
    simSpeed = 100000;
    }

  Vehicle::Cycle();
  }

void Spacecraft::Save(FILE* file) {
  Vehicle::Save(file);
  fprintf(file,"  Altitude %.18f%s",Altitude(),LE);
  fprintf(file,"  Apoapsis %.18f%s",ins->Apoapsis(),LE);
  fprintf(file,"  AscendingNode %.18f%s",ins->AscendingNode(),LE);
  fprintf(file,"  Eccentricity %.18f%s",ins->Eccentricity(),LE);
  fprintf(file,"  DeltaV %.18f%s",deltaV,LE);
  fprintf(file,"  Inclination %.18f%s",ins->Inclination(),LE);
  fprintf(file,"  Periapsis %.18f%s",ins->Periapsis(),LE);
  fprintf(file,"  Radius %.18f%s",Radius(),LE);
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
  if (startsWith(line,"altitude ")) Altitude(atof(nw(line)));
  else if (startsWith(line,"apoapsis ")) Apoapsis(atof(nw(line)));
  else if (startsWith(line,"ascendingnode ")) ins->AscendingNode(atof(nw(line)));
  else if (startsWith(line,"eccentricity ")) ins->Eccentricity(atof(nw(line)));
  else if (startsWith(line,"deltav ")) deltaV = atof(nw(line));
  else if (startsWith(line,"inclination ")) ins->Inclination(atof(nw(line)));
  else if (startsWith(line,"periapsis ")) ins->Periapsis(atof(nw(line)));
  else if (startsWith(line,"radius ")) Radius(atof(nw(line)));
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


