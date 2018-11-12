#include <math.h>
#include <stdlib.h>
#include "vehicle.h"
#include "terminal.h"
#include "helpers.h"
#include "common.h"

Vehicle::Vehicle() {
  distanceTravelled = 0;
  velocityAltitude = 0;
  velocityEast = 0;
  velocityNorth = 0;
  thrust = Vector(0,0,0);
  drag = Vector(0,0,0);
  velocity = Vector(0,0,0);
  faceFront = Vector(0,1,0);
  faceLeft = Vector(1,0,0);
  faceUp = Vector(0,0,1);
  gimbals = Vector(0,0,0);
  panel = NULL;
  comp= NULL;
  type = VT_NONE;
  targetVehicle = NULL;
  Init();
  InitPanel();
  }

Vehicle::~Vehicle() {
  }

/* ****************************** */
/* ***** Accessor functions ***** */
/* ****************************** */

Double Vehicle::AccelAltitude() {
  if (accelAltitude > 999) return 999;
  if (accelAltitude < -999) return -999;
  return accelAltitude;
  }

Double Vehicle::AccelEast() {
  if (accelEast > 999) return 999;
  if (accelEast < -999) return -999;
  return accelEast;
  }

Double Vehicle::AccelNorth() {
  if (accelNorth > 999) return 999;
  if (accelNorth < -999) return -999;
  return accelNorth;
  }

Double Vehicle::AddDistance(Double d) {
  distanceTravelled += d;
  return distanceTravelled;
  }

Double Vehicle::Battery() {
  return battery;
  }

Double Vehicle::Battery(Double d) {
  battery = d;
  if (battery < 0) battery = 0;
  return battery;
  }

Computer* Vehicle::Comp() {
  return comp;
  }

Computer* Vehicle::Comp(Computer* c) {
  comp= c;
  return comp;
  }

void Vehicle::Damage(Double dmg) {
  }

Boolean Vehicle::Destroyed() {
  return destroyed;
  }

Double Vehicle::DistanceTravelled() {
  return distanceTravelled;
  }

Double Vehicle::DryWeight() {
  return dryWeight;
  }

Double Vehicle::DryWeight(Double d) {
  dryWeight = d;
  return dryWeight;
  }

Double Vehicle::EBattery() {
  return ebattery;
  }

Double Vehicle::EBattery(Double d) {
  ebattery = d;
  if (ebattery < 0) ebattery = 0;
  return ebattery;
  }

Byte Vehicle::EnginesLit() {
  return 0;
  }

Double Vehicle::EOxygen() {
  return eoxygen;
  }

Double Vehicle::EOxygen(Double d) {
  eoxygen = d;
  if (eoxygen < 0) eoxygen = 0;
  return eoxygen;
  }

Vector Vehicle::FaceFront() {
  return faceFront;
  }

Vector Vehicle::FaceFront(Vector v) {
  faceFront = v;
  return faceFront;
  }

Vector Vehicle::FaceLeft() {
  return faceLeft;
  }

Vector Vehicle::FaceLeft(Vector v) {
  faceLeft = v;
  return faceLeft;
  }

Vector Vehicle::FaceUp() {
  return faceUp;
  }

Vector Vehicle::FaceUp(Vector v) {
  faceUp = v;
  return faceUp;
  }

Double Vehicle::Fuel() {
  return 0;
  }

Double Vehicle::Latitude() {
  return latitude;
  }

Double Vehicle::Latitude(Double d) {
  latitude = d;
  return latitude;
  }

Double Vehicle::LatitudeVelocity() {
  return latitudeVel;
  }

Double Vehicle::LatitudeAcceleration() {
  return latitudeAcc;
  }

Double Vehicle::Longitude() {
  return longitude;
  }

Double Vehicle::Longitude(Double d) {
  longitude = d;
  return longitude;
  }

Double Vehicle::Mass() {
  return 0;
  }

Double Vehicle::MaxBattery() {
  return maxBattery;
  }

Double Vehicle::MaxBattery(Double d) {
  maxBattery = d;
  return maxBattery;
  }

Double Vehicle::MaxFuel() {
  return 1e-20;
  }

Double Vehicle::MaxOxygen() {
  return maxOxygen;
  }

