#include <string.h>
#include "sequencer.h"
#include "header.h"
#include "terminal.h"

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
  Int32 i;
  Int32 cellX, cellY;
  Boolean dup;
  char  cell;
  switch (function) {
    case SEQ_END_EVA:
         pilotLocation = PILOT_LM;
         ins->Spacecraft(lm);
         ins->Target(csm);
         currentVehicle = lm;
         currentVehicle->SetupPanel();
         if (clockEv > longestEVA) longestEVA = clockEv;
         evas[evaCount-1].end = clockMi;
         evas[evaCount-1].walked = plss->Walked() - evas[evaCount-1].walked;
         evas[evaCount-1].driven = lrv->Driven() - evas[evaCount-1].driven;
         break;
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
         endReason = END_MISSION;
         run = false;
         break;
    case SEQ_MOVE_EVA:
         pilotLocation = PILOT_EVA;
         ins->Spacecraft(plss);
         ins->Target(lm);
         currentVehicle = plss;
         currentVehicle->SetupPanel();
         plss->BeginEva(lm);
         clockEv = 0;
         evaCount++;
         evas[evaCount-1].start = clockMi;
         evas[evaCount-1].end = 0;
         evas[evaCount-1].samples = 0;
         evas[evaCount-1].farthest = 0;
         evas[evaCount-1].walked = plss->Walked();
         evas[evaCount-1].driven = lrv->Driven();
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
         plss->Oxygen(PLSS_OXYGEN);
         plss->Battery(PLSS_BATTERY);
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
    case SEQ_TAKESAMPLE:
         plss->Carrying('R');
         cellX = map->Cell(plss->Longitude());
         cellY = map->Cell(plss->Latitude());
         cell = map->Lurrain(cellX, cellY);
         switch (cell) {
           case '.': plss->Value(1.0); sampleType = S_SMALL_CRATER; break;
           case 'o': plss->Value(1.2); sampleType = S_MEDIUM_CRATER; break;
           case 'O': plss->Value(1.4); sampleType = S_LARGE_CRATER; break;
           case ',': plss->Value(1.2); sampleType = S_SMALL_ROCK; break;
           case '+': plss->Value(1.4); sampleType = S_MEDIUM_ROCK; break;
           case '*': plss->Value(1.6); sampleType = S_LARGE_ROCK; break;
           case '^': plss->Value(2.0); sampleType = S_RISE; break;
           case ' ': plss->Value(0.5); sampleType = S_PLAINS; break;
           default : plss->Value(0.5); sampleType = 0; break;
           }
         if (cell >= '0' && cell <= '9') plss->Value(25.0);
         if (cell >= 'A' && cell <= 'B') plss->Value(25.0);
         dup = false;
         for (i=0; i<numSamples; i++)
           if (samples[i].cellX == cellX && samples[i].cellY == cellY) {
             plss->Value(0.1);
             dup = true;
             }
         if (!dup) {
           samples[numSamples].cellX = cellX;
           samples[numSamples].cellY = cellY;
           if (numSamples < 240) numSamples++;
           }
         break;
    case SEQ_DROPSAMPLE:
         plss->Carrying(' ');
         break;
    case SEQ_SETUPLRV:
         lrv->Setup();
         break;
    case SEQ_STORESAMPLE:
         plss->Carrying(' ');
         lrv->Rock(lrv->Rock() + 1);
         lrv->Value(lrv->Value() + plss->Value());
         switch (sampleType) {
           case S_SMALL_ROCK: lrvSampleSmallRock++; break;
           case S_MEDIUM_ROCK: lrvSampleMediumRock++; break;
           case S_LARGE_ROCK: lrvSampleLargeRock++; break;
           case S_SMALL_CRATER: lrvSampleSmallCrater++; break;
           case S_MEDIUM_CRATER: lrvSampleMediumCrater++; break;
           case S_LARGE_CRATER: lrvSampleLargeCrater++; break;
           case S_RISE: lrvSampleRise++; break;
           case S_PLAINS: lrvSamplePlains++; break;
           }
         evas[evaCount-1].samples++;
         break;
    case SEQ_BOXPLSS:
         plss->Carrying('B');
         break;
    case SEQ_BOXLM:
         plss->Carrying(' ');
         lm->Rock(lm->Rock() + lrv->Rock());
         lrv->Rock(0);
         lrv->Boxes(lrv->Boxes() - 1);
         lm->Value(lm->Value() + lrv->Value());
         lrv->Value(0);
         sampleSmallRock += lrvSampleSmallRock;
         sampleMediumRock += lrvSampleMediumRock;
         sampleLargeRock += lrvSampleLargeRock;
         sampleSmallCrater += lrvSampleSmallCrater;
         sampleMediumCrater += lrvSampleMediumCrater;
         sampleLargeCrater += lrvSampleLargeCrater;
         sampleRise += lrvSampleRise;
         samplePlains += lrvSamplePlains;
         lrvSampleSmallRock = 0;
         lrvSampleMediumRock = 0;
         lrvSampleLargeRock = 0;
         lrvSampleSmallCrater = 0;
         lrvSampleMediumCrater = 0;
         lrvSampleLargeCrater = 0;
         lrvSampleRise = 0;
         lrvSamplePlains = 0;
         break;
    case SEQ_BOXLRV:
         plss->Carrying(' ');
         break;
    case SEQ_MOVELRV:
         pilotLocation = PILOT_LRV;
         ins->Spacecraft(lrv);
         ins->Target(lm);
         currentVehicle = lrv;
         currentVehicle->SetupPanel();
         break;
    case SEQ_EXITLRV:
         pilotLocation = PILOT_EVA;
         ins->Spacecraft(plss);
         ins->Target(lm);
         currentVehicle = plss;
         currentVehicle->SetupPanel();
         plss->BeginEva(lrv);
         break;
    case SEQ_GETFLAG:
         plss->Carrying('F');
         break;
    case SEQ_PUTFLAG:
         plss->Carrying(' ');
         break;
    case SEQ_PLANTFLAG:
         plss->Carrying(' ');
         flagPlanted = -1;
         flagLatitude = plss->Latitude();
         flagLongitude = plss->Longitude();
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

void Sequencer::BoxToLm() {
  time = 5 * 60;
  strcpy(message,"   BOX->LM");
  function = SEQ_BOXLM;
  }

void Sequencer::BoxToLrv() {
  time = 2 * 60;
  strcpy(message,"  BOX->LRV");
  function = SEQ_BOXLRV;
  }

void Sequencer::BoxToPlss() {
  time = 2 * 60;
  strcpy(message," BOX->PLSS");
  function = SEQ_BOXPLSS;
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

void Sequencer::DropSample() {
  time = 5;
  strcpy(message," ROCK->GND");
  function = SEQ_DROPSAMPLE;
  }

void Sequencer::EndEva() {
  time = 8 * 60;
  strcpy(message,"  MOVE->LM");
  function = SEQ_END_EVA;
  }

void Sequencer::MoveCsm() {
  time = 900;
  strcpy(message," MOVE->CSM");
  function = SEQ_MOVE_CSM;
  }

void Sequencer::MoveEva() {
  time = 5 * 60;
  strcpy(message," MOVE->EVA");
  function = SEQ_MOVE_EVA;
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

void Sequencer::SetupLrv() {
  time = 120 * 60;
  strcpy(message,"Setup->LRV");
  function = SEQ_SETUPLRV;
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

void Sequencer::StoreSample() {
  time = 2 * 60;
  strcpy(message," ROCK->LRV");
  function = SEQ_STORESAMPLE;
  }

void Sequencer::TakeSample() {
  time = 1.25 * 60;
  strcpy(message,"ROCK->PLSS");
  function = SEQ_TAKESAMPLE;
  }
 
void Sequencer::Undock() {
  time = 60;
  strcpy(message,"    UNDOCK");
  function = SEQ_UNDOCK;
  }
 
void Sequencer::MoveLrv() {
  time = 3 * 60;
  strcpy(message," MOVE->LRV");
  function = SEQ_MOVELRV;
  }
  
void Sequencer::ExitLrv() {
  time = 1.5 * 60;
  strcpy(message," MOVE->EVA");
  function = SEQ_EXITLRV;
  }

void Sequencer::GetFlag() {
  time = 120;
  strcpy(message,"FLAG->PLSS");
  function = SEQ_GETFLAG;
  }

void Sequencer::PutFlag() {
  time = 120;
  strcpy(message,"  FLAG->LM");
  function = SEQ_PUTFLAG;
  }

void Sequencer::PlantFlag() {
  time = 10 * 60;
  strcpy(message," FLAG->GND");
  function = SEQ_PLANTFLAG;
  }

