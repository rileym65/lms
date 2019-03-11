#include <stdio.h>
#include "header.h"
#include "booster.h"
#include "helpers.h"
#include "g_clockbu.h"

Booster::Booster() {
  UInt32 i;
  stage = 1;
  height = 0;
  cmOffset = 0;
  enginesLit = 0;
  type |= VT_ROCKET;
  for (i=0; i<10; i++) {
    ceco[i] = 0;
    maxPitchRate[i] = 1;
    maxYawRate[i] = 1;
    maxRollRate[i] = 4;
    }
  }

Booster::~Booster() {
  }

void Booster::Cutoff() {
  enginesLit = 0;
  throttle = 0;
  burn[numBurns-1].end = clockGe;
  burn[numBurns-1].fuelUsed -= Fuel();
  }

void Booster::Cycle() {
  Byte i;
  Double th;
  Double tth;
  Double f;
  Double alt;
  Double isp;
  Double air;
  Double d;
  Double v;
  Byte   st;
//  alt = position.Length() - GROUND;
  alt = position.Length() - Orbiting()->Radius();
  thrust = Vector(0,0,0);
  drag = Vector(0,0,0);
  tth = 0;
  st = stage - 1;
  air = AirDensity(alt);
  fuelUsed = 0;
  if (throttle != 0) {
    if (ceco[st] != 0 && clockBu > ceco[st]) {
      ceco[st] = 0;
      enginesLit &= 0xfe;
      }
    for (i=0; i<numEngines[st]; i++) {
      if (enginesLit & (1 << i)) {
        isp = ispVac[st][i] - air * (ispVac[st][i]-ispSl[st][i]);
        th = thrustVac[st][i] - air * (thrustVac[st][i]-thrustSl[st][i]);
        f = th/(9.80665 * isp) / GRAN;
        th = th / Mass();
        if (f <= fuel[st]) {
          tth += th;
          fuel[st] -= f;
          fuelUsed += f;
          }
        else enginesLit &= (~(1 << i));
        }
      }
    fuelUsed *= GRAN;
    thrust = faceUp.Scale(tth);
    if (enginesLit == 0) {
      throttle = 0;
      burn[numBurns-1].end = clockGe;
      burn[numBurns-1].fuelUsed -= Fuel();
      }
    }
  if (air > 0) {
    v = velocity.Length() - 408;
    d = 0.8 * area[st] * 0.5 * (air * 1.2 * v * v);
    if (clockBsp == 0 && d > maxQ) {
      maxQ = d;
      clockMaxQ = clockGe;
      maxQAltitude = Radius() - Orbiting()->Radius();
      }
    d /= Mass();
    drag = velocity.Norm().Scale(d).Neg();
    }
  Spacecraft::Cycle();
//  if (radius < GROUND) destroyed = true;
  if (Radius() < Orbiting()->Radius()) destroyed = true;
  }

void Booster::Ceco(Byte stage, Double d) {
  ceco[stage-1] = d;
  }

Double Booster::CmOffset() {
  return cmOffset;
  }

Double Booster::CmOffset(Double d) {
  cmOffset = d;
  return cmOffset;
  }

