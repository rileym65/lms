#include "header.h"
#include "lm.h"
#include "terminal.h"
#include "computer.h"

LunarModule::LunarModule() {
  landed = 0;
  throttle = 0;
  pitchRate = 0;
  rcsFbMode = ' ';
  rcsLrMode = ' ';
  rcsUdMode = ' ';
  rollRate = 0;
  yawRate = 0;
  descentJettisoned = 0;
  rock = 0;
  InitPanel();
/*
  roll = 0;
  pitch = 0;
  yaw = 0;
  rollMatrix = Matrix::RotateZ(roll);
  pitchMatrix = Matrix::RotateY(pitch);
  yawMatrix = Matrix::RotateX(yaw);
*/
  }

LunarModule::~LunarModule() {
  }

void LunarModule::InitPanel() {
  panel = new Panel("lm.pnl",this);
  }

char   LunarModule::RcsFbMode() {
  return rcsFbMode;
  }

char   LunarModule::RcsFbMode(char c) {
  rcsFbMode = c;
  return rcsFbMode;
  }

char   LunarModule::RcsLrMode() {
  return rcsLrMode;
  }

char   LunarModule::RcsLrMode(char c) {
  rcsLrMode = c;
  return rcsLrMode;
  }

char   LunarModule::RcsUdMode() {
  return rcsUdMode;
  }

char   LunarModule::RcsUdMode(char c) {
  rcsUdMode = c;
  return rcsUdMode;
  }

Double LunarModule::AscentFuel() {
  return ascentFuel;
  }

Double LunarModule::AscentFuel(Double d) {
  ascentFuel = d;
  return ascentFuel;
  }

Double LunarModule::DescentFuel() {
  return descentFuel;
  }

Double LunarModule::DescentFuel(Double d) {
  descentFuel = d;
  return descentFuel;
  }

Int8 LunarModule::DescentJettisoned() {
  return descentJettisoned;
  }

Int8 LunarModule::Landed() {
  return landed;
  }

Double LunarModule::RcsFuel() {
  return rcsFuel;
  }

Double LunarModule::RcsFuel(Double d) {
  rcsFuel = d;
  return rcsFuel;
  }

Int16 LunarModule::Rock() {
  return rock;
  }

Int16 LunarModule::Rock(Int16 i) {
  rock = i;
  return rock;
  }

Double LunarModule::Value() {
  return value;
  }

Double LunarModule::Value(Double d) {
  value = d;
  return value;
  }

Double LunarModule::Mass() {
  Double ret;
  ret = 2234;
  ret += ascentFuel;
  ret += rcsFuel;
  if (!descentJettisoned) {
    ret += 2346;
    ret += descentFuel;
    }
  ret += rock;
  return ret;
  }

