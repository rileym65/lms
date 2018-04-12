#include "header.h"
#include "ins.h"
#include "terminal.h"
#include "math.h"

INS::INS() {
  accAltitude = 0;
  accEast = 0;
  accNorth = 0;
  attUr = 0;
  attFr = 0;
  attLs = 0;
  apolune = 0;
  momEast = 0;
  momNorth = 0;
  perilune = 0;
  orbitTime = 0;
  relAccAltitude = 0;
  relAccEast = 0;
  relAccNorth = 0;
  tarLatitude = 0;
  tarLongitude = 0;
  mode = INS_MODE_POS_ABS;
  target = NULL;
  spacecraft = NULL;
  noData();
  strcpy(displayApolune,"-------");
  strcpy(displayPerilune,"-------");
  }

INS::~INS() {
  }

void INS::Cycle() {
  Vector L;
  Double e;
  Double E;
  Double s;
  Double hyp;
  Vector pos;
  Vector vel;
  Vector orbit;
  pos = spacecraft->Position();
  vel = spacecraft->Velocity();
  orbit = Vector(pos.Y(),-pos.X(),0).Norm();
//  accAltitude = spacecraft->VelocityAltitude() - lastVelAltitude;
  accAltitude = spacecraft->AccelAltitude();
//  lastVelAltitude = spacecraft->VelocityAltitude();
//  accEast = spacecraft->VelocityEast() - lastVelEast;
  accEast = spacecraft->AccelEast();
//  lastVelEast = spacecraft->VelocityEast();
//  accNorth = spacecraft->VelocityNorth() - lastVelNorth;
  accNorth = spacecraft->AccelNorth();
  lastVelNorth = spacecraft->VelocityNorth();
  relPos = spacecraft->Position() - target->Position();
  relVel = spacecraft->Velocity() - target->Velocity();
  relAltitude = spacecraft->Position().Length() - target->Position().Length();
  relLatitude = spacecraft->Latitude() - target->Latitude();
  relLongitude = spacecraft->Longitude() - target->Longitude();
  L = vel.Cross(pos);
  E = vel.Length() * vel.Length() / 2 - MOON / pos.Length();
  s = -MOON / (2 * E);
  e = sqrt(1+2*E*(L.Length()*L.Length())/(MOON*MOON));
  apolune = s * (1 + e);
  perilune = s * (1 - e);
  orbitTime = sqrt(4*(M_PI*M_PI)*(s*s*s)/MOON);
  hyp = sqrt(L.X() * L.X() + L.Y() * L.Y());
  momEast = L.Y() / hyp;
  momEast = asin(momEast) * 180 / M_PI;
  if (L.X() < 0 && L.Y() < 0) momEast = -180 - momEast;
  if (L.X() < 0 && L.Y() >= 0) momEast = 180 - momEast;
  hyp = sqrt(L.Z() * L.Z() + hyp * hyp);
  momNorth = L.Z() / hyp;
  momNorth = asin(momNorth) * 180 / M_PI;
  attUr = acos(pos.Norm().Dot(spacecraft->FaceUp())) * 180 / M_PI;
  attFr = acos(pos.Norm().Dot(spacecraft->FaceFront())) * 180 / M_PI;
  attLs = acos(spacecraft->FaceLeft().Dot(Vector(0,0,-1))) * 180 / M_PI;
  tarLatitude = spacecraft->Latitude() - mission->TargetLatitude();
  tarLongitude = spacecraft->Longitude() - mission->TargetLongitude();
  if (tarLongitude <= -180) tarLongitude += 360;
  if (tarLongitude >= 180) tarLongitude -= 360;

  if (mode == INS_MODE_POS_ABS) populatePosAbs();
  if (mode == INS_MODE_POS_TAR) populatePosTar();
  if (mode == INS_MODE_POS_REL) populatePosRel();
  if (mode == INS_MODE_ORB_ABS) populateOrbAbs();
  if (mode == INS_MODE_ORB_TAR) populateOrbTar();
  }

Double INS::AttUr() {
  return attUr;
  }

