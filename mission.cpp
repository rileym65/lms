#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "mission.h"

Mission::Mission() {
  name = NULL;
  description = NULL;
  region = NULL;
  lander = NULL;
  primaryLongitude = -99999;
  primaryLatitude = -99999;
  secondary1Longitude = -99999;
  secondary1Latitude = -99999;
  secondary2Longitude = -99999;
  secondary2Latitude = -99999;
  secondary3Longitude = -99999;
  secondary3Latitude = -99999;
  targetLongitude = -99999;
  targetLatitude = -99999;
  Vehicle(VEHICLE_APOLLO_MKII);
  }

Mission::~Mission() {
  if (name != NULL) free(name);
  if (region != NULL) free(region);
  }

Double Mission::AscentEmptyWeight() {
  return lander->AscentEmptyWeight();
  }

Double Mission::AscentFullWeight() {
  Double ret;
  ret = AscentEmptyWeight();
  ret += ascentFuel;
  ret += rcsFuel;
  return ret;
  }

Double Mission::AscentFuel() {
  return ascentFuel;
  }

Double Mission::AscentFuel(Double d) {
  ascentFuel = d;
  if (ascentFuel < 0) ascentFuel = 0;
  if (ascentFuel > lander->AscentFuel()) ascentFuel = lander->AscentFuel();
  return ascentFuel;
  }

UInt32 Mission::Consumables() {
  return consumables;
  }

UInt32 Mission::Consumables(UInt32 i) {
  consumables = i;
  if (consumables < 0) consumables = 0;
  if (consumables > lander->Consumables()) consumables = lander->Consumables();
  return consumables;
  }

Double Mission::DescentEmptyWeight() {
  return lander->DescentEmptyWeight();
  }

Double Mission::DescentFullWeight() {
  Double ret;
  Double cons;
  ret = DescentEmptyWeight();
  ret += descentFuel;
  if (rover == 1) ret += 210;
  if (rover == 2) ret += 230;
  if (rover == 3) ret += 310;
  if (lsep == 1) ret += 49;
  if (lsep == 2) ret += 163;
  if (laser != 0) ret += 20;
  cons = consumables;
  ret += (cons * 0.060666);           /* Oxygen */
  ret += (cons * 0.308333);           /* Water */
  ret += (cons * 0.205833);           /* Food */
  return ret;
  }

Double Mission::DescentFuel() {
  return descentFuel;
  }

Double Mission::DescentFuel(Double d) {
  descentFuel = d;
  if (descentFuel < 0) descentFuel = 0;
  if (descentFuel > lander->DescentFuel()) descentFuel = lander->DescentFuel();
  return descentFuel;
  }

char* Mission::Description() {
  return description;
  }

char* Mission::Description(char* s) {
  if (description != NULL) free(description);
  description = (char*)malloc(strlen(s) + 1);
  strcpy(description, s);
  return description;
  }

Byte Mission::Laser() {
  return laser;
  }

Byte Mission::Laser(Byte b) {
  laser = b;
  if (laser > 1) laser = 1;
  return laser;
  }

Byte Mission::Lsep() {
  return lsep;
  }

Byte Mission::Lsep(Byte b) {
  lsep = b;
  if (lsep > 2) lsep = 2;
  return lsep;
  }

char* Mission::Name() {
  return name;
  }

char* Mission::Name(char* s) {
  if (name != NULL) free(name);
  name = (char*)malloc(strlen(s) + 1);
  strcpy(name, s);
  return name;
  }

Double Mission::PrimaryLatitude() {
  return primaryLatitude;
  }

Double Mission::PrimaryLatitude(Double d) {
  primaryLatitude = d;
  return primaryLatitude;
  }

Double Mission::PrimaryLongitude() {
  return primaryLongitude;
  }

Double Mission::PrimaryLongitude(Double d) {
  primaryLongitude = d;
  return primaryLongitude;
  }

