#include "header.h"

void LoadMap(Double latitude, Double longitude, UInt32 level) {
  UInt32 x,y;
  for (y=0; y<19; y++) {
    for (x=0; x<59; x++)
      cells[y][x] = map->Lurrain(longitude+((Double)y-9.0)*0.000329608,
                                 latitude+((Double)x-29.0)*0.000329608);
    cells[y][59] = 0;
    }
  }

