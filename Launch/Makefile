PROJECT = launch
CC = g++
# MINGW
#DEFS = -Wall -DMINGW -UWIN32 -static-libstdc++ -static-libgcc -static

#Linux
DEFS = -Wall

INCDIR =
INCS =
LIBDIR =
LIBS = -lm
PHEADERS = g_clockbu.h g_clockmi.h g_clockut.h g_engines.h g_altitude.h g_velocity.h \
	   g_accel.h g_fuel.h g_clocktb.h g_apoapsis.h g_periapsis.h g_amsdown.h \
	   g_axis.h g_rollrate.h g_pitchrate.h g_yawrate.h g_clockot.h g_radial.h \
	   g_orbit.h g_prograde.h g_position.h g_lan.h g_incl.h g_roc.h \
	   g_csmlamps.h g_rcs.h g_propellant.h g_oxygen.h g_battery.h g_ra.h\
	   g_dec.h g_multiaxis.h
HEADERS = $(PHEADERS) header.h types.h vector.h matrix.h vehicle.h panel.h \
	   booster.h body.h spacecraft.h command.h
OBJS = \
	g_accel.o \
	g_altitude.o \
	g_amsdown.o \
	g_apoapsis.o \
	g_axis.o \
	g_battery.o \
	g_clockbu.o \
	g_clockmi.o \
	g_clockot.o \
	g_clocktb.o \
	g_clockut.o \
	g_csmlamps.o \
	g_dec.o \
	g_engines.o \
	g_fuel.o \
	g_incl.o \
	g_lan.o \
	g_multiaxis.o \
	g_orbit.o \
	g_oxygen.o \
	g_periapsis.o \
	g_pitchrate.o \
	g_position.o \
	g_prograde.o \
	g_propellant.o \
	g_ra.o \
	g_radial.o \
	g_rcs.o \
	g_roc.o \
	g_rollrate.o \
	g_velocity.o \
	g_yawrate.o \
	airdensity.o \
	body.o \
	booster.o \
	command.o \
	gauge.o \
	helpers.o \
	load.o \
	matrix.o \
	panel.o \
	save.o \
	spacecraft.o \
	terminal.o \
	vector.o \
	vehicle.o \
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

g_accel.o:       $(HEADERS) g_accel.cpp
g_altitude.o:    $(HEADERS) g_altitude.cpp
g_amsdown.o:     $(HEADERS) g_amsdown.cpp
g_apoapsis.o:    $(HEADERS) g_apoapsis.cpp
g_axis.o:        $(HEADERS) g_axis.cpp
g_battery.o:     $(HEADERS) g_battery.cpp
g_clockbu.o:     $(HEADERS) g_clockbu.cpp
g_clockmi.o:     $(HEADERS) g_clockmi.cpp
g_clockot.o:     $(HEADERS) g_clockot.cpp
g_clocktb.o:     $(HEADERS) g_clocktb.cpp
g_clockut.o:     $(HEADERS) g_clockut.cpp
g_csmlamps.o:    $(HEADERS) g_csmlamps.cpp
g_dec.o:         $(HEADERS) g_dec.cpp
g_engines.o:     $(HEADERS) g_engines.cpp
g_fuel.o:        $(HEADERS) g_fuel.cpp
g_incl.o:        $(HEADERS) g_incl.cpp
g_lan.o:         $(HEADERS) g_lan.cpp
g_multiaxis.o:   $(HEADERS) g_multiaxis.cpp
g_orbit.o:       $(HEADERS) g_orbit.cpp
g_oxygen.o:      $(HEADERS) g_oxygen.cpp
g_periapsis.o:   $(HEADERS) g_periapsis.cpp
g_pitchrate.o:   $(HEADERS) g_pitchrate.cpp
g_position.o:    $(HEADERS) g_position.cpp
g_prograde.o:    $(HEADERS) g_prograde.cpp
g_propellant.o:  $(HEADERS) g_propellant.cpp
g_ra.o:          $(HEADERS) g_ra.cpp
g_radial.o:      $(HEADERS) g_radial.cpp
g_rcs.o:         $(HEADERS) g_rcs.cpp
g_roc.o:         $(HEADERS) g_roc.cpp
g_rollrate.o:    $(HEADERS) g_rollrate.cpp
g_velocity.o:    $(HEADERS) g_velocity.cpp
g_yawrate.o:     $(HEADERS) g_yawrate.cpp
airdensity.o:    $(HEADERS) airdensity.cpp
body.o:          $(HEADERS) body.cpp
booster.o:       $(HEADERS) booster.cpp
command.o:       $(HEADERS) command.cpp
gauge.o:         $(HEADERS) gauge.cpp
helpers.o:       $(HEADERS) helpers.cpp
load.o:          $(HEADERS) load.cpp
main.o:          $(HEADERS) main.cpp
matrix.o:        $(HEADERS) matrix.cpp
panel.o:         $(HEADERS) panel.cpp
save.o:          $(HEADERS) save.cpp
spacecraft.o:    $(HEADERS) spacecraft.cpp
terminal.o:      $(HEADERS) terminal.cpp
vector.o:        $(HEADERS) vector.cpp
vehicle.o:       $(HEADERS) vehicle.cpp


