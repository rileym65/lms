PROJECT = lms
CC = g++
# MINGW
#DEFS = -Wall -DMINGW -UWIN32 -static-libstdc++ -static-libgcc -static

#Linux
DEFS = -Wall

INCDIR = -I../common
INCS =
LIBDIR =
LIBS = -lm
HEADERS = header.h ../common/types.h
PHEADERS = panel.h ../common/gauge.h \
	   ../common/g_amsatt.h \
	   ../common/g_amsclocks.h g_amscons.h \
           g_amsdock.h \
	   ../common/g_amsdown.h g_amsins.h g_amsland.h g_amslm.h \
           g_amslrv.h \
           g_amsplss.h \
           g_amspilot.h \
           g_amsseq.h \
           g_amsspin.h g_amsstat.h \
	   ../common/g_amswest.h \
	   ../common/g_clocks.h \
           ../common/g_axis.h \
           g_attitude.h \
           ../common/g_clockev.h \
           ../common/g_clockmi.h \
           ../common/g_clockte.h \
           ../common/g_clockut.h \
           g_computer.h \
           g_docked.h \
           g_evaprep.h \
           g_groundins.h \
           g_ins.h \
           g_lamps.h \
           g_landed.h \
           g_lmfuel.h \
           g_lmrock.h \
           g_lrv.h \
           g_maplarge.h \
           g_mapmed.h \
           g_multiaxis.h \
           g_orbitlarge.h \
           ../common/g_oxybat.h \
           g_pilot.h \
           g_pilotloc.h \
           g_plss.h \
           g_precaxis.h \
           g_radars.h \
           ../common/g_rcs.h \
           g_seq.h \
           ../common/g_throttle.h
OBJS = \
	csm.o \
	../common/gauge.o \
        ../common/g_amsatt.o \
        ../common/g_amsclocks.o \
        g_amscons.o \
        g_amsdock.o \
        ../common/g_amsdown.o \
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
	../common/g_amswest.o \
	../common/g_axis.o \
	g_attitude.o \
	../common/g_clocks.o \
	../common/g_clockev.o \
	../common/g_clockmi.o \
	../common/g_clockte.o \
	../common/g_clockut.o \
	g_computer.o \
	g_docked.o \
	g_evaprep.o \
	g_groundins.o \
	g_ins.o \
	g_lamps.o \
	g_landed.o \
        g_lmfuel.o \
        g_lmrock.o \
	g_lrv.o \
	g_multiaxis.o \
	g_orbitlarge.o \
	../common/g_oxybat.o \
	g_pilot.o \
	g_pilotloc.o \
	g_plss.o \
	g_precaxis.o \
	g_radars.o \
	../common/g_rcs.o \
	g_seq.o \
	../common/g_throttle.o \
	computer.o \
	groundvehicle.o \
	helpers.o \
	../common/lander.o \
	lfsr.o \
	load.o \
	lrv.o \
	map.o \
	../common/mission.o \
	records.o \
	save.o \
	lm.o \
	../common/matrix.o \
	../common/body.o \
	missionreport.o \
	panel.o \
	plss.o \
	random.o \
	sequencer.o \
	score.o \
	sgn.o \
	../common/terminal.o \
	../common/vector.o \
	../common/vehicle.o \
	../common/spacecraft.o \
	main.o

MOBJS = \
	helpers.o \
	lfsr.o \
	map.o \
	random.o \
	../common/terminal.o \
	mapgen.o

PLANNEROBJS = \
	helpers.o \
	../common/lander.o \
	lfsr.o \
	map.o \
	../common/mission.o \
	planner.o \
	random.o \
	../common/vector.o \
	../common/terminal.o

GCASMOBJS = \
	../common/terminal.o \
	gcasm.o

all: $(PROJECT) mapgen planner gcasm

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

include ../common/Makefile.incl

mapgen: $(MOBJS)
	$(CC) $(DEFS) $(LIBDIR) $(MOBJS) $(LIBS) -o mapgen

planner: $(PLANNEROBJS)
	$(CC) $(DEFS) $(LIBDIR) $(PLANNEROBJS) $(LIBS) -o planner

gcasm: $(GCASMOBJS)
	$(CC) $(DEFS) $(LIBDIR) $(GCASMOBJS) $(LIBS) -o gcasm

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

rmsave:
	-rm *.sav

doc:
	makedoc lms.d
	makedoc panel.d
	makedoc computer.d
	makedoc training.d
	makedoc landing.d
	makedoc tutorial.d

core:	gcasm core.asm
	./gcasm core.asm

clean:
	-rm $(PROJECT)
	-rm mapgen
	-rm planner
	-rm gcasm
	-rm *.o
	-rm lms.doc
	-rm *.html
	-rm panel.doc
	-rm lms.doc
	-rm computer.doc
	-rm training.doc
	-rm tutorial.doc
	-rm panel.html

