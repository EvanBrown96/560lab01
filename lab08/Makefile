lab: main.o EmptyStructure.o
	g++ -std=c++11 -g main.o EmptyStructure.o -o lab

main.o: main.cpp Heap.hpp Heap.cpp MinHeap.hpp MinHeap.cpp MaxHeap.hpp MaxHeap.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -c main.cpp

EmptyStructure.o: EmptyStructure.hpp EmptyStructure.cpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

clean:
	rm -f lab *.o
