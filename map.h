#ifndef _MAP_H
#define _MAP_H

#include "types.h"
#include "random.h"

class Map {
  protected:
    char level0[182][362];
    void drawCrater(Double longitude, Double latitude, Double diameter);
    void drawFeature(Double longitude, Double latitude, Double diameter, char ch);
    void drawMare(Double longitude, Double latitude, Double diameter, char ch);
    void drawRill(Double longitude, Double latitude, Double diameter, char ch);
    void readFeatures();
    void seed(UInt32 s);
    Int32 random(UInt32 range);
  public:
    Map();
    ~Map();
  Int32 Cell(Double degrees);
  Int32 Cell0(Int32 longitude, Int32 latitude);
  char  Lurrain(Int32 cellX, Int32 cellY);
  };

#endif

