#include "math.h"
#include "orbit.h"

Orbit::Orbit() {
  }

Orbit::~Orbit() {
  }

double Orbit::Apoapsis() {
  return apoapsis;
  }

double Orbit::Periapsis() {
  return periapsis;
  }

double Orbit::Period() {
  return period;
  }

double Orbit::PrimaryMass() {
  return primaryMass;
  }

double Orbit::PrimaryMass(double d) {
  primaryMass = d;
  totalMass = primaryMass + secondaryMass;
  return primaryMass;
  }

double Orbit::SecondaryMass() {
  return secondaryMass;
  }

double Orbit::SecondaryMass(double d) {
  secondaryMass = d;
  totalMass = primaryMass + secondaryMass;
  return secondaryMass;
  }

double Orbit::X() {
  return x;
  }

double Orbit::X(double d) {
  x = d;
  return x;
  }

double Orbit::Y() {
  return y;
  }

double Orbit::Y(double d) {
  y = d;
  return y;
  }

double Orbit::Z() {
  return z;
  }

double Orbit::Z(double d) {
  z = d;
  return z;
  }

double Orbit::VX() {
  return vx;
  }

double Orbit::VX(double d) {
  vx = d;
  return vx;
  }

double Orbit::VY() {
  return vy;
  }

double Orbit::VY(double d) {
  vy = d;
  return vy;
  }

double Orbit::VZ() {
  return vz;
  }

double Orbit::VZ(double d) {
  vz = d;
  return vz;
  }

double Orbit::ArgumentOfPeriapsis() {
  return argumentOfPeriapsis;
  }

double Orbit::ArgumentOfPeriapsis(double d) {
  argumentOfPeriapsis = d;
  w = argumentOfPeriapsis * 3.14159265358979323846 / 180.0;
  cw = cos(w);
  sw = sin(w);
  return argumentOfPeriapsis;
  }

double Orbit::Inclination() {
  return inclination;
  }

double Orbit::Inclination(double d) {
  inclination = d;
  i = inclination * 3.14159265358979323846 / 180.0;
  ci = cos(i);
  si = sin(i);
  return inclination;
  }

double Orbit::Eccentricity() {
  return eccentricity;
  }

double Orbit::Eccentricity(double d) {
  eccentricity = d;
  return eccentricity;
  }

double Orbit::LongitudeAscendingNode() {
  return longitudeAscendingNode;
  }

double Orbit::LongitudeAscendingNode(double d) {
  longitudeAscendingNode = d;
  o = longitudeAscendingNode * 3.14159265358979323846 / 180.0;
  co = cos(o);
  so = sin(o);
  return longitudeAscendingNode;
  }

double Orbit::MeanAnomoly() {
  return meanAnomoly;
  }

double Orbit::MeanAnomoly(double d) {
  meanAnomoly = d;
  m = meanAnomoly * 3.14159265358979323846 / 180.0;
  return meanAnomoly;
  }

double Orbit::SemiMajorAxis() {
  return semiMajorAxis;
  }

double Orbit::SemiMajorAxis(double d) {
  semiMajorAxis = d;
  return semiMajorAxis;
  }

void Orbit::ComputeStateVectors() {
  double diff;
  double eps;
  double e1;
  double eca;
  double ceca, seca;
  double xw, yw;
  double xdw, ydw;
  double px, py, pz;
  double qx, qy, qz;
  double edot;
  double swci, cwci;

  eca = m + eccentricity / 2;
  diff = 10000;
  eps =  0.000001;
  e1 = 0;

  while (diff > eps) {
    e1 = eca - (eca - eccentricity * sin(eca) - m) / (1 - eccentricity * cos(eca));
    diff = fabs(e1 - eca);
    eca = e1;
    }

  ceca = cos(eca);
  seca = sin(eca);
  e1 = semiMajorAxis * sqrt(fabs(1 - eccentricity * eccentricity));
  xw = semiMajorAxis * (ceca - eccentricity);
  yw = e1 * seca;
  edot = sqrt((Gr * totalMass) / semiMajorAxis) / (semiMajorAxis * (1 - eccentricity * ceca));

  xdw = -semiMajorAxis * edot * seca;
  ydw = e1 * edot * ceca;

  swci = sw * ci;
  cwci = cw * ci;
  px = cw * co - so * swci;
  py = cw * so + co * swci;
  pz = sw * si;
  qx = -sw * co - so * cwci;
  qy = -sw * so + co * cwci;
  qz = cw * si;
  x = xw * px + yw * qx;
  y = xw * py + yw * qy;
  z = xw * pz + yw * qz;
  vx = xdw * px + ydw * qx;
  vy = xdw * py + ydw * qy;
  vz = xdw * pz + ydw * qz;
  }

void Orbit::ComputeRemainingOrbitalElements() {
  apoapsis = semiMajorAxis + (semiMajorAxis * eccentricity);
  periapsis = semiMajorAxis - (semiMajorAxis * eccentricity);
  period = 2*3.14159265358979323846 *
           sqrt(semiMajorAxis * semiMajorAxis * semiMajorAxis / (Gr*totalMass));
  }

