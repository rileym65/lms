#ifndef _GDAYS_H
#define _GDAYS_H

#include "types.h"
#include "gauge.h"

#ifdef MAIN
UInt32 days;
#else
extern UInt32 days;
#endif

class Vehicle;

class G_Days : public Gauge {
  protected:
    UInt32 lastDay;
  public:
    G_Days(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Days();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
