#
#
object = main.o userprofile.o 

run : $(object)
	g++ -o run $(object) -g

main.o : userprofile.h
	g++ -c main.cpp -o main.o -g
userprofile.o : userprofile.h

.PHONY : clean
clean:
	-rm run $(object)