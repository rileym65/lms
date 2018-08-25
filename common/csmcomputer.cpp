#include <math.h>
#include "csmcomputer.h"

int test;

CsmComputer::CsmComputer(CommandModule* c) {
  mode = 1;
  csm = c;
  altitude = 0;
  velocity = 0;
  test = 0;
  }

CsmComputer::~CsmComputer() {
  }

void CsmComputer::Cycle() {
  if (mode == 1) {
    if (velocity == 0) {
      if (csm->Periapsis() >= csm->Orbiting()->Radius()) {
        velocity = sqrt(csm->Orbiting()->Gravitation() / csm->Apoapsis());
        }
      }
    else {
      if (csm->Velocity().Length() >= velocity) {
        csm->Cutoff();
        mode = 0;
        }
      }
    }
  }

