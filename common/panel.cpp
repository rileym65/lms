#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "panel.h"
#include "terminal.h"
#include "helpers.h"
#include "gauge.h"
#include "g_accel.h"
#include "g_altitude.h"
#include "g_amsatt.h"
#include "g_amsclocks.h"
#include "g_amscons.h"
#include "g_amsdock.h"
#include "g_amsdown.h"
#include "g_amsins.h"
#include "g_amsland.h"
#include "g_amslm.h"
#include "g_amslrv.h"
#include "g_amsmsg.h"
#include "g_amspilot.h"
#include "g_amsplss.h"
#include "g_amsseq.h"
#include "g_amsspin.h"
#include "g_amsstat.h"
#include "g_amswest.h"
#include "g_apoapsis.h"
#include "g_attitude.h"
#include "g_battery.h"
#include "g_clockbu.h"
#include "g_clockdk.h"
#include "g_clockev.h"
#include "g_clockge.h"
#include "g_clockmi.h"
#include "g_clockot.h"
#include "g_clocks.h"
#include "g_clocktb.h"
#include "g_clockte.h"
#include "g_clockut.h"
#include "g_computer.h"
#include "g_csmdock.h"
#include "g_csmcomputer.h"
#include "g_csmlamps.h"
#include "g_days.h"
#include "g_dec.h"
#include "g_docked.h"
#include "g_engines.h"
#include "g_evaprep.h"
#include "g_fuel.h"
#include "g_ground.h"
#include "g_groundins.h"
#include "g_incl.h"
#include "g_ins.h"
#include "g_lamps.h"
#include "g_lan.h"
#include "g_landed.h"
#include "g_lmfuel.h"
#include "g_lmrock.h"
#include "g_lrv.h"
#include "g_maplarge.h"
#include "g_mapmed.h"
#include "g_moon.h"
#include "g_multiaxis.h"
#include "g_orbit.h"
#include "g_orbitlarge.h"
#include "g_orbiting.h"
#include "g_oxybat.h"
#include "g_oxygen.h"
#include "g_periapsis.h"
#include "g_pilot.h"
#include "g_pilotloc.h"
#include "g_pitchrate.h"
#include "g_plss.h"
#include "g_position.h"
#include "g_precaxis.h"
#include "g_prograde.h"
#include "g_propellant.h"
#include "g_ra.h"
#include "g_radars.h"
#include "g_radial.h"
#include "g_rcs.h"
#include "g_roc.h"
#include "g_rollrate.h"
#include "g_seq.h"
#include "g_throttle.h"
#include "g_vehicle.h"
#include "g_velocity.h"
#include "g_yawrate.h"

Panel::Panel(const char* filename,Vehicle* v) {
  vehicle = v;
  clearPanel();
  if (loadFile(filename) == 0) useDefault(filename);
  }

Panel::~Panel() {
  UInt32 i;
  for (i=0; i<numGauges; i++) delete(gauges[i]);
  }

void Panel::clearPanel() {
  UInt8 x,y;
  for (y=0; y<24; y++)
    for (x=0; x<80; x++)
      screen[y][x] = ' ';
  for (y=0; y<24; y++)
    screen[y][80] = 0;
  for (x=0; x<100; x++)
    gauges[x] = NULL;
  numGauges = 0;
  }

void Panel::ResetPanel(const char* filename) {
  UInt32 i;
  for (i=0; i<numGauges; i++) delete(gauges[i]);
  clearPanel();
  if (loadFile(filename) == 0) useDefault(filename);
  }

