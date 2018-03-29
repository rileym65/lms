#ifndef _LUNARMODULE_H
#define _LUNARMODULE_H

#include "vector.h"
#include "vehicle.h"

class LunarModule : public Vehicle {
  protected:
    
    Int8   descentJettisoned;
    Int8   landed;
    char   rcsFbMode;
    char   rcsLrMode;
    char   rcsUdMode;
    Int8   rcsThrottle;
    Int8   rcsRotThrottle;
    Int16  rock;
    Double ascentFuel;
    Double descentFuel;
    Double pitchRate;
    Double rcsFuel;
    Double rollRate;
    Double yawRate;
    Double roll;
    Double pitch;
    Double yaw;
    Double value;
    Matrix pitchMatrix;
    Matrix rollMatrix;
    Matrix yawMatrix;
  public:
    LunarModule();
    virtual ~LunarModule();
    virtual void InitPanel();
    char   RcsFbMode();
    char   RcsFbMode(char c);
    char   RcsLrMode();
    char   RcsLrMode(char c);
    char   RcsUdMode();
    char   RcsUdMode(char c);
    Int8   RcsThrottle();
    Int8   RcsThrottle(Int8 i);
    Int8   RcsRotThrottle();
    Int8   RcsRotThrottle(Int8 i);
    Int16  Rock();
    Int16  Rock(Int16 i);
    Double AscentFuel();
    Double AscentFuel(Double d);
    Double DescentFuel();
    Double DescentFuel(Double d);
    Int8   DescentJettisoned();
    Int8   Landed();
    Double PitchRate();
    Double PitchRate(Double d);
    Double RcsFuel();
    Double RcsFuel(Double d);
    Double RollRate();
    Double RollRate(Double d);
    Double YawRate();
    Double YawRate(Double d);
    Double Value();
    Double Value(Double d);
    virtual void   Cycle();
    virtual Double Mass();
    virtual void   Abort();
    virtual void   Save(FILE* file);
    virtual Int8   SubLoad(char* line);
    virtual void   ProcessKey(Int32 key);
  };

#endif

