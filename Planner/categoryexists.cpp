#include "header.h"

Boolean CategoryExists(char* name) {
  UInt32 i;
  for (i=0; i<numCategories; i++)
    if (strcasecmp(categories[i],name) == 0) return true;
  return false;
  }

