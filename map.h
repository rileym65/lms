#ifndef _MAP_H
#define _MAP_H

#include "types.h"
#include "random.h"

class Map {
  protected:
  public:
    Map();
    ~Map();
  Int32 Cell(Double degrees);
  char  Lurrain(Int32 cellX, Int32 cellY);
  };

#endif

