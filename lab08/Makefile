lab: main.o UserInput.o EmptyStructure.o String.o ParseError.o InputParser.o
	g++ -std=c++11 -g main.o UserInput.o EmptyStructure.o String.o ParseError.o InputParser.o -o lab

main.o: main.cpp UserInput.hpp Heap.hpp Heap.cpp MinHeap.hpp MinHeap.cpp MaxHeap.hpp MaxHeap.cpp QuickQueue.hpp QuickQueue.cpp InputParser.hpp String.hpp ParseError.hpp EmptyStructure.hpp
	g++ -std=c++11 -g -c main.cpp

UserInput.o: UserInput.hpp UserInput.hpp Heap.hpp Heap.cpp MinHeap.hpp MinHeap.cpp MaxHeap.hpp MaxHeap.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -c UserInput.cpp

EmptyStructure.o: EmptyStructure.hpp EmptyStructure.cpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

String.o: String.hpp String.cpp
	g++ -std=c++11 -g -c String.cpp

ParseError.o: ParseError.hpp ParseError.cpp
	g++ -std=c++11 -g -c ParseError.cpp

InputParser.o: InputParser.hpp InputParser.cpp String.hpp QuickQueue.hpp QuickQueue.cpp ParseError.hpp EmptyStructure.hpp
	g++ -std=c++11 -g -c InputParser.cpp

clean:
	rm -f lab *.o
