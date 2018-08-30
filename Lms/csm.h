#ifndef _CSM_H
#define _CSM_H

#include "vehicle.h"

class CSM : public Spacecraft {
  protected:
  public:
    CSM();
    ~CSM();
    virtual void   Save(FILE* file);
    virtual void ProcessKey(Int32 key);
  };

#endif

