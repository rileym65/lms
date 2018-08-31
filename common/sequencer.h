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
#define SEQ_GETFLAG     24
#define SEQ_PUTFLAG     25
#define SEQ_PLANTFLAG   26
#define SEQ_GETLASER    27
#define SEQ_PUTLASER    28
#define SEQ_SETUPLASER  29
#define SEQ_KILL        30
#define SEQ_ABORT       31
#define SEQ_LIFTOFF     32
#define SEQ_GETALSEP    33
#define SEQ_PUTALSEP    34
#define SEQ_MESSAGE     35
#define SEQ_TOCART      36
#define SEQ_CARTTOLM    37
#define SEQ_CARTTOLRV   38


class Sequencer {
  protected:
    Int32        time;
    Int8         function;
    char         message[32];
    Int32        value;
    void  InProgress();
    void  Complete();
  public:
    Sequencer();
    ~Sequencer();
    Int32 Time();
    char* Message();
    void  Message(const char* msg, Int32 v, Int32 t);
    void  Abort();
    void  BoxToLm();
    void  BoxToLrv();
    void  BoxToPlss();
    void  CartToLm();
    void  CartToLrv();
    void  Cycle();
    void  CabinEvacuate();
    void  CabinPressurize();
    void  Dock();
    void  DropSample();
    void  EndEva();
    void  ExitLrv();
    void  GetAlsep();
    void  GetFlag();
    void  GetLaser();
    void  Kill();
    void  Liftoff();
    void  MoveCsm();
    void  MoveEva();
    void  MoveLm();
    void  MoveLrv();
    void  PlantFlag();
    void  PlssOff();
    void  PlssOn();
    void  PutAlsep();
    void  PutFlag();
    void  PutLaser();
    void  Rest();
    void  SampleToCart();
    void  SetupLaser();
    void  SetupLrv();
    void  Sleep();
    void  SpaceSuitOff();
    void  SpaceSuitOn();
    void  StoreSample();
    void  TakeSample();
    void  Undock();
    Int32 Value();
  };

#endif
