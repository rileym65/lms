#define MAIN

#include "header.h"
#include "computer.h"
#include "g_clockbu.h"
#include "g_clockev.h"
#include "g_clockmi.h"
#include "g_clocktb.h"
#include "g_clockte.h"
#include "g_clockut.h"
#include "g_days.h"
#include "g_moon.h"
#include "g_position.h"
#include "mission.h"
#include "common.h"
#include "csmcomputer.h"

double mn,mx;

void mercuryRedstone() {
  booster->NumStages(1);
  booster->DryWeight(1, 6178);
  booster->Fuel(1, 23821);
  booster->Payload(1400);
  booster->Stage(1);
  booster->NumEngines(1, 1);
  booster->IspVac(1, 1, 215);
  booster->IspSl(1, 1, 215);
  booster->ThrustVac(1, 1, 350000);
  booster->ThrustSl(1, 1, 350000);
  booster->Starts(1,1);
  booster->Diameter(1,1.78);
  booster->Height(25.41);
  booster->CmOffset(2.15);
  booster->MaxFuel(1, booster->Fuel(1));
  csm->DryWeight(1341);
  csm->Diameter(1.78);
  csm->ParachuteDiameter(19.2);
  csm->RetroModuleDryWeight(32);
  csm->RetroModuleFuel(60);
  csm->RetroModuleIsp(230);
  csm->RetroModuleThrust(4450);
  csm->CommandModuleRcsFuel(25);
  csm->CommandModuleRcsIsp(167);
  csm->CommandModuleRcsThrust(107);
  csm->Oxygen(36 * 3600);
  csm->Battery(36 * 3600);
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void mercuryAtlas() {
  booster->NumStages(2);
  booster->Payload(1400);
  booster->Stage(1);
  booster->Height(28.7);
  booster->CmOffset(2.15);
  booster->Diameter(1,1.78);
  booster->DryWeight(1, 3050);
  booster->Fuel(1, 90923);
  booster->NumEngines(1, 3);
  booster->IspVac(1, 1, 309);
  booster->IspVac(1, 2, 282);
  booster->IspVac(1, 3, 282);
  booster->IspSl(1, 1, 215);
  booster->IspSl(1, 2, 248);
  booster->IspSl(1, 3, 248);
  booster->ThrustVac(1, 1, 363220);
  booster->ThrustVac(1, 2, 758700);
  booster->ThrustVac(1, 3, 758700);
  booster->ThrustSl(1, 1, 252700);
  booster->ThrustSl(1, 2, 667200);
  booster->ThrustSl(1, 3, 667200);
  booster->Starts(1,1);

  booster->Diameter(2,1.78);
  booster->DryWeight(2, 2347);
  booster->Fuel(2, 19780);
  booster->NumEngines(2, 1);
  booster->IspVac(2, 1, 309);
  booster->IspSl(2, 1, 215);
  booster->ThrustVac(2, 1, 363220);
  booster->ThrustSl(2, 1, 252700);
  booster->Starts(2,1);

  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  csm->DryWeight(1341);
  csm->Diameter(1.78);
  csm->ParachuteDiameter(19.2);
  csm->RetroModuleDryWeight(32);
//  csm->RetroModuleFuel(205);
  csm->RetroModuleFuel(60);
  csm->RetroModuleIsp(230);
  csm->RetroModuleThrust(4450);
  csm->CommandModuleRcsFuel(25);
  csm->CommandModuleRcsIsp(167);
  csm->CommandModuleRcsThrust(107);
  csm->Oxygen(36 * 3600);
  csm->Battery(36 * 3600);
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void geminiTitan() {
  booster->Height(33.2);
  booster->CmOffset(4);
  booster->NumStages(2);
  booster->DryWeight(1, 8532);
  booster->DryWeight(2, 1870);
  booster->Fuel(1, 117950);
  booster->Fuel(2, 25847);
  booster->Payload(3790);
  booster->Stage(1);
  booster->NumEngines(1, 1);
  booster->NumEngines(2, 1);
  booster->IspSl(1, 1, 258);
  booster->IspVac(1, 1, 296);
  booster->IspSl(2, 1, 160);
  booster->IspVac(2, 1, 316);
  booster->ThrustVac(1, 1, 1913000);
  booster->ThrustVac(2, 1, 445000);
  booster->ThrustSl(1, 1, 1913000);
  booster->ThrustSl(2, 1, 445000);
  booster->Starts(1,1);
  booster->Starts(2,1);
  booster->Diameter(1, 3.05);
  booster->Diameter(2, 3.05);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  csm->DryWeight(1949);
  csm->Diameter(2.30);
  csm->ParachuteDiameter(25.66);
  csm->ServiceModuleDryWeight(956);
  csm->ServiceModuleFuel(0);
  csm->ServiceModuleIsp(230);
  csm->ServiceModuleThrust(710);
  csm->ServiceModuleRcsIsp(273);
  csm->ServiceModuleRcsThrust(444);
  csm->ServiceModuleRcsDThrust(756);
  csm->ServiceModuleRcsUThrust(888);
  csm->ServiceModuleRcsFuel(322);
  csm->RetroModuleDryWeight(491);
  csm->RetroModuleFuel(100);
  csm->RetroModuleIsp(255);
  csm->RetroModuleThrust(11120);
  csm->CommandModuleRcsFuel(33);
  csm->CommandModuleRcsIsp(283);
  csm->CommandModuleRcsThrust(111);
  csm->Oxygen(14 * 24 * 3600);
  csm->Battery(14 * 24 * 3600);
  csm->ServiceModuleMaxFuel(csm->ServiceModuleFuel());
  csm->ServiceModuleRcsMaxFuel(csm->ServiceModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void saturn1B() {
  booster->Height(43.2);
  booster->CmOffset(17.25);
  booster->NumStages(2);
  booster->DryWeight(1, 42000);
  booster->DryWeight(2, 10600);
  booster->Fuel(1, 399400);
  booster->Fuel(2, 103600);
  booster->Payload(18000);
  booster->Stage(1);
  booster->NumEngines(1, 8);
  booster->NumEngines(2, 1);
  booster->IspSl(1, 1, 255);
  booster->IspSl(1, 2, 255);
  booster->IspSl(1, 3, 255);
  booster->IspSl(1, 4, 255);
  booster->IspSl(1, 5, 255);
  booster->IspSl(1, 6, 255);
  booster->IspSl(1, 7, 255);
  booster->IspSl(1, 8, 255);
  booster->IspVac(1, 1, 289);
  booster->IspVac(1, 2, 289);
  booster->IspVac(1, 3, 289);
  booster->IspVac(1, 4, 289);
  booster->IspVac(1, 5, 289);
  booster->IspVac(1, 6, 289);
  booster->IspVac(1, 7, 289);
  booster->IspVac(1, 8, 289);
  booster->IspSl(2, 1, 200);
  booster->IspVac(2, 1, 420);
  booster->ThrustVac(1, 1, 900000);
  booster->ThrustVac(1, 2, 900000);
  booster->ThrustVac(1, 3, 900000);
  booster->ThrustVac(1, 4, 900000);
  booster->ThrustVac(1, 5, 900000);
  booster->ThrustVac(1, 6, 900000);
  booster->ThrustVac(1, 7, 900000);
  booster->ThrustVac(1, 8, 900000);
  booster->ThrustVac(2, 1, 890000);
  booster->ThrustSl(1, 1, 900000);
  booster->ThrustSl(1, 2, 900000);
  booster->ThrustSl(1, 3, 900000);
  booster->ThrustSl(1, 4, 900000);
  booster->ThrustSl(1, 5, 900000);
  booster->ThrustSl(1, 6, 900000);
  booster->ThrustSl(1, 7, 900000);
  booster->ThrustSl(1, 8, 900000);
  booster->ThrustSl(2, 1, 445000);
  booster->Starts(1,1);
  booster->Starts(2,1);
  booster->Diameter(1, 6.53);
  booster->Diameter(2, 6.53);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  csm->DryWeight(5806);
  csm->Diameter(3.90);
  csm->ParachuteDiameter(42.26);
  csm->ServiceModuleDryWeight(6110);
  csm->ServiceModuleFuel(18413);
  csm->ServiceModuleIsp(314);
  csm->ServiceModuleThrust(91190);
  csm->ServiceModuleRcsIsp(290);
  csm->ServiceModuleRcsFuel(617.79);
  csm->ServiceModuleRcsThrust(890);
  csm->ServiceModuleRcsDThrust(1780);
  csm->ServiceModuleRcsUThrust(1780);
  csm->CommandModuleRcsFuel(74);
  csm->CommandModuleRcsIsp(290);
  csm->CommandModuleRcsThrust(410);
  csm->Oxygen(14 * 24 * 3600);
  csm->Battery(14 * 24 * 3600);
  csm->ServiceModuleMaxFuel(csm->ServiceModuleFuel());
  csm->ServiceModuleRcsMaxFuel(csm->ServiceModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void saturnV(UInt8 lem) {
  Double pl;
  pl = 30364;
  switch (lem) {
    case      VEHICLE_APOLLO: pl += 15122; break;
    case    VEHICLE_APOLLO_J: pl += 16411; break;
    case VEHICLE_APOLLO_MKII: pl += 17231; break;
    }
  if (lem != 0) {
    lm = new LunarModule();
    lm->Comp(new Computer(lm));
    }
  booster->Height(85.9);
  booster->CmOffset(17.25);
  booster->NumStages(3);
  booster->DryWeight(1, 130342 + 2447 + 4524);
  booster->DryWeight(2, 36479 + 423 + 3637);
  booster->DryWeight(3, 11357 + 752 + 2027 + 1796);
  booster->Fuel(1, 649508 + 1503381);
  booster->Fuel(2, 382874 + 72779);
  booster->Fuel(3, 19845 + 88738);
  booster->Payload(pl);
  booster->Stage(1);
  booster->NumEngines(1, 5);
  booster->NumEngines(2, 5);
  booster->NumEngines(3, 1);
  booster->IspVac(1, 1, 304);
  booster->IspVac(1, 2, 304);
  booster->IspVac(1, 3, 304);
  booster->IspVac(1, 4, 304);
  booster->IspVac(1, 5, 304);
  booster->IspVac(2, 1, 421);
  booster->IspVac(2, 2, 421);
  booster->IspVac(2, 3, 421);
  booster->IspVac(2, 4, 421);
  booster->IspVac(2, 5, 421);
  booster->IspVac(3, 1, 421);
  booster->IspSl(1, 1, 263);
  booster->IspSl(1, 2, 263);
  booster->IspSl(1, 3, 263);
  booster->IspSl(1, 4, 263);
  booster->IspSl(1, 5, 263);
  booster->IspSl(2, 1, 200);
  booster->IspSl(2, 2, 200);
  booster->IspSl(2, 3, 200);
  booster->IspSl(2, 4, 200);
  booster->IspSl(2, 5, 200);
  booster->IspSl(3, 1, 200);
  booster->ThrustVac(1, 1, 7770000);
  booster->ThrustVac(1, 2, 7770000);
  booster->ThrustVac(1, 3, 7770000);
  booster->ThrustVac(1, 4, 7770000);
  booster->ThrustVac(1, 5, 7770000);
  booster->ThrustVac(2, 1, 1033100);
  booster->ThrustVac(2, 2, 1033100);
  booster->ThrustVac(2, 3, 1033100);
  booster->ThrustVac(2, 4, 1033100);
  booster->ThrustVac(2, 5, 1033100);
  booster->ThrustVac(3, 1, 1033100);
  booster->ThrustSl(1, 1, 6770000);
  booster->ThrustSl(1, 2, 6770000);
  booster->ThrustSl(1, 3, 6770000);
  booster->ThrustSl(1, 4, 6770000);
  booster->ThrustSl(1, 5, 6770000);
  booster->ThrustSl(2, 1, 486200);
  booster->ThrustSl(2, 2, 486200);
  booster->ThrustSl(2, 3, 486200);
  booster->ThrustSl(2, 4, 486200);
  booster->ThrustSl(2, 5, 486200);
  booster->ThrustSl(3, 1, 486200);
  booster->Starts(1,1);
  booster->Starts(2,1);
  booster->Starts(3,2);
  booster->Ceco(1, 139);
  booster->Ceco(2, 297);
  booster->Diameter(1, 10.1);
  booster->Diameter(2, 10.1);
  booster->Diameter(3, 6.6);
  booster->MaxFuel(1, booster->Fuel(1));
  booster->MaxFuel(2, booster->Fuel(2));
  booster->MaxFuel(3, booster->Fuel(3));
  csm->DryWeight(5806);
  csm->Diameter(3.90);
  csm->ParachuteDiameter(42.26);
  csm->ServiceModuleDryWeight(6110);
  csm->ServiceModuleFuel(18413);
  csm->ServiceModuleIsp(314);
  csm->ServiceModuleRcsFuel(617.79);
  csm->ServiceModuleThrust(91190);
  csm->ServiceModuleRcsIsp(290);
  csm->ServiceModuleRcsThrust(890);
  csm->ServiceModuleRcsDThrust(1780);
  csm->ServiceModuleRcsUThrust(1780);
  csm->CommandModuleRcsFuel(74);
  csm->CommandModuleRcsIsp(290);
  csm->CommandModuleRcsThrust(410);
  csm->Oxygen(14 * 24 * 3600);
  csm->Battery(14 * 24 * 3600);
  csm->ServiceModuleMaxFuel(csm->ServiceModuleFuel());
  csm->ServiceModuleRcsMaxFuel(csm->ServiceModuleRcsFuel());
  csm->RetroModuleMaxFuel(csm->RetroModuleFuel());
  csm->CommandModuleRcsMaxFuel(csm->CommandModuleRcsFuel());
  csm->MaxOxygen(csm->Oxygen());
  csm->MaxBattery(csm->Battery());
  }

void init(Byte v) {
  Double dry;
  cabinPressurized = -1;
  clockBu = 0;
  clockBsp = 0;
  clockDk = 0;
  clockEv = 0;
  clockGe = 0;
  clockMi = 0;
  clockOr = 0;
  clockPara = 0;
  clockUt = (8 * 3600) + (30 * 60);
  clockUd = 0;
  clockMaxQ = 0;
  clockSmJt = 0;
  clockRent = 0;
  clockRmJt = 0;
  clockTb = 0;
  clockTe = 0;
  clockLo = 0;
  clockTli = 0;
  clockTei = 0;
  clockLoi = 0;
  clockMSoi = 0;
  clockESoi = 0;
  clockLmDk = 0;
  clockLExt = 0;
  clockLmJt = 0;
  ignitionApoapsis = 0;
  ignitionPeriapsis = 0;
  ignitionEccentricity = 0;
  lmExtracted = 0;
  evaCount = 0;
  longestEVA = 0;
  docked = 0;
  dockingRadarOn = 0;
  dsnOn = 0;
  efficiency = 99;
  farthestFromEarth = 0;
  highestVelocity = 0;
  inAtmosphere = 0xff;
  injury = 0;
  landingRadarOn = 0;
  maxQ = 0;
  metabolicRate = 30.0;
  numSamples = 0;
  mission->TargetLatitude(0.0);
  mission->TargetLongitude(0.0);
  plssOn = 0;
  plssPacks = 4;
  spaceSuitOn = 0;
  sampleSmallRock = 0;
  sampleMediumRock = 0;
  sampleLargeRock = 0;
  sampleSmallCrater = 0;
  sampleMediumCrater = 0;
  sampleLargeCrater = 0;
  samplePlains = 0;
  sampleRise = 0;
  sampleCraterWall = 0;
  lrvSampleSmallRock = 0;
  lrvSampleMediumRock = 0;
  lrvSampleLargeRock = 0;
  lrvSampleSmallCrater = 0;
  lrvSampleMediumCrater = 0;
  lrvSampleLargeCrater = 0;
  lrvSamplePlains = 0;
  lrvSampleRise = 0;
  lrvSampleSpecial = 0;
  lrvSampleDepression = 0;
  lrvSampleCraterWall = 0;
  cartSampleSmallRock = 0;
  cartSampleMediumRock = 0;
  cartSampleLargeRock = 0;
  cartSampleSmallCrater = 0;
  cartSampleMediumCrater = 0;
  cartSampleLargeCrater = 0;
  cartSamplePlains = 0;
  cartSampleRise = 0;
  cartSampleSpecial = 0;
  cartSampleDepression = 0;
  cartSampleCraterWall = 0;
  landedMet = 0;
  liftoffMet = 0;
  landedLongitude = 0;
  landedLatitude = 0;
  farthest = 0;
  flagPlanted = 0;
  flagLongitude = 0;
  flagLatitude = 0;
  alsepSetup = 0;
  alsepLongitude = 0;
  alsepLatitude = 0;
  landedHVel = 0;
  landedVVel = 0;
  evas[0].start = 0;
  clockDOI = 0;
  clockPDI = 0;
  numBurns = 0;
  laserSetup = 0;
  laserLongitude = 0;
  laserLatitude = 0;
  mode_abo = 0;
  mode_arm = 0;
  mode_jet = 0;
  mode_kil = 0;
  mode_lif = 0;
  days = 0;
  engines = 0;
  launched = false;
  kscAngle = 0;
  distanceTravelled = 0;
  if (v == 1) mercuryRedstone();
  if (v == 2) mercuryAtlas();
  if (v == 3) geminiTitan();
  if (v == 4) saturn1B();
  if (v == 5) saturnV(0);
  if (v == 6) saturnV(VEHICLE_APOLLO);
  if (v == 7) saturnV(VEHICLE_APOLLO_J);
  if (v == 8) saturnV(VEHICLE_APOLLO_MKII);
  pilotLocation = PILOT_CSM;
  csm->TargetVehicle(lm);
  if (lm != NULL) {
    dry = mission->Model()->DescentEmptyWeight();
    if (mission->Laser() != 0) dry += LASER_WEIGHT;
    if (mission->Lsep() == 1) dry += ELSEP_WEIGHT;
    if (mission->Lsep() == 2) dry += ALSEP_WEIGHT;
    if (mission->Rover() == 1) dry += ROVER_MKI_WEIGHT;
    if (mission->Rover() == 2) dry += ROVER_MKII_WEIGHT;
    if (mission->Rover() == 3) dry += ROVER_MKIII_WEIGHT;
    dry += (mission->Consumables() / 3600.0 * 0.060666);
    dry += (mission->Consumables() / 3600.0 * 0.308333);
    dry += (mission->Consumables() / 3600.0 * 0.205833);
    lm->Orbiting(Earth);
    lm->RcsFbMode(' ');
    lm->RcsLrMode(' ');
    lm->RcsUdMode(' ');
    lm->RcsThrottle(1);
    lm->AscentFuel(mission->Model()->AscentFuel());
    lm->AscentDryWeight(mission->Model()->AscentEmptyWeight());
    lm->AscentIsp(mission->Model()->AscentIsp());
    lm->AscentNewtons(mission->Model()->AscentThrust());
    lm->DescentFuel(mission->Model()->DescentFuel());
    lm->DescentBattery(mission->Model()->Consumables());
    lm->DescentOxygen(mission->Model()->Consumables());
    lm->DescentDryWeight(dry);
    lm->DescentIsp(mission->Model()->DescentIsp());
    lm->DescentNewtons(mission->Model()->DescentThrust());
    lm->RcsFuel(mission->Model()->RcsFuel());
    lm->RcsIsp(mission->Model()->RcsIsp());
    lm->RcsNewtons(mission->Model()->RcsThrust());
    lm->AscentBattery(mission->Model()->AscentConsumables());
    lm->AscentOxygen(mission->Model()->AscentConsumables());
    lm->AscentEBattery(mission->Model()->AscentEConsumables());
    lm->AscentEOxygen(mission->Model()->AscentEConsumables());
    lm->DescentEBattery(mission->Model()->EConsumables());
    lm->DescentEOxygen(mission->Model()->EConsumables());
    lm->MaxAscentFuel(lm->AscentFuel());
    lm->MaxDescentFuel(lm->DescentFuel());
    lm->MaxRcsFuel(lm->RcsFuel());
    lm->MaxBattery(lm->AscentBattery() + lm->DescentBattery());
    lm->MaxOxygen(lm->AscentOxygen() + lm->DescentOxygen());
    lm->MaxAscentBattery(lm->AscentBattery());
    lm->MaxAscentEBattery(lm->AscentEBattery());
    lm->MaxAscentOxygen(lm->AscentOxygen());
    lm->MaxAscentEOxygen(lm->AscentEOxygen());
    lm->MaxDescentBattery(lm->DescentBattery());
    lm->MaxDescentEBattery(lm->DescentEBattery());
    lm->MaxDescentOxygen(lm->DescentOxygen());
    lm->MaxDescentEOxygen(lm->DescentEOxygen());
    lm->MaxBattery(lm->MaxAscentBattery() + lm->MaxDescentBattery());
    lm->MaxBattery(lm->MaxAscentOxygen() + lm->MaxDescentOxygen());
    lm->TargetVehicle(csm);
    }
  }

Int8 alignedForDocking() {
  Vector pos;
  Vector vel;
  Double px,py;
  if (lm == NULL) return 0;
  if (csm->FaceUp().Dot(lm->FaceUp()) >= 0) return 0;
  if (fabs(csm->FaceFront().Dot(lm->FaceUp())) > 0.150) return 0;
  if (fabs(csm->FaceLeft().Dot(lm->FaceUp())) > 0.150) return 0;
  if (fabs(csm->FaceFront().Dot(lm->FaceLeft())) > 0.150) return 0;
  pos = csm->Position() - lm->Position();
  px = pos.Norm().Dot(lm->FaceLeft()) * pos.Length();
  py = pos.Norm().Dot(lm->FaceFront()) * pos.Length();
  if (fabs(px) > 0.5) return 0;
  if (fabs(py) > 0.5) return 0;
  vel = csm->Velocity() - lm->Velocity();
  if (vel.Length() < 0.2) return 0;
  if (vel.Length() > 0.4) return 0;
  return -1;

  }

void cycle() {
  UInt32 i;
  Vector vu;
  Vector vl;
  Vector vf;
  Vector p,v;
  Double r1;
  Double r2;
  Vector p1,p2;
  clockUt++;
  if (clockUt >= 86400) {
    clockUt = 0;
    days++;
    }
  kscAngle += 0.00417807464;
  if (kscAngle >= 180) kscAngle -= 360;
  if (!launched) {
    Moon->Cycle(1);
    pos = Vector(sin(kscAngle*DR)*0.878817113,
                -cos(kscAngle*DR)*0.878817113, 0.477158760).Norm();
    pos = pos.Scale(6378100);
    vu = booster->Position().Norm();
    vf = Vector(-vu.Y(), vu.X(), 0).Norm();
    vl = vf.Cross(vu);
    booster->FaceUp(vu);
    booster->FaceLeft(vl);
    booster->FaceFront(vf);
    booster->Position(pos);
    csm->Position(booster->Position()+booster->FaceUp().Scale(booster->Height() + booster->CmOffset()));
    csm->FaceUp(booster->FaceUp());
    csm->FaceLeft(booster->FaceLeft());
    csm->FaceFront(booster->FaceFront());
    if (lm != NULL) {
      lm->Position(booster->Position()+booster->FaceUp().Scale(booster->Height()));
      lm->FaceUp(booster->FaceUp());
      lm->FaceLeft(booster->FaceLeft());
      lm->FaceFront(booster->FaceFront());
      }
    booster->Ins();
    csm->Ins();
    csm->UpdatePanel();
    }
  else {
    clockGe++;
    if (pilotLocation == PILOT_LM && !docked) clockMi++;
    if (csm->UseOxygen(1) == false) {
      GotoXY(1,25);
      printf("Astronauts died due to lack of oxygen\n");
      ShowCursor();
      CloseTerminal();
      exit(0);
      }
    if (csm->UseBattery(1) == false) {
      GotoXY(1,25);
      printf("Astronauts died due to lack of power\n");
      ShowCursor();
      CloseTerminal();
      exit(0);
      }
    if (currentVehicle->Throttle() != 0) {
      clockBu++;
      clockTb++;
      }
    r1 = (csm->Position() - csm->Orbiting()->Position()).Length();
    p1 = csm->Position();
    for (i=0; i<GRAN; i++) {
      Moon->Cycle(GRAN);
      if (!booster->Destroyed()) {
        if (lmExtracted == 0 && docked) {
          }
        else booster->Cycle();
        }
      csm->Cycle();
      if (lm != NULL) {
        if (docked) {
          lm->Position(csm->Position()+csm->FaceUp().Scale(5.275));
          lm->Velocity(csm->Velocity());
          lm->FaceUp(csm->FaceUp().Neg());
          lm->FaceLeft(csm->FaceLeft().Neg());
          lm->FaceFront(csm->FaceFront());
          lm->Latitude(csm->Latitude());
          lm->Longitude(csm->Longitude());
          lm->Orbiting(csm->Orbiting());
          }
        else if (lmExtracted == 0) {
          lm->Position(booster->Position()+booster->FaceUp().Scale(booster->Height()+3.5));
          lm->Velocity(booster->Velocity());
          lm->FaceUp(booster->FaceUp());
          lm->FaceLeft(booster->FaceLeft());
          lm->FaceFront(booster->FaceFront());
          lm->Latitude(booster->Latitude());
          lm->Longitude(booster->Longitude());
          lm->Orbiting(booster->Orbiting());
          }
        else lm->Cycle();
        }
      csm->Computer()->Cycle();
      if (csm->Radius() <= csm->Orbiting()->Radius()) {
        if (csm->RateOfClimb() <= -11) {
          GotoXY(1,25);
          printf("Vehicle destroyed due to high velocity impact\n");
          ShowCursor();
          CloseTerminal();
          exit(0);
          }
        else {
          GotoXY(1,25);
          printf("Vehicle has safely landed%s",LE);
          printf("Total distance travelled: %.3fkm%s",distanceTravelled/1000.0,LE);
          endReason = END_MISSION;
          return;
          }
        }

      }
    if (!booster->Destroyed()) booster->Ins();
    csm->Ins();
    seq->Cycle();
    if (lm != NULL) {
      lm->Ins();
      if (lm->Comp() != NULL) lm->Comp()->Cycle();
      }
    if (!docked && lm != NULL) {
      if ((csm->Position() - lm->Position()).Length() < 5.275) {
        if (alignedForDocking()) {
          docked = -1;
          seq->Dock();
          if (currentVehicle == csm && clockLmDk == 0)
            clockLmDk = clockGe;
          }
        else {
          v = csm->Velocity() - csm->TargetVehicle()->Velocity();
          csm->Velocity(csm->Velocity() - v);
          csm->Velocity(csm->Velocity() - v.Scale(0.5));
          lm->Velocity(lm->Velocity() + v.Scale(0.5));
          csm->Position(csm->Position() - v);
          lm->Position(lm->Position() + v);
          if (lmExtracted == 0) {
            booster->Velocity(booster->Velocity() + v.Scale(0.5));
            booster->Position(booster->Position() + v);
            }
          }
        }
      }
    
 
    r2 = (csm->Position() - csm->Orbiting()->Position()).Length();
    p2 = csm->Position();
    distanceTravelled += (p1 - p2).Length();
GotoXY(1,25); printf("distance: %.2fkm\n",distanceTravelled/1000.0);
    csm->RateOfClimb(r2-r1);
    if (metabolicRate > 99) metabolicRate = 99;
    softInjury += 0.000347222;
    if (softInjury > 100) softInjury = 100;
    injury = softInjury + hardInjury;
    if (metabolicRate > 30.0) metabolicRate -= 0.1;
    if (metabolicRate < 30.0) metabolicRate = 30.0;
    efficiency = 99.0;
    if (metabolicRate < 40) efficiency -= (metabolicRate - 30) / 3;
    else if (metabolicRate < 50) efficiency -= (metabolicRate - 30) / 2;
    else if (metabolicRate < 60) efficiency -= (metabolicRate - 30);
    else efficiency -= ((metabolicRate - 30) * 1.5);
    efficiency -= (injury / 2.0);
    if (efficiency < 20) efficiency = 20;
    currentVehicle->UpdatePanel();
    }
  }

void Launch() {
  Vector vu;
  Vector vl;
  Vector vf;
  booster->Ignition();
  vu = booster->Position().Norm();
  vf = Vector(-vu.Y(), vu.X(), 0).Norm();
  vl = vf.Cross(vu);
  booster->FaceUp(vu);
  booster->FaceLeft(vl);
  booster->FaceFront(vf);
  booster->Velocity(vf.Scale(408));
  launched = true;
  clockLo = clockUt;
  }

int main(int argc, char** argv) {
  char buffer[32];
  UInt32 v;
  Boolean flag;
  UInt32  key;
  mission = NULL;
  Earth = new Body("Earth", 5.972e+24, 6378100);
  Moon = new Body("Moon", 7.34767309e+22, 1738300);
  Moon->Position(Vector(325266766, 0, 177193935));
  Moon->Velocity(Vector(0,1060,0));
  Moon->Orbiting(Earth);
  Moon->CalculateOrbit();
  booster = new Booster();
  csm = new CommandModule();
  csm->LaunchVehicle(booster);
  lm = NULL;
  lrv = NULL;
  plss = NULL;
  mission = new Mission();
  mission->TargetLatitude(0);
  mission->TargetLongitude(0);
  mission->Name((char*)"Default");
  seq = new Sequencer();
  map = new Map();
  if (load("fms.sav") == 0) {
    ClrScr();
    printf("1. Mercury/Redstone\n");
    printf("2. Mercury/Atlas\n");
    printf("3. Gemini/Titan\n");
    printf("4. Apollo/Saturn IB\n");
    printf("5. Apollo/Saturn V\n");
    printf("6. Apollo/LM/Saturn V\n");
    printf("7. Apollo/LM-J/Saturn V\n");
    printf("8. Apollo/LM-MkII/Saturn V\n");
    printf("   Vehicle: ");
    fgets(buffer,31,stdin);
    v = atoi(buffer);
    if (v == 6) mission->Vehicle(VEHICLE_APOLLO);
    if (v == 7) mission->Vehicle(VEHICLE_APOLLO_J);
    if (v == 8) mission->Vehicle(VEHICLE_APOLLO_MKII);
    init(v);
    }
  else {
printf("Done loading\n\n"); fflush(stdout);
    csm->TargetVehicle(lm);
    if (lm != NULL) lm->TargetVehicle(csm);
    }
  csm->Orbiting(Earth);
  csm->SetupPanel();
  booster->Orbiting(Earth);
  simSpeed = 100000;
  OpenTerminal();
  HideCursor();
  flag = true;
  currentVehicle = csm;
  ticks = 10;
  keyDelay = 0;
  endReason = 0;
  while (flag) {
    if (ticks >= 10) {
      ticks = 0;
      cycle();
      }
    else ticks++;
    usleep(simSpeed);
    if (KeyPressed()) {
      key = Inkey();
      if (key == '!') simSpeed = 100000;
      if (key == '@') simSpeed = 10000;
      if (key == '#') simSpeed = 1000;
      if (key == '$') simSpeed = 100;
      if (key == '%') simSpeed = 10;
      if (key == 'Q') {
        flag = false;
        endReason = END_QUIT;
        }
      if (key == 'I' && launched) booster->Ignition();
      if (key == 'L' && !launched) Launch();
      if (key == 'S' && launched) booster->NextStage();
      currentVehicle->ProcessKey(key);
      }
    if (endReason != 0) flag = false;
    }
  if (endReason == END_QUIT) save();
  if (endReason == END_MISSION) {
    MissionReport();
    unlink("fms.sav");
    }
  GotoXY(1,25);
  ShowCursor();
  CloseTerminal();
  return 0;
  }
