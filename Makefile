all:
	g++ -Iinclude -Llib -o Main src/*.cpp -lSDL2main -lSDL2 -lSDL2_image -std=c++11 -O3

debug:
	g++ -Iinclude -Llib -o Main src/*.cpp -lSDL2main -lSDL2 -lSDL2_image -std=c++11 -O2 -Wall -g -pedantic