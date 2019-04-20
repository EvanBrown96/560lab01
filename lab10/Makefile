skew: skew_main.o EmptyStructure.o InputParser.o String.o ParseError.o
	g++ -std=c++11 -g skew_main.o EmptyStructure.o InputParser.o String.o ParseError.o -o skew

skew_main.o: skew_main.cpp setup.cpp InputParser.hpp SkewHeap.hpp SkewHeap.cpp SkewNode.hpp SkewNode.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -c skew_main.cpp

EmptyStructure.o: EmptyStructure.hpp EmptyStructure.cpp
	g++ -std=c++11 -g -c EmptyStructure.cpp

InputParser.o: InputParser.hpp InputParser.cpp QuickQueue.hpp QuickQueue.cpp String.hpp EmptyStructure.hpp ParseError.hpp
	g++ -std=c++11 -g -c InputParser.cpp

String.o: String.hpp String.cpp
	g++ -std=c++11 -g -c String.cpp

ParseError.o: ParseError.hpp ParseError.cpp
	g++ -std=c++11 -g -c ParseError.cpp

clean:
	rm *.o skew skew.exe leftist leftist.exe
