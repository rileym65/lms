#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "terminal.h"
#include "types.h"
#include "body.h"
#include "common.h"
#include "helpers.h"

Body::Body(const char* n, Double m, Double r) {
  strcpy(name,n);
  mass = m;
  radius = r;
  gravitation = mass * 6.67408e-11;
  position = Vector(0,0,0);
  velocity = Vector(0,0,0);
  orbiting = NULL;
  meters = (radius * 2 * PI) / 360.0;
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
  ascendingNode = asin(ascendingNode) * 180 / PI;
  if (L.X() < 0 && L.Y() < 0) ascendingNode = -180 - ascendingNode;
  if (L.X() < 0 && L.Y() >= 0) ascendingNode = 180 - ascendingNode;
  hyp = sqrt(L.Z() * L.Z() + hyp * hyp);
  inclination = L.Z() / hyp;
  inclination = asin(inclination) * 180 / PI;
  }

void Body::Cycle(Double gran) {
  Double d;
  Double hyp;
  Double scale;
  if (orbiting == NULL) return;
  scale = 1 / gran;
  position = position + velocity.Scale(scale);
  if (lm != NULL) {
    if (lm ->Orbiting() == this && lm->Landed()) {
      lm->Position(lm->Position() + velocity.Scale(scale));
      }
    }
  if (lrv != NULL) {
    if (lrv ->Orbiting() == this) {
      lrv->Position(lrv->Position() + velocity.Scale(scale));
      }
    }
  if (plss != NULL) {
    if (plss ->Orbiting() == this) {
      plss->Position(plss->Position() + velocity.Scale(scale));
      }
    }
  d = position.Length();
  d = ((G * mass * orbiting->Mass()) / (d * d) ) / mass;
  d = d / gran;
  velocity = velocity - position.Norm().Scale(d);
  hyp = sqrt(position.X() * position.X() + position.Y() * position.Y());
  longitude = position.X() / hyp;
  longitude = asin(longitude) * 180 / PI;
  if (position.X() < 0 && position.Y() >= 0) longitude = -180 - longitude;
  if (position.X() >= 0 && position.Y() >= 0) longitude = 180 - longitude;
  hyp = sqrt(position.Z() * position.Z() + hyp * hyp);
  latitude = position.Z() / hyp;
  latitude = asin(latitude) * 180 / PI;
  }

char* Body::Name() {
  return name;
  }

Double Body::Gravitation() {
  return gravitation;
  }

Double Body::Latitude() {
  return latitude;
  }

Double Body::Longitude() {
  return longitude;
  }

Double Body::Mass() {
  return mass;
  }

Double Body::Meters() {
  return meters;
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

