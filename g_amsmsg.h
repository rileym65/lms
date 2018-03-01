#ifndef _GAMSMSG_H
#define _GAMSMSG_H

#include "types.h"
#include "gauge.h"

class vehicle;

class G_AmsMessage : public Gauge {
  protected:
    Int32 lastSeqTime;
    char  lastMessage[32];
  public:
    G_AmsMessage(Int8 x,Int8 y,Boolean f,Vehicle* v);
    virtual ~G_AmsMessage();
    virtual void Reset();
    virtual void Display();
    virtual void Update();

  };

#endif
