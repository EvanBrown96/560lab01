#include "BinarySearchTree.hpp"
#include "InputParser.hpp"
#include "LinkedList.hpp"
#include "String.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char** argv){

  LinkedList<String> ll;

  std::ifstream f;
  f.open("data.txt");

  InputParser::parse(f, ll);
  f.close();

  //ll.print();
  //int data[] = {20, 99, 15, 19, 45, 10, 13, 106, 99, 99, 19, 45, 45, 45, 100, 78, 15, 1, 4, 5, 45};
  int num_data = ll.getLength();
  String** data = ll.getArray();
  for(int i = 0; i < num_data; i++){
    std::cout << *data[i];
  }
  BinarySearchTree<String> bst = BinarySearchTree<String>::OptimalBSTFactory(data, num_data);

  std::cout << bst.inorder();
  std::cout << bst.preorder();
  return 0;
}
