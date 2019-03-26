#include "TwoThreeTree.hpp"
#include <iostream>

int main(int argc, char** argv){

  TwoThreeTree<char> ttt;
  ttt.insert('A');
  ttt.insert('L');
  ttt.insert('G');
  ttt.insert('O');
  ttt.insert('R');
  ttt.insert('I');
  ttt.insert('T');
  ttt.insert('H');
  ttt.insert('M');
  ttt.insert('S');
  std::cout << ttt.levelOrder() << "\n";
  return 0;
}
