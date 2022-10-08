CFLAGS = -O
CC = g++
SRC = main.cpp request.cpp request-queue.cpp server.cpp server-group.cpp
OBJ = $(SRC:.cpp = .o)

all: build run

build: $(OBJ)
	$(CC) $(CFLAGS) -o LoadBalancingSimulator $(OBJ)

run:
	./LoadBalancingSimulator
	
clean:
	rm -f core *.o