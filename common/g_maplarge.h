#ifndef _GMAPLARGED_H
#define _GMAPLARGED_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_MapLarge : public Gauge {
  protected:
    Int32 lastCellX;
    Int32 lastCellY;
    char  data[19][42];
  public:
    G_MapLarge(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_MapLarge();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
