#include "TwoThreeTree.hpp"
#include <iostream>

int main(int argc, char** argv){

  TwoThreeTree<char> ttt;
  ttt.insert('A');
  std::cout << ttt.levelOrder() << "\n";
  return 0;
}
