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
  tarLongitude = 0;
  tarLatitude = 0;
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

Double Spacecraft::ArgOfPeriapsis() {
  return argOfPeriapsis;
  }

Double Spacecraft::AscendingNode() {
  return ascendingNode;
  }

Int32 Spacecraft::ClockAp() {
  return clockAp;
  }

Int32 Spacecraft::ClockPe() {
  return clockPe;
  }

Double Spacecraft::DeltaV() {
  return deltaV;
  }

Double Spacecraft::EarthG() {
  return earthG;
  }

Double Spacecraft::EccentricAnomaly() {
  return eccentricAnomaly;
  }

Double Spacecraft::FuelUsed() {
  return fuelUsed;
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

Double Spacecraft::MoonG() {
  return moonG;
  }

Double Spacecraft::MeanAnomaly() {
  return meanAnomaly;
  }

Double Spacecraft::Periapsis() {
  return periapsis;
  }

Vector Spacecraft::Position() {
  return position;
  }

Vector Spacecraft::Position(Vector v) {
  Radius((v - orbiting->Position()).Length());
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
  v1 = position - orbiting->Position();
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
  ret = longitude - targetVehicle->Longitude();
  while (ret < -180) ret += 360;
  while (ret > 180) ret -= 360;
  return ret;
  }

Double Spacecraft::RelLatitude() {
  Double ret;
  if (targetVehicle == NULL) return 0;
  ret = latitude - targetVehicle->Latitude();
  return ret;
  }

Double Spacecraft::RelOrbitTime() {
  if (targetVehicle == NULL) return 0;
  return orbitTime - ((Spacecraft*)targetVehicle)->OrbitTime();
  }

Double Spacecraft::RelMomEast() {
  Double ret;
  if (targetVehicle == NULL) return 0;
  ret = ascendingNode - ((Spacecraft*)targetVehicle)->AscendingNode();
  while (ret < -180) ret += 360;
  while (ret > 180) ret -= 360;
  return ret;
  }

Double Spacecraft::RelMomNorth() {
  Double ret;
  if (targetVehicle == NULL) return 0;
  ret = inclination - ((Spacecraft*)targetVehicle)->Inclination();
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
  return tarLongitude;
  }

Double Spacecraft::TargetLatitude() {
  return tarLatitude;
  }

Double Spacecraft::TargetMomEast() {
  return tarMomEast;
  }

Double Spacecraft::TargetMomNorth() {
  return tarMomNorth;
  }

Double Spacecraft::TrueAnomaly() {
  return trueAnomaly;
  }

Double Spacecraft::TrueLongitude() {
  return trueLongitude;
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
  vel = (velocity - orbiting->Velocity()).Norm();
  d = (asin(faceFront.Dot(vel)) * 180 / M_PI);
  if (d > 0) d = -d;
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
  vel = (velocity - orbiting->Velocity()).Norm();
  d = (asin(faceFront.Dot(vel)) * 180 / M_PI);
  if (d < 0) d = -d;
  if (d > maxRate) d = maxRate;
  if (d < -maxRate) d = -maxRate;
  crs = vel.Cross(faceUp).Norm();
  m = Matrix::Rotate(crs, d / GRAN);
  faceUp = m.Transform(faceUp).Norm();
  faceLeft = m.Transform(faceLeft).Norm();
  faceFront = m.Transform(faceFront).Norm();
  }

void Spacecraft::Ins() {
  Vector L;
//  Double E;
//  Double v1,v2;
//  Double s;
//  Double e;
//  Double g;
  Double hyp;
  Vector pos;
  Vector vel;
  Double tmp;
  pos = position - orbiting->Position();
  vel = velocity - orbiting->Velocity();
  altitude = pos.Length() - orbiting->Radius();
//  g = orbiting->Gravitation();
//  L = vel.Cross(pos);
//  v1 = vel.Length();
//  v2 = pos.Length();
//  E = ((v1 * v1) / 2) - (g/ v2);
//  s = -g/ (2 * E);
//  v1 = L.Length();
//  v2 = g* g;
//  e = sqrt(1+2*E*(v1 * v1)/(v2));
//  eccentricity = e;
//  apoapsis = s * (1 + e);
//  periapsis = s * (1 - e);
//  orbitTime = sqrt(4*(M_PI*M_PI)*(s*s*s)/g);
//  hyp = sqrt(L.X() * L.X() + L.Y() * L.Y());
//  ascendingNode = L.Y() / hyp;
//  ascendingNode = asin(ascendingNode) * 180 / M_PI;
//  if (L.X() < 0 && L.Y() < 0) ascendingNode = -180 - ascendingNode;
//  if (L.X() < 0 && L.Y() >= 0) ascendingNode = 180 - ascendingNode;
//  hyp = sqrt(L.Z() * L.Z() + hyp * hyp);
//  inclination = L.Z() / hyp;
//  inclination = asin(inclination) * 180 / M_PI;

  hyp = sqrt(pos.X() * pos.X() + pos.Y() * pos.Y());
  longitude = pos.X() / hyp;
  longitude = asin(longitude) * 180 / M_PI;
  if (pos.X() < 0 && pos.Y() >= 0) longitude = -180 - longitude;
  if (pos.X() >= 0 && pos.Y() >= 0) longitude = 180 - longitude;
//  hyp = sqrt(pos.Z() * pos.Z() + hyp * hyp);
  hyp = pos.Length();
  latitude = pos.Z() / hyp;
  latitude = asin(latitude) * 180 / M_PI;
//  latitude = toDegrees(arctan2(pos.Z(), pos.Length()));
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
  Rx = -pos.Y();
  Ry = pos.X();
  Rz = pos.Z();
  Vx = -vel.Y();
  Vy = vel.X();
  Vz = vel.Z();
  Mu = G * orbiting->Mass();
  R = sqrt(Rx*Rx + Ry*Ry + Rz*Rz);
  V = sqrt(Vx*Vx + Vy*Vy + Vz*Vz);
  a = 1/(2/R - V*V / Mu);
  Hx = Ry*Vz - Rz*Vy;
  Hy = Rz*Vx - Rx*Vz;
  Hz = Rx*Vy - Ry*Vx;
  H = sqrt(Hx*Hx + Hy*Hy + Hz*Hz);
  p = H*H / Mu;
  q = Rx*Vx + Ry*Vy + Rz*Vz;
  eccentricity = sqrt(1 - p/a);
  Ex = 1 - R/a;
  Ey = q / sqrt(a * Mu);
  inclination = acos(Hz / H);
  ascendingNode = 0;
  if (inclination != 0) ascendingNode = arctan2(Hx, -Hy);
  TAx = H*H / (R*Mu) - 1;
  TAy = H*q / (R*Mu);
  trueAnomaly = arctan2(TAy, TAx);
  Cw = (Rx * cos(ascendingNode) + Ry * sin(ascendingNode)) / R;
  Sw = 0;
  if (inclination ==0 || inclination == M_PI)
    Sw = (Ry * cos(ascendingNode) - Rx * sin(ascendingNode)) / R;
  else
    Sw = Rz / (R * sin(inclination));
  argOfPeriapsis = arctan2(Sw, Cw) - trueAnomaly;
  if (argOfPeriapsis < 0) argOfPeriapsis = 2*M_PI+argOfPeriapsis;
  eccentricAnomaly = arctan2(Ey, Ex);
  meanAnomaly = eccentricAnomaly-eccentricity * sin(eccentricAnomaly);
  trueLongitude = argOfPeriapsis + trueAnomaly + ascendingNode;
  while (trueLongitude >= 2*M_PI) trueLongitude = trueLongitude - 2*M_PI;
  PlusMinus = a * eccentricity;
  periapsis = a - PlusMinus;
  apoapsis = a + PlusMinus;
  orbitTime = 2 * M_PI * sqrt(a*a*a / Mu);
  inclination = toDegrees(inclination);
  ascendingNode = toDegrees(ascendingNode);
  eccentricAnomaly = toDegrees(eccentricAnomaly);
  meanAnomaly = toDegrees(meanAnomaly);
  trueAnomaly = toDegrees(trueAnomaly);
  trueLongitude = toDegrees(trueLongitude);
  argOfPeriapsis = toDegrees(argOfPeriapsis);

  spd = orbitTime / 360;
  d = 180 - meanAnomaly;
  while (d<0) d += 360;
  while (d > 360) d -= 360;
  d *= spd;
  clockAp = d;
  d = 360 - meanAnomaly;
  while (d<0) d += 360;
  while (d > 360) d -= 360;
  d *= spd;
  clockPe = d;


//if (this == csm) {
//  GotoXY(40, 28); printf("Radius           : %.10f\n",R);
//  GotoXY(40, 29); printf("Velocity         : %.10f\n",V);
//  GotoXY(40, 30); printf("Semi-Major Axis  : %.10f\n",a);
//  GotoXY(40, 31); printf("Eccentricity     : %.10f\n",eccentricity);
//  GotoXY(40, 32); printf("Inclination      : %.10f\n",inclination);
//  GotoXY(40, 33); printf("Ascending Node   : %.10f\n",ascendingNode);
//  GotoXY(40, 34); printf("Arg of Periapsis : %.10f\n",argOfPeriapsis);
//  GotoXY(40, 35); printf("Eccentric Anomaly: %.10f\n",eccentricAnomaly);
//  GotoXY(40, 36); printf("Mean Anomaly     : %.10f\n",meanAnomaly);
//  GotoXY(40, 37); printf("True Anomaly     : %.10f\n",trueAnomaly);
//  GotoXY(40, 38); printf("True Longitude   : %.10f\n",trueLongitude);
//  GotoXY(40, 39); printf("Periapsis        : %.10f\n",periapsis);
//  GotoXY(40, 40); printf("Apoapsis         : %.10f\n",apoapsis);
//  GotoXY(40, 41); printf("Period           : %.10f\n",orbitTime);
//  }






  if (mission != NULL) {
    tarLatitude = latitude - mission->TargetLatitude();
    tarLongitude = longitude - mission->TargetLongitude();
    while (tarLongitude < -180) tarLongitude += 360;
    while (tarLongitude > 180) tarLongitude -= 360;
    tarMomNorth = inclination - mission->TargetMomNorth();
    tarMomEast = ascendingNode - mission->TargetMomEast();
    while (tarMomNorth < -180) tarMomNorth += 360;
    while (tarMomNorth > 180) tarMomNorth -= 360;
    while (tarMomEast < -180) tarMomEast += 360;
    while (tarMomEast > 180) tarMomEast -= 360;
    }
  tmp = latitude - lastLatitude;
  if (tmp <= -180) tmp += 360;
  if (tmp >= 180) tmp -= 360;
  latitudeVel = tmp * orbiting->Meters();
  latitudeAcc = latitudeVel - lastLatitudeVel;

  lastLatitude = latitude;
  lastLongitude = longitude;
  lastLatitudeVel = latitudeVel;
  }

void Spacecraft::Cycle() {
  Matrix m;
  Double alt3;
  Double g;
  Vector a;
  Vector p1,p2;

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
    roll += (rollRate /GRAN);
    if (roll > 180) roll -= 360;
    if (roll < -180) roll += 360;
    }
  if (pitchRate != 0) {
    pitch += (pitchRate /GRAN);
    if (pitch > 180) pitch -= 360;
    if (pitch < -180) pitch += 360;
    }
  if (yawRate != 0) {
    yaw += (yawRate /GRAN);
    if (yaw > 180) yaw -= 360;
    if (yaw < -180) yaw += 360;
    }
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

  p1 = position - orbiting->Position();
  velocity = velocity + thrust.Scale(1/GRAN);
  deltaV += thrust.Scale(1/GRAN).Length();

  velocity = velocity + drag.Scale(1/GRAN);
  position = position + velocity.Scale(1/GRAN);
  Radius((position - orbiting->Position()).Length());

  if (currentVehicle == this) {
    p2 = position - orbiting->Position();
    distanceTravelled += ((p1-p2).Length());
    }

  if (orbiting == Earth && moonG > earthG) orbiting = Moon;
  if (orbiting == Moon && earthG > moonG) orbiting = Earth;

  Vehicle::Cycle();
  }

void Spacecraft::Save(FILE* file) {
  Vehicle::Save(file);
  fprintf(file,"  Altitude %.18f%s",altitude,LE);
  fprintf(file,"  Apoapsis %.18f%s",apoapsis,LE);
  fprintf(file,"  AscendingNode %.18f%s",ascendingNode,LE);
  fprintf(file,"  Eccentricity %.18f%s",eccentricity,LE);
  fprintf(file,"  DeltaV %.18f%s",deltaV,LE);
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
  else if (startsWith(line,"eccentricity ")) eccentricity = atof(nw(line));
  else if (startsWith(line,"deltav ")) deltaV = atof(nw(line));
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


