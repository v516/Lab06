prog: matrix.o
	g++ -g -Wall -std=c++11 matrix.o -o prog

matrix.o: matrix.cpp
	g++ -g -Wall -std=c++11 -c matrix.cpp

clean:
	rm *.o prog

