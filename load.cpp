#include <stdio.h>
#include <string.h>
#include "header.h"
#include "terminal.h"

/*
char* trim(char* buffer) {
  Int16 p;
  p = strlen(buffer) - 1;
  while (p >= 0 && buffer[p] > 0 && buffer[p] <= ' ') {
    buffer[p] = 0;
    p--;
    }
  while (buffer[0] > 0 && buffer[0] <= ' ') buffer++;
  return buffer;
  }

char* nextLine(FILE* file) {
  static char line[1024];
  if (fgets(line,1024,file) == NULL) return NULL;
  return trim(line);
  }

Int8 startsWith(char* buffer, const char* check) {
  if (strncasecmp(buffer,check,strlen(check)) == 0) return -1;
  return 0;
  }

char* nw(char* buffer) {
  while (buffer[0] > 0 && buffer[0] != ' ') buffer++;
  while (buffer[0] > 0 && buffer[0] == ' ') buffer++;
  return buffer;
  }
*/

Vector atov(char* buffer) {
  Vector ret;
  ret.X(atof(buffer));
  buffer = nw(buffer);
  ret.Y(atof(buffer));
  buffer = nw(buffer);
  ret.Z(atof(buffer));
  return ret;
  }

Matrix atom(char* buffer) {
  Double ax,ay,az;
  Double bx,by,bz;
  Double cx,cy,cz;
  ax = atof(buffer);
  buffer = nw(buffer);
  ay = atof(buffer);
  buffer = nw(buffer);
  az = atof(buffer);
  buffer = nw(buffer);
  bx = atof(buffer);
  buffer = nw(buffer);
  by = atof(buffer);
  buffer = nw(buffer);
  bz = atof(buffer);
  buffer = nw(buffer);
  cx = atof(buffer);
  buffer = nw(buffer);
  cy = atof(buffer);
  buffer = nw(buffer);
  cz = atof(buffer);
  return Matrix(ax,ay,az,bx,by,bz,cx,cy,cz);
  }

void loadSimulation(FILE* file) {
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"cabinpressurized ")) cabinPressurized = atoi(nw(pline));
    else if (startsWith(pline,"clockbu ")) clockBu = atoi(nw(pline));
    else if (startsWith(pline,"clockdk ")) clockDk = atoi(nw(pline));
    else if (startsWith(pline,"clockev ")) clockEv = atoi(nw(pline));
    else if (startsWith(pline,"clockor ")) clockOr = atoi(nw(pline));
    else if (startsWith(pline,"clockmi ")) clockMi = atoi(nw(pline));
    else if (startsWith(pline,"clockut ")) clockUt = atoi(nw(pline));
    else if (startsWith(pline,"clockte ")) clockTe = atoi(nw(pline));
    else if (startsWith(pline,"clockud ")) clockUd = atoi(nw(pline));
    else if (startsWith(pline,"clockdoi ")) clockDOI = atoi(nw(pline));
    else if (startsWith(pline,"clockpdi ")) clockPDI = atoi(nw(pline));
    else if (startsWith(pline,"evacount ")) evaCount = atoi(nw(pline));
    else if (startsWith(pline,"landedmet ")) landedMet = atoi(nw(pline));
    else if (startsWith(pline,"liftoffmet ")) liftoffMet = atoi(nw(pline));
    else if (startsWith(pline,"landedlongitude ")) landedLongitude = atof(nw(pline));
    else if (startsWith(pline,"landedlatitude ")) landedLatitude = atof(nw(pline));
    else if (startsWith(pline,"landedhvel ")) landedHVel = atof(nw(pline));
    else if (startsWith(pline,"landedvvel ")) landedVVel = atof(nw(pline));
    else if (startsWith(pline,"farthestdistance ")) farthest = atof(nw(pline));
    else if (startsWith(pline,"flagplanted ")) flagPlanted = atoi(nw(pline));
    else if (startsWith(pline,"flaglongitude ")) flagLongitude = atof(nw(pline));
    else if (startsWith(pline,"flaglatitude ")) flagLatitude = atof(nw(pline));
    else if (startsWith(pline,"longesteva ")) longestEVA = atoi(nw(pline));
    else if (startsWith(pline,"docked ")) docked = atoi(nw(pline));
    else if (startsWith(pline,"dockingradaron ")) dockingRadarOn = atoi(nw(pline));
    else if (startsWith(pline,"dsnon ")) dsnOn = atoi(nw(pline));
    else if (startsWith(pline,"efficiency ")) efficiency = atof(nw(pline));
    else if (startsWith(pline,"injury ")) sscanf(nw(pline),"%lf",&injury);
    else if (startsWith(pline,"insmode ")) insMode = atoi(nw(pline));
    else if (startsWith(pline,"landingradaron ")) landingRadarOn = atoi(nw(pline));
    else if (startsWith(pline,"metabolicrate ")) metabolicRate = atof(nw(pline));
    else if (startsWith(pline,"pilotlocation ")) pilotLocation = nw(pline)[0];
    else if (startsWith(pline,"plsspacks ")) plssPacks = atoi(nw(pline));
    else if (startsWith(pline,"plsson ")) plssOn = atoi(nw(pline));
    else if (startsWith(pline,"spacesuiton ")) spaceSuitOn = atoi(nw(pline));
    else if (startsWith(pline,"numburns ")) numBurns = atoi(nw(pline));
    else if (startsWith(pline,"ignitiontime ")) ignitionTime = atoi(nw(pline));
    else if (startsWith(pline,"ignitionaltitude ")) ignitionAltitude = atof(nw(pline));
    else if (startsWith(pline,"sampletype ")) sampleType = atoi(nw(pline));
    else if (startsWith(pline,"samplesmallrock ")) sampleSmallRock = atoi(nw(pline));
    else if (startsWith(pline,"samplemediumrock ")) sampleMediumRock = atoi(nw(pline));
    else if (startsWith(pline,"samplelargerock ")) sampleLargeRock = atoi(nw(pline));
    else if (startsWith(pline,"samplesmallcrater ")) sampleSmallCrater = atoi(nw(pline));
    else if (startsWith(pline,"samplemediumcrater ")) sampleMediumCrater = atoi(nw(pline));
    else if (startsWith(pline,"samplelargecrater ")) sampleLargeCrater = atoi(nw(pline));
    else if (startsWith(pline,"samplerise ")) sampleRise = atoi(nw(pline));
    else if (startsWith(pline,"sampleplains ")) samplePlains = atoi(nw(pline));
    else if (startsWith(pline,"samplespecial ")) sampleSpecial = atoi(nw(pline));
    else if (startsWith(pline,"sampledepression ")) sampleDepression = atoi(nw(pline));

    else if (startsWith(pline,"lrvsamplesmallrock ")) lrvSampleSmallRock = atoi(nw(pline));
    else if (startsWith(pline,"lrvsamplemediumrock ")) lrvSampleMediumRock = atoi(nw(pline));
    else if (startsWith(pline,"lrvsamplelargerock ")) lrvSampleLargeRock = atoi(nw(pline));
    else if (startsWith(pline,"lrvsamplesmallcrater ")) lrvSampleSmallCrater = atoi(nw(pline));
    else if (startsWith(pline,"lrvsamplemediumcrater ")) lrvSampleMediumCrater = atoi(nw(pline));
    else if (startsWith(pline,"lrvsamplelargecrater ")) lrvSampleLargeCrater = atoi(nw(pline));
    else if (startsWith(pline,"lrvsamplerise ")) lrvSampleRise = atoi(nw(pline));
    else if (startsWith(pline,"lrvsampleplains ")) lrvSamplePlains = atoi(nw(pline));
    else if (startsWith(pline,"lrvsamplespecial ")) lrvSampleSpecial = atoi(nw(pline));
    else if (startsWith(pline,"lrvsampledepression ")) lrvSampleDepression = atoi(nw(pline));
    else if (startsWith(pline,"sample ")) {
      pline = nw(pline);
      sscanf(pline,"%d,%d",&samples[numSamples].cellX,&samples[numSamples].cellY);
      numSamples++;
      }
    else {
      printf("Unknown line found in save file: %s\n",pline);
      exit(1);
      }
    }
  }

