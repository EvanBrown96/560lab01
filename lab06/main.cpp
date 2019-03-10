#include "BinarySearchTree.hpp"
#include "InputParser.hpp"
#include "LinkedList.hpp"
#include "String.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv){

  if(argc <= 1){
    std::cout << "No input file provided, exiting.\n";
    return -1;
  }

  LinkedList<String> input_data;

  std::ifstream f;
  f.open(argv[1]);

  try{
    InputParser::parse(f, input_data);
  }
  catch(ParseError& err){
    f.close();
    std::cout << "Data could not be imported from " << argv[1] << "; error at position " << err.getErrPos() << "\n";
    return -1;
  }

  f.close();

  int num_data = input_data.getLength();
  String** data = input_data.getArray();
  // for(int i = 0; i < num_data; i++){
  //   std::cout << *data[i];
  // }
  BinarySearchTree<String> bst = BinarySearchTree<String>::OptimalBSTFactory(data, num_data, true);

  return 0;
}
