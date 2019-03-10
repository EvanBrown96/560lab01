#include "BinarySearchTree.hpp"

int hash(const int& v){
  return v;
}

int main(int argc, char** argv){

  int data[] = {15, 12, 9, 9, 7, 12, 15, 15, 15, 12};

  BinarySearchTree<int> bst = BinarySearchTree<int>::OptimalBSTFactory(data, 10, hash);

  return 0;
}
