#include <stdlib.h>
#include "header.h"
#include "map.h"

Map::Map() {
  }

Map::~Map() {
  }

Int32 Map::Cell(Double degrees) {
  Int32 ret;
  ret = (int)(degrees * CELL);
  if (degrees >= 0) ret++;
  return ret;
  }

char Map::Lurrain(Int32 cellX, Int32 cellY) {
  Int32 i;
  i = (cellX & 0xffff) | (cellY << 16);
  srand(i);
  i = rand() & 0x7f;
  if (i >=  0 && i <=  0) return '^';
  if (i >=  1 && i <=  5) return '.';
  if (i >=  6 && i <= 10) return 'o';
  if (i >= 11 && i <= 12) return 'O';
  if (i >= 13 && i <= 15) return '*';
  return ' ';
  }



