#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "csmcomputer.h"
#include "common.h"
#include "helpers.h"

CsmComputer::CsmComputer(CommandModule* c) {
  prog = 0;
  csm = c;
  altitude = 0;
  velocity = 0;
  noun = 0;
  verb = 0;
  _reg1(0);
  _reg2(0);
  _reg3(0);
  running = 0;
  entryMode = '-';
  sprintf(dprog,"%02d",prog);
  sprintf(dverb,"%02d",verb);
  sprintf(dnoun,"%02d",noun);
  }

CsmComputer::~CsmComputer() {
  }

void CsmComputer::_reg1(Int32 i) {
  reg1 = i;
  if (reg1 < -99999) strcpy(dreg1,"-99999");
  else if (reg1 > 99999) strcpy(dreg1,"+99999");
  else {
    sprintf(dreg1,"%06d",abs(reg1));
    dreg1[0] = (reg1 >= 0) ? '+' : '-';
    }
  }

void CsmComputer::_reg2(Int32 i) {
  reg2 = i;
  if (reg2 < -99999) strcpy(dreg2,"-99999");
  else if (reg2 > 99999) strcpy(dreg2,"+99999");
  else {
    sprintf(dreg2,"%06d",abs(reg2));
    dreg2[0] = (reg2 >= 0) ? '+' : '-';
    }
  }

void CsmComputer::_reg3(Int32 i) {
  reg3 = i;
  if (reg3 < -99999) strcpy(dreg3,"-99999");
  else if (reg3 > 99999) strcpy(dreg3,"+99999");
  else {
    sprintf(dreg3,"%06d",abs(reg3));
    dreg3[0] = (reg3 >= 0) ? '+' : '-';
    }
  }

void CsmComputer::_doShow() {
  Double d;
  UInt32 i,j;
  switch (pnoun) {
    case 0:
         _reg1(preg1);
         _reg2(preg2);
         _reg3(preg3);
         break;
    case 1:
         _reg1((csm->Apoapsis()-csm->Orbiting()->Radius()) / 1000.0);
         _reg2((csm->Periapsis()-csm->Orbiting()->Radius()) / 1000.0);
         _reg3(csm->OrbitTime());
         break;
    case 2:
         _reg1(csm->Longitude() * 100);
         _reg2(csm->Latitude() * 100);
         break;
    case 3:
         _reg1(csm->Mass());
         _reg2(csm->Fuel());
         _reg3(csm->RcsFuel());
         break;
    case 4:
         _reg1(csm->Roll() * 100);
         _reg2(csm->Pitch() * 100);
         _reg3(csm->Yaw() * 100);
         break;
    case 5:
         _reg1(csm->TrueAnomaly() * 100);
         _reg2(csm->MeanAnomaly() * 100);
         _reg3(csm->EccentricAnomaly() * 100);
         break;
    case 6:
         _reg1(csm->AscendingNode() * 100);
         _reg2(csm->ArgOfPeriapsis() * 100);
         _reg3((csm->AscendingNode() + csm->ArgOfPeriapsis()) * 100);
         break;
    case 7:
         i = clockGe;
         j = i / 3600;
         i -= (j * 3600);
         _reg1(j);
         j = i / 60;
         i -= (j * 60);
         _reg2(j);
         _reg3(i);
         break;
    case 8:
         i = clockUt;
         j = i / 3600;
         i -= (j * 3600);
         _reg1(j);
         j = i / 60;
         i -= (j * 60);
         _reg2(j);
         _reg3(i);
         break;
    case 9:
         i = csm->ClockAp();
         j = i / 3600;
         i -= (j * 3600);
         _reg1(j);
         j = i / 60;
         i -= (j * 60);
         _reg2(j);
         _reg3(i);
         break;
    case 10:
         i = csm->ClockPe();
         j = i / 3600;
         i -= (j * 3600);
         _reg1(j);
         j = i / 60;
         i -= (j * 60);
         _reg2(j);
         _reg3(i);
         break;
    case 12:
         d = csm->Longitude() - mission->TargetLongitude();
         if (d >= 180) d-= 360;
         if (d <= -180) d += 360;
         _reg1(csm->Radius() - csm->Orbiting()->Radius());
         _reg2(d * 100);
         _reg3((csm->Latitude() - mission->TargetLatitude()) * 100);
         break;
    case 14:
         d = 9.80665 * csm->Isp() * log(csm->Mass() / (csm->Mass() - csm->Fuel()));
         _reg1(d);
         d = 9.80665 * csm->RcsIsp() * log(csm->Mass() / (csm->Mass() - csm->RcsFuel()));
         _reg2(d);
         _reg3(csm->FuelUsed());
         break;
    }
  }

