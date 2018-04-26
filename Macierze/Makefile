CC = g++

main.out : main.o Matrix.o Test.o View.o
	$(CC) main.o Matrix.o Test.o View.o -o main.out

main.o : main.cpp
	$(CC) -g -c main.cpp -o main.o

Matrix.o : Matrix.o Matrix.hpp
	$(CC) -g -c Ship.cpp -o Ship.o

Test.o : Test.o Test.hpp Matrix.hpp
	$(CC) -g -c Test.cpp -o Test.o
		
View.o : View.cpp View.hpp Matrix.hpp
	$(CC) -g -c View.cpp -o View.o
	
clear :
	rm *.o main.out