Double Mission::RcsFuel() {
  return rcsFuel;
  }

Double Mission::RcsFuel(Double d) {
  rcsFuel = d;
  if (rcsFuel < 0) rcsFuel = 0;
  if (rcsFuel > lander->RcsFuel()) rcsFuel = lander->RcsFuel();
  return rcsFuel;
  }

char* Mission::Region() {
  return region;
  }

char* Mission::Region(char* s) {
  if (region != NULL) free(region);
  region = (char*)malloc(strlen(s) + 1);
  strcpy(region, s);
  return region;
  }

Byte Mission::Rover() {
  return rover;
  }

Byte Mission::Rover(Byte b) {
  rover = b;
  if (rover >= vehicle) rover = vehicle - 1;
  return rover;
  }

Double Mission::Secondary1Latitude() {
  return secondary1Latitude;
  }

Double Mission::Secondary1Latitude(Double d) {
  secondary1Latitude = d;
  return secondary1Latitude;
  }

Double Mission::Secondary1Longitude() {
  return secondary1Longitude;
  }

Double Mission::Secondary1Longitude(Double d) {
  secondary1Longitude = d;
  return secondary1Longitude;
  }

Double Mission::Secondary2Latitude() {
  return secondary2Latitude;
  }

Double Mission::Secondary2Latitude(Double d) {
  secondary2Latitude = d;
  return secondary2Latitude;
  }

Double Mission::Secondary2Longitude() {
  return secondary2Longitude;
  }

Double Mission::Secondary2Longitude(Double d) {
  secondary2Longitude = d;
  return secondary2Longitude;
  }

Double Mission::Secondary3Latitude() {
  return secondary3Latitude;
  }

Double Mission::Secondary3Latitude(Double d) {
  secondary3Latitude = d;
  return secondary3Latitude;
  }

Double Mission::Secondary3Longitude() {
  return secondary3Longitude;
  }

Double Mission::Secondary3Longitude(Double d) {
  secondary3Longitude = d;
  return secondary3Longitude;
  }

Double Mission::TargetLatitude() {
  return targetLatitude;
  }

Double Mission::TargetLatitude(Double d) {
  targetLatitude = d;
  return targetLatitude;
  }

Double Mission::TargetLongitude() {
  return targetLongitude;
  }

Double Mission::TargetLongitude(Double d) {
  targetLongitude = d;
  return targetLongitude;
  }

Int8 Mission::Vehicle() {
  return vehicle;
  }

Int8 Mission::Vehicle(Int8 v) {
  vehicle = v;
  if (v < 1 || v > 4) return vehicle;
  if (lander != NULL) delete(lander);
  lander = new Lander(v);
  ascentFuel = lander->AscentFuel();
  rcsFuel = lander->RcsFuel();
  descentFuel = lander->DescentFuel();
  consumables = lander->Consumables();
  rover = v - 1;
  lsep = (v == 1) ? 1 : 2;
  laser = 1;
  return vehicle;
  }

Lander* Mission::Model() {
  return lander;
  }

