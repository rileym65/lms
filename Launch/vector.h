#ifndef _VECTOR_H
#define _VECTOR_H

#include "types.h"

class Vector {
  protected:
    Double x;
    Double y;
    Double z;
  public:
    Vector();
    Vector(double x, double y, double z);
    virtual ~Vector();
    virtual Vector operator+ (const Vector& a);
    virtual Vector operator- (const Vector& a);
    virtual Vector operator* (const double& a);
    virtual void   operator+= (const Vector& a);
    virtual void   operator-= (const Vector& a);
    virtual void   operator*= (const double& a);
    virtual Vector Cross(const Vector& b);
    virtual Double Dot(const Vector& a);
    virtual Double Length();
    virtual Vector Neg();
    virtual Vector Norm();
    virtual Vector Scale(double scale);
    virtual Double X(double v);
    virtual Double Y(double v);
    virtual Double Z(double v);
    virtual Double X();
    virtual Double Y();
    virtual Double Z();
  };

#endif

