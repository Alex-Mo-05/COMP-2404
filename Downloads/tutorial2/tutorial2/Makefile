all: p1

p1: Character.o battle.o main.o
	g++ Character.o battle.o main.o -o p1

Character.o: Character.h Character.cc
	g++ -c Character.cc

battle.o: battle.h battle.cc
	g++ -c battle.cc

main.o: main.cc Character.h battle.h
	g++ -c main.cc

clean:
	rm -f *.o p1

