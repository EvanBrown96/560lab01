lab: main.o CollisionResolution.o QuadraticProbing.o DoubleHashing.o EmptyList.o EmptyLocation.o
	g++ -std=c++11 -g main.o CollisionResolution.o QuadraticProbing.o DoubleHashing.o EmptyList.o EmptyLocation.o -o lab

main.o: main.cpp ClosedHashTable.cpp ClosedHashTable.hpp HashElement.cpp HashElement.hpp OpenHashTable.cpp OpenHashTable.hpp LinkedList.cpp LinkedList.hpp Node.cpp Node.hpp DuplicateValue.cpp DuplicateValue.hpp ValueNotFound.cpp ValueNotFound.hpp
	g++ -std=c++11 -g -c main.cpp

CollisionResolution.o: CollisionResolution.cpp CollisionResolution.hpp
	g++ -std=c++11 -g -c CollisionResolution.cpp

QuadraticProbing.o: QuadraticProbing.cpp QuadraticProbing.hpp
	g++ -std=c++11 -g -c QuadraticProbing.cpp

DoubleHashing.o: DoubleHashing.cpp DoubleHashing.hpp
	g++ -std=c++11 -g -c DoubleHashing.cpp

EmptyList.o: EmptyList.cpp EmptyList.hpp
	g++ -std=c++11 -g -c EmptyList.cpp

EmptyLocation.o: EmptyLocation.cpp EmptyLocation.hpp
	g++ -std=c++11 -g -c EmptyLocation.cpp

clean:
	rm -f lab *.o
