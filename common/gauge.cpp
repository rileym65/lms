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

void Gauge::displayClock(Int32 cx, Int32 cy, Int32 clock) {
  char buffer[32];
  Int32 hours, minutes, seconds;
  hours = clock / 3600;
  clock -= (hours * 3600);
  minutes = clock / 60;
  seconds = clock - (minutes * 60);
  GotoXY(cx, cy);
  if (hours > 999) hours = 999;
  if (hours < 0) hours = -99;
  if (minutes < 0) minutes = 0;
  if (seconds < 0) seconds = 0;
  sprintf(buffer,"%3d:%02d:%02d",hours,minutes,seconds);
  Write(buffer);
  }

void Gauge::Reset() {
  }

void Gauge::Display() {
  }

void Gauge::Update() {
  }

void Gauge::ProcessKey(Int32 key) {
  }

void Gauge::Load(FILE* file,char* firstLine) {
  }

void Gauge::Save(FILE* file) {
  }
