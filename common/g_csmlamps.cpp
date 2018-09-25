#include "types.h"
#include "gauge.h"
#include "g_csmlamps.h"
#include "terminal.h"
#include "vehicle.h"
#include "command.h"
#include "common.h"

G_CsmLamps::G_CsmLamps(Int8 x,Int8 y,Boolean f,Vehicle* v) :
  Gauge(x, y, f, v) {
  Reset();
  width = 19;
  height = 2;
  }

G_CsmLamps::~G_CsmLamps() {
  }

void G_CsmLamps::Reset() {
  }

void G_CsmLamps::Display() {
  GotoXY(x,y+0); Write("BSP PAR     DCK RCS");
  GotoXY(x,y+1); Write("SMJ SPS     BST ATT");
  GotoXY(x,y+2); Write("RMJ RTR         ARM");
  }

void G_CsmLamps::Update() {
  CommandModule* cm;
  if ((vehicle->Type() & VT_COMMAND) == 0) return;
  cm = (CommandModule*)vehicle;
  GotoXY(x+0,y+0);
  if (((CommandModule*)vehicle)->LaunchVehicleJettisoned())
    printf("BSP"); else printf("   ");
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
  GotoXY(x+16, y+2);
  if (cm->Armed()) Write("ARM"); else Write("   ");
  GotoXY(x+12, y+0);
  if (docked) Write("DCK"); else Write("   ");
  GotoXY(x+12, y+1);
  if (docked && (lmExtracted == 0)) Write("BST"); else Write("   ");
  GotoXY(x+16, y+0);
  if (cm->RcsUdMode() != ' ' ||
      cm->RcsLrMode() != ' ' ||
      cm->RcsFbMode() != ' ') Write("RCS");
    else Write("   ");
  GotoXY(x+16, y+1);
  if (fabs(cm->PitchRate()) >= 0.01 ||
      fabs(cm->RollRate()) >= 0.01 ||
      fabs(cm->YawRate()) >= 0.01) Write("ATT");
    else Write("   ");
  }

