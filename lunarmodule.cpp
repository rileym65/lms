#include "header.h"
#include "lunarmodule.h"
#include "terminal.h"

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

Int8   LunarModule::RcsThrottle() {
  return rcsThrottle;
  }

Int8   LunarModule::RcsThrottle(Int8 i) {
  rcsThrottle = i;
  return rcsThrottle;
  }

Double LunarModule::AscentFuel() {
  return ascentFuel;
  }

Double LunarModule::AscentFuel(Double d) {
  ascentFuel = d;
  return ascentFuel;
  }

Double LunarModule::Battery() {
  return battery;
  }

Double LunarModule::Battery(Double d) {
  battery = d;
  if (battery < 0) battery = 0;
  return battery;
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

Double LunarModule::Oxygen() {
  return oxygen;
  }

Double LunarModule::Oxygen(Double d) {
  oxygen = d;
  if (oxygen < 0) oxygen = 0;
  return oxygen;
  }

Double LunarModule::PitchRate() {
  return pitchRate;
  }

Double LunarModule::PitchRate(Double d) {
  pitchRate = d;
  pitchMatrix = Matrix::RotateY(-pitchRate);
  return pitchRate;
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

Double LunarModule::RollRate() {
  return rollRate;
  }

Double LunarModule::RollRate(Double d) {
  rollRate = d;
  rollMatrix = Matrix::RotateZ(-rollRate);
  return rollRate;
  }

Double LunarModule::YawRate() {
  return yawRate;
  }

Double LunarModule::YawRate(Double d) {
  yawRate = d;
  yawMatrix = Matrix::RotateX(yawRate);
  return yawRate;
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
  Vector v;
  Matrix m;
  if (landed && !descentJettisoned) return;
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
    thrust = thrust + (faceFront.Neg().Scale(rcsThrust));
    rcsFuel -= rcsfuel;
    }
  if (rcsFbMode == 'B' && rcsfuel <= rcsFuel) {
    thrust = thrust + (faceFront.Scale(rcsThrust));
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
  if (radius <= GROUND && !landed) {
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
    }
  }

void LunarModule::Save(FILE* file) {
  fprintf(file,"LunarModule {%s",LE);
  Vehicle::Save(file);
  fprintf(file,"  RcsFbMode %d%s",rcsFbMode,LE);
  fprintf(file,"  RcsLrMode %d%s",rcsLrMode,LE);
  fprintf(file,"  RcsUdMode %d%s",rcsUdMode,LE);
  fprintf(file,"  RcsThrottle %d%s",rcsThrottle,LE);
  fprintf(file,"  AscentFuel %.18f%s",ascentFuel,LE);
  fprintf(file,"  Battery %.18f%s",battery,LE);
  fprintf(file,"  DescentFuel %.18f%s",descentFuel,LE);
  fprintf(file,"  Oxygen %.18f%s",oxygen,LE);
  fprintf(file,"  PitchRate %.18f%s",pitchRate,LE);
  fprintf(file,"  RcsFuel %.18f%s",rcsFuel,LE);
  fprintf(file,"  RollRate %.18f%s",rollRate,LE);
  fprintf(file,"  YawRate %.18f%s",yawRate,LE);
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
  else if (startsWith(pline,"rcsthrottle ")) rcsThrottle = atoi(nw(pline));
  else if (startsWith(pline,"ascentfuel ")) ascentFuel = atof(nw(pline));
  else if (startsWith(pline,"battery ")) battery = atof(nw(pline));
  else if (startsWith(pline,"descentfuel ")) descentFuel = atof(nw(pline));
  else if (startsWith(pline,"oxygen ")) oxygen = atof(nw(pline));
  else if (startsWith(pline,"pitchrate ")) PitchRate(atof(nw(pline)));
  else if (startsWith(pline,"rcsfuel ")) rcsFuel = atof(nw(pline));
  else if (startsWith(pline,"rollrate ")) RollRate(atof(nw(pline)));
  else if (startsWith(pline,"yawrate ")) YawRate(atof(nw(pline)));
  else if (startsWith(pline,"landed ")) landed = atoi(nw(pline));
  else if (startsWith(pline,"descentjettisoned ")) descentJettisoned = atoi(nw(pline));
  else if (startsWith(pline,"rock ")) rock = atoi(nw(pline));
  else if (startsWith(pline,"value ")) value = atof(nw(pline));
  else return 0;
  return -1;
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
  if (key == '?') dsnOn = (dsnOn) ? 0 : -1;
  if (key == '>') dockingRadarOn = (dockingRadarOn) ? 0 : -1;
  if (key == '<') landingRadarOn = (landingRadarOn) ? 0 : -1;
  if (landed) {
    if (key == '*') seq->Rest();
    if (key == ')') seq->Sleep();
    if (key == 'L') {
      landed = 0;
      descentJettisoned = -1;
      throttle = 100;
      clockBu = 0;
      descentFuel = 0;
      if (oxygen > 36000) oxygen = 36000;
      if (battery > 36000) battery = 36000;
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
    if (key == 'I' && Throttle() == 0) {
      Throttle(10);
      clockBu = 0;
      }
    if (key == 'i') Throttle(0);
    if (key == KEY_KP_HOME) RollRate(RollRate()+1);
    if (key == KEY_HOME) RollRate(RollRate()+1);
    if (key == KEY_PGUP) RollRate(RollRate()-1);
    if (key == KEY_UP_ARROW) PitchRate(PitchRate()+1);
    if (key == KEY_DOWN_ARROW) PitchRate(PitchRate()-1);
    if (key == KEY_RIGHT_ARROW) YawRate(YawRate()+1);
    if (key == KEY_LEFT_ARROW) YawRate(YawRate()-1);
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
  }


