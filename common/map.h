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
  Double peak;
  Double minLongitude;
  Double maxLongitude;
  Double minLatitude;
  Double maxLatitude;
  char   symbol;
  Int32  cellX;
  Int32  cellY;
  Int32  minCellX,minCellY;
  Int32  maxCellX,maxCellY;
  Double cellRadius;
  Double radius;
  Double rad1;
  Double rad2;
  Double rad3;
  } FEATURE;

class Map {
  protected:
    FEATURE *features;
    UInt32   numFeatures;
    char     levelH[182][362];
    char     levelM[62][62];
    Double   lastLongitude;
    Double   lastLatitude;
    Random   rng;
    UInt32   segments[360][1000];
    UInt32   numSegments[360];
    void addToSegment(Int32 segment, UInt32 value);
    void drawCrater(Double longitude, Double latitude, Double diameter);
    void drawFeature(Double longitude, Double latitude, Double diameter, char ch);
    void drawMare(Double longitude, Double latitude, Double diameter, char ch);
    void drawRill(Double longitude, Double latitude, Double diameter, char ch);
    void loadFeatures(const char* filename);
    void generateLevelHMap();
    void drawCraterMedium(Double longitude, Double latitude, Double diameter);
    void generateLevelMMap(Double longitude,Double latitude);
    char symbolAt(Double longitude, Double latitude);
    void processFeature(const char* line);
  public:
    Map();
    ~Map();
  Int32 Cell(Double degrees);
  Double Degrees(Int32 cell);
  FEATURE* Features();
  Int32    NumFeatures();
  Int32 CellH(Int32 longitude, Int32 latitude);
  Int32 CellM(Double longitude, Double latitude);
  char  Lurrain(Double longitude, Double Latitude);
  };

#endif

