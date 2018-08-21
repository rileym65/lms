#ifndef _BODY_H
#define _BODY_H

#include "vector.h"

class Body {
  protected:
    char name[64];
    Double mass;
    Double radius;
    Double gravitation;
    Vector position;
    Vector velocity;
  public:
    Body(const char* n, Double m, Double r);
    ~Body();
    char  *Name();
    Double Gravitation();
    Double Mass();
    Double Radius();
    Vector Position();
    Vector Position(Vector v);
    Vector Velocity();
    Vector Velocity(Vector v);
  };

#endif

