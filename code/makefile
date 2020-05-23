
G++FLAGS=-std=c++11 -g

poker: ring.o player.o cards.o game_master.o main.o hands.o play_round.o
	g++ $(G++FLAGS) -o poker ring.o player.o cards.o main.o game_master.o hands.o play_round.o

cards.o: cards.cpp
	g++ $(G++FLAGS) -c cards.cpp

player.o: cards.cpp player.cpp
	g++ $(G++FLAGS) -c cards.cpp player.cpp

hands.o: cards.cpp hands.cpp
	g++ $(G++FLAGS) -c cards.cpp hands.cpp

ring.o: player.cpp cards.cpp ring.cpp
	g++ $(G++FLAGS) -c cards.cpp player.cpp ring.cpp

game_master.o: player.cpp cards.cpp ring.cpp game_master.cpp hands.cpp play_round.cpp
	g++ $(G++FLAGS) -c cards.cpp player.cpp ring.cpp game_master.cpp hands.cpp play_round.cpp

main.o: player.cpp cards.cpp ring.cpp game_master.cpp main.cpp play_round.cpp
	g++ $(G++FLAGS) -c cards.cpp player.cpp ring.cpp game_master.cpp main.cpp hands.cpp play_round.cpp

clean: 
	rm *.o
	rm poker

