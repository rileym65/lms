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

include ../common/Makefile.cobjects

PHEADERS = panel.h ../common/gauge.h \
	   ../common/g_amsatt.h \
	   ../common/g_amsclocks.h g_amscons.h \
           g_amsdock.h \
	   ../common/g_amsdown.h g_amsins.h g_amsland.h \
	   ../common/g_amslm.h \
           g_amslrv.h \
           g_amsplss.h \
           ../common/g_amspilot.h \
           ../common/g_amsseq.h \
           ../common/g_amsspin.h g_amsstat.h \
	   ../common/g_amswest.h \
	   ../common/g_clocks.h \
           ../common/g_axis.h \
           ../common/g_attitude.h \
           ../common/g_clockev.h \
           ../common/g_clockmi.h \
           ../common/g_clockte.h \
           ../common/g_clockut.h \
           g_computer.h \
           g_docked.h \
           ../common/g_evaprep.h \
           g_groundins.h \
           g_ins.h \
           g_lamps.h \
           ../common/g_landed.h \
           ../common/g_lmfuel.h \
           ../common/g_lmrock.h \
           g_lrv.h \
           g_maplarge.h \
           ../common/g_mapmed.h \
           ../common/g_multiaxis.h \
           g_orbitlarge.h \
           ../common/g_oxybat.h \
           ../common/g_pilot.h \
           ../common/g_pilotloc.h \
           g_plss.h \
           g_precaxis.h \
           ../common/g_radars.h \
           ../common/g_rcs.h \
           ../common/g_seq.h \
           ../common/g_throttle.h
OBJS = \
	$(COBJS) \
	command.o \
        ../common/g_amsatt.o \
        ../common/g_amsclocks.o \
        g_amscons.o \
        g_amsdock.o \
        ../common/g_amsdown.o \
        g_amsins.o \
        g_amsland.o \
        ../common/g_amslm.o \
        g_amslrv.o \
	g_maplarge.o \
	../common/g_mapmed.o \
        ../common/g_amsmsg.o \
        ../common/g_amspilot.o \
        g_amsplss.o \
        ../common/g_amsseq.o \
        ../common/g_amsspin.o \
        g_amsstat.o \
	../common/g_amswest.o \
	../common/g_axis.o \
	../common/g_attitude.o \
	../common/g_clocks.o \
	../common/g_clockev.o \
	../common/g_clockmi.o \
	../common/g_clockte.o \
	../common/g_clockut.o \
	g_computer.o \
	g_docked.o \
	../common/g_evaprep.o \
	g_groundins.o \
	g_ins.o \
	g_lamps.o \
	../common/g_landed.o \
        ../common/g_lmfuel.o \
        ../common/g_lmrock.o \
	g_lrv.o \
	../common/g_multiaxis.o \
	g_orbitlarge.o \
	../common/g_oxybat.o \
	../common/g_pilot.o \
	../common/g_pilotloc.o \
	g_plss.o \
	g_precaxis.o \
	../common/g_radars.o \
	../common/g_rcs.o \
	../common/g_seq.o \
	../common/g_throttle.o \
	helpers.o \
	load.o \
	records.o \
	save.o \
	missionreport.o \
	panel.o \
	score.o \
	sgn.o \
	main.o

MOBJS = \
	helpers.o \
	../common/lfsr.o \
	../common/map.o \
	../common/random.o \
	../common/terminal.o \
	mapgen.o

PLANNEROBJS = \
	helpers.o \
	../common/lander.o \
	../common/lfsr.o \
	../common/map.o \
	../common/mission.o \
	planner.o \
	../common/random.o \
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

command.o:       $(HEADERS) command.cpp
helpers.o:       $(HEADERS) helpers.cpp
lander.o:        $(HEADERS) lander.cpp
load.o:          $(HEADERS) load.cpp
main.o:          $(HEADERS) main.cpp
mapgen.o:        $(HEADERS) ../common/map.h ../common/random.h mapgen.cpp
missionreport.o: $(HEADERS) missionreport.cpp
panel.o:         $(HEADERS) $(PHEADERS)  panel.cpp
records.o:       $(HEADERS) records.h records.cpp
save.o:          $(HEADERS) save.cpp
sgn.o:           $(HEADERS) sgn.cpp
vehicle.o:       $(HEADERS) vehicle.h panel.h ../common/gauge.h vehicle.cpp

g_amscons.o:    $(HEADERS) ../common/gauge.h g_amscons.h  g_amscons.cpp
g_amsdock.o:    $(HEADERS) ../common/gauge.h g_amsdock.h  g_amsdock.cpp
g_amsins.o:     $(HEADERS) ../common/gauge.h g_amsins.h  g_amsins.cpp
g_amsland.o:    $(HEADERS) ../common/gauge.h g_amsland.h  g_amsland.cpp
g_amslrv.o:     $(HEADERS) ../common/gauge.h g_amslrv.h  g_amslrv.cpp
g_amsplss.o:    $(HEADERS) ../common/gauge.h g_amsplss.h  g_amsplss.cpp
g_amsstat.o:    $(HEADERS) ../common/gauge.h g_amsstat.h  g_amsstat.cpp
g_computer.o:   $(HEADERS) ../common/gauge.h  g_computer.h g_computer.cpp
g_docked.o:     $(HEADERS) ../common/gauge.h  g_docked.h g_docked.cpp
g_groundins.o:  $(HEADERS) ../common/gauge.h  g_groundins.h g_groundins.cpp
g_ins.o:        $(HEADERS) ../common/gauge.h  g_ins.h g_ins.cpp
g_lamps.o:      $(HEADERS) ../common/gauge.h  g_lamps.h g_lamps.cpp
g_lrv.o:        $(HEADERS) ../common/gauge.h  g_lrv.h g_lrv.cpp
g_maplarge.o:   $(HEADERS) ../common/gauge.h  ../common/map.h g_maplarge.h g_maplarge.cpp
g_orbitlarge.o: $(HEADERS) ../common/gauge.h  g_orbitlarge.h g_orbitlarge.cpp
g_plss.o:       $(HEADERS) ../common/gauge.h  g_plss.h g_plss.cpp
g_precaxis.o:   $(HEADERS) ../common/gauge.h  g_precaxis.h g_precaxis.cpp

planner.o:     $(HEADERS) ../common/mission.h planner.cpp

