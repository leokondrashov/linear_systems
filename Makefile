CXX = g++ 
CXXFLAGS = -Wall -g -MMD

.PHONY: clean all

all: linear_system 

clean:
	rm *.d
	rm *.o
	rm linear_system

linear_system: vector.o matrix.o seidel.o gauss.o

-include *.d

