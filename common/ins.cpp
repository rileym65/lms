#include <stdio.h>
#include <math.h>
#include "common.h"
#include "ins.h"
#include "helpers.h"

Ins::Ins(Vehicle* v) {
  vehicle = v;
  altitude = 0.0;
  apoapsis = 0.0;
  argOfPeriapsis = 0.0;
  clockAp = 0;
  clockPe = 0;
  deltaApoapsis = 0.0;
  deltaROC = 0.0;
  eccentricAnomaly = 0.0;
  eccentricity = 0.0;
  inclination = 0.0;
  latitude = 0.0;
  latitudeAcc = 0.0;
  latitudeVel = 0.0;
  longitude = 0.0;
  lastAltitude = 0.0;
  lastApoapsis = 0.0;
  lastLatitude = 0.0;
  lastLatitudeVel = 0.0;
  lastLongitude = 0.0;
  lastROC = 0.0;
  meanAnomaly = 0.0;
  orbiting = NULL;
  orbitTime = 0.0;
  periapsis = 0.0;
  rateOfClimb = 0.0;
  tarLatitude = 0.0;
  tarLongitude = 0.0;
  tarMomEast = 0.0;
  tarMomNorth = 0.0;
  tarDockX = 0.0;
  tarDockY = 0.0;
  trueAnomaly = 0.0;
  trueLongitude = 0.0;
  }

Ins::~Ins() {
  }

Double Ins::Altitude() {
  return altitude;
  }

Double Ins::Altitude(Double d) {
  altitude = d;
  if (orbiting != NULL)
    radius = altitude + orbiting->Radius();
  else
    radius = altitude;
  return altitude;
  }

Double Ins::Apoapsis() {
  return apoapsis;
  }

Double Ins::Apoapsis(Double d) {
  apoapsis = d;
  return apoapsis;
  }

Double Ins::ArgOfPeriapsis() {
  return argOfPeriapsis;
  }

Double Ins::ArgOfPeriapsis(Double d) {
  argOfPeriapsis = d;
  return argOfPeriapsis;
  }

Double Ins::AscendingNode() {
  return ascendingNode;
  }

Double Ins::AscendingNode(Double d) {
  ascendingNode = d;
  return ascendingNode;
  }

Int32 Ins::ClockAp() {
  return clockAp;
  }

Int32 Ins::ClockAp(Int32 i) {
  clockAp = i;
  return clockAp;
  }

Int32 Ins::ClockPe() {
  return clockPe;
  }

Int32 Ins::ClockPe(Int32 i) {
  clockPe = i;
  return clockPe;
  }

Double Ins::DeltaApoapsis() {
  return deltaApoapsis;
  }

Double Ins::DeltaROC() {
  return deltaROC;
  }

Double Ins::EccentricAnomaly() {
  return eccentricAnomaly;
  }

Double Ins::EccentricAnomaly(Double d) {
  eccentricAnomaly = d;
  return eccentricAnomaly;
  }

Double Ins::Eccentricity() {
  return eccentricity;
  }

Double Ins::Eccentricity(Double d) {
  eccentricity = d;
  return eccentricity;
  }

Double Ins::Inclination() {
  return inclination;
  }

Double Ins::Inclination(Double d) {
  inclination = d;
  return inclination;
  }

Double Ins::Latitude() {
  return latitude;
  }

Double Ins::Latitude(Double d) {
  latitude = d;
  return latitude;
  }

Double Ins::Longitude() {
  return longitude;
  }

Double Ins::Longitude(Double d) {
  longitude = d;
  return longitude;
  }

Double Ins::LastLatitude() {
  return lastLatitude;
  }

Double Ins::LastLatitude(Double d) {
  lastLatitude = d;
  return lastLatitude;
  }

Double Ins::LastLatitudeVel() {
  return lastLatitudeVel;
  }

Double Ins::LastLatitudeVel(Double d) {
  lastLatitudeVel = d;
  return lastLatitudeVel;
  }

Double Ins::LastLongitude() {
  return lastLongitude;
  }

Double Ins::LastLongitude(Double d) {
  lastLongitude = d;
  return lastLongitude;
  }

Double Ins::LatitudeAcc() {
  return latitudeAcc;
  }

Double Ins::LatitudeAcc(Double d) {
  latitudeAcc = d;
  return latitudeAcc;
  }

Double Ins::LatitudeVel() {
  return latitudeVel;
  }

Double Ins::LatitudeVel(Double d) {
  latitudeVel = d;
  return latitudeVel;
  }

Double Ins::MeanAnomaly() {
  return meanAnomaly;
  }

Double Ins::MeanAnomaly(Double d) {
  meanAnomaly = d;
  return meanAnomaly;
  }

Body* Ins::Orbiting() {
  return orbiting;
  }

Body* Ins::Orbiting(Body* b) {
  orbiting = b;
  return orbiting;
  }

Double Ins::OrbitTime() {
  return orbitTime;
  }

Double Ins::OrbitTime(Double d) {
  orbitTime = d;
  return orbitTime;
  }

Double Ins::Periapsis() {
  return periapsis;
  }

Double Ins::Periapsis(Double d) {
  periapsis = d;
  return periapsis;
  }

Double Ins::Radius() {
  return radius;
  }

Double Ins::Radius(Double d) {
  radius = d;
  if (orbiting != NULL)
    altitude = radius - orbiting->Radius();
  else
    altitude = radius;
  return radius;
  }

