#include <string.h>
#include "sequencer.h"
#include "terminal.h"
#include "common.h"

Sequencer::Sequencer() {
  time = 0; 
  function = 0;
  value = -1;
  strcpy(message,"----------");
  }

Sequencer::~Sequencer() {
  }

Int32 Sequencer::Time() {
  return time;
  }

Int32 Sequencer::Value() {
  return value;
  }

char* Sequencer::Message() {
  return message;
  }

void Sequencer::Message(const char* msg, Int32 v, Int32 t) {
  strcpy(message, msg);
  value = v;
  time = t;
  function = SEQ_MESSAGE;
  }
void Sequencer::Complete() {
  Int32 i;
  Int32 cellX, cellY;
  Boolean dup;
  char  cell;
  switch (function) {
    case SEQ_END_EVA:
         pilotLocation = PILOT_LM;
         currentVehicle = lm;
         currentVehicle->SetupPanel();
         if (clockEv > longestEVA) longestEVA = clockEv;
         evas[evaCount-1].end = clockMi;
         evas[evaCount-1].walked = plss->Walked() - evas[evaCount-1].walked;
         evas[evaCount-1].driven = lrv->Driven() - evas[evaCount-1].driven;
         break;
    case SEQ_MOVE_LM:
         pilotLocation = PILOT_LM;
         currentVehicle = lm;
         currentVehicle->SetupPanel();
         break;
    case SEQ_MOVE_CSM:
         pilotLocation = PILOT_CSM;
         currentVehicle = csm;
         currentVehicle->SetupPanel();
         break;
    case SEQ_MOVE_EVA:
         pilotLocation = PILOT_EVA;
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
    case SEQ_CMUNDOCK:
         csm->Undock();
         docked = 0;
         break;
    case SEQ_UNDOCK:
         lm->Position(csm->Position()+csm->FaceUp().Scale(5.375));
         lm->Velocity(csm->Velocity() + csm->FaceUp().Scale(0.1));
         lm->FaceUp(csm->FaceUp().Neg());
         lm->FaceLeft(csm->FaceLeft().Neg());
         lm->FaceFront(csm->FaceFront());
         lm->Latitude(csm->Latitude());
         lm->Longitude(csm->Longitude());
         lm->Orbiting(csm->Orbiting());
         lm->Altitude(csm->Altitude());
         lm->Radius(csm->Radius());
         docked = 0;
         clockUd = clockGe;
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
         plss->EOxygen(PLSS_EOXYGEN);
         plss->EBattery(PLSS_EBATTERY);
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
         cell = map->Lurrain(plss->Longitude(), plss->Latitude());
         switch (cell) {
           case '.': plss->Value(1.0); sampleType = S_SMALL_CRATER; break;
           case 'o': plss->Value(1.2); sampleType = S_MEDIUM_CRATER; break;
           case 'O': plss->Value(1.4); sampleType = S_LARGE_CRATER; break;
           case ',': plss->Value(1.2); sampleType = S_SMALL_ROCK; break;
           case '+': plss->Value(1.4); sampleType = S_MEDIUM_ROCK; break;
           case '*': plss->Value(1.6); sampleType = S_LARGE_ROCK; break;
           case '^': plss->Value(2.0); sampleType = S_RISE; break;
           case '(': plss->Value(2.1); sampleType = S_CRATERWALL; break;
           case ')': plss->Value(2.1); sampleType = S_CRATERWALL; break;
           case 'u': plss->Value(2.0); sampleType = S_DEPRESSION; break;
           case ' ': plss->Value(0.5); sampleType = S_PLAINS; break;
           case '=': plss->Value(25.0); sampleType = S_SPECIAL; break;
           case '%': plss->Value(25.0); sampleType = S_SPECIAL; break;
           case 'f': plss->Value(25.0); sampleType = S_SPECIAL; break;
           case '&': plss->Value(25.0); sampleType = S_SPECIAL; break;
           case '/': plss->Value(25.0); sampleType = S_SPECIAL; break;
           case '"': plss->Value(25.0); sampleType = S_SPECIAL; break;
           case '_': plss->Value(25.0); sampleType = S_SPECIAL; break;
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
           case S_CRATERWALL: lrvSampleCraterWall++; break;
           }
         evas[evaCount-1].samples++;
         break;
    case SEQ_TOCART:
         if (plss->AddToCart(plss->Value())) {
           switch (sampleType) {
             case S_SMALL_ROCK: cartSampleSmallRock++; break;
             case S_MEDIUM_ROCK: cartSampleMediumRock++; break;
             case S_LARGE_ROCK: cartSampleLargeRock++; break;
             case S_SMALL_CRATER: cartSampleSmallCrater++; break;
             case S_MEDIUM_CRATER: cartSampleMediumCrater++; break;
             case S_LARGE_CRATER: cartSampleLargeCrater++; break;
             case S_RISE: cartSampleRise++; break;
             case S_PLAINS: cartSamplePlains++; break;
             case S_SPECIAL: cartSampleSpecial++; break;
             case S_DEPRESSION: cartSampleDepression++; break;
             case S_CRATERWALL: cartSampleCraterWall++; break;
             }
           plss->Carrying(' ');
           plss->Value(0);
           evas[evaCount-1].samples++;
           }
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
         sampleCraterWall += lrvSampleCraterWall;
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
         lrvSampleCraterWall = 0;
         break;
    case SEQ_CARTTOLM:
         lm->Rock(lm->Rock() + plss->Cart());
         plss->Cart(0);
         lm->Value(lm->Value() + plss->CartValue());
         plss->CartValue(0);
         sampleSmallRock += cartSampleSmallRock;
         sampleMediumRock += cartSampleMediumRock;
         sampleLargeRock += cartSampleLargeRock;
         sampleSmallCrater += cartSampleSmallCrater;
         sampleMediumCrater += cartSampleMediumCrater;
         sampleLargeCrater += cartSampleLargeCrater;
         sampleRise += cartSampleRise;
         samplePlains += cartSamplePlains;
         sampleSpecial += cartSampleSpecial;
         sampleDepression += cartSampleDepression;
         sampleCraterWall += cartSampleCraterWall;
         cartSampleSmallRock = 0;
         cartSampleMediumRock = 0;
         cartSampleLargeRock = 0;
         cartSampleSmallCrater = 0;
         cartSampleMediumCrater = 0;
         cartSampleLargeCrater = 0;
         cartSampleRise = 0;
         cartSamplePlains = 0;
         cartSampleSpecial = 0;
         cartSampleDepression = 0;
         cartSampleCraterWall = 0;
         break;
    case SEQ_CARTTOLRV:
         while (lrv->Rock() < 30 && plss->Cart() > 0) {
           lrv->Rock(lrv->Rock() + 1);
           plss->Cart(plss->Cart() - 1);
           if (cartSampleSmallRock > 0) {
             lrvSampleSmallRock++;
             cartSampleSmallRock--;
             lrv->Value(lrv->Value() + 1.2);
             plss->CartValue(plss->CartValue() - 1.2);
             }
           if (cartSampleMediumRock > 0) {
             lrvSampleMediumRock++;
             cartSampleMediumRock--;
             lrv->Value(lrv->Value() + 1.4);
             plss->CartValue(plss->CartValue() - 1.4);
             }
           if (cartSampleLargeRock > 0) {
             lrvSampleLargeRock++;
             cartSampleLargeRock--;
             lrv->Value(lrv->Value() + 1.6);
             plss->CartValue(plss->CartValue() - 1.6);
             }
           if (cartSampleSmallCrater > 0) {
             lrvSampleSmallCrater++;
             cartSampleSmallCrater--;
             lrv->Value(lrv->Value() + 1.0);
             plss->CartValue(plss->CartValue() - 1.0);
             }
           if (cartSampleMediumCrater > 0) {
             lrvSampleMediumCrater++;
             cartSampleMediumCrater--;
             lrv->Value(lrv->Value() + 1.2);
             plss->CartValue(plss->CartValue() - 1.2);
             }
           if (cartSampleLargeCrater > 0) {
             lrvSampleLargeCrater++;
             cartSampleLargeCrater--;
             lrv->Value(lrv->Value() + 1.4);
             plss->CartValue(plss->CartValue() - 1.4);
             }
           if (cartSampleRise > 0) {
             lrvSampleRise++;
             cartSampleRise--;
             lrv->Value(lrv->Value() + 2.0);
             plss->CartValue(plss->CartValue() - 2.0);
             }
           if (cartSampleDepression > 0) {
             lrvSampleDepression++;
             cartSampleDepression--;
             lrv->Value(lrv->Value() + 2.0);
             plss->CartValue(plss->CartValue() - 2.0);
             }
           if (cartSamplePlains > 0) {
             lrvSamplePlains++;
             cartSamplePlains--;
             lrv->Value(lrv->Value() + 0.5);
             plss->CartValue(plss->CartValue() - 0.5);
             }
           if (cartSampleSpecial > 0) {
             lrvSampleSpecial++;
             cartSampleSpecial--;
             lrv->Value(lrv->Value() + 25.0);
             plss->CartValue(plss->CartValue() - 25.0);
             }
           if (cartSampleCraterWall > 0) {
             lrvSampleCraterWall++;
             cartSampleCraterWall--;
             lrv->Value(lrv->Value() + 2.1);
             plss->CartValue(plss->CartValue() - 2.1);
             }
           }
         if (plss->Cart() <= 0) plss->CartValue(0);
         break;
    case SEQ_BOXLRV:
         plss->Carrying(' ');
         break;
    case SEQ_MOVELRV:
         pilotLocation = PILOT_LRV;
         currentVehicle = lrv;
         currentVehicle->SetupPanel();
         break;
    case SEQ_EXITLRV:
         pilotLocation = PILOT_EVA;
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
    case SEQ_GETALSEP:
         plss->Carrying('A');
         break;
    case SEQ_PUTALSEP:
         plss->Carrying(' ');
         alsepSetup = -1;
         alsepLatitude = plss->Latitude();
         alsepLongitude = plss->Longitude();
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
    case SEQ_ABORT:
         mode_kil = 0;
         mode_abo = 0;
         mode_jet = 0;
         break;
    case SEQ_LIFTOFF:
         mode_kil = 0;
         mode_lif = 0;
         mode_jet = 0;
         break;
    case SEQ_MESSAGE:
         value = -1;
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
         metabolicRate += 0.106;
         break;
    case SEQ_PLSSON:
         metabolicRate += 0.108;
         break;
    case SEQ_PLSSOFF:
         metabolicRate += 0.106;
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
    case SEQ_CARTTOLRV:
         metabolicRate += 0.108;
         break;
    case SEQ_CARTTOLM:
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
    case SEQ_GETALSEP:
         metabolicRate += 0.108;
         break;
    case SEQ_PUTALSEP:
         metabolicRate += 0.104;
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
 
void Sequencer::CmUndock() {
  time = 60;
  strcpy(message,"    UNDOCK");
  function = SEQ_CMUNDOCK;
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
  Double dist;
  time = 8 * 60;
  strcpy(message,"  MOVE->LM");
  function = SEQ_END_EVA;
  dist = (plss->Position() - lm->Position()).Length();
  plss->Walked(plss->Walked() + dist);
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
  plss->Walked(plss->Walked() + dist + dist);
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
  plss->Walked(plss->Walked() + dist);
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

void Sequencer::GetAlsep() {
  time = 30 * 60;
  strcpy(message,"LSEP->PLSS");
  function = SEQ_GETALSEP;
  }

void Sequencer::PutAlsep() {
  if (mission->Lsep() == 2) time = 120 * 60;
    else time = 90 * 60;
  strcpy(message,"ALSEP->GND");
  function = SEQ_PUTALSEP;
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

void Sequencer::Abort() {
  time = -5;
  strcpy(message,"  ABORT   ");
  lm->Abort();
  function = SEQ_ABORT;
  mode_kil = 0xff;
  mode_abo = 0xff;
  mode_jet = 0xff;
  }

void Sequencer::Liftoff() {
  time = -5;
  strcpy(message," LIFTOFF  ");
  lm->Abort();
  function = SEQ_LIFTOFF;
  mode_kil = 0xff;
  mode_lif = 0xff;
  mode_jet = 0xff;
  }

void Sequencer::SampleToCart() {
  time = 10;
  strcpy(message,"SAMP->CART");
  function = SEQ_TOCART;
  }

void Sequencer::CartToLrv() {
  Double dist;
  dist = (plss->Position() - lrv->Position()).Length();
  plss->Walked(plss->Walked() + dist + dist);
  time = (1 * 60) + (2 * dist) + (20 * plss->Cart());
  strcpy(message," CART->LRV");
  function = SEQ_CARTTOLRV;
  }

void Sequencer::CartToLm() {
  Double dist;
  dist = (plss->Position() - lm->Position()).Length();
  plss->Walked(plss->Walked() + dist + dist);
  time = (1 * 60) + (2 * dist) + (20 * plss->Cart());
  strcpy(message,"  CART->LM");
  function = SEQ_CARTTOLM;
  }
