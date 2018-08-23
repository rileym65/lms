#ifndef _SPACECRAFT_H
#define _SPACECRAFT_H

#include "vehicle.h"

class Spacecraft : public Vehicle {
  protected:
    Double    altitude;
    Double    apoapsis;
    Double    ascendingNode;
    Double    inclination;
    Double    maxRcsFuel;
    Double    periapsis;
    Double    rateOfClimb;
    Double    radius;
    Double    rcsFuel;
    char      rcsFbMode;
    Double    rcsIsp;
    char      rcsLrMode;
    Double    rcsPropellant;
    Int8      rcsRotThrottle;
    Int8      rcsThrottle;
    Double    rcsThrust;
    char      rcsUdMode;
    Double    moonG;
    Double    earthG;
  public:
    Spacecraft();
    ~Spacecraft();
    virtual Double    Altitude();
    virtual Double    Altitude(Double d);
    virtual Double    Apoapsis();
    virtual Double    AscendingNode();
    virtual Double    EarthG();
    virtual Double    Inclination();
    virtual void      Ins();
    virtual Double    MaxRcsFuel();
    virtual Double    MaxRcsFuel(Double d);
    virtual Double    MoonG();
    virtual Double    Periapsis();
    virtual Vector    Position();
    virtual Vector    Position(Vector v);
    virtual Double    Radius();
    virtual Double    Radius(Double d);
    virtual Double    RateOfClimb();
    virtual Double    RateOfClimb(Double d);
    virtual char      RcsFbMode();
    virtual char      RcsFbMode(char c);
    virtual Double    RcsFuel();
    virtual Double    RcsFuel(Double d);
    virtual Double    RcsIsp();
    virtual Double    RcsIsp(Double d);
    virtual char      RcsLrMode();
    virtual char      RcsLrMode(char c);
    virtual Double    RcsPropellant();
    virtual Double    RcsPropellant(Double d);
    virtual Int8      RcsRotThrottle();
    virtual Int8      RcsRotThrottle(Int8 i);
    virtual Int8      RcsThrottle();
    virtual Int8      RcsThrottle(Int8 i);
    virtual Double    RcsThrust();
    virtual Double    RcsThrust(Double d);
    virtual char      RcsUdMode();
    virtual char      RcsUdMode(char c);

    virtual void      Cycle();
    virtual void      Save(FILE* file);
    virtual Int8      SubLoad(FILE* file, char* line);
  };

#endif

