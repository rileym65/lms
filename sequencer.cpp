#include <string.h>
#include "sequencer.h"
#include "header.h"

Sequencer::Sequencer() {
  time = 0; 
  function = 0;
  strcpy(message,"----------");
  }

Sequencer::~Sequencer() {
  }

Int32 Sequencer::Time() {
  return time;
  }

char* Sequencer::Message() {
  return message;
  }

void Sequencer::Complete() {
  switch (function) {
    case SEQ_MOVE_LM:
         pilotLocation = PILOT_LM;
         ins->Spacecraft(lm);
         ins->Target(csm);
         currentVehicle = lm;
         currentVehicle->SetupPanel();
         break;
    case SEQ_MOVE_CSM:
         pilotLocation = PILOT_CSM;
         ins->Spacecraft(csm);
         ins->Target(lm);
         currentVehicle = csm;
         currentVehicle->SetupPanel();
         run = false;
         break;
    case SEQ_UNDOCK:
         lm->Position(csm->Position() + Vector(0,0,19));
         lm->Velocity(csm->Velocity() + Vector(0,0,0.1));
         lm->Altitude(csm->Altitude());
         lm->Latitude(csm->Latitude());
         lm->Longitude(csm->Longitude());
         lm->Radius(csm->Radius());
         docked = 0;
         break;
    case SEQ_SUITON:
         spaceSuitOn = -1;
         break;
    case SEQ_SUITOFF:
         spaceSuitOn = 0;
         break;
    case SEQ_PLSSON:
         plssOn = -1;
         plssOxygen = PLSS_OXYGEN;
         plssBattery = PLSS_BATTERY;
         plssPacks--;
         break;
    case SEQ_PLSSOFF:
         plssOn = 0;
         break;
    case SEQ_CABINEVAC:
         cabinPressurized = 0;
         break;
    case SEQ_CABINPRESS:
         cabinPressurized = -1;
         break;
    }
  }

void Sequencer::Cycle() {
  if (time > 0) {
    time--;
    if (time == 0) {
      strcpy(message,"----------");
      simSpeed = 100000;
      Complete();
      currentVehicle->UpdatePanel();
      }
    }
  }

void Sequencer::CabinEvacuate() {
  time = 5 * 60;
  strcpy(message," CAB->EVAC");
  function = SEQ_CABINEVAC;
  }

void Sequencer::CabinPressurize() {
  time = 2 * 60;
  strcpy(message," CAB->PRES");
  function = SEQ_CABINPRESS;
  }

void Sequencer::Dock() {
  time = 60;
  strcpy(message,"   DOCKING");
  function = SEQ_DOCKING;
  }

void Sequencer::MoveCsm() {
  time = 900;
  strcpy(message," MOVE->CSM");
  function = SEQ_MOVE_CSM;
  }

void Sequencer::MoveLm() {
  time = 2400;
  strcpy(message,"  MOVE->LM");
  function = SEQ_MOVE_LM;
  }

void Sequencer::PlssOff() {
  time = 45 * 60;
  strcpy(message," PLSS->OFF");
  function = SEQ_PLSSOFF;
  }

void Sequencer::PlssOn() {
  time = 35 * 60;
  strcpy(message,"  PLSS->ON");
  function = SEQ_PLSSON;
  }

void Sequencer::Rest() {
  time = 120 * 60;
  strcpy(message,"      Rest");
  function = SEQ_REST;
  }

void Sequencer::Sleep() {
  time = 8 * 60 * 60;
  strcpy(message,"     Sleep");
  function = SEQ_SLEEP;
  }

void Sequencer::SpaceSuitOff() {
  time = 35 * 60;
  strcpy(message," SUIT->OFF");
  function = SEQ_SUITOFF;
  }

void Sequencer::SpaceSuitOn() {
  time = 20 * 60;
  strcpy(message,"  SUIT->ON");
  function = SEQ_SUITON;
  }
 
 
void Sequencer::Undock() {
  time = 60;
  strcpy(message,"    UNDOCK");
  function = SEQ_UNDOCK;
  }
  
