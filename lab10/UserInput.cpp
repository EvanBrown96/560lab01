/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 4/19/19
 * @brief: implementation of UserInput functions
 *         adapted from 560 lab09
 */

#include "UserInput.hpp"
#include "EmptyStructure.hpp"
#include <iostream>
#include <limits>

UserInput::UserInput(bool isskew, SkewHeap<int>* const sh, LeftistHeap<int>* const lh):
    isskew(isskew){

  if(isskew){
    this->sh = *sh;
  }
  else{
    this->lh = *lh;
  }

}

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
    std::cout << "\t2. DeleteMax\n";
    std::cout << "\t3. FindMax\n";
    std::cout << "\t4. Preorder\n";
    std::cout << "\t5. Inorder\n";
    std::cout << "\t6. Postorder\n";
    std::cout << "\t7. Levelorder\n";
    std::cout << "\t8. Exit\n";

    while(!(std::cin >> choice && choice > 0 && choice < 9)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 8){
      break;
    }

    if(isskew){
      switch(choice){
        case 1: {
          skewInsert();
          break;
        }
        case 2: {
          try{
            sh.deleteMax();
            std::cout << "Delete was successful.\n";
          }catch(EmptyStructure& err){
            std::cout << "Heap is empty and has no maximum.\n";
          }
          break;
        }
        case 3: {
          try{
            std::cout << "Maximum number: " << sh.findMax() << "\n";
          }catch(EmptyStructure& err){
            std::cout << "Heap is empty and has no maximum.\n";
          }
          break;
        }
        case 4: {
          std::cout << "Preorder traversal: " << sh.preorder();
          break;
        }
        case 5: {
          std::cout << "Inorder traversal: " << sh.inorder();
          break;
        }
        case 6: {
          std::cout << "Postorder traversal: " << sh.postorder();
          break;
        }
        default: {
          std::cout << "Levelorder traversal: " << sh.levelorder();
        }
      }
    }
    else{
      switch(choice){
        case 1: {
          leftistInsert();
          break;
        }
        case 2: {
          try{
            lh.deleteMax();
            std::cout << "Delete was successful.\n";
          }catch(EmptyStructure& err){
            std::cout << "Heap is empty and has no maximum.\n";
          }
          break;
        }
        case 3: {
          try{
            std::cout << "Maximum number: " << lh.findMax() << "\n";
          }catch(EmptyStructure& err){
            std::cout << "Heap is empty and has no maximum.\n";
          }
          break;
        }
        case 4: {
          std::cout << "Preorder traversal: " << lh.preorder();
          break;
        }
        case 5: {
          std::cout << "Inorder traversal: " << lh.inorder();
          break;
        }
        case 6: {
          std::cout << "Postorder traversal: " << lh.postorder();
          break;
        }
        default: {
          std::cout << "Levelorder traversal: " << lh.levelorder();
        }
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::skewInsert(){

  int insert;
  if(!queryUser<int>("Enter number to be inserted: ", insert)) return;

  sh.insert(insert);
  std::cout << "Insert was successful.\n";

}

void UserInput::leftistInsert(){

  int insert;
  if(!queryUser<int>("Enter number to be inserted: ", insert)) return;

  lh.insert(insert);
  std::cout << "Insert was successful.\n";

}
