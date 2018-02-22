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
#include "lunarmodule.h"
#include "csm.h"
#include "ins.h"
#include "sequencer.h"

#define PILOT_CSM 'c'
#define PILOT_LRV 'v'
#define PILOT_LM  'm'
#define PILOT_EVA 'e'
#define FUEL_ASC  2615.0
#define FUEL_RCS  316.0
#define FUEL_DES  9720.0
#define LM_OXYGEN 432000.0
#define LM_BATTERY 432000.0
#define PLSS_OXYGEN 72000.0
#define PLSS_BATTERY 54000.0
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


#define LE   "\n"

LINK Int8         cabinPressurized;
LINK Int32        clockBu;
LINK Int32        clockDk;
LINK Int32        clockEv;
LINK Int32        clockOr;
LINK Int32        clockMi;
LINK Int32        clockUt;
LINK Int8         docked;
LINK Int8         dockingRadarOn;
LINK Int8         dsnOn;
LINK Double       efficiency;
LINK Double       injury;
LINK Int8         insMode;
LINK Int8         landingRadarOn;
LINK Int16        lmRock;
LINK Double       lrvBattery;
LINK Int8         lrvRock;
LINK Double       metabolicRate;
LINK char         pilotLocation;
LINK Double       plssOxygen;
LINK Double       plssBattery;
LINK Int8         plssPacks;
LINK Int8         sampleBoxes;
LINK Int32        simSpeed;
LINK Double       targetLatitude;
LINK Double       targetLongitude;
LINK Vector       targetPos;
LINK Vector       targetVel;
LINK Double       targetMomEast;
LINK Double       targetMomNorth;
LINK Int8         ticks;
LINK CSM         *csm;
LINK LunarModule *lm;
LINK Int8         plssOn;
LINK Int8         spaceSuitOn;
LINK INS         *ins;
LINK Vehicle*     currentVehicle;
LINK Sequencer*   seq;
LINK Boolean      run;


LINK Int8 INST_DR_X;
LINK Int8 INST_DR_Y;
LINK Int8 INST_ATT_X;
LINK Int8 INST_ATT_Y;
LINK Int8 INST_DOCK_X;
LINK Int8 INST_DOCK_Y;
LINK Int8 INST_DOWN_X;
LINK Int8 INST_DOWN_Y;
LINK Int8 INST_IND_X;
LINK Int8 INST_IND_Y;
LINK Int8 INST_LAND_X;
LINK Int8 INST_LAND_Y;
LINK Int8 INST_WEST_X;
LINK Int8 INST_WEST_Y;
LINK Int8 INST_SPIN_X;
LINK Int8 INST_SPIN_Y;
LINK Int8 INST_CONS_X;
LINK Int8 INST_CONS_Y;
LINK Int8 INST_STAT_X;
LINK Int8 INST_STAT_Y;
LINK Int8 INST_CLCK_X;
LINK Int8 INST_CLCK_Y;
LINK Int8 INST_INS_X;
LINK Int8 INST_INS_Y;
LINK Int8 INST_PILOT_X;
LINK Int8 INST_PILOT_Y;
LINK Int8 INST_PLSS_X;
LINK Int8 INST_PLSS_Y;
LINK Int8 INST_LM_X;
LINK Int8 INST_LM_Y;
LINK Int8 INST_LRV_X;
LINK Int8 INST_LRV_Y;
LINK Int8 INST_SEQ_X;
LINK Int8 INST_SEQ_Y;

extern Matrix atom(char* buffer);
extern Vector atov(char* buffer);
extern Int8   load(char* filename);
extern char*  nextLine(FILE* file);
extern char*  nw(char* buffer);
extern void   save();
extern Double sgn(Double d);
extern Int8   startsWith(char* buffer, const char* check);


#endif

