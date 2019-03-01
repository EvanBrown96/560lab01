lab: main.o UserInput.o EmptyStructure.o FullStructure.o NumberParser.o NumberParseError.o
	g++ -std=c++11 -g main.o UserInput.o EmptyStructure.o FullStructure.o NumberParser.o NumberParseError.o -o lab

main.o: main.cpp UserInput.hpp Traversal.hpp Traversal.cpp Preorder.hpp Preorder.cpp Postorder.hpp Postorder.cpp Inorder.hpp Inorder.cpp Levelorder.hpp Levelorder.cpp QuickQueue.hpp QuickQueue.cpp BinarySearchTree.hpp BinarySearchTree.cpp BSTNode.hpp BSTNode.cpp ValueNotFound.hpp ValueNotFound.cpp LinkedList.hpp LinkedList.cpp Node.hpp Node.cpp
	g++ -std=c++11 -g -c main.cpp

UserInput.o: UserInput.hpp UserInput.cpp Traversal.hpp Traversal.cpp Preorder.hpp Preorder.cpp Postorder.hpp Postorder.cpp Inorder.hpp Inorder.cpp Levelorder.hpp Levelorder.cpp QuickQueue.hpp QuickQueue.cpp BinarySearchTree.hpp BinarySearchTree.cpp BSTNode.hpp BSTNode.cpp ValueNotFound.hpp ValueNotFound.cpp
	g++ -std=c++11 -g -c UserInput.cpp

EmptyStructure.o: EmptyStructure.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

FullStructure.o: FullStructure.cpp FullStructure.hpp
	g++ -std=c++11 -g -c FullStructure.cpp

NumberParser.o: NumberParser.cpp NumberParser.hpp NumberParseError.hpp
	g++ -std=c++11 -g -c NumberParser.cpp

NumberParseError.o: NumberParseError.cpp NumberParseError.hpp
	g++ -std=c++11 -g -c NumberParseError.cpp


clean:
	rm -f lab *.o
