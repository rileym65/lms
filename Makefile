PROJECT = lms
CC = g++
DEFS =
INCDIR =
INCS =
LIBDIR =
LIBS =
HEADERS = header.h console.h vehicle.h csm.h lunarmodule.h
OBJS = \
	console.o \
	csm.o \
	load.o \
	save.o \
	lunarmodule.o \
	terminal.o \
	vector.o \
	vehicle.o \
	main.o

$(PROJECT): $(OBJS)
	$(CC) $(DEFS) $(LIBDIR) $(OBJS) $(LIBS) -o $(PROJECT)

.cpp.o:
	$(CC) $(DEFS) $(INCDIR) $(INCS) -c $<

clean:
	-rm $(PROJECT)
	-rm *.o

console.o:     $(HEADERS) console.cpp
csm.o:         $(HEADERS) csm.cpp
load.o:        $(HEADERS) load.cpp
main.o:        $(HEADERS) main.cpp
save.o:        $(HEADERS) save.cpp
lunarmodule.o: $(HEADERS) lunarmodule.cpp
terminal.o:    $(HEADERS) terminal.cpp
vector.o:      $(HEADERS) vector.cpp
