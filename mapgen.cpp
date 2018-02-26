#define MAIN

#include <stdio.h>
#include "types.h"
#include "map.h"

Map *map;

int main(int argc, char** argv) {
  Int32 x,y;
  map = new Map();

  for (y=-90; y<=90; y++) {
    for (x=-180; x<=180; x++)
      printf("%c",map->Cell0(x,y));
    printf("\n");
    }


  delete(map);
  }

