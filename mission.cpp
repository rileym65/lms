#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "mission.h"

Mission::Mission() {
  name = NULL;
  region = NULL;
  targetLongitude = -99999;
  targetLatitude = -99999;
  }

Mission::~Mission() {
  if (name != NULL) free(name);
  if (region != NULL) free(region);
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

char* Mission::Region() {
  return region;
  }

char* Mission::Region(char* s) {
  if (region != NULL) free(region);
  region = (char*)malloc(strlen(s) + 1);
  strcpy(region, s);
  return region;
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

void Mission::Load(FILE* file) {
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"name ")) Name(nw(pline));
    else if (startsWith(pline,"region ")) Region(nw(pline));
    else if (startsWith(pline,"targetlatitude ")) targetLatitude = atof(nw(pline));
    else if (startsWith(pline,"targetlongitude ")) targetLongitude = atof(nw(pline));
    }
  }

void Mission::Save(FILE* file) {
  fprintf(file,"Mission {%s",LE);
  if (name != NULL) fprintf(file,"  Name %s%s",name,LE);
    else fprintf(file,"  Name None%s",LE);
  if (region != NULL) fprintf(file,"  Region %s%s",region,LE);
    else fprintf(file,"  Region None%s",LE);
  fprintf(file,"  TargetLatitude %f%s",targetLatitude,LE);
  fprintf(file,"  TargetLongitude %f%s",targetLongitude,LE);
  fprintf(file,"  }%s",LE);
  }
