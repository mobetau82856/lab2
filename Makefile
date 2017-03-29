main: A.o
	g++ -o main A.o

A.o: A.cpp A.h
	g++ -c A.cpp

clean:
	rm A *.o