void Booster::Diameter(Byte stage, Double d) {
  d = d/2;
  area[stage-1] = d * d * M_PI;
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

Double Booster::Isp() {
  Int32 i;
  Double ret;
  ret = 0;
  for (i=0; i<numEngines[stage-1]; i++)
    ret += ispVac[stage-1][i];
  ret /= numEngines[stage-1];
  return ret;
  }

Double Booster::Fuel(Byte stage) {
  return fuel[stage-1];
  }

Double Booster::Fuel(Byte stage, Double d) {
  fuel[stage-1] = d;
  return fuel[stage-1];
  }

Double Booster::Height() { 
  return height;
  }

Double Booster::Height(Double d) { 
  height = d;
  return height;
  }

void Booster::Ignition() {
  if (starts[stage-1] > 0) {
    deltaV = 0;
    clockBu = 0;
    if (numEngines[stage-1] == 1) enginesLit = 0x01;
    if (numEngines[stage-1] == 2) enginesLit = 0x03;
    if (numEngines[stage-1] == 3) enginesLit = 0x07;
    if (numEngines[stage-1] == 4) enginesLit = 0x0f;
    if (numEngines[stage-1] == 5) enginesLit = 0x1f;
    if (numEngines[stage-1] == 6) enginesLit = 0x3f;
    if (numEngines[stage-1] == 7) enginesLit = 0x7f;
    if (numEngines[stage-1] == 8) enginesLit = 0xff;
    starts[stage-1]--;
    Throttle(100);
    ignitionTime = clockGe;
    ignitionApoapsis = ins->Apoapsis();
    ignitionPeriapsis = ins->Periapsis();
    ignitionEccentricity = ins->Eccentricity();
    burn[numBurns].start = clockGe;
    burn[numBurns].fuelUsed = Fuel();
    burn[numBurns].engine = '0' + stage;
    numBurns++;
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

Double Booster::MaxPitchRate() {
  return maxPitchRate[stage-1];
  }

Double Booster::MaxPitchRate(Byte stage) {
  return maxPitchRate[stage-1];
  }

Double Booster::MaxPitchRate(Byte stage, Double d) {
  maxPitchRate[stage-1] = d;
  return maxPitchRate[stage-1];
  }

Double Booster::MaxRollRate() {
  return maxRollRate[stage-1];
  }

Double Booster::MaxRollRate(Byte stage) {
  return maxRollRate[stage-1];
  }

Double Booster::MaxRollRate(Byte stage, Double d) {
  maxRollRate[stage-1] = d;
  return maxRollRate[stage-1];
  }

Double Booster::MaxYawRate() {
  return maxYawRate[stage-1];
  }

Double Booster::MaxYawRate(Byte stage) {
  return maxYawRate[stage-1];
  }

Double Booster::MaxYawRate(Byte stage, Double d) {
  maxYawRate[stage-1] = d;
  return maxYawRate[stage-1];
  }

void Booster::NextStage() {
  if (enginesLit != 0) return;
  if (stage < numStages) {
    deltaV = 0;
    clockBu = 0;
    stage++;
    enginesLit = 0;
    starts[stage-1]--;
    if (numEngines[stage-1] == 1) enginesLit = 0x01;
    if (numEngines[stage-1] == 2) enginesLit = 0x03;
    if (numEngines[stage-1] == 3) enginesLit = 0x07;
    if (numEngines[stage-1] == 4) enginesLit = 0x0f;
    if (numEngines[stage-1] == 5) enginesLit = 0x1f;
    if (numEngines[stage-1] == 6) enginesLit = 0x3f;
    if (numEngines[stage-1] == 7) enginesLit = 0x7f;
    if (numEngines[stage-1] == 8) enginesLit = 0xff;
    Throttle(100);
    burn[numBurns].start = clockGe;
    burn[numBurns].fuelUsed = Fuel();
    burn[numBurns].engine = '0' + stage;
    numBurns++;
    }
  }

Byte Booster::MaxEngines() {
  UInt32 i;
  Byte ret;
  ret = 0;
  for (i=0; i<numStages; i++)
    if (numEngines[i] > ret) ret = numEngines[i];
  return ret;
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

Double Booster::PitchRate() {
  return pitchRate;
  }

Double Booster::RollRate() {
  return rollRate;
  }

Double Booster::YawRate() {
  return yawRate;
  }

Double Booster::PitchRate(Double d) {
  if (d > 0 && d > maxPitchRate[stage-1]) d = maxPitchRate[stage-1];
  if (d < 0 && d < -maxPitchRate[stage-1]) d = -maxPitchRate[stage-1];
  pitchRate = d;
  return pitchRate;
  }

Double Booster::RollRate(Double d) {
  if (d > 0 && d > maxRollRate[stage-1]) d = maxRollRate[stage-1];
  if (d < 0 && d < -maxRollRate[stage-1]) d = -maxRollRate[stage-1];
  rollRate = d;
  return rollRate;
  }

Double Booster::YawRate(Double d) {
  if (d > 0 && d > maxYawRate[stage-1]) d = maxYawRate[stage-1];
  if (d < 0 && d < -maxYawRate[stage-1]) d = -maxYawRate[stage-1];
  yawRate = d;
  return yawRate;
  }

void Booster::ProcessKey(Int32 key) {
  if (key == 'I' && launched) Ignition();
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
  Spacecraft::Save(file);
  fprintf(file,"  EnginesLit %d%s",enginesLit,LE);
  fprintf(file,"  Payload %.18f%s",payload,LE);
  fprintf(file,"  Height %.18f%s",height,LE);
  fprintf(file,"  CmOffset %.18f%s",cmOffset,LE);
  fprintf(file,"  Stage %d%s",stage,LE);
  fprintf(file,"  NumStages %d%s",numStages,LE);
  for (i=0; i<numStages; i++) {
    fprintf(file,"  Stage %d {%s",i+1,LE);
    fprintf(file,"    DryWeight %.18f%s",dryWeight[i],LE);
    fprintf(file,"    Area %.18f%s",area[i],LE);
    fprintf(file,"    Fuel %.18f%s",fuel[i],LE);
    fprintf(file,"    MaxFuel %.18f%s",maxFuel[i],LE);
    fprintf(file,"    NumEngines %d%s",numEngines[i],LE);
    fprintf(file,"    Starts %d%s",starts[i],LE);
    fprintf(file,"    Ceco %.18f%s",ceco[i],LE);
    fprintf(file,"    MaxPitchRate %.18f%s",maxPitchRate[i],LE);
    fprintf(file,"    MaxRollRate %.18f%s",maxRollRate[i],LE);
    fprintf(file,"    MaxYawRate %.18f%s",maxYawRate[i],LE);
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

Int8 Booster::loadEngine(FILE* file, char*line, Byte s) {
  Int32 i;
  char* pline;
  i = atoi(line);
printf("Loading engine %d for stage %d\n",i,s);
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return -1;
    else if (startsWith(pline,"ispvac ")) ispVac[s][i] = atof(nw(pline));
    else if (startsWith(pline,"ispsl ")) ispSl[s][i] = atof(nw(pline));
    else if (startsWith(pline,"thrustvac ")) thrustVac[s][i] = atof(nw(pline));
    else if (startsWith(pline,"thrustsl ")) thrustSl[s][i] = atof(nw(pline));
    else return 0;
    }
  return -1;
  }

Int8 Booster::loadStage(FILE* file, char*line) {
  Int32 i;
  char* pline;
  i = atoi(line) - 1;
printf("loading stage %d\n",i);
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return -1;
    else if (startsWith(pline,"dryweight ")) dryWeight[i] = atof(nw(pline));
    else if (startsWith(pline,"area ")) area[i] = atof(nw(pline));
    else if (startsWith(pline,"fuel ")) fuel[i] = atof(nw(pline));
    else if (startsWith(pline,"maxfuel ")) maxFuel[i] = atof(nw(pline));
    else if (startsWith(pline,"numengines ")) numEngines[i] = atoi(nw(pline));
    else if (startsWith(pline,"starts ")) starts[i] = atoi(nw(pline));
    else if (startsWith(pline,"ceco ")) ceco[i] = atof(nw(pline));
    else if (startsWith(pline,"maxpitchrate ")) maxPitchRate[i] = atof(nw(pline));
    else if (startsWith(pline,"maxrollrate ")) maxRollRate[i] = atof(nw(pline));
    else if (startsWith(pline,"maxyawrate ")) maxYawRate[i] = atof(nw(pline));
    else if (startsWith(pline,"engine ") &&
             (strchr(pline,'{') != NULL)) {
      if (loadEngine(file,nw(pline), i) == 0) return 0;
      }
    else return 0;
    }
  return -1;
  }

Int8 Booster::SubLoad(FILE* file, char* pline) {
  if (startsWith(pline,"engineslit ")) enginesLit = atoi(nw(pline));
  else if (startsWith(pline,"numstages ")) numStages = atoi(nw(pline));
  else if (startsWith(pline,"stage ") &&
           strchr(pline,'{') == NULL) stage = atoi(nw(pline));
  else if (startsWith(pline,"stage ") &&
           strchr(pline,'{') != NULL) return loadStage(file,nw(pline));
  else if (startsWith(pline,"payload ")) payload = atof(nw(pline));
  else if (startsWith(pline,"height ")) height = atof(nw(pline));
  else if (startsWith(pline,"cmoffset ")) cmOffset = atof(nw(pline));
  else return Spacecraft::SubLoad(file, pline);
  return -1;
  }