Double Vehicle::MaxOxygen(Double d) {
  maxOxygen = d;
  return maxOxygen;
  }

Byte Vehicle::NumEngines() {
  return 0;
  }

Byte Vehicle::NumEngines(Byte stage) {
  return 0;
  }

Byte Vehicle::NumStages() {
  return 1;
  }

Body* Vehicle::Orbiting() {
  return orbiting;
  }

Body* Vehicle::Orbiting(Body* b) {
  orbiting = b;
  return orbiting;
  }

Double Vehicle::OrbitTime() {
  return orbitTime;
  }

Double Vehicle::Oxygen() {
  return oxygen;
  }

Double Vehicle::Oxygen(Double d) {
  oxygen = d;
  if (oxygen < 0) oxygen = 0;
  return oxygen;
  }

Double Vehicle::Pitch() {
  return gimbals.Y();
  }

Double Vehicle::Pitch(Double d) {
  gimbals.Y(d);
  return gimbals.Y();
  }

Double Vehicle::PitchRate() {
  return pitchRate;
  }

Double Vehicle::PitchRate(Double d) {
  pitchRate = d;
  return pitchRate;
  }

Vector Vehicle::Position() {
  return position;
  }

Vector Vehicle::Position(Vector v) {
  position = v;
  return position;
  }

Double Vehicle::Roll() {
  return gimbals.X();
  }

Double Vehicle::Roll(Double d) {
  gimbals.X(d);
  return gimbals.X();
  }

Double Vehicle::RollRate() {
  return rollRate;
  }

Double Vehicle::RollRate(Double d) {
  rollRate = d;
  return rollRate;
  }

Byte Vehicle::Stage() {
  return 1;
  }

Vehicle* Vehicle::TargetVehicle() {
  return targetVehicle;
  }

