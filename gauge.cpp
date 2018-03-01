#include "types.h"
#include "gauge.h"

Gauge::Gauge(Int8 x,Int8 y,Boolean f,Vehicle* v) {
  this->vehicle = v;
  this->x = x;
  this->y = y;
  width = 0;
  height = 0;
  framed = f;
  }

Gauge::~Gauge() {
  }

void Gauge::Reset() {
  }

void Gauge::Display() {
  }

void Gauge::Update() {
  }

