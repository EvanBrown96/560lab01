#include "MinHeap.hpp"
#include "MaxHeap.hpp"
#include "QuickQueue.hpp"
#include "String.hpp"
#include "ParseError.hpp"
#include "InputParser.hpp"
#include <fstream>

bool compare(const int& v1, const int& v2){
  return (v1 < v2);
}

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

  // create list of ints
  QuickQueue<int> int_data(input_data.getSize());

  while(!input_data.isEmpty()){
    int_data.push(input_data.pop().getInt());
  }

  MinHeap<5, int> h(int_data);

  h.levelOrder();

  // UserInput ui(ttt);
  //
  // ui.start();

  return 0;

}
