PROJECT = lms
CC = g++
DEFS =
INCDIR =
INCS =
LIBDIR =
LIBS =
OBJS = \
	console.o \
	save.o \
	spacecraft.o \
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

console.o:    header.h console.cpp
main.o:       header.h main.cpp
save.o:       header.h save.cpp
spacecraft.o: header.h spacecraft.cpp
vector.o:     header.h vector.cpp
