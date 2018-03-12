#ifndef _MAP_H
#define _MAP_H

#include "types.h"
#include "random.h"

typedef struct {
  char   name[40];
  Int8   category;
  Double longitude;
  Double latitude;
  Double diameter;
  char   symbol;
  Int32  cellX;
  Int32  cellY;
  } FEATURE;

class Map {
  protected:
    FEATURE *features;
    Int16    numFeatures;
    char     levelH[182][362];
    char     levelM[62][62];
    Double   lastLongitude;
    Double   lastLatitude;
    void drawCrater(Double longitude, Double latitude, Double diameter);
    void drawFeature(Double longitude, Double latitude, Double diameter, char ch);
    void drawMare(Double longitude, Double latitude, Double diameter, char ch);
    void drawRill(Double longitude, Double latitude, Double diameter, char ch);
    void loadFeatures(char* filename);
    void generateLevelHMap();
    void seed(UInt32 s);
    Int32 random(UInt32 range);
    void generateLevelMMap(Double longitude,Double latitude);
  public:
    Map();
    ~Map();
  Int32 Cell(Double degrees);
  Int32 CellH(Int32 longitude, Int32 latitude);
  Int32 CellM(Double longitude, Double latitude);
  char  Lurrain(Int32 cellX, Int32 cellY);
  };

#endif