Byte CsmComputer::_rollProgram() {
  Double d;
  if (fabs((Double)preg2/10.0 - ram[1]) < 0.05) {
    csm->LaunchVehicle()->RollRate(0);
    return -1;
    ram[0] = 3;
    }
  d = ram[1] - ((Double)preg2/10.0);
  if (d < -3) d = -3;
  if (d > 3) d = 3;
  ram[1] -= (d / GRAN);
  csm->LaunchVehicle()->RollRate(d);
  return 0;
  }

Double CsmComputer::_ascent(Double angle,Double maxRate,Double apo) {
  Double alt;
  Double d;
  Double g;
  Vector pos;
  Vector vel;
  Vector L;
  Double v1,v2;
  Double E;
  Double s;
  Double e;
  Double a;
  Double da;
  pos = csm->Position() - csm->Orbiting()->Position();
  alt = pos.Length() - csm->Orbiting()->Radius();

  vel = csm->Velocity() - csm->Orbiting()->Velocity();
  g = csm->Orbiting()->Gravitation();
  L = vel.Cross(pos);
  v1 = vel.Length();
  v2 = pos.Length();
  E = ((v1 * v1) / 2) - (g/ v2);
  s = -g/ (2 * E);
  v1 = L.Length();
  v2 = g* g;
  e = sqrt(1+2*E*(v1 * v1)/(v2));
  a = (s * (1 + e)) - csm->Orbiting()->Radius();
  da = a - lastApo;

  if (csm->RateOfClimb() < 0) d = maxRate;
  else if (lastApo + da * 20 * GRAN > apo * 100 &&
      da > 0) d = -maxRate;
  else {
    pos = pos.Norm();
    d = pos.Dot(csm->FaceUp());
    d = acos(d) * 180 / M_PI;
    d -= angle;
    if (d < -maxRate) d = -maxRate;
    if (d > maxRate) d = maxRate;
    }
  csm->LaunchVehicle()->PitchRate(d);
  lastApo = a;
  return alt;
  }

