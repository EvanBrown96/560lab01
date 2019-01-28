lab: main.o UserInput.o EmptyList.o NumberParser.o
	g++ -std=c++11 main.o UserInput.o EmptyList.o NumberParser.o -o lab

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

UserInput.o: UserInput.cpp UserInput.hpp LinkedList.cpp LinkedList.hpp Node.cpp Node.hpp ValueNotFound.cpp ValueNotFound.hpp
	g++ -std=c++11 -c UserInput.cpp

EmptyList.o: EmptyList.cpp EmptyList.hpp
	g++ -std=c++11 -c EmptyList.cpp

NumberParser.o: NumberParser.cpp NumberParser.hpp
	g++ -std=c++11 -c NumberParser.cpp

clean:
	rm -f lab *.o
