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
#include "sequencer.h"
#include "map.h"
#include "mission.h"

#define TITLE "Lunar Mission Simulator"
#define PILOT_CSM 'c'
#define PILOT_LRV 'v'
#define PILOT_LM  'm'
#define PILOT_EVA 'e'
#define PLSS_OXYGEN 36000.0
#define PLSS_BATTERY 36000.0
#define PLSS_EOXYGEN 3600.0
#define PLSS_EBATTERY 3600.0
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
#define MAPCELL           (1.0/(METERS/10.0))
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
#define S_CRATERWALL     11
#define END_QUIT          1
#define END_MISSION       2
#define END_COLLISION     3
#define END_DEAD          4
#define END_CRASHED       5
#define VEHICLE_APOLLO          1
#define VEHICLE_APOLLO_J        2
#define VEHICLE_APOLLO_MKII     3
#define VEHICLE_APOLLO_MKIII    4

#ifdef MINGW
#define LE   "\r\n"
#else
#define LE   "\n"
#endif

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
LINK Int32        clockTe;
LINK Int32        clockUd;
LINK Int32        clockDOI;
LINK Int32        clockPDI;
LINK Double       dockingVel;
LINK Double       dockingLVel;
LINK Double       dockingXAlign;
LINK Double       dockingYAlign;
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
LINK Int8         insMode;
LINK Int8         landingRadarOn;
LINK LunarModule *lm;
LINK Lrv         *lrv;
LINK Map         *map;
LINK Double       metabolicRate;
LINK Int8         mode_abo;
LINK Int8         mode_arm;
LINK Int8         mode_jet;
LINK Int8         mode_kil;
LINK Int8         mode_lif;
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
LINK Double       csmMomEast;
LINK Double       csmMomNorth;
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
LINK UInt8        sampleCraterWall;
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
LINK UInt8        lrvSampleCraterWall;
LINK UInt8        cartSampleSmallRock;
LINK UInt8        cartSampleMediumRock;
LINK UInt8        cartSampleLargeRock;
LINK UInt8        cartSampleSmallCrater;
LINK UInt8        cartSampleMediumCrater;
LINK UInt8        cartSampleLargeCrater;
LINK UInt8        cartSamplePlains;
LINK UInt8        cartSampleRise;
LINK UInt8        cartSampleSpecial;
LINK UInt8        cartSampleDepression;
LINK UInt8        cartSampleCraterWall;
LINK Double       landedLongitude;
LINK Double       landedLatitude;
LINK Double       landedVVel;
LINK Double       landedHVel;
LINK Double       farthest;
LINK Int8         flagPlanted;
LINK Double       flagLongitude;
LINK Double       flagLatitude;
LINK Int8         laserSetup;
LINK Double       laserLongitude;
LINK Double       laserLatitude;
LINK Int8         alsepSetup;
LINK Double       alsepLongitude;
LINK Double       alsepLatitude;
LINK Int8         endReason;
LINK Int32        ignitionTime;
LINK Double       ignitionAltitude;
LINK BURN         burn[1000];
LINK Int32        numBurns;
LINK UInt32       primarySamples;
LINK UInt32       secondary1Samples;
LINK UInt32       secondary2Samples;
LINK UInt32       secondary3Samples;
LINK Random       rng;
LINK UInt8        vehicle;

LINK Int32        ScoreLandedTime;
LINK Int32        ScoreDescentFuel;
LINK Int32        ScoreLandedDistance;
LINK Int32        ScoreLandedVVel;
LINK Int32        ScoreLandedHVel;
LINK Int32        ScoreLatitudeBonus;
LINK Int32        ScoreLanding;
LINK Int32        ScoreEvaCompleted;
LINK Int32        ScoreEvaSamples;
LINK Int32        ScoreEvaTime;
LINK Int32        ScoreEvaValue;
LINK Int32        ScoreEvaFarthest;
LINK Int32        ScoreEvaDriven;
LINK Int32        ScoreEvaWalked;
LINK Int32        ScoreEvaLrvSetup;
LINK Int32        ScoreEvaLaserSetup;
LINK Int32        ScoreEvaFlagSetup;
LINK Int32        ScoreEvaAlsepSetup;
LINK Int32        ScoreEvaPrimarySamples;
LINK Int32        ScoreEvaSecondary1Samples;
LINK Int32        ScoreEvaSecondary2Samples;
LINK Int32        ScoreEvaSecondary3Samples;
LINK Int32        ScoreEvaVariety;
LINK Int32        ScoreEvaTotal;
LINK Int32        ScoreDockTime;
LINK Int32        ScoreDockAscentFuel;
LINK Int32        ScoreDockRcsFuel;
LINK Int32        ScoreDockTotal;
LINK Int32        ScoreDockLVel;
LINK Int32        ScoreDockVel;
LINK Int32        ScoreTotal;

extern Matrix atom(char* buffer);
extern Vector atov(char* buffer);
extern char*  ClockToString(char* buffer, Int32 clock);
extern Int8   load(char* filename);
extern void   MissionReport();
extern char*  nextLine(FILE* file);
extern char*  nw(char* buffer);
extern void   save();
extern void   Score();
extern Double sgn(Double d);
extern Int8   startsWith(char* buffer, const char* check);
extern Double sqr(Double d);
extern Double distance(Double lng1, Double lat1, Double lng2, Double lat2);




#endif

