#include <stdio.h>
#include "header.h"
#include "booster.h"

Double AirDensity(Double altitude) {
  if (altitude < 5500) {
    return 1.0 - (0.5 * (altitude / 5500));
    }
  if (altitude < 16000) {
    return 0.5 - (0.4 * ((altitude - 5500) / 10500));
    }
  if (altitude < 32000) {
    return 0.1 - (0.09 * ((altitude - 16000) / 16000));
    }
  return 0;
  }

Booster::Booster() {
  panel = new Panel("booster.pnl",this);
  stage = 1;
  enginesLit = 0;
  }

Booster::~Booster() {
  }

void Booster::Cutoff() {
  enginesLit = 0;
  }

void Booster::Cycle() {
  Matrix m;
  Byte i;
  Double th;
  Double tth;
  Double f;
  Double alt;
  Double isp;
  Double air;
  Byte   st;
  if (rollRate != 0) {
    m = Matrix::Rotate(faceUp, rollRate);
    faceLeft = m.Transform(faceLeft).Norm();
    faceFront = m.Transform(faceFront).Norm();
    }
  if (yawRate != 0) {
    m = Matrix::Rotate(faceFront, yawRate);
    faceUp = m.Transform(faceUp).Norm();
    faceLeft = m.Transform(faceLeft).Norm();
    }
  if (pitchRate != 0) {
    m = Matrix::Rotate(faceLeft, pitchRate);
    faceUp = m.Transform(faceUp).Norm();
    faceFront = m.Transform(faceFront).Norm();
    }
  alt = position.Length() - GROUND;
  thrust = Vector(0,0,0);
  tth = 0;
  st = stage - 1;
  if (throttle != 0) {
    for (i=0; i<numEngines[st]; i++) {
      if (enginesLit & (1 << i)) {
        air = AirDensity(alt);
        isp = ispVac[st][i] - air * (ispVac[st][i]-ispSl[st][i]);
        th = thrustVac[st][i] - air * (thrustVac[st][i]-thrustSl[st][i]);
        f = th/(9.80665 * isp);
        th = th / Mass();
        if (f <= fuel[st]) {
          tth += th;
          fuel[st] -= f;
          }
        else enginesLit &= (~(1 << i));
        }
      }
    thrust = faceUp.Scale(tth);
GotoXY(1,30); printf("Thrust: %.2f\n",tth);
    }
  Vehicle::Cycle();
  }

Double Booster::DryWeight(Byte stage) {
  return dryWeight[stage-1];
  }

Double Booster::DryWeight(Byte stage, Double d) {
  dryWeight[stage-1] = d;
  return dryWeight[stage-1];
  }

Byte Booster::EnginesLit() {
  return enginesLit;
  }

Double Booster::Fuel() {
  return fuel[stage-1];
  }

Double Booster::Fuel(Byte stage) {
  return fuel[stage-1];
  }

Double Booster::Fuel(Byte stage, Double d) {
  fuel[stage-1] = d;
  return fuel[stage-1];
  }

void Booster::Ignition() {
  if (starts[stage-1] > 0) {
    clockBu = 0;
    if (numEngines[stage-1] == 1) enginesLit = 0x01;
    if (numEngines[stage-1] == 2) enginesLit = 0x03;
    if (numEngines[stage-1] == 3) enginesLit = 0x07;
    if (numEngines[stage-1] == 4) enginesLit = 0x0f;
    if (numEngines[stage-1] == 5) enginesLit = 0x1f;
    starts[stage-1]--;
    Throttle(100);
    }
  }

Double Booster::IspSl(Byte stage, Byte engine) {
  return ispSl[stage-1][engine-1];
  }

Double Booster::IspSl(Byte stage, Byte engine, Double d) {
  ispSl[stage-1][engine-1] = d;
  return ispSl[stage-1][engine-1];
  }

Double Booster::IspVac(Byte stage, Byte engine) {
  return ispVac[stage-1][engine-1];
  }

Double Booster::IspVac(Byte stage, Byte engine, Double d) {
  ispVac[stage-1][engine-1] = d;
  return ispVac[stage-1][engine-1];
  }

Double Booster::Mass() {
  Byte i;
  Double ret;
  ret = payload;
  for (i=stage-1; i<numStages; i++)
    ret += dryWeight[i] + fuel[i];
  return ret;
  }

Double Booster::MaxFuel() {
  return maxFuel[stage-1];
  }

Double Booster::MaxFuel(Byte stage) {
  return maxFuel[stage-1];
  }

Double Booster::MaxFuel(Byte stage, Double d) {
  maxFuel[stage-1] = d;
  return maxFuel[stage-1];
  }

