#ifndef _GAMSDOCK_H
#define _GAMSDOCK_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsDock : public Gauge {
  protected:
    Double lastPx;
    Double lastPy;
    Int16 lastPosX;
    Int16 lastPosY;
    Int16 lastDockingRadarRoll;
    Int16 lastDockingRadarPitch;
    Int16 lastDockingRadarYaw;
    Int16 lastDockingRadarPosX;
    Int16 lastDockingRadarPosY;
    Int16 lastDockingRadarAngX;
    Int16 lastDockingRadarAngY;
    Int16 lastDockingRadarRolX;
  public:
    G_AmsDock(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsDock();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
