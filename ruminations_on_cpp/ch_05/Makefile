
debug := 1
CC := g++
CFLAGS := -Wall -std=c++11 -g
obj := main.o Vehicle.o VehicleSurrogate.o
exec := run

ifeq ($(debug), 1)
	CFLAGS += -DDEBUG
endif
	

.PHONY : all clean

all : $(exec)

$(exec) : $(obj)
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.cpp Vehicle.h VehicleSurrogate.h
	$(CC) $(CFLAGS) -c $<

Vehicle.o : Vehicle.cpp 
	$(CC) $(CFLAGS) -c $<

VehicleSurrogate.o : VehicleSurrogate.cpp VehicleSurrogate.h Vehicle.h
	$(CC) $(CFLAGS) -c $<

clean :
	$(RM) $(obj) $(exec) *.gch
	

