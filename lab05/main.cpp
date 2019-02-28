#include "Preorder.hpp"
#include "BinarySearchTree.hpp"
#include <iostream>

int main(int argc, char** argv){

  BinarySearchTree<int> bst;
  bst.insert(7);
  bst.insert(3);
  bst.insert(8);
  bst.insert(1);
  bst.insert(6);
  bst.insert(8);
  bst.insert(13);
  bst.insert(9);
  bst.insert(15);
  bst.insert(10);
  std::cout << bst.preorder();
  std::cout << bst.inorder();
  std::cout << bst.postorder();
  std::cout << bst.levelorder();

  return 0;
}
