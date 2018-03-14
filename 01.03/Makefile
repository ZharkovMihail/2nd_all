
all:main.o quaternions.o functions.o
	g++ main.o quaternions.o functions.o -o main.exe
main.o:main.cpp func.h quaternions.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra main.cpp -o main.o
quaternions.o:quaternions.cpp quaternions.h func.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra quaternions.cpp -o quaternions.o
func.o:functions.cpp quaternions.h func.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra functions.cpp -o functions.o
clean:
	rm -f *.o