all: libmyBank.a main
main: libmyBank.a main.o
	gcc -Wall -g -o main main.o libmyBank.a -lm
libmyBank.a: myBank.o
	ar -rcs libmyBank.a myBank.o 
myBank.o: myBank.c 
	gcc -Wall -g -c myBank.c 
main.o: main.c myBank.h
	gcc -Wall -g -c main.c 

.PHONY: clean all 

clean:
		rm -f *.o *.a main 