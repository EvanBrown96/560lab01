lab: main.o EmptyStructure.o InvalidNodeType.o
	g++ -std=c++11 -g main.o EmptyStructure.o InvalidNodeType.o -o lab

main.o: main.cpp EmptyStructure.hpp TwoThreeTree.hpp TwoThreeTree.cpp ValueNotFound.hpp ValueNotFound.cpp TwoThreeNode.hpp TwoThreeNode.cpp DuplicateValue.hpp DuplicateValue.cpp
	g++ -std=c++11 -g -c main.cpp

EmptyStructure.o: EmptyStructure.hpp EmptyStructure.cpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

InvalidNodeType.o: InvalidNodeType.hpp InvalidNodeType.cpp
	g++ -std=c++11 -g -c InvalidNodeType.cpp

clean:
	rm -f lab *.o