cleanall:
	-rm $(PROJECT)
	-rm mapgen
	-rm planner
	-rm gcasm
	-rm *.o
	-rm lms.doc
	-rm *.html
	-rm panel.doc
	-rm lms.doc
	-rm computer.doc
	-rm training.doc
	-rm tutorial.doc
	-rm ../common/*.o

computer.o:      $(HEADERS) ../common/vehicle.h computer.h computer.cpp
csm.o:           $(HEADERS) csm.cpp
groundvehicle.o: $(HEADERS) ../common/vehicle.h groundvehicle.h groundvehicle.cpp
helpers.o:       $(HEADERS) helpers.cpp
lander.o:        $(HEADERS) lander.cpp
lfsr.o:          $(HEADERS) lfsr.h lfsr.cpp
load.o:          $(HEADERS) load.cpp
lrv.o:           $(HEADERS) ../common/vehicle.h lrv.h lrv.cpp
main.o:          $(HEADERS) main.cpp
map.o:           $(HEADERS) lfsr.h random.h map.h map.cpp
mapgen.o:        $(HEADERS) map.h random.h mapgen.cpp
missionreport.o: $(HEADERS) missionreport.cpp
panel.o:         $(HEADERS) $(PHEADERS)  panel.cpp
plss.o:          $(HEADERS) ../common/vehicle.h plss.h plss.cpp
random.o:        $(HEADERS) lfsr.h random.h random.cpp
records.o:       $(HEADERS) records.h records.cpp
save.o:          $(HEADERS) save.cpp
sgn.o:           $(HEADERS) sgn.cpp
sequencer.o:     $(HEADERS) sequencer.cpp
lm.o:            $(HEADERS) lm.h lm.cpp
vehicle.o:       $(HEADERS) vehicle.h panel.h ../common/gauge.h vehicle.cpp

g_amscons.o:    $(HEADERS) ../common/gauge.h g_amscons.h  g_amscons.cpp
g_amsdock.o:    $(HEADERS) ../common/gauge.h g_amsdock.h  g_amsdock.cpp
g_amsins.o:     $(HEADERS) ../common/gauge.h g_amsins.h  g_amsins.cpp
g_amsland.o:    $(HEADERS) ../common/gauge.h g_amsland.h  g_amsland.cpp
g_amslm.o:      $(HEADERS) ../common/gauge.h g_amslm.h  g_amslm.cpp
g_amslrv.o:     $(HEADERS) ../common/gauge.h g_amslrv.h  g_amslrv.cpp
g_amsmsg.o:     $(HEADERS) ../common/gauge.h g_amsmsg.h  g_amsmsg.cpp
g_amspilot.o:   $(HEADERS) ../common/gauge.h g_amspilot.h  g_amspilot.cpp
g_amsplss.o:    $(HEADERS) ../common/gauge.h g_amsplss.h  g_amsplss.cpp
g_amsseq.o:     $(HEADERS) ../common/gauge.h g_amsseq.h  g_amsseq.cpp
g_amsspin.o:    $(HEADERS) ../common/gauge.h g_amsspin.h  g_amsspin.cpp
g_amsstat.o:    $(HEADERS) ../common/gauge.h g_amsstat.h  g_amsstat.cpp
g_attitude.o:   $(HEADERS) ../common/gauge.h  g_attitude.h g_attitude.cpp
g_computer.o:   $(HEADERS) ../common/gauge.h  g_computer.h g_computer.cpp
g_docked.o:     $(HEADERS) ../common/gauge.h  g_docked.h g_docked.cpp
g_groundins.o:  $(HEADERS) ../common/gauge.h  g_groundins.h g_groundins.cpp
g_ins.o:        $(HEADERS) ../common/gauge.h  g_ins.h g_ins.cpp
g_lamps.o:      $(HEADERS) ../common/gauge.h  g_lamps.h g_lamps.cpp
g_landed.o:     $(HEADERS) ../common/gauge.h  g_landed.h g_landed.cpp
g_lmfuel.o:     $(HEADERS) ../common/gauge.h  g_lmfuel.h g_lmfuel.cpp
g_lmrock.o:     $(HEADERS) ../common/gauge.h  g_lmrock.h g_lmrock.cpp
g_lrv.o:        $(HEADERS) ../common/gauge.h  g_lrv.h g_lrv.cpp
g_maplarge.o:   $(HEADERS) ../common/gauge.h  map.h g_maplarge.h g_maplarge.cpp
g_mapmed.o:     $(HEADERS) ../common/gauge.h  map.h g_mapmed.h g_mapmed.cpp
g_multiaxis.o:  $(HEADERS) ../common/gauge.h  map.h g_multiaxis.h g_multiaxis.cpp
g_evaprep.o:    $(HEADERS) ../common/gauge.h  g_evaprep.h g_evaprep.cpp
g_orbitlarge.o: $(HEADERS) ../common/gauge.h  g_orbitlarge.h g_orbitlarge.cpp
g_pilot.o:      $(HEADERS) ../common/gauge.h  g_pilot.h g_pilot.cpp
g_pilotloc.o:   $(HEADERS) ../common/gauge.h  g_pilotloc.h g_pilotloc.cpp
g_plss.o:       $(HEADERS) ../common/gauge.h  g_plss.h g_plss.cpp
g_precaxis.o:   $(HEADERS) ../common/gauge.h  g_precaxis.h g_precaxis.cpp
g_radars.o:     $(HEADERS) ../common/gauge.h  g_radars.h g_radars.cpp
g_seq.o:        $(HEADERS) ../common/gauge.h  g_seq.h g_seq.cpp

planner.o:     $(HEADERS) ../common/mission.h planner.cpp