Vehicle* Vehicle::TargetVehicle(Vehicle* v) {
  targetVehicle = v;
  return targetVehicle;
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

Byte Vehicle::Type() {
  return type;
  }

Vector Vehicle::Velocity() {
  return velocity;
  }

Vector Vehicle::Velocity(Vector v) {
  velocity = v;
  return velocity;
  }

Double Vehicle::VelocityAltitude() {
  return velocityAltitude;
  }

Double Vehicle::VelocityEast() {
  return velocityEast;
  }

Double Vehicle::VelocityNorth() {
  return velocityNorth;
  }

Double Vehicle::Yaw() {
  return gimbals.Z();
  }

Double Vehicle::Yaw(Double d) {
  gimbals.Z(d);
  return gimbals.Z();
  }

Double Vehicle::YawRate() {
  return yawRate;
  }

Double Vehicle::YawRate(Double d) {
  yawRate = d;
  return yawRate;
  }

/* ************************* */
/* ***** Other methods ***** */
/* ************************* */

void Vehicle::Cycle() {
  Vector L;
  Vector rvel;
  Vector rpos;
//  Double E;
//  Double s;
//  Double e;
  Vector a;
//  Double alt3;
//  Double hyp;
  Double v1,v2;
  Double vel;
//  Double tmp;
  Vector vnorm;
  rvel = velocity - orbiting->Velocity();
  rpos = position - orbiting->Position();
//  Double g;
//  lastLatitude = latitude;
//  lastLongitude = longitude;
//  lastLatitudeVel = latitudeVel;
//  if (rollRate != 0) {
//    roll += rollRate;
//    if (roll > 180) roll -= 360;
//    if (roll < -180) roll += 360;
//    }
//  if (pitchRate != 0) {
//    pitch += pitchRate;
//    if (pitch > 180) pitch -= 360;
//    if (pitch < -180) pitch += 360;
//    }
//  if (yawRate != 0) {
//    yaw += yawRate;
//    if (yaw > 180) yaw -= 360;
//    if (yaw < -180) yaw += 360;
//    }
//  alt3 = radius * radius * radius;
//  g = orbiting->Gravitation();
//  a = position.Scale(-g);
//  a = a.Scale(1/alt3);
//  velocity = velocity + a;
//  velocity = velocity + thrust;
//  v1 = velocity.Dot(position.Norm());
//  position = position + velocity;
//  Radius(position.Length());

//  g = orbiting->Gravitation();
  v1 = rvel.Dot(rpos.Norm());
//  hyp = sqrt(position.X() * position.X() + position.Y() * position.Y());
//  longitude = position.X() / hyp;
//  longitude = asin(longitude) * 180 / M_PI;
//  if (position.X() < 0 && position.Y() >= 0) longitude = -180 - longitude;
//  if (position.X() >= 0 && position.Y() >= 0) longitude = 180 - longitude;
//  hyp = sqrt(position.Z() * position.Z() + hyp * hyp);
//  latitude = position.Z() / hyp;
//  latitude = asin(latitude) * 180 / M_PI;

  vnorm = rvel.Norm();
  v2 = rvel.Dot(rpos.Norm());
  a = Vector(rpos.Y(), -rpos.X(), 0.0).Norm();
  vel= -(rvel.Dot(a));
  accelEast = (vel - velocityEast) * GRAN;
  velocityEast = vel;
  vel= rvel.Dot(Vector(0,0,1));
  accelNorth = (vel - velocityNorth) * GRAN;
  velocityNorth = vel;
  vel = v1 + ((v2 - v1) / 2);
  accelAltitude = (vel - velocityAltitude) * GRAN;
  velocityAltitude = vel;
  if (isnan(accelNorth)) accelNorth = 0;
  if (isnan(accelEast)) accelEast = 0;
  if (isnan(accelAltitude)) accelAltitude = 0;
  if (accelNorth > 999) accelNorth = 999;
  if (accelEast > 999) accelEast = 999;
  if (accelAltitude > 999) accelAltitude = 999;
  if (accelNorth < -999) accelNorth = -999;
  if (accelEast < -999) accelEast = -999;
  if (accelAltitude < -999) accelAltitude = -999;
//  tmp = latitude - lastLatitude;
//  if (tmp <= -180) tmp += 360;
//  if (tmp >= 180) tmp -= 360;
//  latitudeVel = tmp * orbiting->Meters();
//  latitudeAcc = latitudeVel - lastLatitudeVel;

/*
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
    lan = L.Y() / hyp;
    lan = asin(lan) * 180 / M_PI;
    if (L.X() < 0 && L.Y() < 0) lan = -180 - lan;
    if (L.X() < 0 && L.Y() >= 0) lan = 180 - lan;
    hyp = sqrt(L.Z() * L.Z() + hyp * hyp);
    incl = L.Z() / hyp;
    incl = asin(incl) * 180 / M_PI;
    }
*/
  }

void Vehicle::Init() {
  throttle = 0;
  oxygen = 0;
  battery = 0;
  eoxygen = 0;
  ebattery = 0;
  maxOxygen = 0;
  maxBattery = 0;
  }

void Vehicle::InitPanel() {
  panel = new Panel("ams.pnl",this);
  }

void Vehicle::Load(FILE* file) {
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) {
      return;
      }
    else if (startsWith(pline,"panel {")) panel->Load(file);
    else if (SubLoad(file, pline) == 0) {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
    }
printf("done with vehicle::load\n"); fflush(stdout);
  }

void Vehicle::ProcessKey(Int32 key) {
  }

