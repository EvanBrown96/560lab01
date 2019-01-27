lab: main.o userinput.o emptylist.o
	g++ -std=c++11 main.o userinput.o emptylist.o -o lab

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

userinput.o: UserInput.cpp UserInput.hpp LinkedList.cpp LinkedList.hpp Node.cpp Node.hpp ValueNotFound.cpp ValueNotFound.hpp
	g++ -std=c++11 -c UserInput.cpp

emptylist.o: EmptyList.cpp EmptyList.hpp
	g++ -std=c++11 -c EmptyList.cpp

clean:
	rm -f lab *.o
