// 4/19

#include "SkewHeap.hpp"
#include "LeftistHeap.hpp"
#include "InputParser.hpp"
#include "String.hpp"
#include "UserInput.hpp"
#include <fstream>
#include <iostream>

int setup(int argc, char** argv, bool isskew){

  if(argc <= 1){
    std::cout << "Expected usage: " << argv[0] << " input_file.txt\n";
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

  if(isskew){
    std::cout << "Using skew heap...\n\n";
    SkewHeap<int>* h = new SkewHeap<int>(int_data);

    UserInput ui(isskew, h, nullptr);
    ui.start();
    delete h;
  }
  else{
    std::cout << "Using leftist heap...\n\n";
    LeftistHeap<int>* h = new LeftistHeap<int>(int_data);

    UserInput ui(isskew, nullptr, h);
    ui.start();
    delete h;
  }

  return 0;

}
