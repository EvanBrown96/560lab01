/**
 * @author: Evan Brown
 * @file: main.cpp
 * @date: 1/29/18
 * @brief: entry point to program
 */

#include "HashTable.hpp"
#include "LinkedList.hpp"
#include "NumberParser.hpp"
#include "exceptions/NumberParseError.hpp"
#include "UserInput.hpp"
#include <iostream>
#include <fstream>

int myhash(const int& value){
  return value;
}

int main(int argc, char** argv){

  HashTable<int>* startoff;

  if(argc <= 1){
    std::cout << "No input file provided, exiting.\n";
    return -1;
  }

  LinkedList<int> input_data;

  std::ifstream f;
  f.open(argv[1]);

  try{
    NumberParser::parse(f, input_data);
  }
  catch(NumberParseError& err){
    f.close();
    std::cout << "Data could not be imported from " << argv[1] << "; error at position " << err.getErrPos() << "\n";
    return -1;
  }

  f.close();

  startoff = new HashTable<int>(input_data.popFront(), myhash);

  while(!input_data.isEmpty()){
    try{
      startoff->insert(input_data.popFront());
    }
    catch(DuplicateValue<int>& err){
      // this is fine...
    }
  }

  UserInput inp(*startoff);
  inp.start();

  return 0;

}
