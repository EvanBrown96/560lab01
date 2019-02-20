/**
 * @author: Evan Brown
 * @file: main.cpp
 * @date: 2/19/19
 * @brief: entry point to the program
 */

#include "OpenHashTable.hpp"
#include "ClosedHashTable.hpp"
#include "QuadraticProbing.hpp"
#include "UserInput.hpp"
#include <fstream>
#include "NumberParser.hpp"
#include "NumberParseError.hpp"

int myhash(const int& val){
  return val;
}

int main(int argc, char** argv){
  // OpenHashTable<int> oht(7, myhash);
  // ClosedHashTable<int, QuadraticProbing> cht(7, myhash);

  if(argc <= 1){
    std::cout << "No input file provided, exiting.\n";
    return -1;
  }

  OpenHashTable<int> startoff_open(7, myhash);
  ClosedHashTable<int, QuadraticProbing> startoff_quad(7, myhash);
  startoff_quad.disableRehashing();
  ClosedHashTable<int, DoubleHashing> startoff_double(7, myhash);
  startoff_double.disableRehashing();

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

  while(!input_data.isEmpty()){
    int latest = input_data.popFront();
    try{
      startoff_open.insert(latest);
    }
    catch(DuplicateValue<int>& err){} // this is fine...
    try{
      startoff_quad.insert(latest);
    }
    catch(DuplicateValue<int>& err){} // this is fine...
    try{
      startoff_double.insert(latest);
    }
    catch(DuplicateValue<int>& err){} // this is fine...
  }

  UserInput inp(startoff_open, startoff_quad, startoff_double);
  inp.start();

  return 0;
}
