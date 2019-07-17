PROJECT = planner
CC = g++
# MINGW
#DEFS = -Wall -DMINGW -UWIN32 -static-libstdc++ -static-libgcc -static

#Linux
DEFS = -Wall

INCDIR = -I../common
INCS =
LIBDIR =
LIBS = -lm
HEADERS = ../common/types.h

OBJS = \
	box.o \
	categoryexists.o \
	clearscreen.o \
	doloadout.o \
	flush.o \
	getregion.o \
	hidemapcursor.o \
	input.o \
	loadcategories.o \
	loadmap.o \
	loadoutmenu.o \
	main.o \
	mainmenu.o \
	menu.o \
	missioneditor.o \
	numericdialog.o \
	selectfrommap.o \
	selectvehicle.o \
	showloadout.o \
	showmap.o \
	showmapcursor.o \
	showmapdata.o \
	showselections.o \
	showvehicle.o \
	writecentered.o \
	../common/helpers.o \
	../common/lander.o \
	../common/lfsr.o \
	../common/map.o \
	../common/mission.o \
	../common/random.o \
	../common/vector.o \
	../common/matrix.o \
	../common/terminal.o


$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(INCDIR) $(INCS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

clean:
	-rm *.o
	-rm $(PROJECT)

box.o:                   $(HEADERS) box.cpp
categoryexists.o:        $(HEADERS) categoryexists.cpp
clearscreen.o:           $(HEADERS) clearscreen.cpp
doloadout.o:             $(HEADERS) doloadout.cpp
flush.o:                 $(HEADERS) flush.cpp
hidemapcursor.o:         $(HEADERS) hidemapcursor.cpp
input.o:                 $(HEADERS) input.cpp
getregion.o:             $(HEADERS) getregion.cpp
loadcategories.o:        $(HEADERS) loadcategories.cpp
loadmap.o:               $(HEADERS) loadmap.cpp
loadoutmenu.o:           $(HEADERS) loadoutmenu.cpp
main.o:                  $(HEADERS) main.cpp
mainmenu.o:              $(HEADERS) mainmenu.cpp
menu.o:                  $(HEADERS) menu.cpp
missioneditor.o:         $(HEADERS) missioneditor.cpp
numericdialog.o:         $(HEADERS) numericdialog.cpp
selectfrommap.o:         $(HEADERS) selectfrommap.cpp
selectvehicle.o:         $(HEADERS) selectvehicle.cpp
showloadout.o:           $(HEADERS) showloadout.cpp
showmap.o:               $(HEADERS) showmap.cpp
showmapcursor.o:         $(HEADERS) showmapcursor.cpp
showmapdata.o:           $(HEADERS) showmapdata.cpp
showselections.o:        $(HEADERS) showselections.cpp
showvehicle.o:           $(HEADERS) showvehicle.cpp
writecentered.o:         $(HEADERS) writecentered.cpp
