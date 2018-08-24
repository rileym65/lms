#ifndef _HELPERS_H
#define _HELPERS_H

#include "vector.h"
#include "matrix.h"

extern Matrix atom(char* buffer);
extern Vector atov(char* buffer);
extern char*  nextLine(FILE* file);
extern char*  nw(char* buffer);
extern Int8   startsWith(char* buffer, const char* check);

#endif
