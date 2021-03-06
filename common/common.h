#ifndef _COMMON_H
#define _COMMON_H

#include <math.h>
#include "body.h"
#include "mission.h"
#include "lm.h"
#include "map.h"
#include "sequencer.h"
#include "random.h"
#include "command.h"

#define PI           3.14159265358979323846
#define PILOT_CSM 'c'
#define PILOT_LRV 'v'
#define PILOT_LM  'm'
#define PILOT_EVA 'e'
#define END_QUIT          1
#define END_MISSION       2
#define END_COLLISION     3
#define END_DEAD          4
#define END_CRASHED       5
#define GRAN          100.0
#define G             6.67408e-11
#define VT_NONE       0
#define VT_SPACECRAFT 1
#define VT_ROCKET     2
#define VT_GROUND     4
#define VT_COMMAND    8
#define VT_LANDER     16
#define VT_ROVER      32
#define LRV_BATTERY  200000.0
#define GROUND 1738300
#define METERS ((GROUND*2*PI) / 360.0)
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
#define S_FLAG           12
#define S_ALSEP          13
#define S_LSRF           14
#define S_DESCENT        15
#define S_LRV            16
#define S_DEBRIS         17
#define PLSS_OXYGEN 36000.0
#define PLSS_BATTERY 36000.0
#define PLSS_EOXYGEN 3600.0
#define PLSS_EBATTERY 3600.0
#define VEHICLE_APOLLO          1
#define VEHICLE_APOLLO_J        2
#define VEHICLE_APOLLO_MKII     3
#define VEHICLE_APOLLO_MKIII    4
#define VEHICLE_MERCURY_REDSTONE      5
#define VEHICLE_MERCURY_ATLAS         6
#define VEHICLE_GEMINI_TITAN          7
#define VEHICLE_APOLLO_SATURN_IB      8
#define VEHICLE_APOLLO_SATURN_V       9


#ifdef MINGW
#define LE   "\r\n"
#else
#define LE   "\n"
#endif

#ifdef MAIN
#define CLINK
#else
#define CLINK extern
#endif

typedef struct {
  Int32  start;
  Int32  end;
  Double fuelUsed;
  char   engine;
  } BURN;

typedef struct {
  Int32  start;
  Int32  end;
  Double walked;
  Double driven;
  Double farthest;
  Int32  samples;
  } EVA;

#include "lrv.h"
#include "plss.h"

CLINK Int8         alsepSetup;
CLINK Double       alsepLongitude;
CLINK Double       alsepLatitude;
CLINK BURN         burn[1000];
CLINK Int32        clockAbort;
CLINK Int32        clockBu;
CLINK Int32        clockDk;
CLINK Int32        clockDOI;
CLINK Int32        clockEv;
CLINK Int32        clockGe;
CLINK Int32        clockMi;
CLINK Int32        clockOr;
CLINK Int32        clockOt;
CLINK Int32        clockPDI;
CLINK Int32        clockTb;
CLINK Int32        clockTe;
CLINK Int32        clockUd;
CLINK Int32        clockUt;
CLINK CommandModule *csm;
CLINK Vehicle*     currentVehicle;
CLINK UInt32       days;
CLINK Int8         docked;
CLINK Double       dockingVel;
CLINK Double       dockingLVel;
CLINK Double       dockingXAlign;
CLINK Double       dockingYAlign;
CLINK Int8         dockingRadarOn;
CLINK Int8         dsnOn;
CLINK Body        *Earth;
CLINK Double       efficiency;
CLINK Int8         endReason;
CLINK Int32        evaCount;
CLINK EVA          evas[256];
CLINK Double       farthest;
CLINK Double       farthestFromEarth;
CLINK Int8         flagPlanted;
CLINK Double       flagLongitude;
CLINK Double       flagLatitude;
CLINK Double       hardInjury;
CLINK Double       highestVelocity;
CLINK Int32        ignitionTime;
CLINK Double       ignitionAltitude;
CLINK Double       ignitionApoapsis;
CLINK Double       ignitionPeriapsis;
CLINK Double       ignitionEccentricity;
CLINK Double       injury;
CLINK Double       landedHVel;
CLINK Double       landedLatitude;
CLINK Double       landedLongitude;
CLINK Int32        landedMet;
CLINK Double       landedVVel;
CLINK Int8         landingRadarOn;
CLINK Int8         laserSetup;
CLINK Double       laserLongitude;
CLINK Double       laserLatitude;
CLINK Int32        liftoffMet;
CLINK LunarModule *lm;
CLINK Int8         lmExtracted;
CLINK Int32        longestEVA;
CLINK Lrv         *lrv;
CLINK Int8         keyDelay;
CLINK Double       kscAngle;
CLINK Map         *map;
CLINK Double       metabolicRate;
CLINK Mission     *mission;
CLINK Int8         mode_abo;
CLINK Int8         mode_arm;
CLINK Int8         mode_jet;
CLINK Int8         mode_kil;
CLINK Int8         mode_lif;
CLINK Body        *Moon;
CLINK Int32        numBurns;
CLINK char         pilotLocation;
CLINK Boolean      plog;
CLINK Plss        *plss;
CLINK Int8         plssOn;
CLINK Int8         plssPacks;
CLINK UInt32       primarySamples;
CLINK Double       rendezvousDistance;
CLINK Random       rng;
CLINK Boolean      run;
CLINK UInt32       secondary1Samples;
CLINK UInt32       secondary2Samples;
CLINK UInt32       secondary3Samples;
CLINK Sequencer   *seq;
CLINK Int32        simSpeed;
CLINK Double       softInjury;
CLINK Int8         spaceSuitOn;
CLINK Int8         ticks;
CLINK Boolean      vnlog;
CLINK Int8         cabinPressurized;

