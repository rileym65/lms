#include <stdio.h>
#include <string.h>
#include "header.h"
#include "helpers.h"
#include "computer.h"
#include "terminal.h"
#include "g_clockbu.h"
#include "g_clockmi.h"
#include "g_clocktb.h"
#include "g_clockut.h"
#include "g_days.h"
#include "g_moon.h"
#include "g_position.h"

void loadSimulation(FILE* file) {
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    else if (startsWith(pline,"cabinpressurized ")) cabinPressurized = atoi(nw(pline));
    else if (startsWith(pline,"clockbu ")) clockBu = atoi(nw(pline));
    else if (startsWith(pline,"clockdk ")) clockDk = atoi(nw(pline));
    else if (startsWith(pline,"clockev ")) clockEv = atoi(nw(pline));
    else if (startsWith(pline,"clockge ")) clockGe = atoi(nw(pline));
    else if (startsWith(pline,"clockor ")) clockOr = atoi(nw(pline));
    else if (startsWith(pline,"clockmi ")) clockMi = atoi(nw(pline));
    else if (startsWith(pline,"clockut ")) clockUt = atoi(nw(pline));
    else if (startsWith(pline,"clocktb ")) clockTb = atoi(nw(pline));
    else if (startsWith(pline,"clockte ")) clockTe = atoi(nw(pline));
    else if (startsWith(pline,"clockud ")) clockUd = atoi(nw(pline));
    else if (startsWith(pline,"clockdoi ")) clockDOI = atoi(nw(pline));
    else if (startsWith(pline,"clockpdi ")) clockPDI = atoi(nw(pline));
    else if (startsWith(pline,"clockbsp ")) clockBsp = atoi(nw(pline));
    else if (startsWith(pline,"clocklo ")) clockLo = atoi(nw(pline));
    else if (startsWith(pline,"clockmaxq ")) clockMaxQ = atoi(nw(pline));
    else if (startsWith(pline,"clockpara ")) clockPara = atoi(nw(pline));
    else if (startsWith(pline,"clockrent ")) clockRent = atoi(nw(pline));
    else if (startsWith(pline,"clocksmjt ")) clockSmJt = atoi(nw(pline));
    else if (startsWith(pline,"clockrmjt ")) clockRmJt = atoi(nw(pline));
    else if (startsWith(pline,"clocktli ")) clockTli = atoi(nw(pline));
    else if (startsWith(pline,"clocktei ")) clockTei = atoi(nw(pline));
    else if (startsWith(pline,"clockloi ")) clockLoi = atoi(nw(pline));
    else if (startsWith(pline,"clockmsoi ")) clockMSoi = atoi(nw(pline));
    else if (startsWith(pline,"clockesoi ")) clockESoi = atoi(nw(pline));
    else if (startsWith(pline,"clocklmdk ")) clockLmDk = atoi(nw(pline));
    else if (startsWith(pline,"clocklext ")) clockLExt = atoi(nw(pline));
    else if (startsWith(pline,"clocklmjt ")) clockLmJt = atoi(nw(pline));
    else if (startsWith(pline,"highestvel ")) highestVelocity = atof(nw(pline));
    else if (startsWith(pline,"dockingvel ")) dockingVel = atof(nw(pline));
    else if (startsWith(pline,"dockinglvel ")) dockingLVel = atof(nw(pline));
    else if (startsWith(pline,"modeabo ")) mode_abo = atoi(nw(pline));
    else if (startsWith(pline,"modearm ")) mode_arm = atoi(nw(pline));
    else if (startsWith(pline,"modejet ")) mode_jet = atoi(nw(pline));
    else if (startsWith(pline,"modekil ")) mode_kil = atoi(nw(pline));
    else if (startsWith(pline,"modelif ")) mode_lif = atoi(nw(pline));
    else if (startsWith(pline,"evacount ")) evaCount = atoi(nw(pline));
    else if (startsWith(pline,"landedmet ")) landedMet = atoi(nw(pline));
    else if (startsWith(pline,"liftoffmet ")) liftoffMet = atoi(nw(pline));
    else if (startsWith(pline,"landedlongitude ")) landedLongitude = atof(nw(pline));
    else if (startsWith(pline,"landedlatitude ")) landedLatitude = atof(nw(pline));
    else if (startsWith(pline,"landedhvel ")) landedHVel = atof(nw(pline));
    else if (startsWith(pline,"landedvvel ")) landedVVel = atof(nw(pline));
    else if (startsWith(pline,"farthestdistance ")) farthest = atof(nw(pline));
    else if (startsWith(pline,"farthestfromearth ")) farthestFromEarth = atof(nw(pline));
    else if (startsWith(pline,"flagplanted ")) flagPlanted = atoi(nw(pline));
    else if (startsWith(pline,"flaglongitude ")) flagLongitude = atof(nw(pline));
    else if (startsWith(pline,"flaglatitude ")) flagLatitude = atof(nw(pline));
    else if (startsWith(pline,"lasersetup ")) laserSetup = atoi(nw(pline));
    else if (startsWith(pline,"laserlongitude ")) laserLongitude = atof(nw(pline));
    else if (startsWith(pline,"laserlatitude ")) laserLatitude = atof(nw(pline));
    else if (startsWith(pline,"alsepsetup ")) alsepSetup = atoi(nw(pline));
    else if (startsWith(pline,"alseplongitude ")) alsepLongitude = atof(nw(pline));
    else if (startsWith(pline,"alseplatitude ")) alsepLatitude = atof(nw(pline));
    else if (startsWith(pline,"longesteva ")) longestEVA = atoi(nw(pline));
    else if (startsWith(pline,"docked ")) docked = atoi(nw(pline));
    else if (startsWith(pline,"lmextracted ")) lmExtracted = atoi(nw(pline));
    else if (startsWith(pline,"dockingradaron ")) dockingRadarOn = atoi(nw(pline));
    else if (startsWith(pline,"dsnon ")) dsnOn = atoi(nw(pline));
    else if (startsWith(pline,"efficiency ")) efficiency = atof(nw(pline));
    else if (startsWith(pline,"injury ")) sscanf(nw(pline),"%lf",&injury);
    else if (startsWith(pline,"softinjury ")) sscanf(nw(pline),"%lf",&softInjury);
    else if (startsWith(pline,"hardinjury ")) sscanf(nw(pline),"%lf",&hardInjury);
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
    else if (startsWith(pline,"samplecraterwall ")) sampleCraterWall = atoi(nw(pline));
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
    else if (startsWith(pline,"lrvsamplecraterwall ")) lrvSampleCraterWall = atoi(nw(pline));
    else if (startsWith(pline,"cartsamplesmallrock ")) cartSampleSmallRock = atoi(nw(pline));
    else if (startsWith(pline,"cartsamplemediumrock ")) cartSampleMediumRock = atoi(nw(pline));
    else if (startsWith(pline,"cartsamplelargerock ")) cartSampleLargeRock = atoi(nw(pline));
    else if (startsWith(pline,"cartsamplesmallcrater ")) cartSampleSmallCrater = atoi(nw(pline));
    else if (startsWith(pline,"cartsamplemediumcrater ")) cartSampleMediumCrater = atoi(nw(pline));
    else if (startsWith(pline,"cartsamplelargecrater ")) cartSampleLargeCrater = atoi(nw(pline));
    else if (startsWith(pline,"cartsamplerise ")) cartSampleRise = atoi(nw(pline));
    else if (startsWith(pline,"cartsampleplains ")) cartSamplePlains = atoi(nw(pline));
    else if (startsWith(pline,"cartsamplespecial ")) cartSampleSpecial = atoi(nw(pline));
    else if (startsWith(pline,"cartsampledepression ")) cartSampleDepression = atoi(nw(pline));
    else if (startsWith(pline,"cartsamplecraterwall ")) cartSampleCraterWall = atoi(nw(pline));

    else if (startsWith(pline,"days ")) days = atoi(nw(pline));
    else if (startsWith(pline,"kscangle ")) kscAngle = atof(nw(pline));
    else if (startsWith(pline,"distance ")) distanceTravelled = atof(nw(pline));
    else if (startsWith(pline,"maxq ")) maxQ = atof(nw(pline));
    else if (startsWith(pline,"maxqaltitude ")) maxQAltitude = atof(nw(pline));
    else if (startsWith(pline,"launched true")) launched = true;
    else if (startsWith(pline,"launched false")) launched = false;
    else if (startsWith(pline,"inatmosphere ")) inAtmosphere = atoi(nw(pline));

    else if (startsWith(pline,"sample ")) {
      pline = nw(pline);
      sscanf(pline,"%d,%d",&samples[numSamples].cellX,&samples[numSamples].cellY);
      numSamples++;
      }

    else {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
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

Int8 load(const char* filename) {
  FILE* file;
  char* pline;
  file = fopen(filename,"r");
  if (file == NULL) return 0;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"simulation {")) loadSimulation(file);
    else if (startsWith(pline,"booster {")) booster->Load(file);
    else if (startsWith(pline,"commandmodule {")) csm->Load(file);
    else if (startsWith(pline,"lunarmodule {")) {
      lm = new LunarModule();
      lm->Load(file);
      lm->Comp(new Computer(lm));
      }
    else if (startsWith(pline,"plss {")) {
      plss = new Plss();
      plss->Load(file);
      }
    else if (startsWith(pline,"lrv {")) lrv->Load(file);
    else if (startsWith(pline,"mission {")) mission->Load(file);
    else if (startsWith(pline,"burn ")) LoadBurn(file,nw(pline));
    else if (startsWith(pline,"eva ")) LoadEva(file,nw(pline));
    else if (startsWith(pline,"earth {")) Earth->Load(file);
    else if (startsWith(pline,"moon {")) Moon->Load(file);
    else if (startsWith(pline,"computer ")) {
      if (lm == NULL) {
        WriteLn("Save file contains computer settings but no LM is defined");
        WriteLn("Aborting");
        exit(1);
        }
      if (lm->Comp() == NULL) {
        WriteLn("Save file contains computer settings but LM does not");
        WriteLn("have a computer defined.  Aborting");
        exit(1);
        }
      lm->Comp()->Load(file);
      }
    else {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
    }
  csm->TargetVehicle(lm);
  if (lm != NULL) {
    lm->TargetVehicle(csm);
    if (lm->Orbiting() == NULL) lm->Orbiting(csm->Orbiting());
    }
  fclose(file);
  if (pilotLocation == PILOT_CSM) currentVehicle = csm;
  if (pilotLocation == PILOT_LM) currentVehicle = lm;
  if (pilotLocation == PILOT_EVA) currentVehicle = plss;
  currentVehicle->SetupPanel();
  return -1;
  }

