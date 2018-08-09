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

Matrix Matrix::Rotate(Vector v, Double angle) {
  Double c,s;
  Double ux,uy,uz;
  Double ux2,uy2,uz2;
  ux = v.X();
  uy = v.Y();
  uz = v.Z();
  ux2 = v.X() * v.X();
  uy2 = v.Y() * v.Y();
  uz2 = v.Z() * v.Z();
  c = cos(angle * M_PI / 180);
  s = sin(angle * M_PI / 180);
  return Matrix(c+ux2*(1-c)     , ux*uy*(1-c)-uz*s , ux*uz*(1-c)+uy*s,
                ux*uy*(1-c)+uz*s, c + uy2 * (1 - c), uy*uz*(1-c) - ux*s,
                uz*ux*(1-c)-uy*s, uz*uy*(1-c)+ux*s , c+uz2*(1-c));
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

Vector Matrix::Row(UInt8 r) {
  return Vector(cell[r][0],cell[r][1],cell[r][2]);
  }

void Matrix::Row(UInt8 r,Vector v) {
  cell[r][0] = v.X();
  cell[r][1] = v.Y();
  cell[r][2] = v.Z();
  }

Vector Matrix::Transform(Vector a) {
  Double x,y,z;
  x=cell[0][0]*a.X() + cell[0][1]*a.Y() + cell[0][2]*a.Z();
  y=cell[1][0]*a.X() + cell[1][1]*a.Y() + cell[1][2]*a.Z();
  z=cell[2][0]*a.X() + cell[2][1]*a.Y() + cell[2][2]*a.Z();
  return Vector(x,y,z);
  }

