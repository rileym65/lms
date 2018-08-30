#ifndef _LANDER_H
#define _LANDER_H

#include "types.h"

#define APOLLO_ASCENT_FUEL       2375
#define APOLLO_RCS_FUEL           287
#define APOLLO_DESCENT_FUEL       8248
#define APOLLO_ASCENT_CONSUMABLES  (10 * 3600)
#define APOLLO_ASCENT_ECONSUMABLES  (2 * 3600)
#define APOLLO_CONSUMABLES       (45 * 3600)
#define APOLLO_ECONSUMABLES       (10 * 3600)
#define APOLLO_ASCENT_EMPTY_WEIGHT        2179
#define APOLLO_DESCENT_EMPTY_WEIGHT        1938.14
#define APOLLO_ASCENT_ISP                  311
#define APOLLO_RCS_ISP              290
#define APOLLO_DESCENT_ISP                 311
#define APOLLO_ASCENT_THRUST               14314
#define APOLLO_DESCENT_THRUST              43903
#define APOLLO_RCS_THRUST                  1780

#define APOLLO_J_ASCENT_FUEL     2375
#define APOLLO_J_RCS_FUEL         287
#define APOLLO_J_DESCENT_FUEL     8872
#define APOLLO_J_ASCENT_CONSUMABLES  (10 * 3600)
#define APOLLO_J_ASCENT_ECONSUMABLES  (2 * 3600)
#define APOLLO_J_CONSUMABLES     (75 * 3600)
#define APOLLO_J_ECONSUMABLES     (10 * 3600)
#define APOLLO_J_ASCENT_EMPTY_WEIGHT      2127
#define APOLLO_J_DESCENT_EMPTY_WEIGHT      2313.91
#define APOLLO_J_ASCENT_ISP                311
#define APOLLO_J_RCS_ISP            290
#define APOLLO_J_DESCENT_ISP               311
#define APOLLO_J_ASCENT_THRUST             14345
#define APOLLO_J_DESCENT_THRUST            43903
#define APOLLO_J_RCS_THRUST                1780

#define APOLLO_MKII_ASCENT_FUEL  2615
#define APOLLO_MKII_RCS_FUEL      316
#define APOLLO_MKII_DESCENT_FUEL  9720
#define APOLLO_MKII_ASCENT_CONSUMABLES  (10 * 3600)
#define APOLLO_MKII_ASCENT_ECONSUMABLES  (2 * 3600)
#define APOLLO_MKII_CONSUMABLES  (110 * 3600)
#define APOLLO_MKII_ECONSUMABLES  (10 * 3600)
#define APOLLO_MKII_ASCENT_EMPTY_WEIGHT   2234
#define APOLLO_MKII_DESCENT_EMPTY_WEIGHT   1869.78
#define APOLLO_MKII_ASCENT_ISP             344
#define APOLLO_MKII_RCS_ISP         401
#define APOLLO_MKII_DESCENT_ISP            334
#define APOLLO_MKII_ASCENT_THRUST          16890
#define APOLLO_MKII_DESCENT_THRUST         49215
#define APOLLO_MKII_RCS_THRUST             1970

#define APOLLO_MKIII_ASCENT_FUEL 3500
#define APOLLO_MKIII_RCS_FUEL     350
#define APOLLO_MKIII_DESCENT_FUEL 13000
#define APOLLO_MKIII_ASCENT_CONSUMABLES  (10 * 3600)
#define APOLLO_MKIII_ASCENT_ECONSUMABLES  (2 * 3600)
#define APOLLO_MKIII_CONSUMABLES (220 * 3600)
#define APOLLO_MKIII_ECONSUMABLES (10 * 3600)
#define APOLLO_MKIII_ASCENT_EMPTY_WEIGHT  2410
#define APOLLO_MKIII_DESCENT_EMPTY_WEIGHT  1926.55
#define APOLLO_MKIII_ASCENT_ISP            462
#define APOLLO_MKIII_RCS_ISP        340
#define APOLLO_MKIII_DESCENT_ISP           462
#define APOLLO_MKIII_ASCENT_THRUST         18000
#define APOLLO_MKIII_DESCENT_THRUST        53500
#define APOLLO_MKIII_RCS_THRUST            2150

#define ROVER_MKI_WEIGHT   210
#define ROVER_MKII_WEIGHT  230
#define ROVER_MKIII_WEIGHT 310

#define ELSEP_WEIGHT        49
#define ALSEP_WEIGHT       163
#define LASER_WEIGHT        20

#define APOLLO       1
#define APOLLO_J     2
#define APOLLO_MKII  3
#define APOLLO_MKIII 4

class Lander {
  protected:
    Byte vehicle;
  public:
    Lander(Byte v);
    ~Lander();
    UInt32 AscentConsumables();
    Double AscentDeltaV();
    UInt32 AscentEConsumables();
    Double AscentEmptyWeight();
    Double AscentFuel();
    Double AscentFullWeight();
    Double AscentIsp();
    Double AscentThrust();
    UInt32 Consumables();
    Double DescentDeltaV();
    Double DescentEmptyWeight();
    Double DescentFuel();
    Double DescentFullWeight();
    Double DescentIsp();
    Double DescentThrust();
    UInt32 EConsumables();
    Double RcsFuel();
    Double RcsIsp();
    Double RcsThrust();
    Byte Vehicle();
  };

#endif
