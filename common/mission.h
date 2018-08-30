#ifndef _MISSION_H
#define _MISSION_H

#include "types.h"
#include "vector.h"
#include "lander.h"

class Mission {
  protected:
    char   *name;
    char   *description;
    char   *region;
    Int8    vehicle;
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
    Double  ascentFuel;
    Double  rcsFuel;
    Double  descentFuel;
    UInt32  consumables;
    Byte    rover;
    Byte    lsep;
    Byte    laser;
    Lander *lander;
    void    validate();
    Vector  targetPos;
    Vector  targetVel;
    Double  targetMomEast;
    Double  targetMomNorth;
    void    _computeTargetData();
  public:
    Mission();
    ~Mission();
    Double AscentEmptyWeight();
    Double AscentFullWeight();
    Double AscentFuel();
    Double AscentFuel(Double d);
    UInt32 Consumables();
    UInt32 Consumables(UInt32 i);
    Double DescentEmptyWeight();
    Double DescentFullWeight();
    Double DescentFuel();
    Double DescentFuel(Double d);
    char*  Description();
    char*  Description(char* s);
    Lander* Model();
    Byte   Laser();
    Byte   Laser(Byte b);
    Byte   Lsep();
    Byte   Lsep(Byte b);
    char*  Name();
    char*  Name(char* s);
    Double PrimaryLatitude();
    Double PrimaryLatitude(Double d);
    Double PrimaryLongitude();
    Double PrimaryLongitude(Double d);
    Double RcsFuel();
    Double RcsFuel(Double d);
    char*  Region();
    char*  Region(char* s);
    Byte   Rover();
    Byte   Rover(Byte b);
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
    Double TargetMomEast();
    Double TargetMomNorth();
    Int8   Vehicle();
    Int8   Vehicle(Int8 v);
    void   Save(FILE* file);
    void   Load(FILE* file);
  };

#ifdef MAIN
Mission *mission;
#else
extern Mission *mission;
#endif

#endif

