#include <iostream>
#include <sstream>
#include "NumberParser.hpp"
#include "BinarySearchTree.hpp"
#include "Traversal.hpp"

void testEmptyInsert();
void testInsertLeft();
void testInsertRight();

bool compareTraversal(const Traversal<int>& t, std::string s){
  s += " \n";
  std::stringstream ss;
  ss << t;
  return (s == ss.str());
}

void printTestResults(int i, std::string s, bool r){
  if(r){
    std::cout << "PASSED";
  }
  else{
    std::cout << "FAILED";
  }
  std::cout << ": TEST #" << i << " (" << s << ")\n";
}

int main(int argc, char** argv){
  if(argc < 2){
    std::cout << "Test to run not specified.\n";
    return -1;
  }

  int test_num = 0;
  char* cur = argv[1];
  while(*cur != '\0'){
    if(!NumberParser::isInt(*cur)){
      std::cout << "Invalid test entered.\n";
      return -1;
    }
    test_num *= 10;
    test_num += NumberParser::toInt(*cur);
    cur++;
  }

  switch(test_num){
    case 1: testEmptyInsert(); break;
    case 2: testInsertLeft(); break;
    case 3: testInsertRight(); break;
    default: std::cout << "Invalid test entered.\n"; return -1;
  }

  return 0;
}

void testEmptyInsert(){
  BinarySearchTree<int> bst;
  bst.insert(15);

  bool res = compareTraversal(bst.inorder(), "15");
  printTestResults(1, "insert to empty tree", res);
}
void testInsertLeft(){
  BinarySearchTree<int> bst;
  bst.insert(15);
  bst.insert(10);
  bool res = compareTraversal(bst.inorder(), "10 15");
  printTestResults(2, "insert to left subtree", res);
}
void testInsertRight(){
  BinarySearchTree<int> bst;
  bst.insert(15);
  bst.insert(20);
  bool res = compareTraversal(bst.inorder(), "15 20");
  printTestResults(3, "insert to right subtree", res);
}