Double INS::AttFr() {
  return attFr;
  }

Double INS::AttLs() {
  return attLs;
  }

Double INS::Apolune() {
  return apolune;
  }

char* INS::DisplayAccAltitude() {
  return displayAccAltitude;
  }

char* INS::DisplayAccEast() {
  return displayAccEast;
  }

char* INS::DisplayAccNorth() {
  return displayAccNorth;
  }

char* INS::DisplayPosAltitude() {
  return displayPosAltitude;
  }

char* INS::DisplayPosEast() {
  return displayPosEast;
  }

char* INS::DisplayPosNorth() {
  return displayPosNorth;
  }

Double INS::RelAltitude() {
  return relAltitude;
  }

char* INS::DisplayVelAltitude() {
  return displayVelAltitude;
  }

char* INS::DisplayVelEast() {
  return displayVelEast;
  }

char* INS::DisplayVelNorth() {
  return displayVelNorth;
  }

char* INS::DisplayApolune() {
  return displayApolune;
  }

char* INS::DisplayPerilune() {
  return displayPerilune;
  }

char* INS::DisplayMomEast() {
  return displayMomEast;
  }

char* INS::DisplayMomNorth() {
  return displayMomNorth;
  }

Int8 INS::Mode() {
  return mode;
  }

Double INS::MomEast() {
  return momEast;
  }

Double INS::MomNorth() {
  return momNorth;
  }

Int8 INS::Mode(Int8 i) {
  if (i >= 1 && i <= 6) mode = i;
  return mode;
  }

Double INS::RelLongitude() {
  return relLongitude;
  }

Double INS::RelLatitude() {
  return relLatitude;
  }

Double INS::TargetLongitude() {
  return tarLongitude;
  }

Double INS::TargetLatitude() {
  return tarLatitude;
  }

Boolean INS::hasSignal() {
  if (pilotLocation == PILOT_LM && !dsnOn && !dockingRadarOn &&
      !landingRadarOn) return false;
  if (pilotLocation == PILOT_LM && dsnOn && (dockingRadarOn ||
      landingRadarOn)) return false;
  if (pilotLocation == PILOT_LM && dockingRadarOn && landingRadarOn)
    return false;
  if (pilotLocation == PILOT_LM && dockingRadarOn &&
      (spacecraft->Position() - target->Position()).Length() > 30000)
    return false;
  if (pilotLocation == PILOT_LM && landingRadarOn &&
    (spacecraft->Altitude() > 18000 || attUr > 60)) return false;
  return true;
  }

void INS::noData() {
  strcpy(displayAccAltitude,"-------");
  strcpy(displayAccEast,"-------");
  strcpy(displayAccNorth,"-------");
  strcpy(displayPosAltitude,"-------");
  strcpy(displayPosEast,"-------");
  strcpy(displayPosNorth,"-------");
  strcpy(displayVelAltitude,"-------");
  strcpy(displayVelEast,"-------");
  strcpy(displayVelNorth,"-------");
  }

void INS::populatePosAbs() {
  if (!hasSignal()) {
    noData();
    return;
    }
  sprintf(displayPosAltitude,"%7d",(int)spacecraft->Altitude());
  sprintf(displayPosEast,"%7.2f",spacecraft->Longitude());
  sprintf(displayPosNorth,"%7.2f",spacecraft->Latitude());
  sprintf(displayVelAltitude,"%7.1f",spacecraft->VelocityAltitude());
  sprintf(displayVelEast,"%7.1f",spacecraft->VelocityEast());
  sprintf(displayVelNorth,"%7.1f",spacecraft->VelocityNorth());
  sprintf(displayAccAltitude,"%7.1f",accAltitude);
  sprintf(displayAccEast,"%7.1f",accEast);
  sprintf(displayAccNorth,"%7.1f",accNorth);
  }

