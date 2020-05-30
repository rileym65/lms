#ifndef _ORBIT_H
#define _ORBIT_H

class Orbit {
  protected:
    double primaryMass;
    double secondaryMass;
    double totalMass;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double argumentOfPeriapsis;
    double eccentricity;
    double inclination;
    double longitudeAscendingNode;
    double meanAnomoly;
    double semiMajorAxis;
    double apoapsis;
    double periapsis;
    double period;
    double i;
    double m;
    double o;
    double w;
    double cw;
    double sw;
    double ci;
    double si;
    double co;
    double so;
  public:
    static constexpr double Gr = 6.6725985e-11;
    static constexpr double M_EARTH = 5.972e+24;
    static constexpr double M_MOON  = 7.34767309e+22;
    Orbit();
    ~Orbit();
    double PrimaryMass();
    double PrimaryMass(double d);
    double SecondaryMass();
    double SecondaryMass(double d);

    double X();
    double X(double d);
    double Y();
    double Y(double d);
    double Z();
    double Z(double d);
    double VX();
    double VX(double d);
    double VY();
    double VY(double d);
    double VZ();
    double VZ(double d);

    double Apoapsis();
    double Periapsis();
    double Period();
    double ArgumentOfPeriapsis();
    double ArgumentOfPeriapsis(double d);
    double Eccentricity();
    double Eccentricity(double d);
    double Inclination();
    double Inclination(double d);
    double LongitudeAscendingNode();
    double LongitudeAscendingNode(double d);
    double MeanAnomoly();
    double MeanAnomoly(double d);
    double SemiMajorAxis();
    double SemiMajorAxis(double d);

    void ComputeStateVectors();
    void ComputeRemainingOrbitalElements();

    };

#endif

