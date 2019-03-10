lab: main.o EmptyStructure.o FullStructure.o InputParser.o ParseError.o String.o
	g++ -std=c++11 -g main.o EmptyStructure.o FullStructure.o InputParser.o ParseError.o String.o -o lab

main.o: main.cpp Traversal.hpp Traversal.cpp Preorder.hpp Preorder.cpp Postorder.hpp Postorder.cpp Inorder.hpp Inorder.cpp Levelorder.hpp Levelorder.cpp QuickQueue.hpp QuickQueue.cpp BinarySearchTree.hpp BinarySearchTree.cpp BSTNode.hpp BSTNode.cpp ValueNotFound.hpp ValueNotFound.cpp DuplicateValue.hpp DuplicateValue.cpp LinkedList.hpp LinkedList.cpp Node.hpp Node.cpp quicksort.cpp
	g++ -std=c++11 -g -c main.cpp

EmptyStructure.o: EmptyStructure.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

FullStructure.o: FullStructure.cpp FullStructure.hpp
	g++ -std=c++11 -g -c FullStructure.cpp

InputParser.o: InputParser.cpp InputParser.hpp LinkedList.hpp LinkedList.cpp Node.hpp Node.cpp
	g++ -std=c++11 -g -c InputParser.cpp

ParseError.o: ParseError.cpp ParseError.hpp
	g++ -std=c++11 -g -c ParseError.cpp

String.o: String.cpp String.hpp
	g++ -std=c++11 -g -c String.cpp

clean:
	rm -f lab *.o