void INS::populatePosTar() {
  Int32 i;
  if (pilotLocation == PILOT_EVA || pilotLocation == PILOT_LRV) {
      sprintf(displayPosAltitude,"%7d",0);
      i = tarLongitude * METERS;
      if (i > 999999) i = 999999;
      if (i < -999999) i = -999999;
      sprintf(displayPosEast,"%7d",i);
      i = tarLatitude * METERS;
      if (i > 999999) i = 999999;
      if (i < -999999) i = -999999;
      sprintf(displayPosNorth,"%7d",i);
      printVelocity(relVel.X(), displayVelAltitude);
      printVelocity(relVel.Y(), displayVelEast);
      printVelocity(relVel.Z(), displayVelNorth);
      strcpy(displayAccAltitude,"-------");
      strcpy(displayAccEast,"-------");
      strcpy(displayAccNorth,"-------");
      return;
    }
  if (!hasSignal()) {
    noData();
    return;
    }
  sprintf(displayPosAltitude,"%7d",(int)spacecraft->Altitude());
  sprintf(displayVelAltitude,"%7.1f",spacecraft->VelocityAltitude());
  sprintf(displayVelEast,"%7.1f",spacecraft->VelocityEast());
  sprintf(displayVelNorth,"%7.1f",spacecraft->VelocityNorth());
  sprintf(displayAccAltitude,"%7.1f",accAltitude);
  sprintf(displayAccEast,"%7.1f",accEast);
  sprintf(displayAccNorth,"%7.1f",accNorth);
  if (dsnOn || fabs(tarLongitude) > 3.0 || pilotLocation == PILOT_CSM)
    sprintf(displayPosEast,"%7.2f",tarLongitude);
  else
    sprintf(displayPosEast,"%7.0f",tarLongitude * (METERS));
  if (dsnOn || fabs(tarLatitude) > 3.0 || pilotLocation == PILOT_CSM)
    sprintf(displayPosNorth,"%7.2f",tarLatitude);
  else
    sprintf(displayPosNorth,"%7.0f",tarLatitude * METERS);
  }

void INS::populatePosRel() {
  Int32 i;
  if (pilotLocation == PILOT_EVA || pilotLocation == PILOT_LRV) {
      sprintf(displayPosAltitude,"%7d",0);
      i = sqrt(relPos.Y() * relPos.Y() + relPos.X() * relPos.X());
      i *= sgn(relLongitude);
      if (i > 999999) i = 999999;
      if (i < -999999) i = -999999;
      sprintf(displayPosEast,"%7d",i);
      i = (int)relPos.Z();
      if (i > 999999) i = 999999;
      if (i < -999999) i = -999999;
      sprintf(displayPosNorth,"%7d",i);
      printVelocity(relVel.X(), displayVelAltitude);
      printVelocity(relVel.Y(), displayVelEast);
      printVelocity(relVel.Z(), displayVelNorth);
      strcpy(displayAccAltitude,"-------");
      strcpy(displayAccEast,"-------");
      strcpy(displayAccNorth,"-------");
      return;
    }
  if (docked) {
    sprintf(displayPosAltitude,"%7d",0);
    sprintf(displayPosEast,"%7.2f",0.0);
    sprintf(displayPosNorth,"%7.2f",0.0);
    sprintf(displayVelAltitude,"%7.1f",0.0);
    sprintf(displayVelEast,"%7.1f",0.0);
    sprintf(displayVelNorth,"%7.1f",0.0);
    sprintf(displayAccAltitude,"%7.1f",0.0);
    sprintf(displayAccEast,"%7.1f",0.0);
    sprintf(displayAccNorth,"%7.1f",0.0);
    return;
    }
  i = (dockingRadarOn) ? 1 : 0;
  i |= ((landingRadarOn) ? 2 : 0);
  i |= ((dsnOn) ? 4 : 0);
  if (i == 1) {
    if (relPos.Length() > 30000) {
      noData();
      }
    else {
      sprintf(displayPosAltitude,"%7d",(int)(relPos.X()));
      sprintf(displayPosEast,"%7d",(int)(relPos.Y()));
      sprintf(displayPosNorth,"%7d",(int)(relPos.Z()));
      printVelocity(relVel.X(), displayVelAltitude);
      printVelocity(relVel.Y(), displayVelEast);
      printVelocity(relVel.Z(), displayVelNorth);

//      sprintf(displayVelAltitude,"%7.1f",relVel.Y());
//      sprintf(displayVelEast,"%7.1f",relVel.X());
//      sprintf(displayVelNorth,"%7.1f",relVel.Z());
      strcpy(displayAccAltitude,"-------");
      strcpy(displayAccEast,"-------");
      strcpy(displayAccNorth,"-------");
      }
    }
  else if (i == 4) {
      sprintf(displayPosAltitude,"%7d",(int)(relAltitude));
      sprintf(displayPosEast,"%7.2f",relLongitude);
      sprintf(displayPosNorth,"%7.2f",relLatitude);
      sprintf(displayVelAltitude,"%7.1f",relVel.Y());
      sprintf(displayVelEast,"%7.1f",relVel.X());
      sprintf(displayVelNorth,"%7.1f",relVel.Z());
      strcpy(displayAccAltitude,"-------");
      strcpy(displayAccEast,"-------");
      strcpy(displayAccNorth,"-------");
    }
  else {
    noData();
    }
  }

