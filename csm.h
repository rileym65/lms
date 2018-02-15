#ifndef _CSM_H
#define _CSM_H

#include "vehicle.h"

class CSM : public Vehicle {
  protected:
  public:
    CSM();
    ~CSM();
    virtual void   Save(FILE* file);
  };

#endif

