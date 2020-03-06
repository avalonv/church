# GCC command: g++ -std=c++14 -Wall ptype.cpp Game.cpp Area.cpp Player.cpp  -lncurses

output: ptype.o Game.o Area.o Player.o
	g++ ptype.o Game.o Area.o Player.o -lncurses -o church.out

ptype.o: ptype.cpp
	g++ -c ptype.cpp

Game.o: Game.cpp Game.h
	g++ -c Game.cpp

Area.o: Area.cpp Area.h
	g++ -c Area.cpp

Player.o: Player.cpp Player.h
	g++ -c Player.cpp

clean:
	rm *.o
