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
#include "command.h"
#include "booster.h"
#include "body.h"

// #define GROUND 6378100
// #define METERS ((GROUND*2*M_PI) / 360.0)
#define DR  (3.14159265358979323846 / 180)
#define VT_NONE       0
#define VT_SPACECRAFT 1
#define VT_ROCKET     2
#define VT_GROUND     4
#define VT_COMMAND    8
#define VT_LANDER     16

#include "../common/common.h"

#ifdef MINGW
#define LE   "\r\n"
#else
#define LE   "\n"
#endif

LINK Double  distance;
LINK Byte    engines;
LINK Boolean launched;
LINK Vector  pos;
LINK Booster* booster;
LINK Vector  vel;
//LINK CommandModule* csm;

extern Double AirDensity(Double altitude);
extern Int8   load(const char* filename);
extern void   save();

#endif
