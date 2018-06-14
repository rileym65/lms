#ifndef _RANDOM_H
#define _RANDOM_H

#include "types.h"
#include "lfsr.h"

class Random  {
  protected:
    Lfsr   rng;
    UInt32 bitsize(UInt32 n);
  public:
    Random();
    Random(UInt32 ss);
    virtual ~Random();
    virtual void Seed(UInt32 s);
    virtual void Seed(UInt32 s,UInt32 t);
    virtual UInt32 Next(UInt32 range);
  };

#endif

