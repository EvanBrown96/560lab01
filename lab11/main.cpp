// 4/13

#include "String.hpp"
#include "UserInput.hpp"
#include "ParseError.hpp"
#include "InputParser.hpp"
#include "BinarySearchTree.hpp"
#include "MinHeap.hpp"
#include "MaxHeap.hpp"
#include <fstream>

int main(int argc, char** argv){

  if(argc <= 1){
    std::cout << "No input file provided, exiting.\n";
    return -1;
  }

  QuickQueue<String> input_data(10);

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

  QuickQueue<int> int_data(10);

  while(!input_data.isEmpty()){
    int_data.push(input_data.pop().getInt());
  }

  // create test data structures
  BinarySearchTree<int> bst(int_data);
  MinHeap<5, int> minh(int_data);
  MaxHeap<5, int> maxh(int_data);

  // run user interactivity
  UserInput ui(bst, minh, maxh);
  ui.start();
}
