#ifndef _GAMSSEQ_H
#define _GAMSSEQ_H

#include "types.h"
#include "gauge.h"

class G_AmsSeq : public Gauge {
  protected:
  public:
    G_AmsSeq(Int8 x,Int8 y,Boolean f);
    virtual ~G_AmsSeq();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
