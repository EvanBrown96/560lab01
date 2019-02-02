lab: main.o EmptyList.o NumberParseError.o NumberParser.o
	g++ -std=c++11 main.o EmptyList.o NumberParseError.o NumberParser.o -o lab

main.o: main.cpp HashTable.hpp HashTable.cpp LinkedList.cpp LinkedList.hpp Node.cpp Node.hpp exceptions/ValueNotFound.cpp exceptions/ValueNotFound.hpp exceptions/DuplicateValue.cpp exceptions/DuplicateValue.hpp
	g++ -std=c++11 -c main.cpp

EmptyList.o: exceptions/EmptyList.cpp exceptions/EmptyList.hpp
	g++ -std=c++11 -c exceptions/EmptyList.cpp

NumberParseError.o: exceptions/NumberParseError.cpp exceptions/NumberParseError.hpp
	g++ -std=c++11 -c exceptions/NumberParseError.cpp

NumberParser.o: NumberParser.cpp NumberParser.hpp
	g++ -std=c++11 -c NumberParser.cpp

clean:
	rm -f lab *.o
