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

include ../common/Makefile.pheaders
include ../common/Makefile.pobjects
include ../common/Makefile.cobjects

HEADERS = \
	$(PHEADERS) \
	header.h ../common/types.h

OBJS = \
	$(COBJS) \
	$(POBJS) \
	command.o \
	load.o \
	save.o \
	missionreport.o \
	score.o \
	sgn.o \
	main.o

PLANNEROBJS = \
	../common/helpers.o \
	../common/lander.o \
	../common/lfsr.o \
	../common/map.o \
	../common/mission.o \
	planner.o \
	../common/random.o \
	../common/vector.o \
	../common/matrix.o \
	../common/terminal.o

all: $(PROJECT) planner

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

include ../common/Makefile.incl

planner: $(PLANNEROBJS)
	$(CC) $(DEFS) $(LIBDIR) $(PLANNEROBJS) $(LIBS) -o planner

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

clean:
	-rm $(PROJECT)
	-rm planner
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
	-rm planner
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
lander.o:        $(HEADERS) lander.cpp
load.o:          $(HEADERS) load.cpp
main.o:          $(HEADERS) main.cpp
missionreport.o: $(HEADERS) missionreport.cpp
save.o:          $(HEADERS) save.cpp
sgn.o:           $(HEADERS) sgn.cpp
vehicle.o:       $(HEADERS) vehicle.h panel.h ../common/gauge.h vehicle.cpp


planner.o:     $(HEADERS) ../common/mission.h planner.cpp

