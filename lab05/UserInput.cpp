/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 2/28/19
 * @brief: implementation of UserInput functions
 *         adapted from 560 lab04
 */

#include "UserInput.hpp"
#include "EmptyStructure.hpp"
#include <iostream>
#include <limits>

int myhash(const int& val){
  return val;
}

UserInput::UserInput(const BinarySearchTree<int> startoff):
  test_bst(startoff){}

void UserInput::clearCin(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool UserInput::queryNumber(const char* query_str, int& num){
  std::cout << query_str;

  if(std::cin >> num){
    return true;
  }

  clearCin();
  std::cout << "Invalid number entered.\n";
  return false;
}

void UserInput::start(){

  int choice = 0;

  while(true){

    std::cout << "Choose one operation from the options below:\n\n";
    std::cout << "\t1. Insert\n";
    std::cout << "\t2. Delete\n";
    std::cout << "\t3. Find\n";
    std::cout << "\t4. FindMin\n";
    std::cout << "\t5. FindMax\n";
    std::cout << "\t6. Preorder\n";
    std::cout << "\t7. Inorder\n";
    std::cout << "\t8. Postorder\n";
    std::cout << "\t9. Levelorder\n";
    std::cout << "\t10. Exit\n";

    while(!(std::cin >> choice && choice > -1 && choice < 11)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 10){
      break;
    }

    switch(choice){
      case 0: {
        test_bst.printVisual();
        break;
      }
      case 1: {
        userInsert();
        break;
      }
      case 2: {
        userDelete();
        break;
      }
      case 3: {
        userFind();
        break;
      }
      case 4: {
        try{
          std::cout << "Minimum number: " << test_bst.findMin() << "\n";
        }catch(EmptyStructure& err){
          std::cout << "Tree is empty and has no minimum.\n";
        }
        break;
      }
      case 5: {
        try{
          std::cout << "Maximum number: " << test_bst.findMax() << "\n";
        }catch(EmptyStructure& err){
          std::cout << "Tree is empty and has no maximum.\n";
        }
        break;
      }
      case 6: {
        std::cout << "Preorder traversal: " << test_bst.preorder() << "\n";
        break;
      }
      case 7: {
        std::cout << "Inorder traversal: " << test_bst.inorder() << "\n";
        break;
      }
      case 8: {
        std::cout << "Postorder traversal: " << test_bst.postorder() << "\n";
        break;
      }
      default: {
        std::cout << "Levelorder traversal: " << test_bst.levelorder() << "\n";
        break;
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userInsert(){

  int insert;
  if(!queryNumber("Enter number to insert into BST: ", insert)) return;

  test_bst.insert(insert);

  std::cout << "Insert was successful.\n";
}

void UserInput::userDelete(){

  int del;
  if(!queryNumber("Enter number to delete from BST: ", del)) return;

  try{
    test_bst.deleteVal(del);
    std::cout << "Delete was successful.\n";
  }
  catch(ValueNotFound<int>& err){
    std::cout << "Delete failed; number was not found in tree.\n";
  }

}

void UserInput::userFind(){

  int find;
  if(!queryNumber("Enter number to be found: ", find)) return;

  if(test_bst.find(find)){
    std::cout << "Number is present in the tree.\n";
  }
  else{
    std::cout << "Number is not present in the tree.\n";
  }

}
