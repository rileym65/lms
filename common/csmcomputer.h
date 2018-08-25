#ifndef _CSMCOMPUTER_H
#define _CSMCOMPUTER_H

#include "vehicle.h"
#include "spacecraft.h"
#include "command.h"

class CsmComputer {
  protected:
    Byte mode;
    CommandModule* csm;
    Double altitude;
    Double velocity;
  public:
    CsmComputer(CommandModule* c);
    ~CsmComputer();
    void Cycle();
  };

#endif

