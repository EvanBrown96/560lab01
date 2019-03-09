#include "BinarySearchTree.hpp"

int main(int argc, char** argv){

  int data[] = {5, 99, 17, 99, 24};

  BinarySearchTree<int> bst = BinarySearchTree<int>::OptimalBSTFactory(data, 5);

  return 0;
}
