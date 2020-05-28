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
#include <math.h>
#include "terminal.h"
#include "types.h"
#include "mission.h"
#include "map.h"

#define GROUND 1738300
#define METERS ((GROUND*2*M_PI) / 360.0)
#define CELL   (1.0/(METERS/10.0))
#define M1 19
#define M2 21
#define C1 41
#define C2 54


LINK Mission* mission;

LINK char**   categories;
LINK UInt32   numCategories;
LINK FEATURE *features;
LINK UInt32   numFeatures;
LINK Map*     map;
LINK UInt16   selections[10000];
LINK UInt16   numSelections;
LINK char     cells[21][61];

extern void    Box(UInt32 x, UInt32 y, UInt32 width, UInt32 height);
extern Boolean CategoryExists(char* name);
extern void    ClearScreen();
extern void    DoLoadout();
extern void    Flush();
extern void    GetRegion();
extern void    HideMapCursor(Int32 x, Int32 y);
extern Boolean Input(Int32 x, Int32 y, char* buffer, Boolean append);
extern void    LoadCategories();
extern void    LoadMap(Double latitude, Double longitude, UInt32 level);
extern void    LoadoutMenu();
extern void    MainMenu();
extern void    Menu();
extern void    MissionEditor();
extern Double  NumericDialog(char* msg, Double max);
extern Boolean SelectFromMap(Double* latitude, Double* longitude);
extern void    SelectOrbit();
extern void    SelectVehicle();
extern void    ShowLoadout();
extern void    ShowMap();
extern void    ShowMapCursor(Int32 x, Int32 y);
extern void    ShowMapData(Double latitude, Double longitude);
extern void    ShowSelections(UInt32 top, UInt32 count);
extern void    ShowVehicle(Int8 vehicle);
extern void    WriteCentered(Int32 x, Int32 y, const char* message);

#endif

