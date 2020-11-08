CC := g++
CFLAGS := -Wall -std=c++11

exec := pic

obj := main.o Picture.o

.PHONY : all clean

all : $(exec)

$(exec) : $(obj)
	$(CC) -o $(exec) $(CFLAGS) $^

main.o : main.cpp Picture.h
	$(CC) -c -o $@ $(CFLAGS) $<
	
Picture.o : Picture.cpp Picture.h
	$(CC) -c -o $@ $(CFLAGS) $<
	
clean :
	@$(RM) $(obj) $(exec)
