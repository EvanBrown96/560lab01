#include "Preorder.hpp"
#include "BinarySearchTree.hpp"
#include <iostream>

int main(int argc, char** argv){

  BinarySearchTree<int> bst;
  bst.insert(67);
  bst.insert(12);
  bst.insert(112);
  bst.insert(4);
  std::cout << bst.preorder();

  return 0;
}
