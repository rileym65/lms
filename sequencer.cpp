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
         clockUd = clockUt;
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
           case 'u': plss->Value(2.0); sampleType = S_DEPRESSION; break;
           case ' ': plss->Value(0.5); sampleType = S_PLAINS; break;
           case '=': plss->Value(25.0); sampleType = S_SPECIAL; break;
           case '%': plss->Value(25.0); sampleType = S_SPECIAL; break;
           case 'f': plss->Value(25.0); sampleType = S_SPECIAL; break;
           case '&': plss->Value(25.0); sampleType = S_SPECIAL; break;
           default : plss->Value(0.5); sampleType = 0; break;
           }
         if ((cell >= '0' && cell <= '9') ||
             (cell >= 'A' && cell < 'O') ||
             (cell > 'O' && cell < 'Z')) {
           plss->Value(25.0);
           sampleType = S_SPECIAL;
           }
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
           case S_SPECIAL: lrvSampleSpecial++; break;
           case S_DEPRESSION: lrvSampleDepression++; break;
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
         sampleSpecial += lrvSampleSpecial;
         sampleDepression += lrvSampleDepression;
         lrvSampleSmallRock = 0;
         lrvSampleMediumRock = 0;
         lrvSampleLargeRock = 0;
         lrvSampleSmallCrater = 0;
         lrvSampleMediumCrater = 0;
         lrvSampleLargeCrater = 0;
         lrvSampleRise = 0;
         lrvSamplePlains = 0;
         lrvSampleSpecial = 0;
         lrvSampleDepression = 0;
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
    case SEQ_GETLASER:
         plss->Carrying('L');
         break;
    case SEQ_PUTLASER:
         plss->Carrying(' ');
         break;
    case SEQ_SETUPLASER:
         plss->Carrying(' ');
         laserSetup = -1;
         laserLatitude = plss->Latitude();
         laserLongitude = plss->Longitude();
         break;
    case SEQ_KILL:
         mode_kil = 0;
         break;
    }
  }

void Sequencer::InProgress() {
  switch (function) {
    case SEQ_MOVE_LM:
         metabolicRate += 0.112;
         break;
    case SEQ_SLEEP:
         softInjury -= (0.000347222 * 4);
         if (softInjury < 0) softInjury = 0;
         break;
    case SEQ_REST:
         softInjury -= (0.000347222 * 1);
         if (softInjury < 0) softInjury = 0;
         break;
    case SEQ_SUITON:
         metabolicRate += 0.108;
         break;
    case SEQ_SUITOFF:
         metabolicRate += 0.108;
         break;
    case SEQ_PLSSON:
         metabolicRate += 0.108;
         break;
    case SEQ_PLSSOFF:
         metabolicRate += 0.108;
         break;
    case SEQ_MOVE_EVA:
         metabolicRate += 0.125;
         break;
    case SEQ_SETUPLRV:
         metabolicRate += 0.104;
         break;
    case SEQ_MOVELRV:
         metabolicRate += 0.108;
         break;
    case SEQ_EXITLRV:
         metabolicRate += 0.108;
         break;
    case SEQ_TAKESAMPLE:
         metabolicRate += 0.125;
         break;
    case SEQ_STORESAMPLE:
         metabolicRate += 0.108;
         break;
    case SEQ_BOXPLSS:
         metabolicRate += 0.112;
         break;
    case SEQ_BOXLRV:
         metabolicRate += 0.112;
         break;
    case SEQ_BOXLM:
         metabolicRate += 0.125;
         break;
    case SEQ_END_EVA:
         metabolicRate += 0.125;
         break;
    case SEQ_GETFLAG:
         metabolicRate += 0.108;
         break;
    case SEQ_PUTFLAG:
         metabolicRate += 0.108;
         break;
    case SEQ_PLANTFLAG:
         metabolicRate += 0.125;
         break;
    case SEQ_GETLASER:
         metabolicRate += 0.108;
         break;
    case SEQ_PUTLASER:
         metabolicRate += 0.108;
         break;
    case SEQ_SETUPLASER:
         metabolicRate += 0.125;
         break;
    }
  }

void Sequencer::Cycle() {
  if (time != 0) {
    if (time > 0) time--;
    else if (time < 0) time++;
    InProgress();
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
  strcpy(message," SAMP->GND");
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
  Double dist;
  dist = (plss->Position() - lrv->Position()).Length();
  time = (1 * 60) + (2 * dist);
  strcpy(message," SAMP->LRV");
  function = SEQ_STORESAMPLE;
  }

void Sequencer::TakeSample() {
  time = 1.25 * 60;
  strcpy(message,"SAMP->PLSS");
  function = SEQ_TAKESAMPLE;
  }
 
void Sequencer::Undock() {
  time = 60;
  strcpy(message,"    UNDOCK");
  function = SEQ_UNDOCK;
  }
 
void Sequencer::MoveLrv() {
  Double dist;
  dist = (plss->Position() - lrv->Position()).Length();
  time = 1.5 * 60 + dist;
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



void Sequencer::GetLaser() {
  time = 120;
  strcpy(message,"LSRF->PLSS");
  function = SEQ_GETLASER;
  }

void Sequencer::PutLaser() {
  time = 120;
  strcpy(message,"  LSRF->LM");
  function = SEQ_PUTLASER;
  }

void Sequencer::SetupLaser() {
  time = 10 * 60;
  strcpy(message," LSRF->GND");
  function = SEQ_SETUPLASER;
  }

void Sequencer::Kill() {
  time = -5;
  strcpy(message,"  SEQ:KILL");
  function = SEQ_KILL;
  mode_kil = 0xff;
  lm->RollRate(0);
  lm->PitchRate(0);
  lm->YawRate(0);
  }

