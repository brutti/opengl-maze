CC = g++
LIBC = -Wall -lm
LIBGL = -lGL -lGLU -lglut
SRC_DIR = src/

all: robot
	$(CC) $(SRC_DIR)main.cpp $(SRC_DIR)robot.o -o main $(LIBGL) $(LIBC)
robot:
	$(CC) -c $(SRC_DIR)robot.cpp
	mv robot.o $(SRC_DIR)
clean:
	rm -rf *.o main