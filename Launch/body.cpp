#include <string.h>
#include "types.h"
#include "body.h"

Body::Body(const char* n, Double m, Double r) {
  strcpy(name,n);
  mass = m;
  radius = r;
  gravitation = mass * 6.67408e-11;
  position = Vector(0,0,0);
  velocity = Vector(0,0,0);
  }

Body::~Body() {
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

