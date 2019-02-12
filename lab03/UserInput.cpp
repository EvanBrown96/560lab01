/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 2/2/19
 * @brief: implementation of UserInput functions
 */

#include "UserInput.hpp"
#include "InputParser.hpp"
#include <iostream>
#include <limits>

UserInput::UserInput(const HashTable<CharacterWrapper, QuadraticProbing>& startoff_quad,
  const HashTable<CharacterWrapper, DoubleHashing>& startoff_double): ht_quad(startoff_quad), ht_double(startoff_double){}

void UserInput::clearCin(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInput::start(){

  int choice = 0;

  while(true){

    std::cout << "Choose one operation from the options below:\n\n";
    std::cout << "\t1. Insert\n";
    std::cout << "\t2. Delete\n";
    std::cout << "\t3. Find\n";
    std::cout << "\t4. FindPalindrome\n";
    std::cout << "\t5. ReverseString\n";
    std::cout << "\t6. Print\n";
    std::cout << "\t7. Exit\n";

    while(!(std::cin >> choice && choice > 0 && choice < 8)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 7){
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
      case 4: {
        userFindPalindrome();
        break;
      }
      case 5: {
        userReverseString();
        break;
      }
      default: {
        std::cout << "\nQuadratic Probing:\n\n";
        ht_quad.print();
        std::cout << "\nDouble Hashing:\n\n";
        ht_double.print();
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userInsert(){

  std::cout << "Enter a string to insert: ";

  clearCin();
  char first = std::cin.get();
  CharacterWrapper cw = InputParser::parseString(std::cin, first);
  
  if(cw.getLength() != 0){
    try{
      ht_quad.insert(cw);
      ht_double.insert(cw);
      std::cout << cw << " is added to the hash table.\n";
    }
    catch(DuplicateValue<CharacterWrapper>& err){
      std::cout << cw << " is a duplicate, can't be added to hash table.\n";
    }
  }
  else{
    clearCin();
    std::cout << "Invalid string entered.\n";
  }

}

void UserInput::userDelete(){

  std::cout << "Enter string to be deleted: ";

  clearCin();
  char first = std::cin.get();
  CharacterWrapper cw = InputParser::parseString(std::cin, first);

  if(cw.getLength() != 0){
    try{
      ht_quad.deleteVal(cw);
      ht_double.deleteVal(cw);
      std::cout << cw << " is deleted from the hash table.\n";
    }
    catch(ValueNotFound<int>& err){
      std::cout << cw << " can't be found in the hash table.\n";
    }
  }
  else{
    clearCin();
    std::cout << "Invalid number entered.\n";
  }

}

void UserInput::userFind(){

  // std::cout << "Enter a number to be found: ";
  // if(std::cin >> choice){
  //   try{
  //     int loc = ht.find(choice);
  //     std::cout << choice << " is found at location " << loc << "\n";
  //   }
  //   catch(ValueNotFound<int>& err){
  //     std::cout << choice << " can't be found in the hash table.\n";
  //   }
  // }
  // else{
  //   clearCin();
  //   std::cout << "Invalid number entered.\n";
  // }

}

void UserInput::userFindPalindrome(){

}

void UserInput::userReverseString(){

}
