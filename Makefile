PROJECT = lms
CC = g++
DEFS = -Wall
INCDIR =
INCS =
LIBDIR =
LIBS = -lm
HEADERS = header.h types.h
PHEADERS = panel.h gauge.h g_amsatt.h g_amsclocks.h g_amscons.h \
           g_amsdock.h g_amsdown.h g_amsins.h g_amsland.h g_amslm.h \
           g_amslrv.h \
           g_amsplss.h \
           g_amspilot.h \
           g_amsseq.h \
           g_amsspin.h g_amsstat.h g_amswest.h g_clocks.h \
           g_axis.h \
           g_attitude.h \
           g_clockev.h \
           g_clockmi.h \
           g_clockte.h \
           g_clockut.h \
           g_docked.h \
           g_evaprep.h \
           g_groundins.h \
           g_ins.h \
           g_lamps.h \
           g_landed.h \
           g_lmfuel.h \
           g_lmrock.h \
           g_maplarge.h \
           g_mapmed.h \
           g_multiaxis.h \
           g_orbitlarge.h \
           g_oxybat.h \
           g_pilot.h \
           g_pilotloc.h \
           g_plss.h \
           g_precaxis.h \
           g_radars.h \
           g_rcs.h \
           g_seq.h \
           g_throttle.h
OBJS = \
	csm.o \
	gauge.o \
        g_amsatt.o \
        g_amsclocks.o \
        g_amscons.o \
        g_amsdock.o \
        g_amsdown.o \
        g_amsins.o \
        g_amsland.o \
        g_amslm.o \
        g_amslrv.o \
	g_maplarge.o \
	g_mapmed.o \
        g_amsmsg.o \
        g_amspilot.o \
        g_amsplss.o \
        g_amsseq.o \
        g_amsspin.o \
        g_amsstat.o \
	g_amswest.o \
	g_axis.o \
	g_attitude.o \
	g_clocks.o \
	g_clockev.o \
	g_clockmi.o \
	g_clockte.o \
	g_clockut.o \
	g_docked.o \
	g_evaprep.o \
	g_groundins.o \
	g_ins.o \
	g_lamps.o \
	g_landed.o \
        g_lmfuel.o \
        g_lmrock.o \
	g_multiaxis.o \
	g_orbitlarge.o \
	g_oxybat.o \
	g_pilot.o \
	g_pilotloc.o \
	g_plss.o \
	g_precaxis.o \
	g_radars.o \
	g_rcs.o \
	g_seq.o \
	g_throttle.o \
	groundvehicle.o \
	helpers.o \
	ins.o \
	lfsr.o \
	load.o \
	lrv.o \
	map.o \
	mission.o \
	records.o \
	save.o \
	lm.o \
	matrix.o \
	missionreport.o \
	panel.o \
	plss.o \
	random.o \
	sequencer.o \
	sgn.o \
	terminal.o \
	vector.o \
	vehicle.o \
	main.o

MOBJS = \
	helpers.o \
	lfsr.o \
	map.o \
	random.o \
	mapgen.o

PLANNEROBJS = \
	helpers.o \
	mission.o \
	planner.o \
	terminal.o

all: $(PROJECT) mapgen planner

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

mapgen: $(MOBJS)
	$(CC) $(DEFS) $(LIBDIR) $(MOBJS) $(LIBS) -o mapgen

planner: $(PLANNEROBJS)
	$(CC) $(DEFS) $(LIBDIR) $(PLANNEROBJS) $(LIBS) -o planner

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

rmsave:
	-rm *.sav

clean:
	-rm $(PROJECT)
	-rm mapgen
	-rm planner
	-rm *.o

csm.o:           $(HEADERS) csm.cpp
gauge.o:         $(HEADERS) gauge.h gauge.cpp
groundvehicle.o: $(HEADERS) vehicle.h groundvehicle.h groundvehicle.cpp
ins.o:           $(HEADERS) ins.cpp
helpers.o:       $(HEADERS) helpers.cpp
lfsr.o:          $(HEADERS) lfsr.h lfsr.cpp
load.o:          $(HEADERS) load.cpp
lrv.o:           $(HEADERS) vehicle.h lrv.h lrv.cpp
main.o:          $(HEADERS) main.cpp
map.o:           $(HEADERS) lfsr.h random.h map.h map.cpp
mapgen.o:        $(HEADERS) map.h random.h mapgen.cpp
matrix.o:        $(HEADERS) matrix.cpp
missionreport.o: $(HEADERS) missionreport.cpp
panel.o:         $(HEADERS) $(PHEADERS)  panel.cpp
plss.o:          $(HEADERS) vehicle.h plss.h plss.cpp
random.o:        $(HEADERS) lfsr.h random.h random.cpp
records.o:       $(HEADERS) records.h records.cpp
save.o:          $(HEADERS) save.cpp
sgn.o:           $(HEADERS) sgn.cpp
sequencer.o:     $(HEADERS) sequencer.cpp
lm.o:            $(HEADERS) lm.h lm.cpp
terminal.o:      $(HEADERS) terminal.cpp
vector.o:        $(HEADERS) vector.cpp
vehicle.o:       $(HEADERS) vehicle.h panel.h gauge.h vehicle.cpp

