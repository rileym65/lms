#ifndef _GORBITLARGED_H
#define _GORBITLARGED_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_OrbitLarge : public Gauge {
  protected:
    Int32 lastCellX;
    Int32 lastCellY;
    char  data[19][42];
  public:
    G_OrbitLarge(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_OrbitLarge();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
