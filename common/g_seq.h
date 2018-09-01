#ifndef _GSEQ_H
#define _GSEQ_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Seq : public Gauge {
  protected:
    Int8 lastArm;
    Int8 lastAbo;
    Int8 lastJet;
    Int8 lastKil;
    Int8 lastLif;
  public:
    G_Seq(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Seq();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
