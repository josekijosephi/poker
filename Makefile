G++FLAGS=-std=c++11 -g

poker: ring.o player.o cards.o game_master.o main.o hands.o play_round.o
	g++ $(G++FLAGS) -o poker ring.o player.o cards.o main.o game_master.o hands.o play_round.o

cards.o: ./code/cards.cpp
	g++ $(G++FLAGS) -c ./code/cards.cpp

player.o: ./code/cards.cpp ./code/player.cpp
	g++ $(G++FLAGS) -c ./code/cards.cpp ./code/player.cpp

hands.o: ./code/cards.cpp ./code/hands.cpp
	g++ $(G++FLAGS) -c ./code/cards.cpp ./code/hands.cpp

ring.o: ./code/player.cpp ./code/cards.cpp ./code/ring.cpp
	g++ $(G++FLAGS) -c ./code/cards.cpp ./code/player.cpp ./code/ring.cpp

game_master.o: ./code/player.cpp ./code/cards.cpp ./code/ring.cpp ./code/game_master.cpp ./code/hands.cpp ./code/play_round.cpp
	g++ $(G++FLAGS) -c ./code/cards.cpp ./code/player.cpp ./code/ring.cpp ./code/game_master.cpp ./code/hands.cpp ./code/play_round.cpp

main.o: ./code/player.cpp ./code/cards.cpp ./code/ring.cpp ./code/game_master.cpp ./code/main.cpp ./code/play_round.cpp
	g++ $(G++FLAGS) -c ./code/cards.cpp ./code/player.cpp ./code/ring.cpp ./code/game_master.cpp ./code/main.cpp ./code/hands.cpp ./code/play_round.cpp

clean: 
	rm *.o
	rm poker

