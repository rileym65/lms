#include "types.h"
#include "gauge.h"
#include "g_vehicle.h"
#include "terminal.h"
#include "vehicle.h"
#include "common.h"

G_Vehicle::G_Vehicle(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 9;
  height = 1;
  displayed = false;
  }

G_Vehicle::~G_Vehicle() {
  }

void G_Vehicle::Reset() {
  displayed = false;
  }

void G_Vehicle::Display() {
  GotoXY(x,y); Write("---------");
  }

void G_Vehicle::Update() {
  if (displayed) return;
  GotoXY(x,y);
  switch (mission->Vehicle()) {
    case VEHICLE_MERCURY_REDSTONE:
         Write(" Mercury ");
         break;
    case VEHICLE_MERCURY_ATLAS:
         Write(" Mercury ");
         break;
    case VEHICLE_GEMINI_TITAN:
         Write(" Gemini  ");
         break;
    case VEHICLE_APOLLO_SATURN_IB:
         Write(" Apollo  ");
         break;
    case VEHICLE_APOLLO_SATURN_V:
         Write(" Apollo  ");
         break;
    case VEHICLE_APOLLO:
         Write(" Apollo  ");
         break;
    case VEHICLE_APOLLO_J:
         Write("Apollo J ");
         break;
    case VEHICLE_APOLLO_MKII:
         Write("Apollo II");
         break;
    }
  displayed = true;
  }

