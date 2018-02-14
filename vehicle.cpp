#include <math.h>
#include "header.h"
#include "vehicle.h"

Vehicle::Vehicle() {
  }

Vehicle::~Vehicle() {
  }

Double Vehicle::Altitude() {
  return altitude;
  }

Double Vehicle::Altitude(Double d) {
  altitude = d;
  radius = altitude + 1738300;
  return altitude;
  }

Vector Vehicle::FaceFront() {
  return faceFront;
  }

Vector Vehicle::FaceFront(Vector v) {
  faceFront = v;
  return faceFront;
  }

Vector Vehicle::FaceLeft() {
  return faceLeft;
  }

Vector Vehicle::FaceLeft(Vector v) {
  faceLeft = v;
  return faceLeft;
  }

Vector Vehicle::FaceUp() {
  return faceUp;
  }

Vector Vehicle::FaceUp(Vector v) {
  faceUp = v;
  return faceUp;
  }

Double Vehicle::Latitude() {
  return latitude;
  }

Double Vehicle::Latitude(Double d) {
  latitude = d;
  return latitude;
  }

Double Vehicle::Longitude() {
  return longitude;
  }

Double Vehicle::Longitude(Double d) {
  longitude = d;
  return longitude;
  }

Vector Vehicle::Position() {
  return position;
  }

Vector Vehicle::Position(Vector v) {
  position = v;
  Radius(position.Length());
  return position;
  }

Double Vehicle::Radius() {
  return radius;
  }

Double Vehicle::Radius(Double d) {
  radius = d;
  altitude = radius - 1738300;
  return radius;
  }

Vector Vehicle::Thrust() {
  return thrust;
  }

Vector Vehicle::Thrust(Vector t) {
  thrust = t;
  return thrust;
  }

Vector Vehicle::Velocity() {
  return velocity;
  }

Vector Vehicle::Velocity(Vector v) {
  velocity = v;
  return velocity;
  }

void Vehicle::Cycle() {
  Vector a;
  Double alt3;
  Double hyp;
  alt3 = radius * radius * radius;
  a = position.Scale(-4.9075e12);
  a = a.Scale(1/alt3);
  velocity = velocity + a;
  position = position + velocity;
  Radius(position.Length());
  hyp = sqrt(position.X() * position.X() + position.Y() * position.Y());
  longitude = position.X() / hyp;
  longitude = asin(longitude) * 180 / M_PI;
  if (position.X() < 0 && position.Y() >= 0) longitude = -180 - longitude;
  if (position.X() >= 0 && position.Y() >= 0) longitude = 180 - longitude;
  hyp = sqrt(position.Z() * position.Z() + hyp * hyp);
  latitude = position.Z() / hyp;
  latitude = asin(latitude) * 180 / M_PI;
  }

Double Vehicle::VelocityEast() {
  Double vel;
  vel = sqrt(velocity.X() * velocity.X() + velocity.Y() * velocity.Y());
  if (sgn(velocity.X()) == sgn(position.Y())) vel = -vel;
  return vel;
  }

Double Vehicle::VelocityNorth() {
  return velocity.Z();
  }

void Vehicle::Save(FILE* file) {
  fprintf(file,"  Altitude %f%s",altitude,LE);
  fprintf(file,"  Latitude %f%s",latitude,LE);
  fprintf(file,"  Longitude %f%s",longitude,LE);
  fprintf(file,"  Radius %f%s",radius,LE);
  fprintf(file,"  FaceFront %f %f %f%s",faceFront.X(),faceFront.Y(),faceFront.Z(),LE);
  fprintf(file,"  FaceUp %f %f %f%s",faceUp.X(),faceUp.Y(),faceUp.Z(),LE);
  fprintf(file,"  FaceLeft %f %f %f%s",faceLeft.X(),faceLeft.Y(),faceLeft.Z(),LE);
  fprintf(file,"  Position %f %f %f%s",position.X(),position.Y(),position.Z(),LE);
  fprintf(file,"  Velocity %f %f %f%s",velocity.X(),velocity.Y(),velocity.Z(),LE);
  fprintf(file,"  Thrust %f %f %f%s",thrust.X(),thrust.Y(),thrust.Z(),LE);
  }