void Booster::NextStage() {
  if (enginesLit != 0) return;
  if (stage < numStages) {
    clockBu = 0;
    stage++;
    enginesLit = 0;
    starts[stage-1]--;
    if (numEngines[stage-1] == 1) enginesLit = 0x01;
    if (numEngines[stage-1] == 2) enginesLit = 0x03;
    if (numEngines[stage-1] == 3) enginesLit = 0x07;
    if (numEngines[stage-1] == 4) enginesLit = 0x0f;
    if (numEngines[stage-1] == 5) enginesLit = 0x1f;
    Throttle(100);
    }
  }

Byte Booster::NumEngines() {
  return numEngines[stage - 1];
  }

Byte Booster::NumEngines(Byte stage) {
  return numEngines[stage-1];
  }

Byte Booster::NumEngines(Byte stage, Byte b) {
  numEngines[stage-1] = b;
  return numEngines[stage-1];
  }

Byte Booster::NumStages() {
  return numStages;
  }

Byte Booster::NumStages(Byte b) {
  numStages = b;
  return numStages;
  }

Double Booster::Payload() {
  return payload;
  }

Double Booster::Payload(Double d) {
  payload = d;
  return payload;
  }

Byte Booster::Stage() {
  return stage;
  }

Byte Booster::Stage(Byte b) {
  stage = b;
  return stage;
  }

Byte Booster::Starts() {
  return starts[stage-1];
  }

Byte Booster::Starts(Byte stage) {
  return starts[stage-1];
  }

Byte Booster::Starts(Byte stage, Byte b) {
  starts[stage-1] = b;
  return starts[stage-1];
  }

Double Booster::ThrustVac(Byte stage, Byte engine) {
  return thrustVac[stage-1][engine-1];
  }

Double Booster::ThrustVac(Byte stage, Byte engine, Double d) {
  thrustVac[stage-1][engine-1] = d;
  return thrustVac[stage-1][engine-1];
  }

Double Booster::ThrustSl(Byte stage, Byte engine) {
  return thrustSl[stage-1][engine-1];
  }

Double Booster::ThrustSl(Byte stage, Byte engine, Double d) {
  thrustSl[stage-1][engine-1] = d;
  return thrustSl[stage-1][engine-1];
  }

Byte Booster::Type() {
  return VT_ROCKET;
  }

void Booster::ProcessKey(Int32 key) {
  if (key == 'C') Cutoff();
  if (key == KEY_KP_HOME) rollRate++;
  if (key == KEY_PGUP) rollRate--;
  if (key == KEY_LEFT_ARROW) yawRate++;
  if (key == KEY_RIGHT_ARROW) yawRate--;
  if (key == KEY_UP_ARROW) pitchRate++;
  if (key == KEY_DOWN_ARROW) pitchRate--;
  }

void Booster::Save(FILE* file) {
  Byte i;
  Byte j;
  fprintf(file,"Booster {%s",LE);
  Vehicle::Save(file);
  fprintf(file,"  Payload %.18f%s",payload,LE);
  fprintf(file,"  Stage %d%s",stage,LE);
  fprintf(file,"  NumStages %d%s",numStages,LE);
  for (i=0; i<numStages; i++) {
    fprintf(file,"  Stage %d {%s",i+1,LE);
    fprintf(file,"    DryWeight %.18f%s",dryWeight[i],LE);
    fprintf(file,"    Fuel %.18f%s",fuel[i],LE);
    fprintf(file,"    MaxFuel %.18f%s",maxFuel[i],LE);
    fprintf(file,"    NumEngines %d%s",numEngines[i],LE);
    for (j=0; j<numEngines[i]; j++) {
      fprintf(file,"    Engine %d {%s",j,LE);
      fprintf(file,"      IspVac %.18f%s",ispVac[i][j],LE);
      fprintf(file,"      IspSl %.18f%s",ispSl[i][j],LE);
      fprintf(file,"      ThrustVac %.18f%s",thrustVac[i][j],LE);
      fprintf(file,"      ThrustSl %.18f%s",thrustSl[i][j],LE);
      fprintf(file,"      }%s",LE);
      }
    fprintf(file,"    }%s",LE);
    }
  fprintf(file,"  }%s",LE);
  }

Int8 Booster::SubLoad(char* pline) {
  if (startsWith(pline,"numstages ")) numStages = atoi(nw(pline));
  else if (startsWith(pline,"stage ")) stage = atoi(nw(pline));
  else if (startsWith(pline,"payload ")) payload = atof(nw(pline));
  else return 0;
  return -1;
  }


