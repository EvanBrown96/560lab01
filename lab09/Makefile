lab: main.o UserInput.o EmptyStructure.o Process.o
	g++ -std=c++11 -g main.o UserInput.o EmptyStructure.o Process.o -o lab

main.o: main.cpp UserInput.hpp Process.hpp MinMax.hpp MinMax.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -Wno-deprecated -c main.cpp

UserInput.o: UserInput.hpp UserInput.cpp Process.hpp MinMax.hpp MinMax.cpp QuickQueue.hpp QuickQueue.cpp EmptyStructure.hpp
	g++ -std=c++11 -g -Wno-deprecated -c UserInput.cpp

EmptyStructure.o: EmptyStructure.hpp EmptyStructure.cpp
	g++ -std=c++11 -g -Wno-deprecated -c EmptyStructure.cpp

Process.o: Process.hpp Process.cpp
	g++ -std=c++11 -g -Wno-deprecated -c Process.cpp

clean:
	rm -f lab lab.exe *.o
