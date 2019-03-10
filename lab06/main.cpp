#include "BinarySearchTree.hpp"


int main(int argc, char** argv){

  int data[] = {20, 99, 15, 19, 45, 10, 13, 106, 99, 99, 19, 45, 45, 45, 100, 78, 15, 1, 4, 5, 45};

  BinarySearchTree<int> bst = BinarySearchTree<int>::OptimalBSTFactory(data, 21);

  std::cout << bst.inorder();
  std::cout << bst.preorder();
  return 0;
}
