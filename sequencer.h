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
#define SEQ_MOVE_EVA    13
#define SEQ_END_EVA     14
#define SEQ_TAKESAMPLE  15
#define SEQ_DROPSAMPLE  16
#define SEQ_SETUPLRV    17
#define SEQ_STORESAMPLE 18
#define SEQ_BOXPLSS     19
#define SEQ_BOXLM       20
#define SEQ_BOXLRV      21
#define SEQ_MOVELRV     22
#define SEQ_EXITLRV     23

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
    void  BoxToLm();
    void  BoxToLrv();
    void  BoxToPlss();
    void  Complete();
    void  Cycle();
    void  CabinEvacuate();
    void  CabinPressurize();
    void  Dock();
    void  DropSample();
    void  EndEva();
    void  ExitLrv();
    void  MoveCsm();
    void  MoveEva();
    void  MoveLm();
    void  MoveLrv();
    void  PlssOff();
    void  PlssOn();
    void  Rest();
    void  SetupLrv();
    void  Sleep();
    void  SpaceSuitOff();
    void  SpaceSuitOn();
    void  StoreSample();
    void  TakeSample();
    void  Undock();
  };

#endif
