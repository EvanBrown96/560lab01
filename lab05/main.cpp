#include "Preorder.hpp"
#include "BinarySearchTree.hpp"
#include "NumberParser.hpp"
#include "NumberParseError.hpp"
#include "UserInput.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv){

  if(argc <= 1){
    std::cout << "No input file provided, exiting.\n";
    return -1;
  }

  BinarySearchTree<int> startoff;

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
    startoff.insert(latest);
  }

  //std::cout << startoff.inorder();
  UserInput inp(startoff);
  inp.start();

  return 0;
}
