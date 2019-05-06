lab: main.o Graph.o GraphNode.o Edge.o InputParser.o ParseError.o EmptyStructure.o String.o
	g++ -std=c++11 -g main.o Graph.o GraphNode.o Edge.o InputParser.o ParseError.o EmptyStructure.o String.o -o lab

main.o: main.cpp Graph.hpp Edge.hpp
	g++ -std=c++11 -g -c main.cpp

InputParser.o: InputParser.hpp InputParser.cpp ParseError.hpp String.hpp QuickQueue.hpp QuickQueue.cpp
	g++ -std=c++11 -g -c InputParser.cpp

ParseError.o: ParseError.hpp ParseError.cpp
	g++ -std=c++11 -g -c ParseError.cpp

String.o: String.hpp String.cpp
	g++ -std=c++11 -g -c String.cpp

Graph.o: Graph.hpp Graph.cpp GraphNode.hpp PriQueue.hpp PriQueue.cpp MinHeap.hpp MinHeap.cpp Heap.hpp Heap.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp DJS.hpp DJS.cpp Set.hpp Set.cpp SetNode.hpp SetNode.cpp ValueNotFound.hpp ValueNotFound.cpp
	g++ -std=c++11 -g -c Graph.cpp

GraphNode.o: GraphNode.hpp GraphNode.cpp
	g++ -std=c++11 -g -c GraphNode.cpp

Edge.o: Edge.hpp Edge.cpp
	g++ -std=c++11 -g -c Edge.cpp

EmptyStructure.o: EmptyStructure.cpp EmptyStructure.cpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

clean:
	rm -f *.o lab lab.exe
