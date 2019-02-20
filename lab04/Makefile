lab: main.o UserInput.o NumberParser.o NumberParseError.o CollisionResolution.o QuadraticProbing.o DoubleHashing.o EmptyList.o EmptyLocation.o RandomGenerator.o Timer.o
	g++ -std=c++11 -g main.o UserInput.o NumberParser.o NumberParseError.o CollisionResolution.o QuadraticProbing.o DoubleHashing.o EmptyList.o EmptyLocation.o RandomGenerator.o Timer.o -o lab

main.o: main.cpp ClosedHashTable.cpp ClosedHashTable.hpp HashElement.cpp HashElement.hpp OpenHashTable.cpp OpenHashTable.hpp LinkedList.cpp LinkedList.hpp Node.cpp Node.hpp DuplicateValue.cpp DuplicateValue.hpp ValueNotFound.cpp ValueNotFound.hpp
	g++ -std=c++11 -g -c main.cpp

UserInput.o: UserInput.cpp ClosedHashTable.cpp ClosedHashTable.hpp HashElement.cpp HashElement.hpp OpenHashTable.cpp OpenHashTable.hpp LinkedList.cpp LinkedList.hpp Node.cpp Node.hpp DuplicateValue.cpp DuplicateValue.hpp ValueNotFound.cpp ValueNotFound.hpp
	g++ -std=c++11 -g -c UserInput.cpp

NumberParser.o: NumberParser.cpp NumberParser.hpp NumberParseError.hpp
	g++ -std=c++11 -g -c NumberParser.cpp

NumberParseError.o: NumberParseError.cpp NumberParseError.hpp
	g++ -std=c++11 -g -c NumberParseError.cpp

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

RandomGenerator.o: RandomGenerator.cpp RandomGenerator.hpp
	g++ -std=c++11 -g -c RandomGenerator.cpp

Timer.o: Timer.cpp Timer.hpp
	g++ -std=c++11 -g -c Timer.cpp

clean:
	rm -f lab *.o
