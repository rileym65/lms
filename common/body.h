#ifndef _BODY_H
#define _BODY_H

#include <stdio.h>
#include "vector.h"

class Body {
  protected:
    char name[64];
    Double ascendingNode;
    Double inclination;
    Double mass;
    Double meters;
    Double radius;
    Double gravitation;
    Vector position;
    Vector velocity;
    Body  *orbiting;
    Double latitude;
    Double longitude;
  public:
    Body(const char* n, Double m, Double r);
    ~Body();
    void   CalculateOrbit();
    void   Cycle(Double gran);
    Double AscendingNode();
    Double Inclination();
    char  *Name();
    Double Gravitation();
    Double Latitude();
    Double Longitude();
    Double Mass();
    Double Meters();
    Body  *Orbiting();
    Body  *Orbiting(Body* b);
    Double Radius();
    Vector Position();
    Vector Position(Vector v);
    Vector Velocity();
    Vector Velocity(Vector v);
    virtual void Load(FILE* file);
    virtual void Save(FILE* file);
  };

#ifdef MAIN
Body *Moon;
Body *Earth;
#else
extern Body *Moon;
extern Body *Earth;
#endif

#endif

