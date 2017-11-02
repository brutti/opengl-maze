CC = g++
LIBC = -Wall -lm
LIBGL = -lGL -lGLU -lglut
SRC_DIR = src/

all: robot maze objects
	$(CC) $(SRC_DIR)main.cpp $(SRC_DIR)robot.o $(SRC_DIR)maze.o $(SRC_DIR)objects.o -o main $(LIBGL) $(LIBC)
objects:
	$(CC) -c $(SRC_DIR)objects.cpp
	mv objects.o $(SRC_DIR)
maze:
	$(CC) -c $(SRC_DIR)maze.cpp
	mv maze.o $(SRC_DIR)
robot:
	$(CC) -c $(SRC_DIR)robot.cpp
	mv robot.o $(SRC_DIR)
clean:
	rm -rf $(SRC_DIR)*.o main
