/**
 * @author: Evan Brown
 * @file: main.cpp
 * @date: 1/25/19
 * @brief: entry point to program
 */

#include "UserInput.hpp"
#include <fstream>
#include "NumberParser.hpp"

int main(int argc, char** argv){

  // create linked list to import data to
  LinkedList<int> startoff;

  if(argc > 1){
    // create and open filestream from passed-in argument
    std::ifstream f;
    f.open(argv[1]);
    // parse file for numbers and store them in the startoff linked list
    NumberParser::parse(f, startoff);
    f.close();

    std::cout << "Imported from " << argv[1] << ":\n";
    startoff.print();
    std::cout << "\n";
  }

  UserInput inp(startoff);
  inp.start();

  return 0;
}
