PROJECT = fms
CC = g++
# MINGW
#DEFS = -Wall -DMINGW -UWIN32 -static-libstdc++ -static-libgcc -static

#Linux
DEFS = -Wall


INCDIR = -I../common
INCS =
LIBDIR =
LIBS = -lm
PHEADERS = ../common/g_clockbu.h \
	   ../common/g_clockmi.h \
	   ../common/g_clockut.h \
	   ../common/g_engines.h \
	   ../common/g_altitude.h \
	   ../common/g_velocity.h \
	   ../common/g_accel.h \
	   ../common/g_fuel.h \
	   ../common/g_clocktb.h \
	   ../common/g_apoapsis.h \
	   ../common/g_periapsis.h \
	   ../common/g_amsdown.h \
	   ../common/g_axis.h \
	   ../common/g_rollrate.h \
	   ../common/g_pitchrate.h \
	   ../common/g_yawrate.h \
	   ../common/g_clockot.h \
	   ../common/g_radial.h \
	   ../common/g_orbit.h \
           ../common/g_prograde.h \
	   ../common/g_position.h \
	   ../common/g_lan.h \
	   ../common/g_incl.h \
	   ../common/g_roc.h \
	   ../common/g_csmlamps.h \
	   ../common/g_rcs.h \
	   ../common/g_propellant.h \
	   ../common/g_oxygen.h \
	   ../common/g_battery.h \
	   ../common/g_ra.h\
	   ../common/g_dec.h \
	   ../common/g_multiaxis.h \
	   ../common/g_moon.h \
	   ../common/g_days.h \
	   ../common/g_orbiting.h

HEADERS = $(PHEADERS) header.h ../common/types.h \
	   ../common/vector.h \
	   ../common/matrix.h \
	   ../common/vehicle.h \
	   ../common/panel.h \
	   ../common/booster.h \
	   ../common/body.h \
	   ../common/spacecraft.h \
	   ../common/command.h
OBJS = \
	../common/g_accel.o \
	../common/g_altitude.o \
	../common/g_amsdown.o \
	../common/g_apoapsis.o \
	../common/g_axis.o \
	../common/g_battery.o \
	../common/g_clockbu.o \
	../common/g_clockmi.o \
	../common/g_clockot.o \
	../common/g_clocktb.o \
	../common/g_clockut.o \
	../common/g_csmlamps.o \
	../common/g_days.o \
	../common/g_dec.o \
	../common/g_engines.o \
	../common/g_fuel.o \
	../common/g_incl.o \
	../common/g_lan.o \
	../common/g_moon.o \
	../common/g_multiaxis.o \
	../common/g_orbit.o \
	../common/g_orbiting.o \
	../common/g_oxygen.o \
	../common/g_periapsis.o \
	../common/g_pitchrate.o \
	../common/g_position.o \
	../common/g_prograde.o \
	../common/g_propellant.o \
	../common/g_ra.o \
	../common/g_radial.o \
	../common/g_rcs.o \
	../common/g_roc.o \
	../common/g_rollrate.o \
	../common/g_velocity.o \
	../common/g_yawrate.o \
	airdensity.o \
	../common/body.o \
	booster.o \
	command.o \
	../common/gauge.o \
	../common/helpers.o \
	load.o \
	../common/matrix.o \
	../common/panel.o \
	save.o \
	../common/spacecraft.o \
	../common/terminal.o \
	../common/vector.o \
	../common/vehicle.o \
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

cleancommon:
	-rm $(PROJECT)
	-rm *.o
	-rm ../common/*.o

include ../common/Makefile.incl

airdensity.o:    $(HEADERS) airdensity.cpp
booster.o:       $(HEADERS) booster.cpp
command.o:       $(HEADERS) command.cpp
gauge.o:         $(HEADERS) gauge.cpp
load.o:          $(HEADERS) load.cpp
main.o:          $(HEADERS) main.cpp
save.o:          $(HEADERS) save.cpp
terminal.o:      $(HEADERS) terminal.cpp


