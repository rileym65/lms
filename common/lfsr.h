#ifndef _LFSR_H
#define _LFSR_H

#include "types.h"

class Lfsr {
  protected:
    UInt32 seed;
    UInt32 taps;
  public:
    Lfsr();
    Lfsr(UInt32 s, UInt32 t);
    virtual ~Lfsr();
    virtual void Seed(UInt32 s);
    virtual void Taps(UInt32 t);
    virtual void Shift(int count);
    virtual UInt32 Next(int bits);
    virtual Byte   NextByte();
    virtual Word   NextWord();
    virtual Dword  NextDword();
    virtual Qword  NextQword();
  };

#endif
