main: main.o matrix.o methods.o
	g++ main.o matrix.o methods.o -std=c++11 -o program

main.o: program.cpp 
	g++ program.cpp -std=c++11 -o main.o -c

matrix.o: matrix.cpp 
	g++ matrix.cpp -std=c++11 -o matrix.o -c

methods.o: methods.cpp 
	g++ methods.cpp -std=c++11 -o methods.o -c
