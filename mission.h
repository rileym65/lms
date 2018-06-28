#ifndef _MISSION_H
#define _MISSION_H

#include "types.h"

class Mission {
  protected:
    char   *name;
    char   *description;
    char   *region;
    Double  targetLongitude;
    Double  targetLatitude;
    Double  primaryLongitude;
    Double  primaryLatitude;
    Double  secondary1Longitude;
    Double  secondary1Latitude;
    Double  secondary2Longitude;
    Double  secondary2Latitude;
    Double  secondary3Longitude;
    Double  secondary3Latitude;
  public:
    Mission();
    ~Mission();
    char*  Description();
    char*  Description(char* s);
    char*  Name();
    char*  Name(char* s);
    Double PrimaryLatitude();
    Double PrimaryLatitude(Double d);
    Double PrimaryLongitude();
    Double PrimaryLongitude(Double d);
    char*  Region();
    char*  Region(char* s);
    Double Secondary1Latitude();
    Double Secondary1Latitude(Double d);
    Double Secondary1Longitude();
    Double Secondary1Longitude(Double d);
    Double Secondary2Latitude();
    Double Secondary2Latitude(Double d);
    Double Secondary2Longitude();
    Double Secondary2Longitude(Double d);
    Double Secondary3Latitude();
    Double Secondary3Latitude(Double d);
    Double Secondary3Longitude();
    Double Secondary3Longitude(Double d);
    Double TargetLatitude();
    Double TargetLatitude(Double d);
    Double TargetLongitude();
    Double TargetLongitude(Double d);
    void   Save(FILE* file);
    void   Load(FILE* file);
  };

#endif

