#include "BinarySearchTree.hpp"

int hash(const int& v){
  return 2;
}

int main(int argc, char** argv){

  int data[] = {5, 99, 17, 99, 24};

  BinarySearchTree<int> bst = BinarySearchTree<int>::OptimalBSTFactory(data, 5, hash);

  return 0;
}
