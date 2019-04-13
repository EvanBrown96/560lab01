// 4/13

#include "MinMax.hpp"
#include "UserInput.hpp"
#include "ParseError.hpp"
#include "InputParser.hpp"
#include <fstream>

int main(int argc, char** argv){

  if(argc <= 1){
    std::cout << "No input file provided, exiting.\n";
    return -1;
  }

  QuickQueue<Process> input_data(10);

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

  // create min-max heap
  MinMax<Process> mm(input_data);

  // run user interactivity
  UserInput ui(mm);
  ui.start();
}
