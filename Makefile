CC= g++
CFLAGS= -Wextra -Wvla -Wall -std=c++14 -g

all: test

test:  test.o
	$(CC) $(CFLAGS) test.o -o test

test.o: my_set.cpp my_set.hpp my_set.h
	$(CC) -c $(CFLAGS) my_set.cpp -o test.o

clean:
	-rm -f *.o test
