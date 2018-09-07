#ifndef _CSMCOMPUTER_H
#define _CSMCOMPUTER_H

#include "vehicle.h"
#include "spacecraft.h"
#include "command.h"

class CsmComputer {
  protected:
    char entryMode;
    Byte prog;
    Byte noun;
    Byte verb;
    Int32 reg1;
    Int32 reg2;
    Int32 reg3;
    Byte  running;
    char dprog[4];
    char dnoun[4];
    char dverb[4];
    char dreg1[8];
    char dreg2[8];
    char dreg3[8];
    Double ram[256];
    CommandModule* csm;
    Double altitude;
    Double velocity;
    void   _doShow();
    void   _reg1(Int32 i);
    void   _reg2(Int32 i);
    void   _reg3(Int32 i);
    void   _processNoun();
  public:
    CsmComputer(CommandModule* c);
    ~CsmComputer();
    virtual void Cycle();
    virtual char* Noun();
    virtual char* Prog();
    virtual char* Reg1();
    virtual char* Reg2();
    virtual char* Reg3();
    virtual Byte  Running();
    virtual char* Verb();
    virtual void ProcessKey(Int32 key);
    virtual Int8 Load(FILE* file);
    virtual void Save(FILE* file);
  };

#endif

