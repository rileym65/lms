PROJECT = lms
CC = g++
# MINGW
#DEFS = -Wall -DMINGW -UWIN32 -static-libstdc++ -static-libgcc -static

#Linux
DEFS = -Wall -std=c++11


INCDIR = -I../common
INCS =
LIBDIR =
LIBS = -lm

include ../common/Makefile.pheaders
include ../common/Makefile.pobjects
include ../common/Makefile.cobjects

HEADERS = $(PHEADERS) header.h ../common/types.h \
	   ../common/common.h \
	   ../common/vector.h \
	   ../common/matrix.h \
	   ../common/vehicle.h \
	   ../common/panel.h \
	   ../common/booster.h \
	   ../common/body.h \
	   ../common/spacecraft.h \
	   ../common/command.h \
	   ../common/csmcomputer.h
OBJS = \
	$(POBJS) \
	$(COBJS) \
	airdensity.o \
	booster.o \
	command.o \
	flight.o \
	load.o \
	missionreport.o \
	orbit.o \
	save.o \
	score.o \
	main.o

all: $(PROJECT)

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

rmsave:
	-rm *.sav

clean:
	-rm $(PROJECT)
	-rm *.o

cleanall:
	-rm $(PROJECT)
	-rm *.o
	-rm ../common/*.o

include ../common/Makefile.incl

airdensity.o:    $(HEADERS) airdensity.cpp
booster.o:       $(HEADERS) booster.cpp
command.o:       $(HEADERS) command.cpp
csmcomputer.o:   $(HEADERS) csmcomputer.cpp
flight.o:        $(HEADERS) flight.cpp
gauge.o:         $(HEADERS) gauge.cpp
load.o:          $(HEADERS) load.cpp
main.o:          $(HEADERS) orbit.h main.cpp
missionreport.o: $(HEADERS) missionreport.cpp
orbit.o:         $(HEADERS) orbit.h orbit.cpp
save.o:          $(HEADERS) save.cpp
score.o:         $(HEADERS) score.cpp
terminal.o:      $(HEADERS) terminal.cpp


