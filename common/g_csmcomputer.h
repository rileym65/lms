#ifndef _GCSMCOMPUTER_H
#define _GCSMCOMPUTER_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_CsmComputer : public Gauge {
  protected:
  public:
    G_CsmComputer(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_CsmComputer();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
