#ifndef _HEADER_H
#define _HEADER_H

#ifdef MAIN 
#define LINK
#else
#define LINK extern
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include "types.h"
#include "vector.h"
#include "lm.h"
#include "plss.h"
#include "csm.h"
#include "lrv.h"
#include "ins.h"
#include "sequencer.h"
#include "map.h"
#include "mission.h"

#define TITLE "Lunar Mission Simulator"
#define PILOT_CSM 'c'
#define PILOT_LRV 'v'
#define PILOT_LM  'm'
#define PILOT_EVA 'e'
#define FUEL_ASC  2615.0
#define FUEL_RCS  316.0
#define FUEL_DES  9720.0
#define LM_OXYGEN 432000.0
#define LM_BATTERY 432000.0
#define LM_EOXYGEN 432000.0
#define LM_EBATTERY 216000.0
#define ASC_OXYGEN 36000.0
#define ASC_BATTERY 36000.0
#define ASC_EOXYGEN 36000.0
#define ASC_EBATTERY 18000.0
#define PLSS_OXYGEN 36000.0
#define PLSS_BATTERY 36000.0
#define PLSS_EOXYGEN 18000.0
#define PLSS_EBATTERY 9000.0
#define LRV_BATTERY  200000.0
#define INS_MODE_POS_ABS 1
#define INS_MODE_POS_TAR 2
#define INS_MODE_POS_REL 3
#define INS_MODE_ORB_ABS 4
#define INS_MODE_ORB_TAR 5
#define INS_MODE_ORB_REL 6
#define MOON  4.9075e12
#define GROUND 1738300
#define METERS ((GROUND*2*M_PI) / 360.0)
#define CELL (METERS / 10)
#define DR  (3.14159265358979323846 / 180)
#define S_SMALL_ROCK      1
#define S_MEDIUM_ROCK     2
#define S_LARGE_ROCK      3
#define S_SMALL_CRATER    4
#define S_MEDIUM_CRATER   5
#define S_LARGE_CRATER    6
#define S_PLAINS          7
#define S_RISE            8
#define S_SPECIAL         9
#define S_DEPRESSION     10
#define END_QUIT          1
#define END_MISSION       2
#define END_COLLISION     3
#define END_DEAD          4
#define END_CRASHED       5

#define LE   "\n"

typedef struct {
  Int32 cellX;
  Int32 cellY;
  } LOCATION;

typedef struct {
  Int32  start;
  Int32  end;
  Double walked;
  Double driven;
  Double farthest;
  Int32  samples;
  } EVA;

typedef struct {
  Int32  start;
  Int32  end;
  Double fuelUsed;
  char   engine;
  } BURN;

LINK Int8         cabinPressurized;
LINK Int32        clockBu;
LINK Int32        clockDk;
LINK Int32        clockEv;
LINK Int32        clockOr;
LINK Int32        clockMi;
LINK Int32        clockUt;
LINK Int32        clockTe;
LINK Int32        clockUd;
LINK Int32        clockDOI;
LINK Int32        clockPDI;
LINK EVA          evas[256];
LINK Int32        evaCount;
LINK Int32        landedMet;
LINK Int32        liftoffMet;
LINK Int32        longestEVA;
LINK CSM         *csm;
LINK Vehicle*     currentVehicle;
LINK Int8         docked;
LINK Int8         dockingRadarOn;
LINK Int8         dsnOn;
LINK Double       efficiency;
LINK Double       injury;
LINK Double       softInjury;
LINK Double       hardInjury;
LINK INS         *ins;
LINK Int8         insMode;
LINK Int8         landingRadarOn;
LINK LunarModule *lm;
LINK Lrv         *lrv;
LINK Map         *map;
LINK Double       metabolicRate;
LINK Mission     *mission;
LINK Int16        numSamples;
LINK char         pilotLocation;
LINK Plss        *plss;
LINK Int8         plssOn;
LINK Int8         plssPacks;
LINK Boolean      run;
LINK LOCATION     samples[240];
LINK Sequencer*   seq;
LINK Int32        simSpeed;
LINK Int8         spaceSuitOn;
LINK Vector       targetPos;
LINK Vector       targetVel;
LINK Double       targetMomEast;
LINK Double       targetMomNorth;
LINK Int8         ticks;
LINK Int8         keyDelay;
LINK UInt8        sampleType;
LINK UInt8        sampleSmallRock;
LINK UInt8        sampleMediumRock;
LINK UInt8        sampleLargeRock;
LINK UInt8        sampleSmallCrater;
LINK UInt8        sampleMediumCrater;
LINK UInt8        sampleLargeCrater;
LINK UInt8        samplePlains;
LINK UInt8        sampleRise;
LINK UInt8        sampleSpecial;
LINK UInt8        sampleDepression;
LINK UInt8        lrvSampleSmallRock;
LINK UInt8        lrvSampleMediumRock;
LINK UInt8        lrvSampleLargeRock;
LINK UInt8        lrvSampleSmallCrater;
LINK UInt8        lrvSampleMediumCrater;
LINK UInt8        lrvSampleLargeCrater;
LINK UInt8        lrvSamplePlains;
LINK UInt8        lrvSampleRise;
LINK UInt8        lrvSampleSpecial;
LINK UInt8        lrvSampleDepression;
LINK Double       landedLongitude;
LINK Double       landedLatitude;
LINK Double       landedVVel;
LINK Double       landedHVel;
LINK Double       farthest;
LINK Int8         flagPlanted;
LINK Double       flagLongitude;
LINK Double       flagLatitude;
LINK Int8         endReason;
LINK Int32        ignitionTime;
LINK Double       ignitionAltitude;
LINK BURN         burn[1000];
LINK Int32        numBurns;


extern Matrix atom(char* buffer);
extern Vector atov(char* buffer);
extern char*  ClockToString(char* buffer, Int32 clock);
extern Int8   load(char* filename);
extern void   MissionReport();
extern char*  nextLine(FILE* file);
extern char*  nw(char* buffer);
extern void   save();
extern Double sgn(Double d);
extern Int8   startsWith(char* buffer, const char* check);
extern Double sqr(Double d);
extern Double distance(Double lng1, Double lat1, Double lng2, Double lat2);




#endif

