#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "types.h"
#include "vector.h"
#include "matrix.h"

char* trim(char* buffer) {
  Int16 p;
  p = strlen(buffer) - 1;
  while (p >= 0 && buffer[p] > 0 && buffer[p] <= ' ') {
    buffer[p] = 0;
    p--;
    }
  while (buffer[0] > 0 && buffer[0] <= ' ') buffer++;
  return buffer;
  }

char* nextLine(FILE* file) {
  static char line[1024];
  if (fgets(line,1024,file) == NULL) return NULL;
  return trim(line);
  }

Int8 startsWith(char* buffer, const char* check) {
  if (strncasecmp(buffer,check,strlen(check)) == 0) return -1;
  return 0;
  }

char* nw(char* buffer) {
  while (buffer[0] > 0 && buffer[0] != ' ') buffer++;
  while (buffer[0] > 0 && buffer[0] == ' ') buffer++;
  return buffer;
  }

Double sqr(Double d) {
  return d*d;
  }

Double distance(Double lng1, Double lat1, Double lng2, Double lat2) {
  Double r;
  Double deltaLong;
  Double deltaLat;
  Double a;
  Double c;
  deltaLat = (lat2-lat1) * (3.14159265358979323846 / 180);
  deltaLong = (lng2-lng1) * (3.14159265358979323846 / 180);
  lat1 = lat1 * (3.14159265358979323846 / 180);
  lat2 = lat2 * (3.14159265358979323846 / 180);
  r = 1738300;
  a = sin(deltaLat/2) * sin(deltaLat/2) +
      cos(lat1) * cos(lat2) *
      sin(deltaLong/2) * sin(deltaLong/2);
  c = 2 * atan2(sqrt(a),sqrt(1-a));
  return c*r;
  }

Vector atov(char* buffer) {
  Vector ret;
  ret.X(atof(buffer));
  buffer = nw(buffer);
  ret.Y(atof(buffer));
  buffer = nw(buffer);
  ret.Z(atof(buffer));
  return ret;
  }

Matrix atom(char* buffer) {
  Double ax,ay,az;
  Double bx,by,bz;
  Double cx,cy,cz;
  ax = atof(buffer);
  buffer = nw(buffer);
  ay = atof(buffer);
  buffer = nw(buffer);
  az = atof(buffer);
  buffer = nw(buffer);
  bx = atof(buffer);
  buffer = nw(buffer);
  by = atof(buffer);
  buffer = nw(buffer);
  bz = atof(buffer);
  buffer = nw(buffer);
  cx = atof(buffer);
  buffer = nw(buffer);
  cy = atof(buffer);
  buffer = nw(buffer);
  cz = atof(buffer);
  return Matrix(ax,ay,az,bx,by,bz,cx,cy,cz);
  }

