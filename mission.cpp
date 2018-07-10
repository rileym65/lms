#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "mission.h"

Mission::Mission() {
  name = NULL;
  description = NULL;
  region = NULL;
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
  vehicle = VEHICLE_APOLLO_MKII;
  }

Mission::~Mission() {
  if (name != NULL) free(name);
  if (region != NULL) free(region);
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

char* Mission::Region() {
  return region;
  }

char* Mission::Region(char* s) {
  if (region != NULL) free(region);
  region = (char*)malloc(strlen(s) + 1);
  strcpy(region, s);
  return region;
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
  return vehicle;
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
    else if (startsWith(pline,"vehicle ")) vehicle = atoi(nw(pline));
    }
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
  fprintf(file,"  }%s",LE);
  }
