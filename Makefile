lab: main.o
	g++ -std=c++11 main.o -o lab

main.o: main.cpp HashTable.hpp HashTable.cpp LinkedList.cpp LinkedList.hpp Node.cpp Node.hpp exceptions/ValueNotFound.cpp exceptions/ValueNotFound.hpp
	g++ -std=c++11 -c main.cpp

EmptyList.o: exceptions/EmptyList.cpp exceptions/EmptyList.hpp
	g++ -std=c++11 -c exceptions/EmptyList.cpp

clean:
	rm -f lab *.o
