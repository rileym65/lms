#include <stdio.h>
#include "header.h"
#include "common.h"
#include "csm.h"

CSM::CSM() {
  panel = new Panel("csm.pnl",this);
  }

CSM::~CSM() {
  }

void CSM::Save(FILE* file) {
  fprintf(file,"CSM {%s",LE);
  Spacecraft::Save(file);
  fprintf(file,"  }%s",LE);
  }

void CSM::ProcessKey(Int32 key) {
  if (key == 'M') seq->MoveLm();
  panel->ProcessKey(key);
  }

