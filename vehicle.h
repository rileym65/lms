#ifndef _VEHICLE_H
#define _VEHICLE_H

#include "types.h"
#include "vector.h"

class Vehicle {
  protected:
    Double altitude;
    Vector faceFront;
    Vector faceLeft;
    Vector faceUp;
    Double latitude;
    Double longitude;
    Vector orientation;
    Vector position;
    Double radius;
    Vector thrust;
    Vector velocity;
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
    virtual Vector Orientation();
    virtual Vector Orientation(Vector v);
    virtual Vector Position();
    virtual Vector Position(Vector v);
    virtual Double Radius();
    virtual Double Radius(Double d);
    virtual Vector Thrust();
    virtual Vector Thrust(Vector v);
    virtual Vector Velocity();
    virtual Vector Velocity(Vector v);
    virtual Double VelocityEast();
    virtual Double VelocityNorth();
    virtual void   Cycle();
  };

#endif
