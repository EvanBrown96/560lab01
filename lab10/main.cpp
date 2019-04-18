#include "SkewHeap.hpp"
#include <iostream>

int main(int argc, char** argv){

  SkewHeap<int> s;

  s.insert(12);
  s.insert(20);
  s.insert(4);
  s.insert(99);
  s.insert(14);
  s.insert(184);
  s.insert(48);
  s.insert(7);

  s.printVisual();

  return 0;

}
