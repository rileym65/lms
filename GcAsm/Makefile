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

all: $(PROJECT) core

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(INCDIR) $(INCS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

core:   gcasm core.asm
	./gcasm core.asm

clean:
	-rm *.o
	-rm $(PROJECT)
	-rm core.bin

gcasm.o:    $(HEADERS) gcasm.cpp

