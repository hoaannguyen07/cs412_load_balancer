CFLAGS = -O
CC = g++
SRC = main.cpp request.cpp request-queue.cpp
OBJ = $(SRC:.cpp = .o)

all: build run

build: $(OBJ)
	$(CC) $(CFLAGS) -o LoadBalancer $(OBJ)

run: LoadBalancer
	./LoadBalancer
	
clean:
	rm -f core *.o