#ifndef _VEHICLE_H
#define _VEHICLE_H

#include <stdio.h>
#include "types.h"
#include "vector.h"
#include "matrix.h"
#include "panel.h"
#include "body.h"
#include "ins.h"

class Computer;

class Vehicle {
  protected:
    Double    accelAltitude;
    Double    accelEast;
    Double    accelNorth;
    Double    battery;
    Computer *comp; 
    Boolean   destroyed;
    Double    distanceTravelled;
    Vector    drag;
    Double    dryWeight;
    Double    ebattery;
    Double    eoxygen;
    Vector    faceFront;
    Vector    faceLeft;
    Vector    faceUp;
    Vector    gimbals;
//    Double    lastLatitudeVel;
//    Double    latitudeVel;
//    Double    latitudeAcc;
    Double    longitudeVel;
    Double    maxBattery;
    Double    maxOxygen;
//    Double    orbitTime;
    Double    oxygen;
    Panel    *panel;
    Double    pitchRate;
    Vector    position;
    Double    rollRate;
    Int8      throttle;
    Vector    thrust;
    Int8      type;
    Vector    velocity;
    Double    velocityAltitude;
    Double    velocityEast;
    Double    velocityNorth;
    Double    yawRate;
    Vehicle  *targetVehicle;
    Ins      *ins;
  public:
    Vehicle();
    virtual ~Vehicle();
    virtual Double    AccelAltitude();
    virtual Double    AccelEast();
    virtual Double    AccelNorth();
    virtual Double    AddDistance(Double d);
    virtual Double    Battery();
    virtual Double    Battery(Double d);
    virtual Computer *Comp();
    virtual Computer *Comp(Computer* c);
    virtual void      Damage(Double dmg);
    virtual Boolean   Destroyed();
    virtual Double    DistanceTravelled();
    virtual Double    DistanceTravelled(Double d);
    virtual Double    DryWeight();
    virtual Double    DryWeight(Double d);
    virtual Double    EBattery();
    virtual Double    EBattery(Double d);
    virtual Byte      EnginesLit();
    virtual Double    EOxygen();
    virtual Double    EOxygen(Double d);
    virtual Vector    FaceFront();
    virtual Vector    FaceFront(Vector v);
    virtual Vector    FaceLeft();
    virtual Vector    FaceLeft(Vector v);
    virtual Vector    FaceUp();
    virtual Vector    FaceUp(Vector v);
    virtual Double    Fuel();
    virtual Ins      *GetIns();
    virtual Double    Latitude();
    virtual Double    Latitude(Double d);
    virtual Double    LatitudeVelocity();
    virtual Double    LatitudeAcceleration();
    virtual Double    Longitude();
    virtual Double    Longitude(Double d);
    virtual Double    MaxBattery();
    virtual Double    MaxBattery(Double d);
    virtual Double    MaxFuel();
    virtual Double    MaxOxygen();
    virtual Double    MaxOxygen(Double d);
    virtual Byte      NumEngines();
    virtual Byte      NumEngines(Byte stage);
    virtual Byte      NumStages();
    virtual Body*     Orbiting();
    virtual Body*     Orbiting(Body* b);
    virtual Double    OrbitTime();
    virtual Double    Oxygen();
    virtual Double    Oxygen(Double d);
    virtual Panel*    GetPanel();
    virtual Double    Pitch();
    virtual Double    Pitch(Double d);
    virtual Double    PitchRate();
    virtual Double    PitchRate(Double d);
    virtual Vector    Position();
    virtual Vector    Position(Vector v);
    virtual Double    Roll();
    virtual Double    Roll(Double d);
    virtual Double    RollRate();
    virtual Double    RollRate(Double d);
    virtual Byte      Stage();
    virtual Vehicle*  TargetVehicle();
    virtual Vehicle*  TargetVehicle(Vehicle* v);
    virtual Int8      Throttle();
    virtual Int8      Throttle(Int8 i);
    virtual Vector    Thrust();
    virtual Vector    Thrust(Vector v);
    virtual Byte      Type();
    virtual Vector    Velocity();
    virtual Vector    Velocity(Vector v);
    virtual Double    VelocityAltitude();
    virtual Double    VelocityEast();
    virtual Double    VelocityNorth();
    virtual Double    Yaw();
    virtual Double    Yaw(Double d);
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
    virtual Int8      SubLoad(FILE* file, char* line);
    virtual void      UpdatePanel();
    virtual Boolean   UseBattery(Double units);
    virtual Boolean   UseOxygen(Double units);
  };

#endif
