lab: main.o
	g++ -std=c++11 main.o -o lab

main.o: main.cpp HashTable.hpp HashTable.cpp
	g++ -std=c++11 -c main.cpp

clean:
	rm -f lab *.o
