lab: main.o EmptyTree.o
	g++ -std=c++11 -g main.o EmptyTree.o -o lab

main.o: main.cpp Traversal.hpp Traversal.cpp Preorder.hpp Preorder.cpp Postorder.hpp Postorder.cpp Inorder.hpp Inorder.cpp Levelorder.hpp Levelorder.cpp BinarySearchTree.hpp BinarySearchTree.cpp BSTNode.hpp BSTNode.cpp ValueNotFound.hpp ValueNotFound.cpp
	g++ -std=c++11 -g -c main.cpp

EmptyTree.o: EmptyTree.cpp EmptyTree.hpp
	g++ -std=c++11 -g -c EmptyTree.cpp



clean:
	rm -f lab *.o
