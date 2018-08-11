#ifndef _SPACECRAFT_H
#define _SPACECRAFT_H

#include "vehicle.h"

class Spacecraft : public Vehicle {
  protected:
    Double    altitude;
    Double    apoapsis;
    Double    ascendingNode;
    Double    inclination;
    Double    periapsis;
    Double    radius;
    char      rcsFbMode;
    char      rcsLrMode;
    Int8      rcsRotThrottle;
    Int8      rcsThrottle;
    char      rcsUdMode;
  public:
    Spacecraft();
    ~Spacecraft();
    virtual Double    Altitude();
    virtual Double    Altitude(Double d);
    virtual Double    Apoapsis();
    virtual Double    AscendingNode();
    virtual Double    Inclination();
    virtual Double    Periapsis();
    virtual Vector    Position();
    virtual Vector    Position(Vector v);
    virtual Double    Radius();
    virtual Double    Radius(Double d);
    virtual char      RcsFbMode();
    virtual char      RcsFbMode(char c);
    virtual char      RcsLrMode();
    virtual char      RcsLrMode(char c);
    virtual Int8      RcsRotThrottle();
    virtual Int8      RcsRotThrottle(Int8 i);
    virtual Int8      RcsThrottle();
    virtual Int8      RcsThrottle(Int8 i);
    virtual char      RcsUdMode();
    virtual char      RcsUdMode(char c);

    virtual void      Cycle();
    virtual void      Save(FILE* file);
    virtual Int8      SubLoad(FILE* file, char* line);
  };

#endif

