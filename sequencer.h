#ifndef _SEQUENCER_H
#define _SEQUENCER_H

#include "types.h"

#define SEQ_MOVE_LM      1
#define SEQ_MOVE_CSM     2
#define SEQ_UNDOCK       3
#define SEQ_SUITON       4
#define SEQ_SUITOFF      5
#define SEQ_PLSSON       6
#define SEQ_PLSSOFF      7
#define SEQ_CABINEVAC    8
#define SEQ_CABINPRESS   9
#define SEQ_DOCKING     10
#define SEQ_REST        11
#define SEQ_SLEEP       12

class Sequencer {
  protected:
    Int32        time;
    Int8         function;
    char         message[32];
  public:
    Sequencer();
    ~Sequencer();
    Int32 Time();
    char* Message();
    void  Complete();
    void  Cycle();
    void  CabinEvacuate();
    void  CabinPressurize();
    void  Dock();
    void  MoveCsm();
    void  MoveLm();
    void  PlssOff();
    void  PlssOn();
    void  Rest();
    void  Sleep();
    void  SpaceSuitOff();
    void  SpaceSuitOn();
    void  Undock();
  };

#endif