void CsmComputer::_program11() {
  Vector pos;
  Vector vel;
  switch (mission->Vehicle()) {

/* **************************************************************** */
/* *****                    Mercury Redstone                  ***** */
/* **************************************************************** */

    case VEHICLE_MERCURY_REDSTONE:
         if (ram[0] == 1) {
           pos = csm->Position() - csm->Orbiting()->Position();
           if (pos.Length() > csm->Orbiting()->Radius() + 100) {
             ram[0] = 2;
             }
           }
         if (ram[0] == 2) {
           if (_rollProgram()) ram[0] = 3;
           }
         if (ram[0] == 3) {
           _ascent((Double)preg1 / 10.0,1.0,0);
           if (csm->Throttle() == 0) {
             ram[0] = 4;
             }
           }
         if (ram[0] == 4) {
           csm->LaunchVehicle()->PitchRate(0);
           running = 0;
           }
         break;

/* **************************************************************** */
/* *****                     Mercury Atlas                    ***** */
/* **************************************************************** */

    case VEHICLE_MERCURY_ATLAS:
         /* ************************ */
         /* ***** Clear launch tower */
         /* ************************ */
         if (ram[0] == 1) {
           pos = csm->Position() - csm->Orbiting()->Position();
           if (pos.Length() > csm->Orbiting()->Radius() + 100) {
             ram[0] = 2;
             }
           }
         /* ****************************************** */
         /* ***** Perform roll to launch azimuth ***** */
         /* ****************************************** */
         if (ram[0] == 2) {
           if (_rollProgram()) ram[0] = 3;
           }
         /* ********************************************************* */
         /* ***** Pitch back to 20 degrees and hold until 8000m ***** */
         /* ********************************************************* */
         if (ram[0] == 3) {
           if (_ascent(20,1.0,preg1) >= 8000) ram[0] = 4;
           if (csm->Throttle() == 0) ram[0] = 4;
           }
         /* ********************************************* */
         /* ***** Picth back to 65 degrees and hold ***** */
         /* ********************************************* */
         if (ram[0] == 4) {
           _ascent(65,1.0,preg1);
           if (csm->Throttle() == 0) {
             ram[0] = 5;
             ram[2] = clockGe;
             csm->LaunchVehicle()->PitchRate(0);
             }
           }
         /* ******************************************************* */
         /* ***** Wait three seconds and then perform staging ***** */
         /* ******************************************************* */
         if (ram[0] == 5) {
           if (clockGe - ram[2] > 3) {
             csm->LaunchVehicle()->NextStage();
             ram[0] = 6;
             }
           }
         /* ************************ */
         /* ***** Second stage ***** */
         /* ************************ */
         if (ram[0] == 6) {
           _ascent(65,1.0,preg1);
           if (csm->Velocity().Length() > ram[3]) {
             ram[0] = 7;
             csm->LaunchVehicle()->PitchRate(0);
             }
           if (csm->Throttle() == 0) {
             ram[0] = 7;
             csm->LaunchVehicle()->PitchRate(0);
             }
           }

         if (ram[0] == 7) {
           csm->Cutoff();
           running = 0;
           }
         break;

/* **************************************************************** */
/* *****                     Gemini Titan                     ***** */
/* **************************************************************** */

    case VEHICLE_GEMINI_TITAN:
         /* ************************ */
         /* ***** Clear launch tower */
         /* ************************ */
         if (ram[0] == 1) {
           pos = csm->Position() - csm->Orbiting()->Position();
           if (pos.Length() > csm->Orbiting()->Radius() + 100) {
             ram[0] = 2;
             }
           }
         /* ****************************************** */
         /* ***** Perform roll to launch azimuth ***** */
         /* ****************************************** */
         if (ram[0] == 2) {
           if (_rollProgram()) ram[0] = 3;
           }
         /* ********************************************************* */
         /* ***** Pitch back to 20 degrees and hold until 8000m ***** */
         /* ********************************************************* */
         if (ram[0] == 3) {
           if (_ascent(20,1.0,preg1) >= 8000) ram[0] = 4;
           if (csm->Throttle() == 0) ram[0] = 4;
           }
         /* ********************************************* */
         /* ***** Picth back to 65 degrees and hold ***** */
         /* ********************************************* */
         if (ram[0] == 4) {
           _ascent(65,1.0,preg1);
           if (csm->Throttle() == 0) {
             ram[0] = 5;
             ram[2] = clockGe;
             csm->LaunchVehicle()->PitchRate(0);
             }
           }
         /* ******************************************************* */
         /* ***** Wait three seconds and then perform staging ***** */
         /* ******************************************************* */
         if (ram[0] == 5) {
           if (clockGe - ram[2] > 3) {
             csm->LaunchVehicle()->NextStage();
             ram[0] = 6;
             }
           }
         /* ************************ */
         /* ***** Second stage ***** */
         /* ************************ */
         if (ram[0] == 6) {
           _ascent(65,1.0,preg1);
           if (csm->Velocity().Length() > ram[3]) {
             ram[0] = 7;
             csm->LaunchVehicle()->PitchRate(0);
             }
           if (csm->Throttle() == 0) {
             ram[0] = 7;
             csm->LaunchVehicle()->PitchRate(0);
             }
           }

         if (ram[0] == 7) {
           csm->Cutoff();
           running = 0;
           }
         break;

/* **************************************************************** */
/* *****                     Apollo SaturnV                   ***** */
/* **************************************************************** */

    case VEHICLE_APOLLO:
    case VEHICLE_APOLLO_J:
    case VEHICLE_APOLLO_SATURN_V:
         /* ************************ */
         /* ***** Clear launch tower */
         /* ************************ */
         if (ram[0] == 1) {
           pos = csm->Position() - csm->Orbiting()->Position();
           if (pos.Length() > csm->Orbiting()->Radius() + 200) {
             ram[0] = 2;
             }
           }
         /* ****************************************** */
         /* ***** Perform roll to launch azimuth ***** */
         /* ****************************************** */
         if (ram[0] == 2) {
           if (_rollProgram()) ram[0] = 3;
           }
         /* ********************************************************* */
         /* ***** Pitch back to 20 degrees and hold until 8000m ***** */
         /* ********************************************************* */
         if (ram[0] == 3) {
           if (_ascent(20,1.0,preg1) >= 8000) ram[0] = 4;
           if (csm->Throttle() == 0) ram[0] = 4;
           }
         /* ********************************************* */
         /* ***** Picth back to 65 degrees and hold ***** */
         /* ********************************************* */
         if (ram[0] == 4) {
           _ascent(64,1.0,preg1);
           if (csm->Throttle() == 0) {
             ram[0] = 5;
             ram[2] = clockGe;
             csm->LaunchVehicle()->PitchRate(0);
             }
           }
         /* ******************************************************* */
         /* ***** Wait three seconds and then perform staging ***** */
         /* ******************************************************* */
         if (ram[0] == 5) {
           if (clockGe - ram[2] > 3) {
             csm->LaunchVehicle()->NextStage();
             ram[0] = 6;
             }
           }
         /* ************************ */
         /* ***** Second stage ***** */
         /* ************************ */
         if (ram[0] == 6) {
           _ascent(64,1.0,preg1);
           if (csm->Velocity().Length() > ram[3]) {
             ram[0] = 9;
             csm->LaunchVehicle()->PitchRate(0);
             }
           if (csm->Throttle() == 0) {
             ram[0] = 7;
             csm->LaunchVehicle()->PitchRate(0);
             ram[2] = clockGe;
             }
           }
         /* ******************************************************* */
         /* ***** Wait three seconds and then perform staging ***** */
         /* ******************************************************* */
         if (ram[0] == 7) {
           if (clockGe - ram[2] > 3) {
             csm->LaunchVehicle()->NextStage();
             ram[0] = 8;
             }
           }
         /* *********************** */
         /* ***** Third stage ***** */
         /* *********************** */
         if (ram[0] == 8) {
           _ascent(65,1.0,preg1);
           if (csm->Velocity().Length() > ram[3]) {
             ram[0] = 9;
             csm->LaunchVehicle()->PitchRate(0);
             }
           if (csm->Throttle() == 0) {
             ram[0] = 9;
             csm->LaunchVehicle()->PitchRate(0);
             }
           }

         if (ram[0] == 9) {
           csm->Cutoff();
           running = 0;
           }
         break;
    }
  }

