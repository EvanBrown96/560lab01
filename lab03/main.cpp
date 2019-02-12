/**
 * @author: Evan Brown
 * @file: main.cpp
 * @date: 2/12/19
 * @brief: main entry point to the program
 */

#include <fstream>
#include "HashTable.hpp"
#include "CharacterWrapper.hpp"
#include "InputParser.hpp"
#include "ParseError.hpp"
#include "UserInput.hpp"
#include "QuadraticProbing.hpp"

int main(int argc, char** argv){

  if(argc <= 1){
    std::cout << "No input file provided, exiting.\n";
    return -1;
  }

  LinkedList<CharacterWrapper> input_data;
  int hash_size;

  std::ifstream f;
  f.open(argv[1]);

  try{
    hash_size = InputParser::parse(f, input_data);
  }
  catch(ParseError& err){
    f.close();
    std::cout << "Data could not be imported from " << argv[1] << "; error at position " << err.getErrPos() << "\n";
    return -1;
  }

  f.close();

  HashTable<CharacterWrapper, QuadraticProbing> startoff_quad(hash_size, CharacterWrapper::cwhash);
  HashTable<CharacterWrapper, DoubleHashing> startoff_double(hash_size, CharacterWrapper::cwhash);

  while(!input_data.isEmpty()){
    CharacterWrapper cw = input_data.popFront();
    startoff_quad.insert(cw);
    startoff_double.insert(cw);
  }

  UserInput inp(startoff_quad, startoff_double);
  inp.start();

  return 0;
}
