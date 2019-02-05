lab: main.o EmptyList.o NumberParseError.o NumberParser.o UserInput.o
	g++ -std=c++11 main.o EmptyList.o NumberParseError.o NumberParser.o UserInput.o -o lab

main.o: main.cpp HashTable.hpp HashTable.cpp LinkedList.cpp LinkedList.hpp Node.cpp Node.hpp ValueNotFound.cpp ValueNotFound.hpp DuplicateValue.cpp DuplicateValue.hpp
	g++ -std=c++11 -c main.cpp

EmptyList.o: EmptyList.cpp EmptyList.hpp
	g++ -std=c++11 -c EmptyList.cpp

NumberParseError.o: NumberParseError.cpp NumberParseError.hpp
	g++ -std=c++11 -c NumberParseError.cpp

NumberParser.o: NumberParser.cpp NumberParser.hpp
	g++ -std=c++11 -c NumberParser.cpp

UserInput.o: UserInput.cpp UserInput.hpp
	g++ -std=c++11 -c UserInput.cpp

clean:
	rm -f lab *.o
