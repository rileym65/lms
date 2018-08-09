#ifndef _MATRIX_H
#define _MATRIX_H

#include "types.h"
#include "vector.h"

class Matrix {
  protected:
    Double cell[3][3];
  public:
    Matrix();
    Matrix(Double ax, Double ay, Double az,
           Double bx, Double by, Double bz,
           Double cx, Double cy, Double cz);
    ~Matrix();
    static Matrix RotateX(Double angle);
    static Matrix RotateY(Double angle);
    static Matrix RotateZ(Double angle);
    static Matrix Rotate(Vector v, Double angle);
    static Matrix Zero();
    static Matrix Identity();
    Double Cell(int x,int y);
    void MultipliedBy(Matrix b);
    Vector Row(UInt8 r);
    void   Row(UInt8 r,Vector v);
    Vector Transform(Vector a);
  };

#endif
