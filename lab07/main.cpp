#include "TwoThreeTree.hpp"
#include "QuickQueue.hpp"
#include "InputParser.hpp"
#include "String.hpp"
#include "UserInput.hpp"
#include <iostream>
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

  // create 2-3 tree
  TwoThreeTree<char> ttt;
  while(!input_data.isEmpty()){
    ttt.insert(input_data.pop()[0]);
  }

  UserInput ui(ttt);

  ui.start();

  return 0;
}
