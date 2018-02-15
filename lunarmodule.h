#ifndef _LUNARMODULE_H
#define _LUNARMODULE_H

#include "vector.h"
#include "vehicle.h"

class LunarModule : public Vehicle {
  protected:
    
    char   rcsFbMode;
    char   rcsLrMode;
    char   rcsUdMode;
    Int8   rcsThrottle;
    Int8   throttle;
    Double ascentFuel;
    Double battery;
    Double descentFuel;
    Double oxygen;
    Double pitchRate;
    Double rcsFuel;
    Double rollRate;
    Double yawRate;
  public:
    LunarModule();
    ~LunarModule();
    char   RcsFbMode();
    char   RcsFbMode(char c);
    char   RcsLrMode();
    char   RcsLrMode(char c);
    char   RcsUdMode();
    char   RcsUdMode(char c);
    Int8   RcsThrottle();
    Int8   RcsThrottle(Int8 i);
    Int8   Throttle();
    Int8   Throttle(Int8 i);
    Double AscentFuel();
    Double AscentFuel(Double d);
    Double Battery();
    Double Battery(Double d);
    Double DescentFuel();
    Double DescentFuel(Double d);
    Double Oxygen();
    Double Oxygen(Double d);
    Double PitchRate();
    Double PitchRate(Double d);
    Double RcsFuel();
    Double RcsFuel(Double d);
    Double RollRate();
    Double RollRate(Double d);
    Double YawRate();
    Double YawRate(Double d);
    virtual void Save(FILE* file);
    virtual Int8 SubLoad(char* line);
  };

#endif

