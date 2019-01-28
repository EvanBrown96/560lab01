lab: main.o UserInput.o EmptyList.o NumberParser.o NumberParseError.o
	g++ -std=c++11 main.o UserInput.o EmptyList.o NumberParser.o NumberParseError.o -o lab

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

UserInput.o: UserInput.cpp UserInput.hpp LinkedList.cpp LinkedList.hpp Node.cpp Node.hpp exceptions/ValueNotFound.cpp exceptions/ValueNotFound.hpp
	g++ -std=c++11 -c UserInput.cpp

EmptyList.o: exceptions/EmptyList.cpp exceptions/EmptyList.hpp
	g++ -std=c++11 -c exceptions/EmptyList.cpp

NumberParser.o: NumberParser.cpp NumberParser.hpp
	g++ -std=c++11 -c NumberParser.cpp

NumberParseError.o: exceptions/NumberParseError.cpp exceptions/NumberParseError.hpp
	g++ -std=c++11 -c exceptions/NumberParseError.cpp

clean:
	rm -f lab *.o
