all: skew leftist

skew: skew_main.o UserInput.o EmptyStructure.o InputParser.o String.o ParseError.o
	g++ -std=c++11 -g skew_main.o UserInput.o EmptyStructure.o InputParser.o String.o ParseError.o -o skew

leftist: leftist_main.o UserInput.o EmptyStructure.o InputParser.o String.o ParseError.o
	g++ -std=c++11 -g leftist_main.o UserInput.o EmptyStructure.o InputParser.o String.o ParseError.o -o leftist

leftist_main.o: leftist_main.cpp setup.cpp InputParser.hpp SkewHeap.hpp SkewHeap.cpp SkewNode.hpp SkewNode.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp ParseError.hpp
	g++ -std=c++11 -g -c leftist_main.cpp

skew_main.o: skew_main.cpp setup.cpp InputParser.hpp SkewHeap.hpp SkewHeap.cpp SkewNode.hpp SkewNode.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp ParseError.hpp
	g++ -std=c++11 -g -c skew_main.cpp

UserInput.o: UserInput.hpp UserInput.cpp SkewHeap.hpp SkewHeap.cpp SkewNode.hpp SkewNode.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -c UserInput.cpp

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
