output: main.o POKER.o
	g++ main.o POKER.o -o output
main.o: main.cpp
	g++ -c main.cpp
POKER.o: POKER.cpp POKER.h pokeralgorytmy.h
	g++ -c POKER.cpp
clean:
	rm *.o output
