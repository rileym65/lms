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
#define VEHICLE_APOLLO          1
#define VEHICLE_APOLLO_J        2
#define VEHICLE_APOLLO_MKII     3
#define VEHICLE_APOLLO_MKIII    4

#ifdef MINGW
#define LE   "\r\n"
#else
#define LE   "\n"
#endif

LINK Int8         insMode;
LINK Vector       targetPos;
LINK Vector       targetVel;
LINK Double       targetMomEast;
LINK Double       targetMomNorth;
LINK Double       csmMomEast;
LINK Double       csmMomNorth;
LINK UInt8        vehicle;

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

