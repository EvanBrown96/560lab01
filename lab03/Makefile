lab: main.o CollisionResolution.o LinearProbing.o CharacterWrapper.o InputFileParser.o ParseError.o EmptyList.o
	g++ -std=c++11 main.o CollisionResolution.o LinearProbing.o CharacterWrapper.o InputFileParser.o ParseError.o EmptyList.o -o lab

main.o: main.cpp HashTable.hpp HashTable.cpp HashElement.hpp HashElement.cpp
	g++ -std=c++11 -c main.cpp

CollisionResolution.o: CollisionResolution.cpp CollisionResolution.hpp
	g++ -std=c++11 -c CollisionResolution.cpp

LinearProbing.o: LinearProbing.cpp LinearProbing.hpp
	g++ -std=c++11 -c LinearProbing.cpp

CharacterWrapper.o: CharacterWrapper.cpp CharacterWrapper.hpp
	g++ -std=c++11 -c CharacterWrapper.cpp

InputFileParser.o: InputFileParser.cpp InputFileParser.hpp
	g++ -std=c++11 -c InputFileParser.cpp

ParseError.o: ParseError.cpp ParseError.hpp
	g++ -std=c++11 -c ParseError.cpp

EmptyList.o: EmptyList.cpp EmptyList.hpp
	g++ -std=c++11 -c EmptyList.cpp

clean:
	rm -f lab *.o