void LoadEva(FILE* file, char*line) {
  Int32 i;
  char* pline;
  i = atoi(line);
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"start ")) evas[i].start = atoi(nw(pline));
    else if (startsWith(pline,"end ")) evas[i].end = atoi(nw(pline));
    else if (startsWith(pline,"walked ")) evas[i].walked = atof(nw(pline));
    else if (startsWith(pline,"driven ")) evas[i].driven = atof(nw(pline));
    else if (startsWith(pline,"farthest ")) evas[i].farthest = atof(nw(pline));
    else if (startsWith(pline,"samples ")) evas[i].samples = atoi(nw(pline));
    }
  }

void LoadBurn(FILE* file, char*line) {
  Int32 i;
  char* pline;
  i = atoi(line);
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"start ")) burn[i].start = atoi(nw(pline));
    else if (startsWith(pline,"end ")) burn[i].end = atoi(nw(pline));
    else if (startsWith(pline,"fuelused ")) burn[i].fuelUsed = atof(nw(pline));
    else if (startsWith(pline,"engine ")) burn[i].engine = nw(pline)[0];
    }
  }

Int8 load(char* filename) {
  FILE* file;
  char* pline;
  file = fopen(filename,"r");
  if (file == NULL) return 0;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"simulation {")) loadSimulation(file);
    else if (startsWith(pline,"csm {")) csm->Load(file);
    else if (startsWith(pline,"lunarmodule {")) lm->Load(file);
    else if (startsWith(pline,"plss {")) plss->Load(file);
    else if (startsWith(pline,"lrv {")) lrv->Load(file);
    else if (startsWith(pline,"mission {")) mission->Load(file);
    else if (startsWith(pline,"eva ")) LoadEva(file,nw(pline));
    else if (startsWith(pline,"burn ")) LoadBurn(file,nw(pline));
    else {
      printf("Unknown line found in save file: %s\n",pline);
      exit(1);
      }
    }

  fclose(file);
  ins->Mode(insMode);
  return -1;
  }

