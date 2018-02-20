#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <stdio.h>
#include "types.h"
#include "vector.h"
#include "matrix.h"

class Vehicle {
  protected:
    Double altitude;
    Vector baseFront;
    Vector baseLeft;
    Vector baseUp;
    Vector faceFront;
    Vector faceLeft;
    Vector faceUp;
    Double latitude;
    Double longitude;
    Matrix orientation;
    Vector position;
    Double radius;
    Vector thrust;
    Vector velocity;
    Double velocityAltitude;
  public:
    Vehicle();
    ~Vehicle();
    virtual Double Altitude();
    virtual Double Altitude(Double d);
    virtual Vector FaceFront();
    virtual Vector FaceFront(Vector v);
    virtual Vector FaceLeft();
    virtual Vector FaceLeft(Vector v);
    virtual Vector FaceUp();
    virtual Vector FaceUp(Vector v);
    virtual Double Latitude();
    virtual Double Latitude(Double d);
    virtual Double Longitude();
    virtual Double Longitude(Double d);
    virtual Vector Position();
    virtual Vector Position(Vector v);
    virtual Double Radius();
    virtual Double Radius(Double d);
    virtual Vector Thrust();
    virtual Vector Thrust(Vector v);
    virtual Vector Velocity();
    virtual Vector Velocity(Vector v);
    virtual Double VelocityAltitude();
    virtual Double VelocityEast();
    virtual Double VelocityNorth();
    virtual void   Cycle();
    virtual void   Save(FILE* file);
    virtual Int8   SubLoad(char* line);
    virtual void   Load(FILE* file);
    virtual void   SetupPanel();
    virtual void   UpdatePanel();
    virtual void   ProcessKey(Int32 key);
  };

#endif
