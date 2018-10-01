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


$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(INCDIR) $(INCS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

clean:
	-rm *.o
	-rm $(PROJECT)

planner.o:    $(HEADERS) planner.cpp