void Mission::Load(FILE* file) {
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"name ")) Name(nw(pline));
    else if (startsWith(pline,"region ")) Region(nw(pline));
    else if (startsWith(pline,"description ")) Description(nw(pline));
    else if (startsWith(pline,"targetlatitude ")) targetLatitude = atof(nw(pline));
    else if (startsWith(pline,"targetlongitude ")) targetLongitude = atof(nw(pline));
    else if (startsWith(pline,"primarylatitude ")) primaryLatitude = atof(nw(pline));
    else if (startsWith(pline,"primarylongitude ")) primaryLongitude = atof(nw(pline));
    else if (startsWith(pline,"secondary1latitude ")) secondary1Latitude = atof(nw(pline));
    else if (startsWith(pline,"secondary1longitude ")) secondary1Longitude = atof(nw(pline));
    else if (startsWith(pline,"secondary2latitude ")) secondary2Latitude = atof(nw(pline));
    else if (startsWith(pline,"secondary2longitude ")) secondary2Longitude = atof(nw(pline));
    else if (startsWith(pline,"secondary3latitude ")) secondary3Latitude = atof(nw(pline));
    else if (startsWith(pline,"secondary3longitude ")) secondary3Longitude = atof(nw(pline));
    else if (startsWith(pline,"vehicle ")) Vehicle(atoi(nw(pline)));
    else if (startsWith(pline,"ascentfuel ")) ascentFuel = atof(nw(pline));
    else if (startsWith(pline,"rcsfuel ")) rcsFuel = atof(nw(pline));
    else if (startsWith(pline,"descentfuel ")) descentFuel = atof(nw(pline));
    else if (startsWith(pline,"consumables ")) consumables = atoi(nw(pline));
    else if (startsWith(pline,"rover ")) rover = atoi(nw(pline));
    else if (startsWith(pline,"lsep ")) lsep = atoi(nw(pline));
    else if (startsWith(pline,"laser ")) laser = atoi(nw(pline));
    }
  validate();
  }

void Mission::Save(FILE* file) {
  fprintf(file,"Mission {%s",LE);
  if (name != NULL) fprintf(file,"  Name %s%s",name,LE);
    else fprintf(file,"  Name None%s",LE);
  if (description != NULL) fprintf(file,"  Description %s%s",description,LE);
    else fprintf(file,"  Description None%s",LE);
  if (region != NULL) fprintf(file,"  Region %s%s",region,LE);
    else fprintf(file,"  Region None%s",LE);
  fprintf(file,"  TargetLatitude %f%s",targetLatitude,LE);
  fprintf(file,"  TargetLongitude %f%s",targetLongitude,LE);
  if (primaryLatitude >= -180) {
    fprintf(file,"  PrimaryLatitude %f%s",primaryLatitude,LE);
    fprintf(file,"  PrimaryLongitude %f%s",primaryLongitude,LE);
    }
  if (secondary1Latitude >= -180) {
    fprintf(file,"  Secondary1Latitude %f%s",secondary1Latitude,LE);
    fprintf(file,"  Secondary1Longitude %f%s",secondary1Longitude,LE);
    }
  if (secondary2Latitude >= -180) {
    fprintf(file,"  Secondary2Latitude %f%s",secondary2Latitude,LE);
    fprintf(file,"  Secondary2Longitude %f%s",secondary2Longitude,LE);
    }
  if (secondary3Latitude >= -180) {
    fprintf(file,"  Secondary3Latitude %f%s",secondary3Latitude,LE);
    fprintf(file,"  Secondary3Longitude %f%s",secondary3Longitude,LE);
    }
  fprintf(file,"  Vehicle %d%s",vehicle,LE);
  fprintf(file,"  AscentFuel %f%s",ascentFuel,LE);
  fprintf(file,"  RcsFuel %f%s",rcsFuel,LE);
  fprintf(file,"  DescentFuel %f%s",descentFuel,LE);
  fprintf(file,"  Consumables %d%s",consumables,LE);
  fprintf(file,"  Rover %d%s",rover,LE);
  fprintf(file,"  Lsep %d%s",lsep,LE);
  fprintf(file,"  Laser %d%s",laser,LE);
  fprintf(file,"  }%s",LE);
  }

void Mission::validate() {
  if (ascentFuel > lander->AscentFuel()) ascentFuel = lander->AscentFuel();
  if (descentFuel > lander->DescentFuel()) descentFuel = lander->DescentFuel();
  if (rcsFuel > lander->RcsFuel()) rcsFuel = lander->RcsFuel();
  if (consumables > lander->Consumables()) consumables = lander->Consumables();
  if (rover >= vehicle) rover = vehicle - 1;
  if (lsep > 2) lsep = 2;
  if (laser > 1) laser = 1;
  }

