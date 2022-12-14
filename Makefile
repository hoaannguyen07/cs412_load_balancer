CFLAGS = -O
CC = g++
SRC = main.cpp request.cpp request-queue.cpp server.cpp server-group.cpp load-balancer.cpp test-load-balancer.cpp
OBJ = $(SRC:.cpp = .o)

all: build run

build: $(OBJ)
	$(CC) $(CFLAGS) -o LoadBalancingSimulator.exe $(OBJ)

run: build
	./LoadBalancingSimulator.exe
	
clean:
	rm -f core *.o