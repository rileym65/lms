#ifndef _GAMSSEQ_H
#define _GAMSSEQ_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_AmsSeq : public Gauge {
  protected:
    Int8 lastAbo;
    Int8 lastJet;
    Int8 lastKil;
    Int8 lastLif;
  public:
    G_AmsSeq(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsSeq();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
