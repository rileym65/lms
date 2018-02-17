#include "header.h"
#include "ins.h"

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
  accAltitude = spacecraft->VelocityAltitude() - lastVelAltitude;
  lastVelAltitude = spacecraft->VelocityAltitude();
  accEast = spacecraft->VelocityEast() - lastVelEast;
  lastVelEast = spacecraft->VelocityEast();
  accNorth = spacecraft->VelocityNorth() - lastVelNorth;
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
//  attFr = acos(pos.Norm().Dot(spacecraft->FaceFront())) * 180 / M_PI;
//  attFr = acos(spacecraft->FaceFront().Norm().Dot(orbit) ) * 180 / M_PI;
  attFr = acos(pos.Norm().Dot(spacecraft->FaceFront())) * 180 / M_PI;
  attLs = acos(spacecraft->FaceLeft().Dot(Vector(0,0,-1))) * 180 / M_PI;
  tarLatitude = spacecraft->Latitude() - targetLatitude;
  tarLongitude = spacecraft->Longitude() - targetLongitude;
  if (tarLongitude <= -180) tarLongitude += 360;
  if (tarLongitude >= 180) tarLongitude -= 360;

  if (mode == INS_MODE_POS_ABS) populatePosAbs();
  if (mode == INS_MODE_POS_TAR) populatePosTar();
  if (mode == INS_MODE_POS_REL) populatePosRel();
  if (mode == INS_MODE_ORB_ABS) populateOrbAbs();
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

Int8 INS::Mode(Int8 i) {
  if (i >= 1 && i <= 6) mode = i;
  return mode;
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
    (spacecraft->Altitude() > 18000 || attUr > 45)) return false;
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
  sprintf(displayVelAltitude,"%7.1f",lastVelAltitude);
  sprintf(displayVelEast,"%7.1f",spacecraft->VelocityEast());
  sprintf(displayVelNorth,"%7.1f",spacecraft->VelocityNorth());
  sprintf(displayAccAltitude,"%7.1f",accAltitude);
  sprintf(displayAccEast,"%7.1f",accEast);
  sprintf(displayAccNorth,"%7.1f",accNorth);
  }

void INS::populatePosTar() {
  if (!hasSignal()) {
    noData();
    return;
    }
  sprintf(displayPosAltitude,"%7d",(int)spacecraft->Altitude());
  sprintf(displayVelAltitude,"%7.1f",lastVelAltitude);
  sprintf(displayVelEast,"%7.1f",spacecraft->VelocityEast());
  sprintf(displayVelNorth,"%7.1f",spacecraft->VelocityNorth());
  sprintf(displayAccAltitude,"%7.1f",accAltitude);
  sprintf(displayAccEast,"%7.1f",accEast);
  sprintf(displayAccNorth,"%7.1f",accNorth);
  if (dsnOn || fabs(tarLongitude) > 3.0)
    sprintf(displayPosEast,"%7.2f",tarLongitude);
  else
    sprintf(displayPosEast,"%7.0f",tarLongitude * (METERS));
  if (dsnOn || fabs(tarLatitude) > 3.0)
    sprintf(displayPosNorth,"%7.2f",tarLatitude);
  else
    sprintf(displayPosNorth,"%7.2f",tarLatitude * METERS);
  }

void INS::populatePosRel() {
  Int32 i;
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
      sprintf(displayPosAltitude,"%7d",(int)(relPos.Y()));
      sprintf(displayPosEast,"%7d",(int)(relPos.X()));
      sprintf(displayPosNorth,"%7d",(int)(relPos.Z()));
      printVelocity(relVel.X(), displayVelEast);
      printVelocity(relVel.Y(), displayVelAltitude);
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

void INS::printVelocity(Double v,char* buffer) {
  if (fabs(v) < 10) sprintf(buffer,"%7.3f",v);
  else if (fabs(v) < 100) sprintf(buffer,"%7.2f",v);
  else sprintf(buffer,"%7.1f",v);
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

