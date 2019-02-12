/**
 * @author: Evan Brown
 * @file: main.cpp
 * @date: 2/11/19
 * @brief: main entry point to the program
 */

#include <fstream>
#include "HashTable.hpp"
#include "LinearProbing.hpp"
#include "CharacterWrapper.hpp"
#include "InputFileParser.hpp"
#include "ParseError.hpp"

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
    hash_size = InputFileParser::parse(f, input_data);
  }
  catch(ParseError& err){
    f.close();
    std::cout << "Data could not be imported from " << argv[1] << "; error at position " << err.getErrPos() << "\n";
    return -1;
  }

  f.close();

  input_data.print();

  HashTable<CharacterWrapper, LinearProbing> ht(7, CharacterWrapper::cwhash);

  while(!input_data.isEmpty()){
    CharacterWrapper cw = input_data.popFront();
    ht.insert(cw);
  }
  // CharacterWrapper cw("test");
  // ht.insert(cw);
  ht.print();

  return 0;
}
