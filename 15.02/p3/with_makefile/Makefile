OPT=-c -Wall -Wextra

all: main.o sort.dll
	g++ -L. -lsort main.o -o main.exe
main.o: main.cpp funk.h backpack.h
	g++ $(OPT) main.cpp -o main.o
sort.dll: sort.cpp backpack.h
	g++ $(OPT) sort.cpp -o sort.o
	g++ -shared sort.o -o sort.dll
clean:
	rm -f *.o