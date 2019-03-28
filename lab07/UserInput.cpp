/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 2/28/19
 * @brief: implementation of UserInput functions
 *         adapted from 560 lab04
 */

#include "UserInput.hpp"
#include "EmptyStructure.hpp"
#include "DuplicateValue.hpp"
#include "ValueNotFound.hpp"
#include <iostream>
#include <limits>

int myhash(const int& val){
  return val;
}

UserInput::UserInput(const TwoThreeTree<char> startoff):
  test_tree(startoff){}

void UserInput::clearCin(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
bool UserInput::queryUser(const char* query_str, T& res){
  std::cout << query_str;

  if(std::cin >> res){
    return true;
  }

  clearCin();
  std::cout << "Invalid input entered\n";
  return false;
}

void UserInput::start(){

  int choice = 0;

  while(true){

    std::cout << "Choose one operation from the options below:\n\n";
    std::cout << "\t1. Insert\n";
    std::cout << "\t2. Delete\n";
    std::cout << "\t3. DeleteMin\n";
    std::cout << "\t4. DeleteMax\n";
    std::cout << "\t5. Find\n";
    std::cout << "\t6. FindMin\n";
    std::cout << "\t7. FindMax\n";
    std::cout << "\t8. Levelorder\n";
    std::cout << "\t9. Exit\n";

    while(!(std::cin >> choice && choice > 0 && choice < 10)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 9){
      break;
    }

    switch(choice){
      case 1: {
        userInsert();
        break;
      }
      case 2: {
        userDelete();
        break;
      }
      case 3: {
        break;
      }
      case 4: {
        break;
      }
      case 5: {
        userFind();
        break;
      }
      case 6: {
        try{
          std::cout << "Minimum number: " << test_tree.findMin() << "\n";
        }catch(EmptyStructure& err){
          std::cout << "Tree is empty and has no minimum.\n";
        }
        break;
      }
      case 7: {
        try{
          std::cout << "Maximum number: " << test_tree.findMax() << "\n";
        }catch(EmptyStructure& err){
          std::cout << "Tree is empty and has no maximum.\n";
        }
        break;
      }
      default: {
        std::cout << "Levelorder traversal: " << test_tree.levelOrder() << "\n";
        break;
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userInsert(){

  char insert;
  if(!queryUser<char>("Enter character to be inserted: ", insert)) return;

  test_tree.insert(insert);

  std::cout << "Insert was successful.\n";
}

void UserInput::userDelete(){

  char del;
  if(!queryUser<char>("Enter character to be deleted: ", del)) return;

  try{
    test_tree.remove(del);
    std::cout << "Delete was successful.\n";
  }
  catch(ValueNotFound<char>& err){
    std::cout << "Delete failed; character was not found.\n";
  }

}

void UserInput::userFind(){

  char find;
  if(!queryUser("Enter character to be found: ", find)) return;

  if(test_tree.find(find)){
    std::cout << "Character is present in the tree.\n";
  }
  else{
    std::cout << "Character is not present in the tree.\n";
  }

}