void CsmComputer::Cycle() {
  Double a;
  Double E;
  Double e;
  Double l;
  Double g;
  Double s;
  Double d;
  Vector L;
  Vector tvUp;
  Vector tvFr;
  Vector tvLf;
  Vector crs;
  Vector xvec;
  Double v1,v2;
  Vector pos;
  Vector vel;
  Matrix m;
  if (pverb == 16) _doShow();
  if (running == 0) return;
  if (prog == 0) {
    running = 0;
    return;
    }
  if (prog == 1) {
    preg1 = csm->Altitude() / 100;
    preg2 = csm->RateOfClimb();
    preg3 = csm->Velocity().Length();
    if (velocity == 0) {
      if (csm->Periapsis() >= csm->Orbiting()->Radius()) {
        velocity = sqrt(csm->Orbiting()->Gravitation() / csm->Apoapsis());
        preg1 = (Int32)velocity;
        }
      }
    else {
      if (csm->Velocity().Length() >= velocity) {
        csm->Cutoff();
        running = 0;
        }
      }
    }
  else if (prog == 2) {
    pos = csm->Position() - csm->Orbiting()->Position();
    vel = csm->Velocity() - csm->Orbiting()->Velocity();
    g = csm->Orbiting()->Gravitation();
    L = vel.Cross(pos);
    v1 = vel.Length();
    v2 = pos.Length();
    E = ((v1 * v1) / 2) - (g/ v2);
    s = -g/ (2 * E);
    v1 = L.Length();
    v2 = g* g;
    e = sqrt(1+2*E*(v1 * v1)/(v2));
    a = (s * (1 + e)) - csm->Orbiting()->Radius();
    preg2 = a / 1000000;
    if (preg2 >= preg1) {
      csm->Cutoff();
      running = 0;
      }
    }
  else if (prog == 3) {
    if (csm->Throttle() == 0) return;
    preg2 = preg1 - csm->DeltaV();
    if (preg2 <= 0) {
      csm->Cutoff();
      running = 0;
      }
    }
  else if (prog == 4) {
    if (csm->TargetVehicle() != NULL) {
      pos = csm->Position() - (csm->TargetVehicle())->Position();
      tvUp = csm->TargetVehicle()->FaceUp().Norm();
      tvFr = csm->TargetVehicle()->FaceFront().Norm();
      tvLf = csm->TargetVehicle()->FaceLeft().Norm();
      l = pos.Length();
      preg1 = l*10;
      a = (ram[0] - l) * 1000 * GRAN;
      if (a <-99999) a = -99999;
      if (a > 99999) a = 99999;
      ram[0] = l;
      preg2 = a;
      }
    }
  else if (prog == 11) _program11();
  else if (prog == 15) {
    csm->Prograde(3);
    if (ram[0] == 1) {
      d = (Moon->Longitude() + 360) - (csm->Longitude() + 360) - 360;
      while (d >= 180) d -= 360;
      while (d <= -180) d += 360;
      preg3 = d*100;
      if (fabs(d-ram[2]/100) < 2) {
        if (d < ram[2]/100) {
          csm->Ignition();
          ram[0] = 2;
          }
        }
      }
    if (ram[0] == 2) {
      pos = csm->Position() - csm->Orbiting()->Position();
      vel = csm->Velocity() - csm->Orbiting()->Velocity();
      g = csm->Orbiting()->Gravitation();
      L = vel.Cross(pos);
      v1 = vel.Length();
      v2 = pos.Length();
      E = ((v1 * v1) / 2) - (g/ v2);
      s = -g/ (2 * E);
      v1 = L.Length();
      v2 = g* g;
      e = sqrt(1+2*E*(v1 * v1)/(v2));
      a = (s * (1 + e)) - csm->Orbiting()->Radius();
      preg2 = a / 1000000;
      if (preg2 >= preg1) {
        csm->Cutoff();
        running = 0;
        }
      }
    }
  else if (prog == 20) {
    a = sqrt(csm->Orbiting()->Gravitation() / (preg1*1000 + csm->Orbiting()->Radius()));
    preg2 = a*10;
    running = 0;
    }
  else if (prog == 21) {
    csm->Prograde(3);
    }
  else if (prog == 22) {
    csm->Retrograde(3);
    }
  else if (prog == 30) {
    if (csm->Throttle() == 0) return;
    if (ram[0] == 1) {
      preg1 = ram[1] - (csm->DeltaV() * 10);
      if (preg1 <= 0) {
        csm->Cutoff();
        ram[0] = 2;
        preg1 = 0;
        }
      }
    else {
      preg2 = ram[2] - (csm->DeltaV() * 10);
      if (preg2 <= 0) {
        csm->Cutoff();
        preg2 = 0;
        running = 0;
        }
      }
    }
  }