g_amsatt.o:     $(HEADERS) gauge.h g_amsatt.h terminal.h g_amsatt.cpp
g_amsclocks.o:  $(HEADERS) gauge.h g_amsclocks.h terminal.h g_amsclocks.cpp
g_amscons.o:    $(HEADERS) gauge.h g_amscons.h terminal.h g_amscons.cpp
g_amsdock.o:    $(HEADERS) gauge.h g_amsdock.h terminal.h g_amsdock.cpp
g_amsdown.o:    $(HEADERS) gauge.h g_amsdown.h terminal.h g_amsdown.cpp
g_amsins.o:     $(HEADERS) gauge.h g_amsins.h terminal.h g_amsins.cpp
g_amsland.o:    $(HEADERS) gauge.h g_amsland.h terminal.h g_amsland.cpp
g_amslm.o:      $(HEADERS) gauge.h g_amslm.h terminal.h g_amslm.cpp
g_amslrv.o:     $(HEADERS) gauge.h g_amslrv.h terminal.h g_amslrv.cpp
g_amsmsg.o:     $(HEADERS) gauge.h g_amsmsg.h terminal.h g_amsmsg.cpp
g_amspilot.o:   $(HEADERS) gauge.h g_amspilot.h terminal.h g_amspilot.cpp
g_amsplss.o:    $(HEADERS) gauge.h g_amsplss.h terminal.h g_amsplss.cpp
g_amsseq.o:     $(HEADERS) gauge.h g_amsseq.h terminal.h g_amsseq.cpp
g_amsspin.o:    $(HEADERS) gauge.h g_amsspin.h terminal.h g_amsspin.cpp
g_amsstat.o:    $(HEADERS) gauge.h g_amsstat.h terminal.h g_amsstat.cpp
g_amswest.o:    $(HEADERS) gauge.h g_amswest.h terminal.h g_amswest.cpp
g_axis.o:       $(HEADERS) gauge.h terminal.h g_axis.h g_axis.cpp
g_attitude.o:   $(HEADERS) gauge.h terminal.h g_attitude.h g_attitude.cpp
g_clocks.o:     $(HEADERS) gauge.h terminal.h g_clocks.h g_clocks.cpp
g_clockev.o:    $(HEADERS) gauge.h terminal.h g_clockev.h g_clockev.cpp
g_clockmi.o:    $(HEADERS) gauge.h terminal.h g_clockmi.h g_clockmi.cpp
g_clockte.o:    $(HEADERS) gauge.h terminal.h g_clockte.h g_clockte.cpp
g_clockut.o:    $(HEADERS) gauge.h terminal.h g_clockut.h g_clockut.cpp
g_docked.o:     $(HEADERS) gauge.h terminal.h g_docked.h g_docked.cpp
g_groundins.o:  $(HEADERS) gauge.h terminal.h g_groundins.h g_groundins.cpp
g_ins.o:        $(HEADERS) gauge.h terminal.h g_ins.h g_ins.cpp
g_lamps.o:      $(HEADERS) gauge.h terminal.h g_lamps.h g_lamps.cpp
g_landed.o:     $(HEADERS) gauge.h terminal.h g_landed.h g_landed.cpp
g_lmfuel.o:     $(HEADERS) gauge.h terminal.h g_lmfuel.h g_lmfuel.cpp
g_lmrock.o:     $(HEADERS) gauge.h terminal.h g_lmrock.h g_lmrock.cpp
g_maplarge.o:   $(HEADERS) gauge.h terminal.h map.h g_maplarge.h g_maplarge.cpp
g_mapmed.o:     $(HEADERS) gauge.h terminal.h map.h g_mapmed.h g_mapmed.cpp
g_multiaxis.o:  $(HEADERS) gauge.h terminal.h map.h g_multiaxis.h g_multiaxis.cpp
g_evaprep.o:    $(HEADERS) gauge.h terminal.h g_evaprep.h g_evaprep.cpp
g_orbitlarge.o: $(HEADERS) gauge.h terminal.h g_orbitlarge.h g_orbitlarge.cpp
g_oxybat.o:     $(HEADERS) gauge.h terminal.h g_oxybat.h g_oxybat.cpp
g_pilot.o:      $(HEADERS) gauge.h terminal.h g_pilot.h g_pilot.cpp
g_pilotloc.o:   $(HEADERS) gauge.h terminal.h g_pilotloc.h g_pilotloc.cpp
g_plss.o:       $(HEADERS) gauge.h terminal.h g_plss.h g_plss.cpp
g_precaxis.o:   $(HEADERS) gauge.h terminal.h g_axis.h g_precaxis.h g_precaxis.cpp
g_rcs.o:        $(HEADERS) gauge.h terminal.h g_rcs.h g_rcs.cpp
g_radars.o:     $(HEADERS) gauge.h terminal.h g_radars.h g_radars.cpp
g_seq.o:        $(HEADERS) gauge.h terminal.h g_seq.h g_seq.cpp
g_throttle.o:   $(HEADERS) gauge.h terminal.h g_throttle.h g_throttle.cpp

mission.o:     $(HEADERS) mission.h mission.cpp
planner.o:     $(HEADERS) mission.h planner.cpp

