#ifndef _GCOMPUTER_H
#define _GCOMPUTER_H

#include "types.h"
#include "gauge.h"

class Vehicle;

class G_Computer : public Gauge {
  protected:
    char   lastProg[8];
    char   lastVerb[8];
    char   lastNoun[8];
    char   lastReg1[8];
    char   lastReg2[8];
    char   lastReg3[8];
    char   lastReg4[8];
    char   lastReg5[8];
    char   lastReg6[8];
    char   lastReg7[8];
    char   lastReg8[8];
    char   lastReg9[8];
    char   lastReg10[8];
    char   lastReg11[8];
    char   lastReg12[8];
    char   lastReg13[8];
    char   lastReg14[8];
    char   lastReg15[8];
    Int8   lastInputMode;
    Int8   inputMode;
    Boolean lastRunning;
    Boolean lastInput;
    Boolean lastErr;
  public:
    G_Computer(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_Computer();
    virtual void Reset();
    virtual void Display();
    virtual void Update();
  };

#endif
