PROJECT = lms
CC = g++
DEFS = -Wall
INCDIR =
INCS =
LIBDIR =
LIBS = -lm
HEADERS = header.h console.h vehicle.h csm.h lunarmodule.h ins.h matrix.h
OBJS = \
	console.o \
	csm.o \
	ins.o \
	load.o \
	save.o \
	lunarmodule.o \
	matrix.o \
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

console.o:     $(HEADERS) console.cpp
csm.o:         $(HEADERS) csm.cpp
ins.o:         $(HEADERS) ins.cpp
load.o:        $(HEADERS) load.cpp
main.o:        $(HEADERS) main.cpp
matrix.o:      $(HEADERS) matrix.cpp
save.o:        $(HEADERS) save.cpp
lunarmodule.o: $(HEADERS) lunarmodule.cpp
terminal.o:    $(HEADERS) terminal.cpp
vector.o:      $(HEADERS) vector.cpp
