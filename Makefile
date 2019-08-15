out : hello.o
	gcc -o out hello.o
hello.o:hello.c
	gcc -c hello.c
	
.PHONY : clean
clean:
	rm out hello.o
