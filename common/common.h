#ifndef _COMMON_H
#define _COMMON_H

#include "body.h"
#include "mission.h"

#define GRAN          100.0
#define G             6.67408e-11
#define VT_NONE       0
#define VT_SPACECRAFT 1
#define VT_ROCKET     2
#define VT_GROUND     4
#define VT_COMMAND    8
#define VT_LANDER     16

#define VEHICLE_APOLLO          1
#define VEHICLE_APOLLO_J        2
#define VEHICLE_APOLLO_MKII     3
#define VEHICLE_APOLLO_MKIII    4

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

CLINK Int32 clockBu;
CLINK Int32 clockDk;
CLINK Int32 clockDOI;
CLINK Int32 clockEv;
CLINK Int32 clockMi;
CLINK Int32 clockOr;
CLINK Int32 clockOt;
CLINK Int32 clockPDI;
CLINK Int32 clockTb;
CLINK Int32 clockTe;
CLINK Int32 clockUd;
CLINK Int32 clockUt;
CLINK UInt32 days;
CLINK Double kscAngle;
CLINK Mission *mission;
CLINK Body *Moon;
CLINK Body *Earth;


#endif



