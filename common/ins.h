#ifndef _INS_H
#define _INS_H

#include "types.h"
#include "vector.h"
#include "matrix.h"
#include "body.h"
#include "vehicle.h"

class Ins {
  protected:
    Double altitude;
    Double apoapsis;
    Double argOfPeriapsis;
    Double ascendingNode;
    Int32  clockAp;
    Int32  clockPe;
    Double deltaROC;
    Double deltaApoapsis;
    Double eccentricAnomaly;
    Double eccentricity;
    Double inclination;
    Double latitude;
    Double longitude;
    Double lastAltitude;
    Double lastApoapsis;
    Double lastLatitude;
    Double lastLatitudeVel;
    Double lastLongitude;
    Double lastROC;
    Double latitudeAcc;
    Double latitudeVel;
    Double meanAnomaly;
    Body  *orbiting;
    Double orbitTime;
    Double periapsis;
    Double radius;
    Double rateOfClimb;
    Double tarLatitude;
    Double tarLongitude;
    Double trueAnomaly;
    Double trueLongitude;
    Double tarMomEast;
    Double tarMomNorth;
    Double tarDockX;
    Double tarDockY;
    Double tarDockZ;
    Double tarDockVelX;
    Double tarDockVelY;
    Double tarDockVelZ;
    Vehicle* vehicle;
  public:
    Ins(Vehicle* v);
    ~Ins();
    Double Altitude();
    Double Altitude(Double d);
    Double Apoapsis();
    Double Apoapsis(Double d);
    Double ArgOfPeriapsis();
    Double ArgOfPeriapsis(Double d);
    Double AscendingNode();
    Double AscendingNode(Double d);
    Int32  ClockAp();
    Int32  ClockAp(Int32 i);
    Int32  ClockPe();
    Int32  ClockPe(Int32 i);
    Double DeltaApoapsis();
    Double DeltaROC();
    Double EccentricAnomaly();
    Double EccentricAnomaly(Double d);
    Double Eccentricity();
    Double Eccentricity(Double d);
    Double Inclination();
    Double Inclination(Double d);
    Double Latitude();
    Double Latitude(Double d);
    Double Longitude();
    Double Longitude(Double d);
    Double LastLatitude();
    Double LastLatitude(Double d);
    Double LastLatitudeVel();
    Double LastLatitudeVel(Double d);
    Double LastLongitude();
    Double LastLongitude(Double d);
    Double LatitudeAcc();
    Double LatitudeAcc(Double d);
    Double LatitudeVel();
    Double LatitudeVel(Double d);
    Double MeanAnomaly();
    Double MeanAnomaly(Double d);
    Body*  Orbiting();
    Body*  Orbiting(Body* b);
    Double OrbitTime();
    Double OrbitTime(Double d);
    Double Periapsis();
    Double Periapsis(Double d);
    Double Radius();
    Double Radius(Double d);
    Double RateOfClimb();
    Double TarLatitude();
    Double TarLatitude(Double d);
    Double TarLongitude();
    Double TarLongitude(Double d);
    Double TarMomEast();
    Double TarMomEast(Double d);
    Double TarMomNorth();
    Double TarMomNorth(Double d);
    Double TarDockX();
    Double TarDockX(Double d);
    Double TarDockY();
    Double TarDockY(Double d);
    Double TarDockZ();
    Double TarDockZ(Double d);
    Double TarDockVelX();
    Double TarDockVelX(Double d);
    Double TarDockVelY();
    Double TarDockVelY(Double d);
    Double TarDockVelZ();
    Double TarDockVelZ(Double d);
    Double TrueAnomaly();
    Double TrueAnomaly(Double d);
    Double TrueLongitude();
    Double TrueLongitude(Double d);

    void Cycle();
  };

#endif