void Vehicle::Save(FILE* file) {
  fprintf(file,"  Latitude %.18f%s",latitude,LE);
  fprintf(file,"  Longitude %.18f%s",longitude,LE);
  fprintf(file,"  Distance %.18f%s",distanceTravelled,LE);
  fprintf(file,"  Battery %.18f%s",battery,LE);
  fprintf(file,"  MaxBattery %.18f%s",maxBattery,LE);
  fprintf(file,"  EBattery %.18f%s",ebattery,LE);
  fprintf(file,"  Oxygen %.18f%s",oxygen,LE);
  fprintf(file,"  MaxOxygen %.18f%s",maxOxygen,LE);
  fprintf(file,"  EOxygen %.18f%s",eoxygen,LE);
  fprintf(file,"  Throttle %d%s",throttle,LE);
  fprintf(file,"  RollRate %.18f%s",rollRate,LE);
  fprintf(file,"  YawRate %.18f%s",yawRate,LE);
  fprintf(file,"  PitchRate %.18f%s",pitchRate,LE);
  fprintf(file,"  Orbiting %s%s",orbiting->Name(),LE);
  fprintf(file,"  Gimbals %.18f %.18f %.18f%s",gimbals.X(),gimbals.Y(),gimbals.Z(),LE);
  fprintf(file,"  FaceFront %.18f %.18f %.18f%s",faceFront.X(),faceFront.Y(),faceFront.Z(),LE);
  fprintf(file,"  FaceUp %.18f %.18f %.18f%s",faceUp.X(),faceUp.Y(),faceUp.Z(),LE);
  fprintf(file,"  FaceLeft %.18f %.18f %.18f%s",faceLeft.X(),faceLeft.Y(),faceLeft.Z(),LE);
  fprintf(file,"  Position %.18f %.18f %.18f%s",position.X(),position.Y(),position.Z(),LE);
  fprintf(file,"  Velocity %.18f %.18f %.18f%s",velocity.X(),velocity.Y(),velocity.Z(),LE);
  fprintf(file,"  Thrust %.18f %.18f %.18f%s",thrust.X(),thrust.Y(),thrust.Z(),LE);
  fprintf(file,"  DryWeight %.18f%s",dryWeight,LE);
  if (panel != NULL) panel->Save(file);
  }

void Vehicle::SetupPanel() {
  ClrScr();
  if (panel != NULL) {
    panel->Reset();
    panel->Display();
    }
  }

Int8 Vehicle::SubLoad(FILE* file, char* line) {
  if (startsWith(line,"latitude ")) latitude = atof(nw(line));
  else if (startsWith(line,"longitude ")) longitude = atof(nw(line));
  else if (startsWith(line,"distance ")) distanceTravelled = atof(nw(line));
  else if (startsWith(line,"gimbals ")) gimbals = atov(nw(line));
  else if (startsWith(line,"facefront ")) faceFront = atov(nw(line));
  else if (startsWith(line,"faceup ")) faceUp = atov(nw(line));
  else if (startsWith(line,"faceleft ")) faceLeft = atov(nw(line));
  else if (startsWith(line,"position ")) position = atov(nw(line));
  else if (startsWith(line,"velocity ")) velocity = atov(nw(line));
  else if (startsWith(line,"thrust ")) thrust = atov(nw(line));
  else if (startsWith(line,"throttle ")) throttle = atoi(nw(line));
  else if (startsWith(line,"battery ")) battery = atof(nw(line));
  else if (startsWith(line,"maxbattery ")) maxBattery = atof(nw(line));
  else if (startsWith(line,"ebattery ")) ebattery = atof(nw(line));
  else if (startsWith(line,"oxygen ")) oxygen = atof(nw(line));
  else if (startsWith(line,"maxoxygen ")) maxOxygen = atof(nw(line));
  else if (startsWith(line,"eoxygen ")) eoxygen = atof(nw(line));
  else if (startsWith(line,"pitchrate ")) PitchRate(atof(nw(line)));
  else if (startsWith(line,"rollrate ")) RollRate(atof(nw(line)));
  else if (startsWith(line,"yawrate ")) YawRate(atof(nw(line)));
  else if (startsWith(line,"pitch ")) gimbals.Y(atof(nw(line)));
  else if (startsWith(line,"roll ")) gimbals.X(atof(nw(line)));
  else if (startsWith(line,"yaw ")) gimbals.Z(atof(nw(line)));
  else if (startsWith(line,"dryweight ")) dryWeight = atof(nw(line));
  else if (startsWith(line,"orbiting earth")) orbiting = Earth;
  else if (startsWith(line,"orbiting moon")) orbiting = Moon;
  else return 0;
  return -1;
  }

void Vehicle::UpdatePanel() {
  if (panel != NULL)
    panel->Update();
  }

Boolean Vehicle::UseBattery(Double units) {
  battery -= units;
  if (battery >= 0) return true;
  ebattery += battery;
  battery = 0;
  if (ebattery >= 0) return true;
  ebattery = 0;
  return false;
  }

Boolean Vehicle::UseOxygen(Double units) {
  oxygen -= units;
  if (oxygen >= 0) return true;
  eoxygen += oxygen;
  oxygen = 0;
  if (eoxygen >= 0) return true;
  eoxygen = 0;
  return false;
  }