char* CsmComputer::Noun() {
  return dnoun;
  }

char* CsmComputer::Prog() {
  return dprog;
  }

char* CsmComputer::Reg1() {
  return dreg1;
  }

char* CsmComputer::Reg2() {
  return dreg2;
  }

char* CsmComputer::Reg3() {
  return dreg3;
  }

Byte CsmComputer::Running() {
  return running;
  }

char* CsmComputer::Verb() {
  return dverb;
  }

void CsmComputer::_processRequest() {
  Double d;
  Double atx,via,vfb,vtxa,vtxb,dva,dvb;
  Double ra,rb;
  pnoun = noun;
  pverb = verb;
  if (verb == 0) {
    running = 0;
    }
  if (verb == 21) {
    entryMode = '1';
    strcpy(dreg1,"+_____");
    }
  if (verb == 22) {
    entryMode = '2';
    strcpy(dreg2,"+_____");
    }
  if (verb == 23) {
    entryMode = '3';
    strcpy(dreg3,"+_____");
    }
  if (verb == 30) {
    csm->Roll(0);
    csm->Pitch(0);
    csm->Yaw(0);
    }
  if (verb == 31) {
    d = reg1;
    while (d >= 180) d -= 360;
    while (d <= -180) d += 360;
    csm->Roll(d);
    d = reg2;
    while (d >= 180) d -= 360;
    while (d <= -180) d += 360;
    csm->Pitch(d);
    d = reg3;
    while (d >= 180) d -= 360;
    while (d <= -180) d += 360;
    csm->Yaw(d);
    }
  if (verb == 37) {
    prog = noun;
    sprintf(dprog,"%02d",prog);
    running = 0xff;
    preg1 = reg1;
    preg2 = reg2;
    preg3 = reg3;
    if (prog == 3) {
      preg2 = preg1;
      }
    if (prog == 11) {
      ram[0] = 1;
      ram[1] = 90;
      ram[3] = sqrt(csm->Orbiting()->Gravitation() / (preg1*100 + csm->Orbiting()->Radius()));
      }
    if (prog == 15) {
      ram[0] = 1;
      ram[1] = preg1;
      ram[2] = preg2;
      }
    if (prog == 30) {
      ra = csm->Radius();
      rb = (preg1 * 1000) + csm->Orbiting()->Radius();
      atx = (ra + rb) / 2;
      via = sqrt(csm->Orbiting()->Gravitation() / ra);
      vfb = sqrt(csm->Orbiting()->Gravitation() / rb);
      vtxa = sqrt(csm->Orbiting()->Gravitation() * (2/ra - 1/atx));
      vtxb = sqrt(csm->Orbiting()->Gravitation() * (2/rb - 1/atx));
      dva = fabs(vtxa-via);
      dvb = fabs(vfb-vtxb);
      preg1 = (dva * 10);
      preg2 = (dvb * 10);
      ram[0] = 1;
      ram[1] = preg1;
      ram[2] = preg2;
      }
    pverb = 16;
    pnoun = 0;
    }
  }

