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
#include "console.h"

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
#define SEQ_MOVE_LM      1

#define LE   "\n"

LINK Int8         cabinPressurized;
LINK Int32        clockBu;
LINK Int32        clockDk;
LINK Int32        clockEv;
LINK Int32        clockOr;
LINK Int32        clockMi;
LINK Int32        clockUt;
LINK Console     *console;
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
LINK char         message[32];
LINK Double       metabolicRate;
LINK char         pilotLocation;
LINK Double       plssOxygen;
LINK Double       plssBattery;
LINK Int8         plssPacks;
LINK Int8         sampleBoxes;
LINK Int32        seqTime;
LINK Int8         seqFunction;
LINK Int32        simSpeed;
LINK Int8         ticks;
LINK CSM         *csm;
LINK LunarModule *lm;
LINK Int8         plssOn;
LINK Int8         spaceSuitOn;

extern Vector atov(char* buffer);
extern Int8   load(char* filename);
extern char*  nextLine(FILE* file);
extern char*  nw(char* buffer);
extern void   save();
extern Double sgn(Double d);
extern Int8   startsWith(char* buffer, const char* check);


#endif

