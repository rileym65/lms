#ifndef _SPACECRAFT_H
#define _SPACECRAFT_H

#include "vehicle.h"

class Spacecraft : public Vehicle {
  protected:
    Double    altitude;
    Double    apoapsis;
    Double    argOfPeriapsis;
    Double    ascendingNode;
    Int32     clockAp;
    Int32     clockPe;
    Double    eccentricity;
    Double    deltaV;
    Double    fuelUsed;
    Double    inclination;
    Double    maxRcsFuel;
    Double    meanAnomaly;
    Double    trueAnomaly;
    Double    trueLongitude;
    Double    eccentricAnomaly;
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
    Double    tarLongitude;
    Double    tarLatitude;
    Double    tarMomEast;
    Double    tarMomNorth;
  public:
    Spacecraft();
    ~Spacecraft();
    virtual Double    Altitude();
    virtual Double    Altitude(Double d);
    virtual Double    Apoapsis();
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
    virtual Double    MaxRcsFuel();
    virtual Double    MaxRcsFuel(Double d);
    virtual Double    MeanAnomaly();
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
    virtual Double    RelAltitude();
    virtual Vector    RelPos();
    virtual Vector    RelVel();
    virtual Double    RelLongitude();
    virtual Double    RelLatitude();
    virtual Double    RelMomEast();
    virtual Double    RelMomNorth();
    virtual Double    RelOrbitTime();
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