CLINK UInt8        sampleType;
CLINK UInt8        sampleSmallRock;
CLINK UInt8        sampleMediumRock;
CLINK UInt8        sampleLargeRock;
CLINK UInt8        sampleSmallCrater;
CLINK UInt8        sampleMediumCrater;
CLINK UInt8        sampleLargeCrater;
CLINK UInt8        samplePlains;
CLINK UInt8        sampleRise;
CLINK UInt8        sampleSpecial;
CLINK UInt8        sampleDepression;
CLINK UInt8        sampleCraterWall;

CLINK Int32        ScoreLandedTime;
CLINK Int32        ScoreDescentFuel;
CLINK Int32        ScoreLandedDistance;
CLINK Int32        ScoreLandedVVel;
CLINK Int32        ScoreLandedHVel;
CLINK Int32        ScoreLatitudeBonus;
CLINK Int32        ScoreLanding;
CLINK Int32        ScoreEvaCompleted;
CLINK Int32        ScoreEvaSamples;
CLINK Int32        ScoreEvaTime;
CLINK Int32        ScoreEvaValue;
CLINK Int32        ScoreEvaFarthest;
CLINK Int32        ScoreEvaDriven;
CLINK Int32        ScoreEvaWalked;
CLINK Int32        ScoreEvaLrvSetup;
CLINK Int32        ScoreEvaLaserSetup;
CLINK Int32        ScoreEvaFlagSetup;
CLINK Int32        ScoreEvaAlsepSetup;
CLINK Int32        ScoreEvaPrimarySamples;
CLINK Int32        ScoreEvaSecondary1Samples;
CLINK Int32        ScoreEvaSecondary2Samples;
CLINK Int32        ScoreEvaSecondary3Samples;
CLINK Int32        ScoreEvaVariety;
CLINK Int32        ScoreEvaTotal;
CLINK Int32        ScoreDockTime;
CLINK Int32        ScoreDockAscentFuel;
CLINK Int32        ScoreDockRcsFuel;
CLINK Int32        ScoreDockTotal;
CLINK Int32        ScoreDockLVel;
CLINK Int32        ScoreDockVel;
CLINK Int32        ScoreDockXAlign;
CLINK Int32        ScoreDockYAlign;
CLINK Int32        ScoreTotal;
CLINK Int32        ScoreRendezvous;
CLINK Int32        ScoreSampleDiv;

extern SAMPLE ParseSample(char* line);




#endif