Double Ins::RateOfClimb() {
  return rateOfClimb;
  }

Double Ins::TarLatitude() {
  return tarLatitude;
  }

Double Ins::TarLatitude(Double d) {
  tarLatitude = d;
  return tarLatitude;
  }

Double Ins::TarLongitude() {
  return tarLongitude;
  }

Double Ins::TarLongitude(Double d) {
  tarLongitude = d;
  return tarLongitude;
  }

Double Ins::TarMomEast() {
  return tarMomEast;
  }

Double Ins::TarMomEast(Double d) {
  tarMomEast = d;
  return tarMomEast;
  }

Double Ins::TarMomNorth() {
  return tarMomNorth;
  }

Double Ins::TarMomNorth(Double d) {
  tarMomNorth = d;
  return tarMomNorth;
  }

Double Ins::TarDockX() {
  return tarDockX;
  }

Double Ins::TarDockX(Double d) {
  tarDockX = d;
  return tarDockX;
  }

Double Ins::TarDockY() {
  return tarDockY;
  }

Double Ins::TarDockY(Double d) {
  tarDockY = d;
  return tarDockY;
  }

Double Ins::TarDockZ() {
  return tarDockZ;
  }

Double Ins::TarDockZ(Double d) {
  tarDockZ = d;
  return tarDockZ;
  }

Double Ins::TarDockVelX() {
  return tarDockVelX;
  }

Double Ins::TarDockVelX(Double d) {
  tarDockVelX = d;
  return tarDockVelX;
  }

Double Ins::TarDockVelY() {
  return tarDockVelY;
  }

Double Ins::TarDockVelY(Double d) {
  tarDockVelY = d;
  return tarDockVelY;
  }

Double Ins::TarDockVelZ() {
  return tarDockVelZ;
  }

Double Ins::TarDockVelZ(Double d) {
  tarDockVelZ = d;
  return tarDockVelZ;
  }

Double Ins::TrueAnomaly() {
  return trueAnomaly;
  }

Double Ins::TrueAnomaly(Double d) {
  trueAnomaly = d;
  return trueAnomaly;
  }

Double Ins::TrueLongitude() {
  return trueLongitude;
  }

Double Ins::TrueLongitude(Double d) {
  trueLongitude = d;
  return trueLongitude;
  }

void Ins::Cycle() {
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
  pos = vehicle->Position() - orbiting->Position();
  vel = vehicle->Velocity() - orbiting->Velocity();
  altitude = pos.Length() - orbiting->Radius();

  hyp = sqrt(pos.X() * pos.X() + pos.Y() * pos.Y());
  longitude = pos.X() / hyp;
  longitude = asin(longitude) * 180 / M_PI;
  if (pos.X() < 0 && pos.Y() >= 0) longitude = -180 - longitude;
  if (pos.X() >= 0 && pos.Y() >= 0) longitude = 180 - longitude;
  hyp = pos.Length();
  latitude = pos.Z() / hyp;
  latitude = asin(latitude) * 180 / M_PI;
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
  latitudeVel = tmp * Orbiting()->Meters();
  latitudeAcc = latitudeVel - lastLatitudeVel;

  rateOfClimb = altitude - lastAltitude;
  deltaROC = rateOfClimb - lastROC;
  deltaApoapsis = apoapsis - lastApoapsis;

  lastAltitude = altitude;
  lastLatitude = latitude;
  lastLongitude = longitude;
  lastLatitudeVel = latitudeVel;
  lastROC = rateOfClimb;
  lastApoapsis = apoapsis;

  if (vehicle->TargetVehicle() == NULL || dockingRadarOn == 0) {
    tarDockX = 9999.9;
    tarDockY = 9999.9;
    tarDockZ = 9999.9;
    tarDockVelX = 9999.9;
    tarDockVelY = 9999.9;
    tarDockVelZ = 9999.9;
    return; 
    }
  if (docked) {
    tarDockX = 0;
    tarDockY = 0;
    tarDockZ = 0;
    tarDockVelX = 0;
    tarDockVelY = 0;
    tarDockVelZ = 0;
    return;
    }
  pos = vehicle->Position() - (vehicle->TargetVehicle()->Position());
  if (pos.Length() > 250) {
    tarDockX = 9999.9;
    tarDockY = 9999.9;
    tarDockZ = 9999.9;
    tarDockVelX = 9999.9;
    tarDockVelY = 9999.9;
    tarDockVelZ = 9999.9;
    return; 
    }
  L =  vehicle->TargetVehicle()->FaceLeft().Norm();
  tarDockX = pos.Norm().Dot(L) * pos.Length();
  L =  vehicle->TargetVehicle()->FaceFront().Norm();
  tarDockY = pos.Norm().Dot(L) * pos.Length();
  tarDockZ = pos.Length() - 5.275;
  vel = vehicle->Velocity() - (vehicle->TargetVehicle()->Velocity());
  L =  vehicle->TargetVehicle()->FaceLeft().Norm();
  tarDockVelX = vel.Norm().Dot(L) * vel.Length();
  L =  vehicle->TargetVehicle()->FaceFront().Norm();
  tarDockVelY = vel.Norm().Dot(L) * vel.Length();
  L =  vehicle->TargetVehicle()->FaceUp().Norm();
  tarDockVelZ = vel.Norm().Dot(L) * vel.Length();
  }

