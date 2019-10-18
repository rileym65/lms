#include "common.h"

SAMPLE ParseSample(char* line) {
  SAMPLE ret;
  sscanf(line,"%d,%d,%d,%lf,%d",&ret.cellX,&ret.cellY,&ret.clockGe,&ret.value,&ret.type);
  return ret;
  }

