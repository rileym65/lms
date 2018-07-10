#include <math.h>
#include "header.h"
#include "vehicle.h"
#include "terminal.h"

Vehicle::Vehicle() {
  velocityAltitude = 0;
  velocityEast = 0;
  velocityNorth = 0;
  thrust = Vector(0,0,0);
  velocity = Vector(0,0,0);
  faceFront = Vector(0,1,0);
  faceLeft = Vector(1,0,0);
  faceUp = Vector(0,0,1);
  orientation = Matrix::Identity();
  panel = NULL;
  comp= NULL;
  rcsThrottle = 1;
  rcsRotThrottle = 100;
  roll = 0;
  pitch = 0;
  yaw = 0;
  rcsFbMode = ' ';
  rcsLrMode = ' ';
  rcsUdMode = ' ';
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

Double Vehicle::Altitude() {
  return altitude;
  }

Double Vehicle::Altitude(Double d) {
  altitude = d;
  radius = altitude + 1738300;
  return altitude;
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

Double Vehicle::EBattery() {
  return ebattery;
  }

Double Vehicle::EBattery(Double d) {
  ebattery = d;
  if (ebattery < 0) ebattery = 0;
  return ebattery;
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

Double Vehicle::MaxBattery() {
  return maxBattery;
  }

Double Vehicle::MaxBattery(Double d) {
  maxBattery = d;
  return maxBattery;
  }

Double Vehicle::MaxOxygen() {
  return maxOxygen;
  }

Double Vehicle::MaxOxygen(Double d) {
  maxOxygen = d;
  return maxOxygen;
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
  return pitch;
  }

Double Vehicle::PitchRate() {
  return pitchRate;
  }

Double Vehicle::PitchRate(Double d) {
  pitchRate = d;
  pitchMatrix = Matrix::RotateY(-pitchRate);
  return pitchRate;
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
  radius = d;
  altitude = radius - 1738300;
  return radius;
  }

char   Vehicle::RcsFbMode() {
  return rcsFbMode;
  }

char   Vehicle::RcsFbMode(char c) {
  rcsFbMode = c;
  return rcsFbMode;
  }

char   Vehicle::RcsLrMode() {
  return rcsLrMode;
  }

char   Vehicle::RcsLrMode(char c) {
  rcsLrMode = c;
  return rcsLrMode;
  }

Int8   Vehicle::RcsRotThrottle() {
  return rcsRotThrottle;
  }

Int8   Vehicle::RcsRotThrottle(Int8 i) {
  rcsRotThrottle = i;
  return rcsRotThrottle;
  }

Int8   Vehicle::RcsThrottle() {
  return rcsThrottle;
  }

Int8   Vehicle::RcsThrottle(Int8 i) {
  if (i < 10) i = 1;
  else if (i < 25) i = 10;
  else i = 100;
  rcsThrottle = i;
  return rcsThrottle;
  }

char   Vehicle::RcsUdMode() {
  return rcsUdMode;
  }

char   Vehicle::RcsUdMode(char c) {
  rcsUdMode = c;
  return rcsUdMode;
  }

Double Vehicle::Roll() {
  return roll;
  }

Double Vehicle::RollRate() {
  return rollRate;
  }

Double Vehicle::RollRate(Double d) {
  rollRate = d;
  rollMatrix = Matrix::RotateZ(-rollRate);
  return rollRate;
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
  return yaw;
  }

Double Vehicle::YawRate() {
  return yawRate;
  }

Double Vehicle::YawRate(Double d) {
  yawRate = d;
  yawMatrix = Matrix::RotateX(yawRate);
  return yawRate;
  }

/* ************************* */
/* ***** Other methods ***** */
/* ************************* */

void Vehicle::Cycle() {
  Vector a;
  Double alt3;
  Double hyp;
  Double v1,v2;
  Double vel;
  Vector vnorm;
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
  a = position.Scale(-4.9075e12);
  a = a.Scale(1/alt3);
  velocity = velocity + a;
  velocity = velocity + thrust;
  v1 = velocity.Dot(position.Norm());
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
  vnorm = velocity.Norm();
  v2 = velocity.Dot(position.Norm());
  a = Vector(position.Y(), -position.X(), 0.0).Norm();
  vel= -(velocity.Dot(a));
  accelEast = vel - velocityEast;
  velocityEast = vel;
  vel= velocity.Dot(Vector(0,0,1));
  accelNorth = vel - velocityNorth;
  velocityNorth = vel;
  vel = v1 + ((v2 - v1) / 2);
  accelAltitude = vel - velocityAltitude;
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
    else if (startsWith(pline,"battery ")) battery = atof(nw(pline));
    else if (startsWith(pline,"maxbattery ")) maxBattery = atof(nw(pline));
    else if (startsWith(pline,"ebattery ")) ebattery = atof(nw(pline));
    else if (startsWith(pline,"oxygen ")) oxygen = atof(nw(pline));
    else if (startsWith(pline,"maxoxygen ")) maxOxygen = atof(nw(pline));
    else if (startsWith(pline,"eoxygen ")) eoxygen = atof(nw(pline));
    else if (startsWith(pline,"pitchrate ")) PitchRate(atof(nw(pline)));
    else if (startsWith(pline,"rollrate ")) RollRate(atof(nw(pline)));
    else if (startsWith(pline,"yawrate ")) YawRate(atof(nw(pline)));
    else if (startsWith(pline,"pitch ")) pitch = atof(nw(pline));
    else if (startsWith(pline,"roll ")) roll = atof(nw(pline));
    else if (startsWith(pline,"yaw ")) yaw = atof(nw(pline));
    else if (startsWith(pline,"rcsthrottle ")) rcsThrottle = atoi(nw(pline));
    else if (startsWith(pline,"rcsrotthrottle ")) rcsRotThrottle = atoi(nw(pline));
    else if (startsWith(pline,"rcsfbmode ")) rcsFbMode = atoi(nw(pline));
    else if (startsWith(pline,"rcslrmode ")) rcsLrMode = atoi(nw(pline));
    else if (startsWith(pline,"rcsudmode ")) rcsUdMode = atoi(nw(pline));
    else if (startsWith(pline,"panel {")) panel->Load(file);
    else if (SubLoad(pline) == 0) {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
    }
  }

Double Vehicle::Mass() {
  return 0;
  }

void Vehicle::ProcessKey(Int32 key) {
  if (key == 'M') seq->MoveLm();
  }

void Vehicle::Save(FILE* file) {
  fprintf(file,"  Altitude %.18f%s",altitude,LE);
  fprintf(file,"  Latitude %.18f%s",latitude,LE);
  fprintf(file,"  Longitude %.18f%s",longitude,LE);
  fprintf(file,"  Radius %.18f%s",radius,LE);
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
  fprintf(file,"  Roll %.18f%s",roll,LE);
  fprintf(file,"  Yaw %.18f%s",yaw,LE);
  fprintf(file,"  Pitch %.18f%s",pitch,LE);
  fprintf(file,"  RcsThrottle %d%s",rcsThrottle,LE);
  fprintf(file,"  RcsRotThrottle %d%s",rcsRotThrottle,LE);
  fprintf(file,"  RcsFbMode %d%s",rcsFbMode,LE);
  fprintf(file,"  RcsLrMode %d%s",rcsLrMode,LE);
  fprintf(file,"  RcsUdMode %d%s",rcsUdMode,LE);
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
  if (panel != NULL) panel->Save(file);
  }

void Vehicle::SetupPanel() {
  ClrScr();
  if (panel != NULL) {
    panel->Reset();
    panel->Display();
    }
  }

Int8 Vehicle::SubLoad(char* line) {
  return 0;
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
  if (metabolicRate < 60) units += (.2 * ((metabolicRate - 30) / 30.0));
  if (metabolicRate >= 60) {
    units += .2;
    units += ((metabolicRate - 60) / 10.0);
    }
  oxygen -= units;
  if (oxygen >= 0) return true;
  eoxygen += oxygen;
  oxygen = 0;
  if (eoxygen >= 0) return true;
  eoxygen = 0;
  return false;
  }

