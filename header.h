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
#define PLSS_OXYGEN 36000.0
#define PLSS_BATTERY 36000.0
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

#define LE   "\n"

typedef struct {
  Int32 cellX;
  Int32 cellY;
  } LOCATION;

LINK Int8         cabinPressurized;
LINK Int32        clockBu;
LINK Int32        clockDk;
LINK Int32        clockEv;
LINK Int32        clockOr;
LINK Int32        clockMi;
LINK Int32        clockUt;
LINK Int32        clockTe;
LINK CSM         *csm;
LINK Vehicle*     currentVehicle;
LINK Int8         docked;
LINK Int8         dockingRadarOn;
LINK Int8         dsnOn;
LINK Double       efficiency;
LINK Double       injury;
LINK INS         *ins;
LINK Int8         insMode;
LINK Int8         landingRadarOn;
LINK LunarModule *lm;
LINK Lrv         *lrv;
LINK Map         *map;
LINK Double       metabolicRate;
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
LINK Double       targetLatitude;
LINK Double       targetLongitude;
LINK Vector       targetPos;
LINK Vector       targetVel;
LINK Double       targetMomEast;
LINK Double       targetMomNorth;
LINK Int8         ticks;



extern Matrix atom(char* buffer);
extern Vector atov(char* buffer);
extern Int8   load(char* filename);
extern char*  nextLine(FILE* file);
extern char*  nw(char* buffer);
extern void   save();
extern Double sgn(Double d);
extern Int8   startsWith(char* buffer, const char* check);


#endif

