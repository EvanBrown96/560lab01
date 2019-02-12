lab: main.o UserInput.o CollisionResolution.o QuadraticProbing.o DoubleHashing.o CharacterWrapper.o InputParser.o ParseError.o EmptyList.o EmptyLocation.o
	g++ -std=c++11 -g main.o UserInput.o CollisionResolution.o QuadraticProbing.o DoubleHashing.o CharacterWrapper.o InputParser.o ParseError.o EmptyList.o EmptyLocation.o -o lab

main.o: main.cpp HashTable.hpp HashTable.cpp HashElement.hpp HashElement.cpp
	g++ -std=c++11 -g -c main.cpp

UserInput.o: UserInput.cpp UserInput.hpp
	g++ -std=c++11 -g -c UserInput.cpp

CollisionResolution.o: CollisionResolution.cpp CollisionResolution.hpp
	g++ -std=c++11 -g -c CollisionResolution.cpp

QuadraticProbing.o: QuadraticProbing.cpp QuadraticProbing.hpp
	g++ -std=c++11 -g -c QuadraticProbing.cpp

DoubleHashing.o: DoubleHashing.cpp DoubleHashing.hpp
	g++ -std=c++11 -g -c DoubleHashing.cpp

CharacterWrapper.o: CharacterWrapper.cpp CharacterWrapper.hpp
	g++ -std=c++11 -g -c CharacterWrapper.cpp

InputParser.o: InputParser.cpp InputParser.hpp
	g++ -std=c++11 -g -c InputParser.cpp

ParseError.o: ParseError.cpp ParseError.hpp
	g++ -std=c++11 -g -c ParseError.cpp

EmptyList.o: EmptyList.cpp EmptyList.hpp
	g++ -std=c++11 -g -c EmptyList.cpp

EmptyLoation.o: EmptyLocation.cpp EmptyLocation.hpp
	g++ -std=c++11 -g -c EmptyLocation.cpp

clean:
	rm -f lab *.o