Int8 Panel::loadFile(const char* filename) {
  Int32 x1,y1,x2,y2;
  FILE *file;
  char  line[1024];
  char  str[1024];
  if ((file = fopen(filename,"r")) == NULL) return 0;
  while (fgets(line,1024,file) != NULL) {
    if (line[0] == '#') {
      }
    else if (strncasecmp(line,"box ",4) == 0) {
      sscanf(nw(line),"%d,%d,%d,%d",&x1,&y1,&x2,&y2);
      Box(x1,y1,x2,y2);
      }
    else if (strncasecmp(line,"line ",5) == 0) {
      sscanf(nw(line),"%d,%d,%d,%d",&x1,&y1,&x2,&y2);
      if (x1 == x2) VLine(x1,y1,y2);
      else if (y1 == y2) HLine(x1,y1,x2);
      else {
        Write("Diagonal lines are not allowed: ");
        WriteLn(line);
        exit(1);
        }
      }
    else if (strncasecmp(line,"label ",6) == 0) {
      sscanf(nw(line),"%d,%d,\"%[^\"]",&x1,&y1,str);
      Label(x1,y1,str);
      }
    else if (strncasecmp(line,"gauge ",6) == 0) {
      sscanf(nw(line),"%s %d,%d",str,&x1,&y1);
      if (strcasecmp(str,"accel") == 0)
        addGauge(new G_Accel(x1, y1, false, vehicle));
      else if (strcasecmp(str,"altitude") == 0)
        addGauge(new G_Altitude(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_attitude") == 0)
        addGauge(new G_AmsAtt(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_clocks") == 0)
        addGauge(new G_AmsClocks(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_consumables") == 0)
        addGauge(new G_AmsCons(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_dockingradar") == 0)
        addGauge(new G_AmsDock(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_downaxis") == 0)
        addGauge(new G_AmsDown(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_ins") == 0)
        addGauge(new G_AmsIns(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_landingradar") == 0)
        addGauge(new G_AmsLand(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_lm") == 0)
        addGauge(new G_AmsLm(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_lrv") == 0)
        addGauge(new G_AmsLrv(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_message") == 0)
        addGauge(new G_AmsMessage(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_pilot") == 0)
        addGauge(new G_AmsPilot(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_plss") == 0)
        addGauge(new G_AmsPlss(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_sequencer") == 0)
        addGauge(new G_AmsSeq(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_spin") == 0)
        addGauge(new G_AmsSpin(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_status") == 0)
        addGauge(new G_AmsStatus(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ams_westaxis") == 0)
        addGauge(new G_AmsWest(x1, y1, false, vehicle));
      else if (strcasecmp(str,"apoapsis") == 0)
        addGauge(new G_Apoapsis(x1, y1, false, vehicle));
      else if (strcasecmp(str,"attitude") == 0)
        addGauge(new G_Attitude(x1, y1, false, vehicle));
      else if (strcasecmp(str,"battery") == 0)
        addGauge(new G_Battery(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockbu") == 0)
        addGauge(new G_ClockBU(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockdk") == 0)
        addGauge(new G_ClockDK(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockev") == 0)
        addGauge(new G_ClockEV(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockge") == 0)
        addGauge(new G_ClockGE(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockmi") == 0)
        addGauge(new G_ClockMI(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockot") == 0)
        addGauge(new G_ClockOT(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clocks") == 0)
        addGauge(new G_Clocks(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clocktb") == 0)
        addGauge(new G_ClockTB(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockte") == 0)
        addGauge(new G_ClockTE(x1, y1, false, vehicle));
      else if (strcasecmp(str,"clockut") == 0)
        addGauge(new G_ClockUT(x1, y1, false, vehicle));
      else if (strcasecmp(str,"computer") == 0)
        addGauge(new G_Computer(x1, y1, false, vehicle));
      else if (strcasecmp(str,"csmcomputer") == 0)
        addGauge(new G_CsmComputer(x1, y1, false, vehicle));
      else if (strcasecmp(str,"csmdock") == 0)
        addGauge(new G_CsmDock(x1, y1, false, vehicle));
      else if (strcasecmp(str,"csmlamps") == 0)
        addGauge(new G_CsmLamps(x1, y1, false, vehicle));
      else if (strcasecmp(str,"days") == 0)
        addGauge(new G_Days(x1, y1, false, vehicle));
      else if (strcasecmp(str,"declination") == 0)
        addGauge(new G_Declination(x1, y1, false, vehicle));
      else if (strcasecmp(str,"docked") == 0)
        addGauge(new G_Docked(x1, y1, false, vehicle));
      else if (strcasecmp(str,"engines") == 0)
        addGauge(new G_Engines(x1, y1, false, vehicle));
      else if (strcasecmp(str,"evaprep") == 0)
        addGauge(new G_EvaPrep(x1, y1, false, vehicle));
      else if (strcasecmp(str,"fuel") == 0)
        addGauge(new G_Fuel(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ground") == 0)
        addGauge(new G_Ground(x1, y1, false, vehicle));
      else if (strcasecmp(str,"groundins") == 0)
        addGauge(new G_GroundIns(x1, y1, false, vehicle));
      else if (strcasecmp(str,"inclination") == 0)
        addGauge(new G_Incl(x1, y1, false, vehicle));
      else if (strcasecmp(str,"ins") == 0)
        addGauge(new G_Ins(x1, y1, false, vehicle));
      else if (strcasecmp(str,"lamps") == 0)
        addGauge(new G_Lamps(x1, y1, false, vehicle));
      else if (strcasecmp(str,"lan") == 0)
        addGauge(new G_Lan(x1, y1, false, vehicle));
      else if (strcasecmp(str,"landed") == 0)
        addGauge(new G_Landed(x1, y1, false, vehicle));
      else if (strcasecmp(str,"lmfuel") == 0)
        addGauge(new G_LmFuel(x1, y1, false, vehicle));
      else if (strcasecmp(str,"lmrock") == 0)
        addGauge(new G_LmRock(x1, y1, false, vehicle));
      else if (strcasecmp(str,"lrv") == 0)
        addGauge(new G_Lrv(x1, y1, false, vehicle));
      else if (strcasecmp(str,"maplarge") == 0)
        addGauge(new G_MapLarge(x1, y1, false, vehicle));
      else if (strcasecmp(str,"mapmedium") == 0)
        addGauge(new G_MapMed(x1, y1, false, vehicle));
      else if (strcasecmp(str,"moon") == 0)
        addGauge(new G_Moon(x1, y1, false, vehicle));
      else if (strcasecmp(str,"multiaxis") == 0)
        addGauge(new G_MultiAxis(x1, y1, false, vehicle));
      else if (strcasecmp(str,"orbit") == 0)
        addGauge(new G_Orbit(x1, y1, false, vehicle));
      else if (strcasecmp(str,"orbiting") == 0)
        addGauge(new G_Orbiting(x1, y1, false, vehicle));
      else if (strcasecmp(str,"orbitlarge") == 0)
        addGauge(new G_OrbitLarge(x1, y1, false, vehicle));
      else if (strcasecmp(str,"oxybat") == 0)
        addGauge(new G_OxyBat(x1, y1, false, vehicle));
      else if (strcasecmp(str,"oxygen") == 0)
        addGauge(new G_Oxygen(x1, y1, false, vehicle));
      else if (strcasecmp(str,"oxygenbattery") == 0)
        addGauge(new G_OxyBat(x1, y1, false, vehicle));
      else if (strcasecmp(str,"periapsis") == 0)
        addGauge(new G_Periapsis(x1, y1, false, vehicle));
      else if (strcasecmp(str,"pilot") == 0)
        addGauge(new G_Pilot(x1, y1, false, vehicle));
      else if (strcasecmp(str,"pilotlocation") == 0)
        addGauge(new G_PilotLocation(x1, y1, false, vehicle));
      else if (strcasecmp(str,"pitchrate") == 0)
        addGauge(new G_PitchRate(x1, y1, false, vehicle));
      else if (strcasecmp(str,"plss") == 0)
        addGauge(new G_Plss(x1, y1, false, vehicle));
      else if (strcasecmp(str,"position") == 0)
        addGauge(new G_Position(x1, y1, false, vehicle));
      else if (strcasecmp(str,"precisionaxis") == 0)
        addGauge(new G_PrecAxis(x1, y1, false, vehicle));
      else if (strcasecmp(str,"prograde") == 0)
        addGauge(new G_Prograde(x1, y1, false, vehicle));
      else if (strcasecmp(str,"propellant") == 0)
        addGauge(new G_Propellant(x1, y1, false, vehicle));
      else if (strcasecmp(str,"radars") == 0)
        addGauge(new G_Radars(x1, y1, false, vehicle));
      else if (strcasecmp(str,"radial") == 0)
        addGauge(new G_Radial(x1, y1, false, vehicle));
      else if (strcasecmp(str,"rcs") == 0)
        addGauge(new G_Rcs(x1, y1, false, vehicle));
      else if (strcasecmp(str,"rightascension") == 0)
        addGauge(new G_RightAscension(x1, y1, false, vehicle));
      else if (strcasecmp(str,"roc") == 0)
        addGauge(new G_Roc(x1, y1, false, vehicle));
      else if (strcasecmp(str,"rollrate") == 0)
        addGauge(new G_RollRate(x1, y1, false, vehicle));
      else if (strcasecmp(str,"seq") == 0)
        addGauge(new G_Seq(x1, y1, false, vehicle));
      else if (strcasecmp(str,"throttle") == 0)
        addGauge(new G_Throttle(x1, y1, false, vehicle));
      else if (strcasecmp(str,"vehicle") == 0)
        addGauge(new G_Vehicle(x1, y1, false, vehicle));
      else if (strcasecmp(str,"velocity") == 0)
        addGauge(new G_Velocity(x1, y1, false, vehicle));
      else if (strcasecmp(str,"yawrate") == 0)
        addGauge(new G_YawRate(x1, y1, false, vehicle));
      else {
        Write("Unknown guage: ");
        WriteLn(str);
        exit(1);
        }
      }
    else {
      Write("Unknown command: ");
      WriteLn(line);
      exit(1);
      }
    }
 
  fclose(file);
  return -1;
  }

void Panel::addGauge(Gauge* g) {
  if (numGauges < 100) {
    gauges[numGauges++] = g;
    }
  else delete(g);
  }

void Panel::useDefault(const char* filename) {
  if (strcmp(filename,"csm.pnl") == 0) {
    Box( 1,1,80,24);
    Box( 64,1,80,7);
    Box( 21,18,27,24);
    Box( 13,18,21,24);
    Box( 25,1,55,5);
    Box( 27,9,53,24);
    Box( 1,18,13,24);
    Box( 1,14,27,18);
    Box( 1,9,27,14);
    Box( 25,5,55,9);
    HLine(1,5,25);
    HLine(53,20,80);
    HLine(64,9,80);
    HLine(53,9,64);
    VLine(64,6,9);
    addGauge(new G_ClockUT(66,2, false, vehicle));
    addGauge(new G_ClockGE(66,3, false, vehicle));
    addGauge(new G_ClockBU(66,4, false, vehicle));
    addGauge(new G_ClockTB(66,5, false, vehicle));
    addGauge(new G_Days(66,6, false, vehicle));
    addGauge(new G_Engines(23,20, false, vehicle));
    addGauge(new G_Fuel(14,19, false, vehicle));
    addGauge(new G_Altitude(27,2, false, vehicle));
    addGauge(new G_Roc(27,3, false, vehicle));
    addGauge(new G_Velocity(42,2, false, vehicle));
    addGauge(new G_Accel(42,3, false, vehicle));
    addGauge(new G_Apoapsis(27,6, false, vehicle));
    addGauge(new G_Periapsis(27,7, false, vehicle));
    addGauge(new G_Ground(42,8, false, vehicle));
    addGauge(new G_ClockOT(27,8, false, vehicle));
    addGauge(new G_RightAscension(27,4, false, vehicle));
    addGauge(new G_Declination(42,4, false, vehicle));
    addGauge(new G_MultiAxis(28,10, false, vehicle));
    addGauge(new G_Propellant(4,19, false, vehicle));
    addGauge(new G_Oxygen(4,20, false, vehicle));
    addGauge(new G_Battery(4,21, false, vehicle));
    addGauge(new G_Radial(3,15, false, vehicle));
    addGauge(new G_Orbit(16,15, false, vehicle));
    addGauge(new G_Prograde(3,10, false, vehicle));
    addGauge(new G_Lan(42,6, false, vehicle));
    addGauge(new G_Incl(42,7, false, vehicle));
    addGauge(new G_CsmLamps(3,2, false, vehicle));
    addGauge(new G_Rcs(3,6, false, vehicle));
    addGauge(new G_Moon(55,21, false, vehicle));
    addGauge(new G_Orbiting(70,8, false, vehicle));
    addGauge(new G_CsmComputer(57,2, false, vehicle));
    addGauge(new G_CsmDock(54,11, false, vehicle));
    addGauge(new G_AmsMessage(64,10, false, vehicle));
    addGauge(new G_Vehicle(3,23, false, vehicle));
    return;
    }
  if (strcmp(filename,"csms.pnl") == 0) {
    Box(1,1,80,24);
    VLine(47,1,24);
    Box(56,4,71,6);
    Box(49,9,77,17);
    Box(56,20,72,22);
    Label(63,2,"CSM");
    addGauge(new G_AmsMessage(57, 21, false, vehicle));
    addGauge(new G_Ins(50, 10, false, vehicle));
    addGauge(new G_ClockUT(58, 5, false, vehicle));
    addGauge(new G_OrbitLarge(2, 2, false, vehicle));
    return;
    }
  if (strcmp(filename,"lm.pnl") == 0) {
    Box(1,1,80,24);
    Box(38,14,54,16);
    HLine(1,16,80);
    VLine(27,1,16);
    VLine(54,1,16);
    HLine(27,3,54);
    VLine(22,16,24);
    VLine(52,16,24);
    VLine(60,16,22);
    HLine(1,20,22);
    HLine(52,22,73);
    VLine(73,16,24);
    Label(49,15,":");
    addGauge(new G_AmsDock(41,4, false, vehicle));
    addGauge(new G_MultiAxis(55,2, false, vehicle));
    addGauge(new G_AmsLand(28,4, false, vehicle));
    addGauge(new G_AmsMessage(39,15, false, vehicle));
    addGauge(new G_PrecAxis(2,2, false, vehicle));
    addGauge(new G_ClockUT(61,17, false, vehicle));
    addGauge(new G_ClockGE(61,18, false, vehicle));
    addGauge(new G_ClockMI(61,19, false, vehicle));
    addGauge(new G_ClockBU(61,20, false, vehicle));
    addGauge(new G_ClockDK(61,21, false, vehicle));
    addGauge(new G_EvaPrep(53,23, false, vehicle));
    addGauge(new G_LmFuel(53,17, false, vehicle));
    addGauge(new G_LmRock(74,23, false, vehicle));
    addGauge(new G_OxyBat(53,20, false, vehicle));
    addGauge(new G_Pilot(74,17, false, vehicle));
    addGauge(new G_PilotLocation(75,21, false, vehicle));
    addGauge(new G_Rcs(2,17, false, vehicle));
    addGauge(new G_Attitude(5,12, false, vehicle));
    addGauge(new G_Radars(31,13, false, vehicle));
    addGauge(new G_Throttle(41,13, false, vehicle));
    addGauge(new G_Computer(23,17, false, vehicle));
    addGauge(new G_Lamps(2,21, false, vehicle));
    addGauge(new G_Seq(29,2, false, vehicle));
    return;
    }
  if (strcmp(filename,"lrv.pnl") == 0) {
    Box(1,1,80,24);
    VLine(47,1,24);
    VLine(54,1,16);
    HLine(47,4,54);
    HLine(47,11,54);
    HLine(47,16,80);
    VLine(60,16,22);
    VLine(73,16,24);
    Box(52,22,68,24);
    addGauge(new G_ClockUT(61,17, false, vehicle));
    addGauge(new G_ClockGE(61,18, false, vehicle));
    addGauge(new G_ClockMI(61,19, false, vehicle));
    addGauge(new G_ClockEV(61,20, false, vehicle));
    addGauge(new G_ClockTE(61,21, false, vehicle));
    addGauge(new G_AmsDown(55,2, false, vehicle));
    addGauge(new G_AmsLrv(48,12, false, vehicle));
    addGauge(new G_AmsMessage(53,23, false, vehicle));
    addGauge(new G_Pilot(74,17, false, vehicle));
    addGauge(new G_PilotLocation(75,21, false, vehicle));
    addGauge(new G_Plss(48,5, false, vehicle));
    addGauge(new G_MapLarge(2,2, false, vehicle));
    addGauge(new G_GroundIns(48,17, false, vehicle));
    return;
    }
  if (strcmp(filename,"plss.pnl") == 0) {
    Box(1,1,80,24);
    VLine(47,1,24);
    VLine(54,1,16);
    HLine(47,4,54);
    HLine(47,11,54);
    HLine(47,16,80);
    VLine(60,16,22);
    VLine(73,16,24);
    Box(52,22,68,24);
    addGauge(new G_ClockUT(61,17, false, vehicle));
    addGauge(new G_ClockGE(61,18, false, vehicle));
    addGauge(new G_ClockMI(61,19, false, vehicle));
    addGauge(new G_ClockEV(61,20, false, vehicle));
    addGauge(new G_ClockTE(61,21, false, vehicle));
    addGauge(new G_AmsDown(55,2, false, vehicle));
    addGauge(new G_AmsLrv(48,12, false, vehicle));
    addGauge(new G_AmsMessage(53,23, false, vehicle));
    addGauge(new G_Pilot(74,17, false, vehicle));
    addGauge(new G_PilotLocation(75,21, false, vehicle));
    addGauge(new G_Plss(48,5, false, vehicle));
    addGauge(new G_MapLarge(2,2, false, vehicle));
    addGauge(new G_GroundIns(48,17, false, vehicle));
    return;
    }
  Box(1,1,80,16);
  Box(1,16,80,24);
  VLine(27,1,16);
  VLine(54,1,16);
  HLine(27,3,54);
  VLine(31,2,2);
  VLine(51,2,2);
  VLine(35,12,15);
  VLine(43,12,15);
  VLine(47,12,15);
  Label(45,12,"--");
  Label(45,13,"--");
  Label(45,14,"--");
  Label(45,15,"--");
  VLine(9,17,20);
  VLine(16,17,23);
  VLine(24,17,23);
  VLine(52,17,23);
  VLine(67,17,23);
  HLine(2,21,15);
  HLine(36,22,51);
  VLine(36,22,23);
  Label(47,23,":");
  addGauge(new G_AmsAtt(2, 17, false, vehicle));
  addGauge(new G_AmsClocks(68, 17, false, vehicle));
  addGauge(new G_AmsCons(17, 17, false, vehicle));
  addGauge(new G_AmsDock(41,  4, false, vehicle));
  addGauge(new G_AmsDown(55,  2, false, vehicle));
  addGauge(new G_AmsIns(25, 17, false, vehicle));
  addGauge(new G_AmsLand(28,  4, false, vehicle));
  addGauge(new G_AmsLm(48, 12, false, vehicle));
  addGauge(new G_AmsLrv(37, 12, false, vehicle));
  addGauge(new G_AmsMessage(37, 23, false, vehicle));
  addGauge(new G_AmsPilot(32,  2, false, vehicle));
  addGauge(new G_AmsPlss(29, 12, false, vehicle));
  addGauge(new G_AmsSeq( 2, 22, false, vehicle));
  addGauge(new G_AmsSpin(10, 17, false, vehicle));
  addGauge(new G_AmsStatus(53, 17, false, vehicle));
  if (strcmp(filename,"lrv.pnl") == 0) addGauge(new G_MapMed( 2, 2, false, vehicle));
  else if (strcmp(filename,"plss.pnl") == 0) addGauge(new G_MapMed( 2, 2, false, vehicle));
  else addGauge(new G_AmsWest( 2,  2, false, vehicle));
  }

void Panel::Box(UInt8 x1,UInt8 y1,UInt8 x2,UInt8 y2) {
  HLine(x1,y1,x2);
  HLine(x1,y2,x2);
  VLine(x1,y1,y2);
  VLine(x2,y1,y2);
  }

void Panel::HLine(UInt8 x1,UInt8 y1,UInt8 x2) {
  UInt8 i;
  y1--;
  for (i=x1-1; i<x2; i++) {
    if (screen[y1][i] == '|') screen[y1][i] = '+';
    else if (screen[y1][i] == '+') screen[y1][i] = '+';
    else screen[y1][i] = '-';
    }
  }

void Panel::VLine(UInt8 x1,UInt8 y1,UInt8 y2) {
  UInt8 i;
  x1--;
  for (i=y1-1; i<y2; i++) {
    if (screen[i][x1] == '-') screen[i][x1] = '+';
    else if (screen[i][x1] == '+') screen[i][x1] = '+';
    else screen[i][x1] = '|';
    }
  }

void Panel::Label(UInt8 x,UInt8 y,const char* label) {
  UInt8 i;
  for (i=0; i<strlen(label); i++)
    screen[y-1][x-1+i] = label[i];
  }

void Panel::Display() {
  UInt8 i;
  ClrScr();
  for (i=0; i<24; i++) {
    GotoXY(1,i+1);
    Write(screen[i]);
    }
  for (i=0; i<numGauges; i++)
    gauges[i]->Display();
  fflush(stdout);
  }

void Panel::Update() {
  UInt8 i;
  for (i=0; i<numGauges; i++) {
    gauges[i]->Update();
    }
  fflush(stdout);
  }

void Panel::Reset() {
  UInt8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->Reset();
  fflush(stdout);
  }

void Panel::ProcessKey(Int32 key) {
  UInt8 i;
  for (i=0; i<numGauges; i++)
    gauges[i]->ProcessKey(key);
  }

void Panel::Save(FILE* file) {
  UInt32 i;
  fprintf(file,"  Panel {%s",LE);
  for (i=0; i<numGauges; i++)
    gauges[i]->Save(file);
  fprintf(file,"    }%s",LE);
  }

void Panel::Load(FILE* file) {
  UInt32 i;
  char* pline;
  while ((pline = nextLine(file)) != NULL) {
    if (startsWith(pline,"}")) return;
    for (i=0; i<numGauges; i++)
      gauges[i]->Load(file, pline);
    }
  }