void CsmComputer::ProcessKey(Int32 key) {
  UInt8 i;
  Int8 p;
  char *buffer;
  if (key == 'p' && entryMode == '-') {
    _processRequest();
    }
  if (key == 'v' && entryMode == '-') {
    entryMode = 'V';
    strcpy(dverb,"__");
    }
  if (key == 'n' && entryMode == '-') {
    entryMode = 'N';
    strcpy(dnoun,"__");
    }
  if (key >= '0' && key <= '9' && entryMode != '-') {
    p = -1;
    if (entryMode == 'P') buffer=dprog;
    if (entryMode == 'V') buffer=dverb;
    if (entryMode == 'N') buffer=dnoun;
    if (entryMode == '1') buffer=dreg1;
    if (entryMode == '2') buffer=dreg2;
    if (entryMode == '3') buffer=dreg3;
    for (i=0; i<strlen(buffer); i++)
      if (p == -1 && buffer[i] == '_') p = i;
    if (p >= 0) {
      buffer[p] = key;
      if ((UInt8)p == strlen(buffer) - 1) {
        if (entryMode == 'P') prog = atoi(dprog);
        if (entryMode == 'V') verb = atoi(dverb);
        if (entryMode == '1') reg1 = atoi(dreg1);
        if (entryMode == '2') reg2 = atoi(dreg2);
        if (entryMode == '3') reg3 = atoi(dreg3);
        if (entryMode == 'N') noun = atoi(dnoun);
        entryMode = '-';
        }
      }
    }
  if (key == '-' && entryMode != '-') {
    if (entryMode == 'P') buffer=dprog;
    if (entryMode == 'V') buffer=dverb;
    if (entryMode == 'N') buffer=dnoun;
    if (entryMode == '1') buffer=dreg1;
    if (entryMode == '2') buffer=dreg2;
    if (entryMode == '3') buffer=dreg3;
    if (buffer[0] == '+') buffer[0] = '-';
    }
  if (key == '+' && entryMode != '-') {
    if (entryMode == 'P') buffer=dprog;
    if (entryMode == 'V') buffer=dverb;
    if (entryMode == 'N') buffer=dnoun;
    if (entryMode == '1') buffer=dreg1;
    if (entryMode == '2') buffer=dreg2;
    if (entryMode == '3') buffer=dreg3;
    if (buffer[0] == '-') buffer[0] = '+';
    }
  }

