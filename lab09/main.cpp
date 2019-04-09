#include "MinMax.hpp"

int main(int argc, char** argv){
  MinMax<int> mm;
  mm.insert(12);
  mm.insert(25);
  mm.insert(2);
  mm.insert(11);
  mm.levelOrder();
}
