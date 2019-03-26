lab: main.o EmptyStructure.o InvalidNodeType.o ParseError.o InputParser.o String.o
	g++ -std=c++11 -g main.o EmptyStructure.o InvalidNodeType.o ParseError.o InputParser.o String.o -o lab

main.o: main.cpp InputParser.hpp String.hpp QuickQueue.hpp QuickQueue.cpp TwoThreeTree.hpp TwoThreeTree.cpp TwoThreeNode.hpp TwoThreeNode.cpp ParseError.hpp EmptyStructure.hpp ValueNotFound.hpp ValueNotFound.cpp DuplicateValue.hpp DuplicateValue.cpp
	g++ -std=c++11 -g -c main.cpp

EmptyStructure.o: EmptyStructure.hpp EmptyStructure.cpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

InvalidNodeType.o: InvalidNodeType.hpp InvalidNodeType.cpp
	g++ -std=c++11 -g -c InvalidNodeType.cpp

ParseError.o: ParseError.hpp ParseError.cpp
	g++ -std=c++11 -g -c ParseError.cpp

InputParser.o: InputParser.hpp InputParser.cpp String.hpp QuickQueue.hpp QuickQueue.cpp ParseError.hpp EmptyStructure.hpp ValueNotFound.hpp ValueNotFound.cpp
	g++ -std=c++11 -g -c InputParser.cpp

String.o: String.hpp String.cpp
	g++ -std=c++11 -g -c String.cpp

clean:
	rm -f lab *.o
