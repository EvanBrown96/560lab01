lab: main.o UserInput.o CollisionResolution.o LinearProbing.o CharacterWrapper.o InputParser.o ParseError.o EmptyList.o EmptyLocation.o
	g++ -std=c++11 -g main.o UserInput.o CollisionResolution.o LinearProbing.o CharacterWrapper.o InputParser.o ParseError.o EmptyList.o EmptyLocation.o -o lab

main.o: main.cpp HashTable.hpp HashTable.cpp HashElement.hpp HashElement.cpp
	g++ -std=c++11 -g -c main.cpp

UserInput.o: UserInput.cpp UserInput.hpp
	g++ -std=c++11 -g -c UserInput.cpp

CollisionResolution.o: CollisionResolution.cpp CollisionResolution.hpp
	g++ -std=c++11 -g -c CollisionResolution.cpp

LinearProbing.o: LinearProbing.cpp LinearProbing.hpp
	g++ -std=c++11 -g -c LinearProbing.cpp

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
