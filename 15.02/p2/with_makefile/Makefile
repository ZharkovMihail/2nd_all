OPT=-c -Wall -Wextra

all: main.o sort.o
	g++ main.o sort.o -o main.exe
main.o: main.cpp funk.h backpack.h
	g++ $(OPT) main.cpp -o main.o
sort.o: sort.cpp backpack.h
	g++ $(OPT) sort.cpp -o sort.o
clean:
	rm -f *.o