#ifndef _HEADER_H
#define _HEADER_H

#ifdef MAIN
#define LINK
#else
#define LINK extern
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "types.h"
#include "vector.h"
#include "matrix.h"
#include "vehicle.h"
#include "booster.h"


#define GROUND 6378100
#define METERS ((GROUND*2*M_PI) / 360.0)
#define DR  (3.14159265358979323846 / 180)
#define VT_NONE       0
#define VT_SPACECRAFT 1
#define VT_ROCKET     2
#define VT_GROUND     3

#ifdef MINGW
#define LE   "\r\n"
#else
#define LE   "\n"
#endif

LINK UInt32  clockBu;
LINK UInt32  clockUt;
LINK UInt32  clockMi;
LINK UInt32  clockTb;
LINK Byte    engines;
LINK Boolean launched;
LINK Double  kscAngle;
LINK Vector  pos;
LINK UInt32  simSpeed;
LINK Booster* booster;
LINK Vector  vel;

extern Matrix atom(char* buffer);
extern Vector atov(char* buffer);
extern char* nextLine(FILE* file);
extern char* nw(char* buffer);
extern Int8 startsWith(char* buffer, const char* check);

#endif
