#include <stdio.h>
#include "header.h"
#include "csm.h"

CSM::CSM() {
  }

CSM::~CSM() {
  }

void CSM::Save(FILE* file) {
  fprintf(file,"CSM {%s",LE);
  Vehicle::Save(file);
  fprintf(file,"  }%s",LE);
  }
