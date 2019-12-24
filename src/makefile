all: Transition.cpp  Game.cpp Graph.cpp utils.cpp main.cpp

	g++ -O3 -march=native -std=c++11 Transition.cpp  Game.cpp  Graph.cpp utils.cpp main.cpp -w -o game

test: main2.cpp Transition.cpp Graph.cpp utils.cpp

	g++ -O3 -march=native -std=c++11 main2.cpp Transition.cpp  Graph.cpp utils.cpp -lgmpxx -lgmp -o test
