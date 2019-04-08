PROJECT = gcasm
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
	../common/terminal.o \
	gcasm.o

all: $(PROJECT) core.lm

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(INCDIR) $(INCS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

core.lm:   gcasm lm.asm
	./gcasm lm.asm
	mv core.bin core.lm

clean:
	-rm *.o
	-rm $(PROJECT)
	-rm core.bin
	-rm core.lm

gcasm.o:    $(HEADERS) gcasm.cpp

