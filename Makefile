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
           g_amsspin.h g_amsstat.h g_amswest.h
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
        g_amsmsg.o \
        g_amspilot.o \
        g_amsplss.o \
        g_amsseq.o \
        g_amsspin.o \
        g_amsstat.o \
	g_amswest.o \
	groundvehicle.o \
	ins.o \
	load.o \
	lrv.o \
	save.o \
	lunarmodule.o \
	matrix.o \
	panel.o \
	plss.o \
	sequencer.o \
	sgn.o \
	terminal.o \
	vector.o \
	vehicle.o \
	main.o

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

rmsave:
	-rm *.sav

clean:
	-rm $(PROJECT)
	-rm *.o

csm.o:           $(HEADERS) csm.cpp
gauge.o:         $(HEADERS) gauge.h gauge.cpp
groundvehicle.o: $(HEADERS) vehicle.h groundvehicle.h groundvehicle.cpp
ins.o:           $(HEADERS) ins.cpp
load.o:          $(HEADERS) load.cpp
lrv.o:           $(HEADERS) vehicle.h lrv.h lrv.cpp
main.o:          $(HEADERS) main.cpp
matrix.o:        $(HEADERS) matrix.cpp
panel.o:         $(HEADERS) $(PHEADERS)  panel.cpp
plss.o:          #(HEADERS) vehicle.h plss.h plss.cpp
save.o:          $(HEADERS) save.cpp
sgn.o:           $(HEADERS) sgn.cpp
sequencer.o:     $(HEADERS) sequencer.cpp
lunarmodule.o:   $(HEADERS) lunarmodule.cpp
terminal.o:      $(HEADERS) terminal.cpp
vector.o:        $(HEADERS) vector.cpp
vehicle.o:       $(HEADERS) vehicle.h panel.h gauge.h vehicle.cpp

g_amsatt.o:    $(HEADERS) gauge.h g_amsatt.h terminal.h g_amsatt.cpp
g_amsclocks.o: $(HEADERS) gauge.h g_amsclocks.h terminal.h g_amsclocks.cpp
g_amscons.o:   $(HEADERS) gauge.h g_amscons.h terminal.h g_amscons.cpp
g_amsdock.o:   $(HEADERS) gauge.h g_amsdock.h terminal.h g_amsdock.cpp
g_amsdown.o:   $(HEADERS) gauge.h g_amsdown.h terminal.h g_amsdown.cpp
g_amsins.o:    $(HEADERS) gauge.h g_amsins.h terminal.h g_amsins.cpp
g_amsland.o:   $(HEADERS) gauge.h g_amsland.h terminal.h g_amsland.cpp
g_amslm.o:     $(HEADERS) gauge.h g_amslm.h terminal.h g_amslm.cpp
g_amslrv.o:    $(HEADERS) gauge.h g_amslrv.h terminal.h g_amslrv.cpp
g_amsmsg.o:    $(HEADERS) gauge.h g_amsmsg.h terminal.h g_amsmsg.cpp
g_amspilot.o:  $(HEADERS) gauge.h g_amspilot.h terminal.h g_amspilot.cpp
g_amsplss.o:   $(HEADERS) gauge.h g_amsplss.h terminal.h g_amsplss.cpp
g_amsseq.o:    $(HEADERS) gauge.h g_amsseq.h terminal.h g_amsseq.cpp
g_amsspin.o:   $(HEADERS) gauge.h g_amsspin.h terminal.h g_amsspin.cpp
g_amsstat.o:   $(HEADERS) gauge.h g_amsstat.h terminal.h g_amsstat.cpp
g_amswest.o:   $(HEADERS) gauge.h g_amswest.h terminal.h g_amswest.cpp

