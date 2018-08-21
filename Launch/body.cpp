#include <string.h>
#include "header.h"
#include "types.h"
#include "body.h"

Body::Body(const char* n, Double m, Double r) {
  strcpy(name,n);
  mass = m;
  radius = r;
  gravitation = mass * 6.67408e-11;
  position = Vector(0,0,0);
  velocity = Vector(0,0,0);
  orbiting = NULL;
  }

Body::~Body() {
  }

Double Body::AscendingNode() {
  return ascendingNode;
  }

Double Body::Inclination() {
  return inclination;
  }

void Body::CalculateOrbit() {
  Vector L;
  Double hyp;
  L = velocity.Cross(position);
  hyp = sqrt(L.X() * L.X() + L.Y() * L.Y());
  ascendingNode = L.Y() / hyp;
  ascendingNode = asin(ascendingNode) * 180 / M_PI;
  if (L.X() < 0 && L.Y() < 0) ascendingNode = -180 - ascendingNode;
  if (L.X() < 0 && L.Y() >= 0) ascendingNode = 180 - ascendingNode;
  hyp = sqrt(L.Z() * L.Z() + hyp * hyp);
  inclination = L.Z() / hyp;
  inclination = asin(inclination) * 180 / M_PI;
  }

void Body::Cycle() {
  Double d;
  if (orbiting == NULL) return;
  position = position + velocity;
  d = position.Length();
  d = ((G * mass * orbiting->Mass()) / (d * d) ) / mass;
  velocity = velocity - position.Norm().Scale(d);
  }

char* Body::Name() {
  return name;
  }

Double Body::Gravitation() {
  return gravitation;
  }

Double Body::Mass() {
  return mass;
  }

Body* Body::Orbiting() {
  return orbiting;
  }

Body* Body::Orbiting(Body* b) {
  orbiting = b;
  return orbiting;
  }

Double Body::Radius() {
  return radius;
  }

Vector Body::Position() {
  return position;
  }

Vector Body::Position(Vector v) {
  position = v;
  return position;
  }

Vector Body::Velocity() {
  return velocity;
  }

Vector Body::Velocity(Vector v) {
  velocity = v;
  return velocity;
  }


void Body::Load(FILE* file) {
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) {
      return;
      }
    else if (startsWith(pline,"position ")) position = atov(nw(pline));
    else if (startsWith(pline,"velocity ")) velocity = atov(nw(pline));
    else {
      Write("Unknown line found in save file: ");
      WriteLn(pline);
      exit(1);
      }
    }
  CalculateOrbit();
  }


void Body::Save(FILE* file) {
  fprintf(file,"%s {%s",name,LE);
  fprintf(file,"  Position %.18f %.18f %.18f%s",position.X(),position.Y(),position.Z(),LE);
  fprintf(file,"  Velocity %.18f %.18f %.18f%s",velocity.X(),velocity.Y(),velocity.Z(),LE);
  fprintf(file,"  }%s",LE);
  }

