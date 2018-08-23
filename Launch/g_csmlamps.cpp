#include "header.h"
#include "types.h"
#include "gauge.h"
#include "g_csmlamps.h"
#include "terminal.h"

G_CsmLamps::G_CsmLamps(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 15;
  height = 2;
  }

G_CsmLamps::~G_CsmLamps() {
  }

void G_CsmLamps::Reset() {
  }

void G_CsmLamps::Display() {
  GotoXY(x,y+0); Write("CSP PAR        ");
  GotoXY(x,y+1); Write("SMJ SPS        ");
  GotoXY(x,y+2); Write("RMJ RTR     ARM");
  }

void G_CsmLamps::Update() {
  CommandModule* cm;
  if ((vehicle->Type() & VT_COMMAND) == 0) return;
  cm = (CommandModule*)vehicle;
  GotoXY(x+0,y+0);
  if (((CommandModule*)vehicle)->LaunchVehicleJettisoned())
    printf("CSP"); else printf("   ");
  GotoXY(x+4,y+0);
  if (((CommandModule*)vehicle)->ParachuteDeployment() > 0)
    printf("PAR"); else printf("   ");
  if (cm->Throttle() > 0 && cm->LaunchVehicleJettisoned()) {
    if (cm->ServiceModuleDryWeight() > 0) {
      GotoXY(x+4, y+1);
      printf("SPS");
      }
    else if (cm->RetroModuleDryWeight() > 0) {
      GotoXY(x+4, y+2);
      printf("RTR");
      }
    }
  else {
    GotoXY(x+4, y+1); printf("   ");
    GotoXY(x+4, y+2); printf("   ");
    }
  GotoXY(x+0,y+1);
  if (cm->ServiceModuleIsp() > 0 && cm->ServiceModuleDryWeight() == 0)
    printf("SMJ"); else printf("   ");
  GotoXY(x+0,y+2);
  if (cm->RetroModuleIsp() > 0 && cm->RetroModuleDryWeight() == 0)
    printf("RMJ"); else printf("   ");
  GotoXY(x+12, y+2);
  if (cm->Armed()) Write("ARM"); else Write("   ");
  }

