lab: main.o UserInput.o InputParser.o String.o ParseError.o EmptyStructure.o Timer.o RandomGenerator.o
	g++ -std=c++11 -g main.o UserInput.o InputParser.o String.o ParseError.o EmptyStructure.o Timer.o RandomGenerator.o -o lab

main.o: main.cpp UserInput.hpp BinarySearchTree.hpp BinarySearchTree.cpp BSTNode.hpp BSTNode.cpp Traversal.hpp Traversal.cpp Preorder.hpp Preorder.cpp Inorder.hpp Inorder.cpp Postorder.hpp Postorder.cpp Levelorder.hpp Levelorder.cpp MinHeap.hpp MinHeap.cpp MaxHeap.hpp MaxHeap.cpp Heap.hpp Heap.cpp QuickQueue.hpp QuickQueue.cpp ValueNotFound.hpp ValueNotFound.cpp EmptyStructure.hpp ParseError.hpp
	g++ -std=c++11 -g -c main.cpp

UserInput.o: UserInput.hpp UserInput.cpp Timer.hpp RandomGenerator.hpp BinarySearchTree.hpp BinarySearchTree.cpp BSTNode.hpp BSTNode.cpp Traversal.hpp Traversal.cpp Preorder.hpp Preorder.cpp Inorder.hpp Inorder.cpp Postorder.hpp Postorder.cpp Levelorder.hpp Levelorder.cpp MinHeap.hpp MinHeap.cpp MaxHeap.hpp MaxHeap.cpp Heap.hpp Heap.cpp QuickQueue.hpp QuickQueue.cpp ValueNotFound.hpp ValueNotFound.cpp EmptyStructure.hpp ParseError.hpp
	g++ -std=c++11 -g -c UserInput.cpp

InputParser.o: InputParser.hpp InputParser.cpp QuickQueue.hpp QuickQueue.cpp String.hpp ParseError.hpp EmptyStructure.hpp
	g++ -std=c++11 -g -c InputParser.cpp

String.o: String.hpp String.cpp
	g++ -std=c++11 -g -c String.cpp

ParseError.o: ParseError.hpp ParseError.cpp
	g++ -std=c++11 -g -c ParseError.cpp

EmptyStructure.o: EmptyStructure.hpp EmptyStructure.cpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

Timer.o: Timer.hpp Timer.cpp
	g++ -std=c++11 -g -c Timer.cpp

RandomGenerator.o: RandomGenerator.hpp RandomGenerator.cpp
	g++ -std=c++11 -g -c RandomGenerator.cpp

clean:
	rm -f *.o lab lab.exe