void LunarModule::Cycle() {
  Double rcsfuel;
  Double rcsThrust;
  Double newtons;
  Double mainThrust;
  Double mainfuel;
  Double vVel;
  Double hVel;
  Vector v;
  Matrix m;
  if (comp != NULL) comp->Cycle();
  if (landed && throttle == 0) return;
  if (rollRate >= -0.0001 && rollRate < 0.0001) rollRate = 0;
  if (pitchRate >= -0.0001 && pitchRate < 0.0001) pitchRate = 0;
  if (yawRate >= -0.0001 && yawRate < 0.0001) yawRate = 0;
  if (rollRate != 0 || pitchRate != 0 || yawRate != 0) {
/*
    m = Matrix::Identity();
    if (rollRate != 0) {
      roll += rollRate;
      if (roll > 180) roll -= 360;
      if (roll < -180) roll += 360;
      rollMatrix = Matrix::RotateZ(roll);
      }
    m.MultipliedBy(rollMatrix);
    if (pitchRate != 0) {
      pitch += pitchRate;
      if (pitch > 180) pitch -= 360;
      if (pitch < -180) pitch += 360;
      pitchMatrix = Matrix::RotateY(-pitch);
      }
    m.MultipliedBy(pitchMatrix);
    if (yawRate != 0) {
      yaw += yawRate;
      if (yaw > 180) yaw -= 360;
      if (yaw < -180) yaw += 360;
      yawMatrix = Matrix::RotateX(yaw);
      }
    m.MultipliedBy(yawMatrix);
    faceFront = m.Transform(baseFront).Norm();
    faceLeft = m.Transform(baseLeft).Norm();
*/
    if (rollRate != 0) orientation.MultipliedBy(rollMatrix);
    if (pitchRate != 0) orientation.MultipliedBy(pitchMatrix);
    if (yawRate != 0) orientation.MultipliedBy(yawMatrix);
    orientation.Row(0,orientation.Row(0).Norm());
    orientation.Row(1,orientation.Row(1).Norm());
    orientation.Row(2,orientation.Row(2).Norm());
    faceFront = orientation.Transform(baseFront).Norm();
    faceLeft = orientation.Transform(baseLeft).Norm();
    faceUp = faceFront.Cross(faceLeft).Norm();
    faceLeft = faceUp.Cross(faceFront).Norm();
    }
  switch (rcsThrottle) {
    case 1: rcsThrust = 19.7; rcsfuel = 0.05; break;
    case 10: rcsThrust = 197.0; rcsfuel = 0.05; break;
    case 100: rcsThrust = 1970.0; rcsfuel = 0.5; break;
    default : rcsThrust = 0;
    }
//GotoXY(1,25); printf("fl %f fu %f lu %f\n",faceFront.Dot(faceLeft),faceFront.Dot(faceUp),faceLeft.Dot(faceUp));
  rcsThrust = rcsThrust / Mass();
  thrust = Vector(0,0,0);
  if (rcsUdMode == 'D' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceUp.Neg().Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsUdMode == 'U' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceUp.Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsLrMode == 'R' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceLeft.Neg().Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsLrMode == 'L' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceLeft.Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsFbMode == 'F' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceFront.Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsFbMode == 'B' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceFront.Neg().Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (throttle != 0) {
    if (descentJettisoned) {
      throttle = 100;
      mainThrust = 16890.0 / Mass();
      if (ascentFuel >= 5) {
        thrust = thrust + faceUp.Scale(mainThrust);
        ascentFuel -= 5;
        }
      }
    else {
      newtons = (double)throttle / 100.0;
      mainfuel = 15.0 * newtons;
      newtons *= 49215;
      mainThrust = newtons / Mass();
      if (mainfuel <= descentFuel) {
        thrust = thrust + faceUp.Scale(mainThrust);
        descentFuel -= mainfuel;
        }
      }
    }
  Vehicle::Cycle();
//  if (radius <= GROUND && !landed) {
  if (radius <= GROUND) {
    vVel = fabs(velocityAltitude);
    hVel = sqrt(lm->VelocityEast() * lm->VelocityEast() +
                lm->VelocityNorth() * lm->VelocityNorth());
    landedVVel = vVel;
    landedHVel = hVel;
    if (vVel >= 3 || fabs(lm->VelocityEast()) >= 0.3 ||
                    fabs(lm->VelocityNorth()) >= 0.3) {
      run = false;
      endReason = END_CRASHED;
      }
    RollRate(0);
    PitchRate(0);
    YawRate(0);
    velocity = Vector(0,0,0);
    velocityAltitude = 0;
    landed = -1;
    throttle = 0;
    position = position.Norm().Scale(GROUND);
    rcsFbMode = ' ';
    rcsLrMode = ' ';
    rcsUdMode = ' ';
    altitude = 0;
    radius = GROUND;
    landedMet = clockMi;
    landedLongitude = longitude;
    landedLatitude = latitude;
    clockPDI = ignitionTime;
    burn[numBurns-1].end = clockMi;
    burn[numBurns-1].fuelUsed -= descentFuel;
    accelNorth = 0;
    accelEast = 0;
    accelAltitude = 0;
    velocityAltitude = 0;
    velocityNorth = 0;
    velocityEast = 0;
    }
  }

void LunarModule::Save(FILE* file) {
  fprintf(file,"LunarModule {%s",LE);
  Vehicle::Save(file);
  fprintf(file,"  RcsFbMode %d%s",rcsFbMode,LE);
  fprintf(file,"  RcsLrMode %d%s",rcsLrMode,LE);
  fprintf(file,"  RcsUdMode %d%s",rcsUdMode,LE);
  fprintf(file,"  AscentFuel %.18f%s",ascentFuel,LE);
  fprintf(file,"  DescentFuel %.18f%s",descentFuel,LE);
  fprintf(file,"  RcsFuel %.18f%s",rcsFuel,LE);
  fprintf(file,"  Landed %d%s",landed,LE);
  fprintf(file,"  DescentJettisoned %d%s",descentJettisoned,LE);
  fprintf(file,"  Rock %d%s",rock,LE);
  fprintf(file,"  Value %.18f%s",value,LE);
  fprintf(file,"  }%s",LE);
  }

Int8 LunarModule::SubLoad(char* pline) {
  if (startsWith(pline,"rcsfbmode ")) rcsFbMode = atoi(nw(pline));
  else if (startsWith(pline,"rcslrmode ")) rcsLrMode = atoi(nw(pline));
  else if (startsWith(pline,"rcsudmode ")) rcsUdMode = atoi(nw(pline));
  else if (startsWith(pline,"ascentfuel ")) ascentFuel = atof(nw(pline));
  else if (startsWith(pline,"descentfuel ")) descentFuel = atof(nw(pline));
  else if (startsWith(pline,"rcsfuel ")) rcsFuel = atof(nw(pline));
  else if (startsWith(pline,"landed ")) landed = atoi(nw(pline));
  else if (startsWith(pline,"descentjettisoned ")) descentJettisoned = atoi(nw(pline));
  else if (startsWith(pline,"rock ")) rock = atoi(nw(pline));
  else if (startsWith(pline,"value ")) value = atof(nw(pline));
  else return 0;
  return -1;
  }

void LunarModule::Abort() {
  landed = 0;
  descentJettisoned = -1;
  mode_arm = 0;
  throttle = 100;
  clockBu = 0;
  if (oxygen > ASC_OXYGEN) oxygen = ASC_OXYGEN;
  if (battery > ASC_BATTERY) battery = ASC_BATTERY;
  if (eoxygen > ASC_EOXYGEN) eoxygen = ASC_EOXYGEN;
  if (ebattery > ASC_EBATTERY) ebattery = ASC_EBATTERY;
  liftoffMet = clockMi;
  numBurns++;
  burn[numBurns-1].start = clockMi;
  if (descentJettisoned) {
    burn[numBurns-1].fuelUsed = ascentFuel;
    burn[numBurns-1].engine = 'A';
    }
  else {
    burn[numBurns-1].fuelUsed = descentFuel;
    burn[numBurns-1].engine = 'D';
    }
  }

void LunarModule::ProcessKey(Int32 key) {
  if (key == 'M') {
    if (docked) seq->MoveCsm();
    if (landed && spaceSuitOn && plssOn && !cabinPressurized)
      seq->MoveEva();
    }
  if (key == 'U' && docked) seq->Undock();
  if (key == 'S') {
    if (!spaceSuitOn) seq->SpaceSuitOn();
    else if (cabinPressurized && ! plssOn) seq->SpaceSuitOff();
    }
  if (key == 'P') {
    if (!plssOn && spaceSuitOn && plssPacks > 0) seq->PlssOn();
    else if (plssOn && cabinPressurized) seq->PlssOff();
    }
  if (key == 'C') {
    if (!cabinPressurized) seq->CabinPressurize();
    else if (spaceSuitOn) seq->CabinEvacuate();
    }
  if (key == '?') {
    dsnOn = -1;
    dockingRadarOn = 0;
    landingRadarOn = 0;
    }
  if (key == '>') {
    dsnOn = 0;
    dockingRadarOn = -1;
    landingRadarOn = 0;
    }
  if (key == '<') {
    dsnOn = 0;
    dockingRadarOn = 0;
    landingRadarOn = -1;
    }
  if (key == 27 && !landed && mode_arm != 0 && !descentJettisoned) {
    seq->Abort();
    }
  if (landed) {
    if (key == '*') seq->Rest();
    if (key == ')') seq->Sleep();
    if (key == 'L' && mode_arm != 0) {
      seq->Liftoff();
      }
    }
  if (!docked) {
    if (key == 'f' && RcsFbMode() == ' ') RcsFbMode('F');
    if (key == 'f' && RcsFbMode() == 'B') RcsFbMode(' ');
    if (key == 'b' && RcsFbMode() == ' ') RcsFbMode('B');
    if (key == 'b' && RcsFbMode() == 'F') RcsFbMode(' ');
    if (key == 'l' && RcsLrMode() == ' ') RcsLrMode('L');
    if (key == 'l' && RcsLrMode() == 'R') RcsLrMode(' ');
    if (key == 'r' && RcsLrMode() == ' ') RcsLrMode('R');
    if (key == 'r' && RcsLrMode() == 'L') RcsLrMode(' ');
    if (key == 'd' && RcsUdMode() == ' ') RcsUdMode('D');
    if (key == 'd' && RcsUdMode() == 'U') RcsUdMode(' ');
    if (key == 'u' && RcsUdMode() == ' ') RcsUdMode('U');
    if (key == 'u' && RcsUdMode() == 'D') RcsUdMode(' ');
    if (key == '=' && RcsThrottle() == 10) RcsThrottle(100);
    if (key == '=' && RcsThrottle() == 1) RcsThrottle(10);
    if (key == '-' && RcsThrottle() == 10) RcsThrottle(1);
    if (key == '-' && RcsThrottle() == 100) RcsThrottle(10);

    if (key == '+' && RcsRotThrottle() == 50) RcsRotThrottle(100);
    if (key == '+' && RcsRotThrottle() == 10) RcsRotThrottle(50);
    if (key == '_' && RcsRotThrottle() == 50) RcsRotThrottle(10);
    if (key == '_' && RcsRotThrottle() == 100) RcsRotThrottle(50);
    if (key == 'I' && Throttle() == 0 && !landed) {
      Throttle(10);
      clockBu = 0;
      ignitionAltitude = altitude;
      ignitionTime = clockMi;
      numBurns++;
      burn[numBurns-1].start = clockMi;
      if (descentJettisoned) {
        burn[numBurns-1].fuelUsed = ascentFuel;
        burn[numBurns-1].engine = 'A';
        }
      else {
        burn[numBurns-1].fuelUsed = descentFuel;
        burn[numBurns-1].engine = 'D';
        }
      }
    if (key == 'i' && Throttle() > 0) { 
      Throttle(0);
      burn[numBurns-1].end = clockMi;
      if (descentJettisoned)
        burn[numBurns-1].fuelUsed -= ascentFuel;
      else
        burn[numBurns-1].fuelUsed -= descentFuel;
      if (!descentJettisoned) {
        if (ignitionAltitude > 50000 && ins->Perilune()-GROUND < 50000)
          clockDOI = ignitionTime;
        }
      }
    if (key == 'K') seq->Kill();
    if (key == 9) {
      if (mode_arm != 0) mode_arm = 0;
      else if (!descentJettisoned) mode_arm = 0xff;
      }
    if (key == KEY_KP_HOME) RollRate(RollRate()+(rcsRotThrottle / 100.0));
    if (key == KEY_HOME) RollRate(RollRate()+(rcsRotThrottle / 100.0));
    if (key == KEY_PGUP) RollRate(RollRate()-(rcsRotThrottle / 100.0));
    if (key == KEY_UP_ARROW) PitchRate(PitchRate()+(rcsRotThrottle / 100.0));
    if (key == KEY_DOWN_ARROW) PitchRate(PitchRate()-(rcsRotThrottle / 100.0));
    if (key == KEY_RIGHT_ARROW) YawRate(YawRate()+(rcsRotThrottle / 100.0));
    if (key == KEY_LEFT_ARROW) YawRate(YawRate()-(rcsRotThrottle / 100.0));
    if (Throttle() > 0 && !descentJettisoned) {
      if (key == KEY_PGDN) Throttle(Throttle()+2);
      if (key == KEY_END) Throttle(Throttle()-2);
      if (key == KEY_KP_END) Throttle(Throttle()-2);
      if (key == KEY_F1) Throttle(10);
      if (key == KEY_F2) Throttle(20);
      if (key == KEY_F3) Throttle(30);
      if (key == KEY_F4) Throttle(40);
      if (key == KEY_F5) Throttle(50);
      if (key == KEY_F6) Throttle(60);
      if (key == KEY_F7) Throttle(70);
      if (key == KEY_F8) Throttle(80);
      if (key == KEY_F9) Throttle(90);
      if (key == KEY_F10) Throttle(100);
      }
    }
  panel->ProcessKey(key);
  if (comp != NULL) comp->ProcessKey(key);
  }


