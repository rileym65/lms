#ifndef _HELPERS_H
#define _HELPERS_H

#include "vector.h"
#include "matrix.h"

extern Matrix atom(char* buffer);
extern Vector atov(char* buffer);
extern char*  ClockToString(char* buffer, Int32 clock);
extern Double distance(Double lng1, Double lat1, Double lng2, Double lat2);
extern char*  nextLine(FILE* file);
extern char*  nw(char* buffer);
extern Int8   startsWith(char* buffer, const char* check);
extern double toDegrees(double theta);
extern double toRadians(double theta);
extern double arctan2(double Ey, double Ex);
#endif
