#include "math.h"
#include "matrix.h"

Matrix::Matrix() {
  cell[0][0] = 0.0; cell[0][1] = 0.0; cell[0][2] = 0.0;
  cell[1][0] = 0.0; cell[1][1] = 0.0; cell[1][2] = 0.0;
  cell[2][0] = 0.0; cell[2][1] = 0.0; cell[2][2] = 0.0;
  }

Matrix::Matrix(Double ax, Double ay, Double az,
               Double bx, Double by, Double bz,
               Double cx, Double cy, Double cz) {
  cell[0][0] = ax; cell[0][1] = ay; cell[0][2] = az;
  cell[1][0] = bx; cell[1][1] = by; cell[1][2] = bz;
  cell[2][0] = cx; cell[2][1] = cy; cell[2][2] = cz;
  }

Matrix::~Matrix() {
  }

Matrix Matrix::RotateX(Double angle) {
  Double c,s;
  c = cos(angle * M_PI / 180);
  s = sin(angle * M_PI / 180);
  return Matrix(1.0,0.0,0.0, 0.0,c,-s, 0.0,s,c);
  }

Matrix Matrix::RotateY(Double angle) {
  Double c,s;
  c = cos(angle * M_PI / 180);
  s = sin(angle * M_PI / 180);
  return Matrix(c,0.0,s, 0.0,1.0,0.0, -s,0.0,c);
  }

Matrix Matrix::RotateZ(Double angle) {
  Double c,s;
  c = cos(angle * M_PI / 180);
  s = sin(angle * M_PI / 180);
  return Matrix(c,-s,0.0, s,c,0.0, 0.0,0.0,1.0);
  }

Matrix Matrix::Zero() {
  return Matrix(0.0,0.0,0.0, 0.0,0.0,0.0, 0.0,0.0,0.0);
  }

Matrix Matrix::Identity() {
  return Matrix(1.0,0.0,0.0, 0.0,1.0,0.0, 0.0,0.0,1.0);
  }

Double Matrix::Cell(int x,int y) {
  return cell[x][y];
  }

void Matrix::MultipliedBy(Matrix b) {
  int i,j,k;
  double acc;
  for (i=0;i<3;i++)
    for (j=0;j<3;j++) {
      acc=0;
      for (k=0;k<3;k++)
        acc += cell[i][k] * b.Cell(k, j);
      cell[i][j]=acc;
      }
  }

Vector Matrix::Transform(Vector a) {
  Double x,y,z;
  x=cell[0][0]*a.X() + cell[0][1]*a.Y() + cell[0][2]*a.Z();
  y=cell[1][0]*a.X() + cell[1][1]*a.Y() + cell[1][2]*a.Z();
  z=cell[2][0]*a.X() + cell[2][1]*a.Y() + cell[2][2]*a.Z();
  return Vector(x,y,z);
  }

