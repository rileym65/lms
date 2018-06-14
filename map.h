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
    Random   rng;
    void drawCrater(Double longitude, Double latitude, Double diameter);
    void drawFeature(Double longitude, Double latitude, Double diameter, char ch);
    void drawMare(Double longitude, Double latitude, Double diameter, char ch);
    void drawRill(Double longitude, Double latitude, Double diameter, char ch);
    void loadFeatures(const char* filename);
    void generateLevelHMap();
    void drawCraterMedium(Double longitude, Double latitude, Double diameter);
    void generateLevelMMap(Double longitude,Double latitude);
  public:
    Map();
    ~Map();
  Int32 Cell(Double degrees);
  Double Degrees(Int32 cell);
  Int32 CellH(Int32 longitude, Int32 latitude);
  Int32 CellM(Double longitude, Double latitude);
  char  Lurrain(Double longitude, Double Latitude);
  };

#endif

