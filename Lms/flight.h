#ifndef _FLIGHT_H
#define _FLIGHT_H

#define FLIGHT_SAVE     1
#define FLIGHT_COMPLETE 2
#define FLIGHT_CRASHED  3

class Flight {
  protected:
    Int8 alignedForDocking();
    void cycle();
    void Launch();
    void geminiTitan();
    void mercuryAtlas();
    void mercuryRedstone();
    void saturn1B();
    void saturnV(UInt8 lem);
    void saturnVb(UInt8 lem);
  public:
    void Init();
    UInt32 Fly();
  };

#endif

