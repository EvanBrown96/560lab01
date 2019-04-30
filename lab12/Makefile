lab: main.o EmptyStructure.o
	g++ -std=c++11 -g main.o EmptyStructure.o -o lab

main.o: main.cpp Graph.hpp Graph.cpp GraphNode.hpp GraphNode.cpp PriQueue.hpp PriQueue.cpp MinHeap.hpp MinHeap.cpp Heap.hpp Heap.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -c main.cpp

EmptyStructure.o: EmptyStructure.cpp EmptyStructure.cpp
	g++ -std=c++11 -g -c EmptyStructure.cpp
