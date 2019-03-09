lab: main.o EmptyStructure.o FullStructure.o
	g++ -std=c++11 -g main.o EmptyStructure.o FullStructure.o -o lab

main.o: main.cpp Traversal.hpp Traversal.cpp Preorder.hpp Preorder.cpp Postorder.hpp Postorder.cpp Inorder.hpp Inorder.cpp Levelorder.hpp Levelorder.cpp QuickQueue.hpp QuickQueue.cpp BinarySearchTree.hpp BinarySearchTree.cpp BSTNode.hpp BSTNode.cpp ValueNotFound.hpp ValueNotFound.cpp
	g++ -std=c++11 -g -c main.cpp

EmptyStructure.o: EmptyStructure.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

FullStructure.o: FullStructure.cpp FullStructure.hpp
	g++ -std=c++11 -g -c FullStructure.cpp

clean:
	rm -f lab *.o
