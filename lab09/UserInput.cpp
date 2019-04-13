/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 4/13/19
 * @brief: implementation of UserInput functions
 *         adapted from 560 lab08
 */

#include "UserInput.hpp"
#include "EmptyStructure.hpp"
#include <iostream>
#include <limits>

UserInput::UserInput(const MinMax<Process>& startoff):
  test_heap(startoff){}

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
    std::cout << "\t2. DeleteMin\n";
    std::cout << "\t3. DeleteMax\n";
    std::cout << "\t4. FindMin\n";
    std::cout << "\t5. FindMax\n";
    std::cout << "\t6. RunSchedule\n";
    std::cout << "\t7. Exit\n";

    while(!(std::cin >> choice && choice > -1 && choice < 8)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 7){
      break;
    }

    switch(choice){
      case 0: {
        // for debugging
        test_heap.levelOrder();
      }
      case 1: {
        userInsert();
        test_heap.levelOrder();
        break;
      }
      case 2: {
        try{
          test_heap.deleteMin();
          std::cout << "Delete was successful.\n";
          test_heap.levelOrder();
        }catch(EmptyStructure& err){
          std::cout << "Heap is empty and has no mininum.\n";
        }
        break;
      }
      case 3: {
        try{
          test_heap.deleteMax();
          std::cout << "Delete was successful.\n";
          test_heap.levelOrder();
        }catch(EmptyStructure& err){
          std::cout << "Heap is empty and has no maximum.\n";
        }
        break;
      }
      case 4: {
        try{
          std::cout << "Minimum process: " << test_heap.findMin() << "\n";
        }catch(EmptyStructure& err){
          std::cout << "Heap is empty and has no minimum.\n";
        }
        break;
      }
      case 5: {
        try{
          std::cout << "Maximum process: " << test_heap.findMax() << "\n";
        }catch(EmptyStructure& err){
          std::cout << "Heap is empty and has no maximum.\n";
        }
        break;
      }
      default: {
        // todo
        break;
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userInsert(){

  Process insert(0, 0);
  if(!queryUser<Process>("Enter process to be inserted: ", insert)) return;

  test_heap.insert(insert);
  std::cout << "Insert was successful.\n";

}
