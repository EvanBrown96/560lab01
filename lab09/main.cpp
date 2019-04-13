#include "MinMax.hpp"

int main(int argc, char** argv){
  MinMax<int> mm;
  mm.insert(12);
  mm.insert(25);
  mm.insert(2);
  mm.insert(11);
  mm.insert(22);
  mm.insert(111);
  mm.insert(17);
  mm.levelOrder();
  mm.deleteMax();
  mm.levelOrder();
}
