#ifndef _SPACECRAFT_H
#define _SPACECRAFT_H

#include "vehicle.h"

class Spacecraft : public Vehicle {
  protected:
    Double    deltaV;
    Double    fuelUsed;
    Double    isp;
    Double    maxRcsFuel;
    Double    rateOfClimb;
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
    virtual Double    Apoapsis(Double d);
    virtual Double    ArgOfPeriapsis();
    virtual Double    AscendingNode();
    virtual Int32     ClockAp();
    virtual Int32     ClockPe();
    virtual Double    DeltaV();
    virtual Double    EarthG();
    virtual Double    EccentricAnomaly();
    virtual Double    FuelUsed();
    virtual Double    Inclination();
    virtual void      Ins();
    virtual Double    Isp();
    virtual Double    MaxRcsFuel();
    virtual Double    MaxRcsFuel(Double d);
    virtual Double    MeanAnomaly();
    virtual Double    MoonG();
    virtual Double    Periapsis();
    virtual Double    Periapsis(Double d);
    virtual Vector    Position();
    virtual Vector    Position(Vector v);
    virtual void      Prograde(Double maxRate);
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
    virtual Double    RelAltitude();
    virtual Vector    RelPos();
    virtual Vector    RelVel();
    virtual Double    RelLongitude();
    virtual Double    RelLatitude();
    virtual Double    RelMomEast();
    virtual Double    RelMomNorth();
    virtual Double    RelOrbitTime();
    virtual void      Retrograde(Double maxRate);
    virtual Double    TargetLongitude();
    virtual Double    TargetLatitude();
    virtual Double    TargetMomEast();
    virtual Double    TargetMomNorth();
    virtual Double    TrueAnomaly();
    virtual Double    TrueLongitude();

    virtual void      Cycle();
    virtual void      Save(FILE* file);
    virtual Int8      SubLoad(FILE* file, char* line);
  };

#endif

