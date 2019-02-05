/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 2/2/19
 * @brief: implementation of UserInput functions
 */

#include "UserInput.hpp"
#include <iostream>
#include <limits>

UserInput::UserInput(const HashTable<int>& startoff): ht(startoff){}

void UserInput::clearCin(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInput::start(){

  choice = 0;

  while(true){

    std::cout << "Choose one operation from the options below:\n\n";
    std::cout << "\t1. Insert\n";
    std::cout << "\t2. Delete\n";
    std::cout << "\t3. Find\n";
    std::cout << "\t4. Print\n";
    std::cout << "\t5. Exit\n";

    while(!(std::cin >> choice && choice > 0 && choice < 6)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 5){
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
        userFind();
        break;
      }
      default: {
        ht.print();
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userInsert(){

  std::cout << "Enter number to insert: ";
  if(std::cin >> choice){
    try{
      ht.insert(choice);
      std::cout << choice << " is added to the hash table.\n";
    }
    catch(DuplicateValue<int>& err){
      std::cout << choice << " is a duplicate, can't be added to hash table.\n";
    }
  }
  else{
    clearCin();
    std::cout << "Invalid number entered.\n";
  }

}

void UserInput::userDelete(){

  std::cout << "Enter number to be deleted: ";
  if(std::cin >> choice){
    try{
      ht.deleteVal(choice);
      std::cout << choice << " is deleted from the hash table.\n";
    }
    catch(ValueNotFound<int>& err){
      std::cout << choice << " can't be found in the hash table.\n";
    }
  }
  else{
    clearCin();
    std::cout << "Invalid number entered.\n";
  }

}

void UserInput::userFind(){

  std::cout << "Enter a number to be found: ";
  if(std::cin >> choice){
    try{
      int loc = ht.find(choice);
      std::cout << choice << " is found at location " << loc << "\n";
    }
    catch(ValueNotFound<int>& err){
      std::cout << choice << " can't be found in the hash table.\n";
    }
  }
  else{
    clearCin();
    std::cout << "Invalid number entered.\n";
  }

}