Int8 CsmComputer::Load(FILE* file) {
  UInt32 addr;
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) {
      sprintf(dprog,"%02d",prog);
      sprintf(dverb,"%02d",verb);
      sprintf(dnoun,"%02d",noun);
      return -1;
      }
    else if (startsWith(pline,"altitude ")) altitude = atof(nw(pline));
    else if (startsWith(pline,"velocity ")) velocity = atof(nw(pline));
    else if (startsWith(pline,"prog ")) prog = atoi(nw(pline));
    else if (startsWith(pline,"noun ")) noun = atoi(nw(pline));
    else if (startsWith(pline,"pverb ")) pverb = atoi(nw(pline));
    else if (startsWith(pline,"pnoun ")) pnoun = atoi(nw(pline));
    else if (startsWith(pline,"verb ")) verb = atoi(nw(pline));
    else if (startsWith(pline,"reg1 ")) _reg1(atoi(nw(pline)));
    else if (startsWith(pline,"reg2 ")) _reg2(atoi(nw(pline)));
    else if (startsWith(pline,"reg3 ")) _reg3(atoi(nw(pline)));
    else if (startsWith(pline,"preg1 ")) preg1 = atoi(nw(pline));
    else if (startsWith(pline,"preg2 ")) preg2 = atoi(nw(pline));
    else if (startsWith(pline,"preg3 ")) preg3 = atoi(nw(pline));
    else if (startsWith(pline,"running ")) running = atoi(nw(pline));
    else if (startsWith(pline,"entrymode ")) entryMode = (nw(pline))[0];
    else if (startsWith(pline,"ram")) {
      addr = atoi(pline+3);
      ram[addr] = atof(nw(pline));
      }
    else return 0;
    }
  sprintf(dprog,"%02d",prog);
  sprintf(dverb,"%02d",verb);
  sprintf(dnoun,"%02d",noun);
  return -1;
  }

void CsmComputer::Save(FILE* file) {
  Int32 i;
  fprintf(file,"  Computer {%s",LE);
  fprintf(file,"    Altitude %.18f%s",altitude,LE);
  fprintf(file,"    Velocity %.18f%s",velocity,LE);
  fprintf(file,"    Prog %d%s",prog,LE);
  fprintf(file,"    Verb %d%s",verb,LE);
  fprintf(file,"    Noun %d%s",noun,LE);
  fprintf(file,"    PVerb %d%s",pverb,LE);
  fprintf(file,"    PNoun %d%s",pnoun,LE);
  fprintf(file,"    Reg1 %d%s",reg1,LE);
  fprintf(file,"    Reg2 %d%s",reg2,LE);
  fprintf(file,"    Reg3 %d%s",reg3,LE);
  fprintf(file,"    PReg1 %d%s",preg1,LE);
  fprintf(file,"    PReg2 %d%s",preg2,LE);
  fprintf(file,"    PReg3 %d%s",preg3,LE);
  fprintf(file,"    Running %d%s",running,LE);
  fprintf(file,"    EntryMode %c%s",entryMode,LE);
  for (i=0; i<256; i++)
    if (ram[i] != 0) fprintf(file,"    Ram%d %f%s",i,ram[i],LE);
  fprintf(file,"    }%s",LE);
  }

