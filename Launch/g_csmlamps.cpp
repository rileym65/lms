#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_csmlamps.h"
#include "terminal.h"

G_CsmLamps::G_CsmLamps(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 11;
  height = 1;
  }

G_CsmLamps::~G_CsmLamps() {
  }

void G_CsmLamps::Reset() {
  }

void G_CsmLamps::Display() {
  GotoXY(x,y); Write("CSP PAR OMS");
  }

void G_CsmLamps::Update() {
  GotoXY(x+0,y+0);
  if (((CommandModule*)vehicle)->LaunchVehicleJettisoned())
    printf("CSP"); else printf("   ");
  GotoXY(x+4,y+0);
  if (((CommandModule*)vehicle)->ParachuteDeployment() > 0)
    printf("PAR"); else printf("   ");
  GotoXY(x+8,y+0);
  if (((CommandModule*)vehicle)->Throttle() > 0)
    printf("OMS"); else printf("   ");
  }

