#ifndef _MISSION_H
#define _MISSION_H

#include "types.h"

class Mission {
  protected:
    char   *name;
    char   *region;
    Double  targetLongitude;
    Double  targetLatitude;
  public:
    Mission();
    ~Mission();
    char*  Name();
    char*  Name(char* s);
    char*  Region();
    char*  Region(char* s);
    Double TargetLatitude();
    Double TargetLatitude(Double d);
    Double TargetLongitude();
    Double TargetLongitude(Double d);
    void   Save(FILE* file);
    void   Load(FILE* file);
  };

#endif

