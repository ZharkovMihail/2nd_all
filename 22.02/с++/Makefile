
all: main.o parse_opt.o read.o write_ans.o
	g++ -std=gnu++11 -O0 -Wall -Wextra main.o parse_opt.o read.o write_ans.o calc.o -o main.exe
main.o: main.cpp gauss.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra main.cpp -o main.o
parse_opt.o: parse_opt.cpp
	g++ -c -std=gnu++11 -O0 -Wall -Wextra parse_opt.cpp -o parse_opt.o
read.o: read.cpp gauss.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra read.cpp -o read.o	
write_ans.o: write_ans.cpp calc.o gauss.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra write_ans.cpp -o write_ans.o
calc.o: calc.cpp gauss.h const.h
	g++ -c -std=gnu++11 -O0 -Wall -Wextra calc.cpp -o calc.o
clean:
	rm -f *.o