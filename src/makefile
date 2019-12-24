all: Transition.cpp  Game.cpp Graph.cpp utils.cpp main.cpp

	g++ -O3 -march=native -std=c++11 Transition.cpp  Game.cpp  Graph.cpp utils.cpp main.cpp -w -o game

test: main.cpp Transition.cpp Graph.cpp utils.cpp algorithm.cpp

	g++ -O3 -march=native -std=c++11 main.cpp Transition.cpp  Graph.cpp utils.cpp algorithm.cpp -lgmpxx -lgmp -o test
