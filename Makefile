default:
	g++ ./src/*.cpp -o Game.exe -O2 -Wall -I ./include/ -L ./lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
