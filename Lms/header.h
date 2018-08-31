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
#include "command.h"
#include "lrv.h"
#include "sequencer.h"
#include "map.h"
#include "mission.h"

#define TITLE "Lunar Mission Simulator"
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
#define VEHICLE_APOLLO          1
#define VEHICLE_APOLLO_J        2
#define VEHICLE_APOLLO_MKII     3
#define VEHICLE_APOLLO_MKIII    4

#ifdef MINGW
#define LE   "\r\n"
#else
#define LE   "\n"
#endif

LINK Double       dockingVel;
LINK Double       dockingLVel;
LINK Double       dockingXAlign;
LINK Double       dockingYAlign;
LINK Int8         insMode;
LINK Vector       targetPos;
LINK Vector       targetVel;
LINK Double       targetMomEast;
LINK Double       targetMomNorth;
LINK Double       csmMomEast;
LINK Double       csmMomNorth;
LINK Int8         ticks;
LINK Int8         keyDelay;
LINK UInt32       primarySamples;
LINK UInt32       secondary1Samples;
LINK UInt32       secondary2Samples;
LINK UInt32       secondary3Samples;
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

