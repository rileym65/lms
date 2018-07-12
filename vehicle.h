#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <stdio.h>
#include "types.h"
#include "vector.h"
#include "matrix.h"
#include "panel.h"

class Computer;

class Vehicle {
  protected:
    Double    accelAltitude;
    Double    accelEast;
    Double    accelNorth;
    Double    altitude;
    Vector    baseFront;
    Vector    baseLeft;
    Vector    baseUp;
    Double    battery;
    Computer *comp; 
    Double    ebattery;
    Double    eoxygen;
    Vector    faceFront;
    Vector    faceLeft;
    Vector    faceUp;
    Double    latitude;
    Double    longitude;
    Double    lastLatitude;
    Double    lastLatitudeVel;
    Double    lastLongitude;
    Double    latitudeVel;
    Double    latitudeAcc;
    Double    longitudeVel;
    Double    maxBattery;
    Double    maxOxygen;
    Matrix    orientation;
    Double    oxygen;
    Panel    *panel;
    Double    pitch;
    Matrix    pitchMatrix;
    Double    pitchRate;
    Vector    position;
    Double    radius;
    char      rcsFbMode;
    char      rcsLrMode;
    Int8      rcsRotThrottle;
    Int8      rcsThrottle;
    char      rcsUdMode;
    Double    roll;
    Matrix    rollMatrix;
    Double    rollRate;
    Int8      throttle;
    Vector    thrust;
    Vector    velocity;
    Double    velocityAltitude;
    Double    velocityEast;
    Double    velocityNorth;
    Double    yaw;
    Matrix    yawMatrix;
    Double    yawRate;

  public:
    Vehicle();
    virtual ~Vehicle();
    virtual Double    AccelAltitude();
    virtual Double    AccelEast();
    virtual Double    AccelNorth();
    virtual Double    Altitude();
    virtual Double    Altitude(Double d);
    virtual Double    Battery();
    virtual Double    Battery(Double d);
    virtual Computer *Comp();
    virtual Computer *Comp(Computer* c);
    virtual void      Damage(Double dmg);
    virtual Double    EBattery();
    virtual Double    EBattery(Double d);
    virtual Double    EOxygen();
    virtual Double    EOxygen(Double d);
    virtual Vector    FaceFront();
    virtual Vector    FaceFront(Vector v);
    virtual Vector    FaceLeft();
    virtual Vector    FaceLeft(Vector v);
    virtual Vector    FaceUp();
    virtual Vector    FaceUp(Vector v);
    virtual Double    Latitude();
    virtual Double    Latitude(Double d);
    virtual Double    LatitudeVelocity();
    virtual Double    LatitudeAcceleration();
    virtual Double    Longitude();
    virtual Double    Longitude(Double d);
    virtual Double    MaxBattery();
    virtual Double    MaxBattery(Double d);
    virtual Double    MaxOxygen();
    virtual Double    MaxOxygen(Double d);
    virtual Double    Oxygen();
    virtual Double    Oxygen(Double d);
    virtual Double    Pitch();
    virtual Double    PitchRate();
    virtual Double    PitchRate(Double d);
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
    virtual Double    Roll();
    virtual Double    RollRate();
    virtual Double    RollRate(Double d);
    virtual Int8      Throttle();
    virtual Int8      Throttle(Int8 i);
    virtual Vector    Thrust();
    virtual Vector    Thrust(Vector v);
    virtual Vector    Velocity();
    virtual Vector    Velocity(Vector v);
    virtual Double    VelocityAltitude();
    virtual Double    VelocityEast();
    virtual Double    VelocityNorth();
    virtual Double    Yaw();
    virtual Double    YawRate();
    virtual Double    YawRate(Double d);

    virtual void      Cycle();
    virtual void      Init();
    virtual void      InitPanel();
    virtual void      Load(FILE* file);
    virtual Double    Mass();
    virtual void      ProcessKey(Int32 key);
    virtual void      Save(FILE* file);
    virtual void      SetupPanel();
    virtual Int8      SubLoad(char* line);
    virtual void      UpdatePanel();
    virtual Boolean   UseBattery(Double units);
    virtual Boolean   UseOxygen(Double units);
  };

#endif
