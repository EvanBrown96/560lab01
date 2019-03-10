#include "BinarySearchTree.hpp"

int hash(const int& v){
  return v;
}

int main(int argc, char** argv){

  int data[] = {5, 99, 17, 99, 24, 17, 68, 68, 44, 212, 9, 99, 99, 34, 24, 11, 10, 9, 99, 110};

  BinarySearchTree<int> bst = BinarySearchTree<int>::OptimalBSTFactory(data, 20, hash);

  return 0;
}