void INS::populateOrbAbs() {
  sprintf(displayApolune,"%7.1f",(apolune-GROUND)/1000);
  sprintf(displayPerilune,"%7.1f",(perilune-GROUND)/1000);
  sprintf(displayMomEast,"%7.2f",momEast);
  sprintf(displayMomNorth,"%7.2f",momNorth);
  clockOr = orbitTime;
  }

void INS::populateOrbTar() {
/*
  Vector L;
  Double mn;
  Double me;
  Double hyp;
  Vector vel;
  Vector pos;
  Double x,y,z;
  Double c,s;
  c = -1680.226342 * cos(targetLongitude*M_PI/180);
  s = -1680.226342 * sin(targetLongitude*M_PI/180);
  z = sin(targetLatitude*M_PI/180);
  x = sin(targetLongitude*M_PI/180) * cos(targetLatitude*M_PI/180);
  y = -cos(targetLongitude*M_PI/180) * cos(targetLatitude*M_PI/180);
  pos = Vector(x*GROUND,y*GROUND,z*GROUND);
GotoXY(1,26); printf("POS: %f %f %f\n",pos.X(),pos.Y(),pos.Z());
  vel = Vector(c,s,0);
  L = vel.Cross(pos).Norm();
  hyp = sqrt(L.X() * L.X() + L.Y() * L.Y());
  me = L.X() / hyp;
  me = acos(me) * 180 / M_PI;
  if (me <= -180) me += 360;
  if (me >= 180) me -= 360;
GotoXY(1,27); printf("Cross: %f %f %f\n",L.X(),L.Y(),L.Z());
  mn = asin(L.Z()) * 180 / M_PI;
*/
  sprintf(displayApolune,"%7.1f",(apolune-GROUND)/1000);
  sprintf(displayPerilune,"%7.1f",(perilune-GROUND)/1000);
  sprintf(displayMomEast,"%7.2f",targetMomEast);
  sprintf(displayMomNorth,"%7.2f",targetMomNorth);
  clockOr = orbitTime;
  }

void INS::printVelocity(Double v,char* buffer) {
  if (fabs(v) < 10) sprintf(buffer,"%7.3f",v);
  else if (fabs(v) < 100) sprintf(buffer,"%7.2f",v);
  else sprintf(buffer,"%7.1f",v);
  }

Double INS::Perilune() {
  return perilune;
  }

Vector INS::RelPos() {
  return relPos;
  }

Vector INS::RelVel() {
  return relVel;
  }

void INS::Reset() {
  }

Vehicle* INS::Spacecraft() {
  return spacecraft;
  }

Vehicle* INS::Spacecraft(Vehicle* v) {
  spacecraft = v;
  return spacecraft;
  }

Vehicle* INS::Target() {
  return target;
  }

Vehicle* INS::Target(Vehicle* v) {
  target = v;
  return target;
  }

