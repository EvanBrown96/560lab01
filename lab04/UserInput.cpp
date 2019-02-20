/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 2/19/19
 * @brief: implementation of UserInput functions
 *         adapted from 560 lab03
 */

#include "UserInput.hpp"
#include <iostream>
#include <limits>

UserInput::UserInput(const OpenHashTable<int>& startoff_open,
  const ClosedHashTable<int, QuadraticProbing>& startoff_quad,
  const ClosedHashTable<int, DoubleHashing>& startoff_double): test_open(startoff_open), test_quad(startoff_quad), test_double(startoff_double){}

void UserInput::clearCin(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInput::start(){

  int choice = 0;

  while(true){

    std::cout << "Choose one operation from the options below:\n\n";
    std::cout << "\t1. Test Hash Tables\n";
    std::cout << "\t2. Performance Comparison\n";
    std::cout << "\t3. Exit\n";

    while(!(std::cin >> choice && choice > 0 && choice < 4)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 3){
      break;
    }

    switch(choice){
      case 1: {
        userTest();
        break;
      }
      default: {
        userPerformance();
        break;
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userTest(){

  std::cout << "Open hashing:\n";
  test_open.print();
  std::cout << "\nClosed hashing with quadratic probing:\n";
  test_quad.print();
  std::cout << "\nClosed hashing with double hashing:\n";
  test_double.print();

}

void UserInput::userPerformance(){

  // std::cout << "Enter string to be deleted: ";
  //
  // clearCin();
  // char first = std::cin.get();
  // CharacterWrapper cw = InputParser::parseString(std::cin, first);
  //
  // try{
  //   ht_quad.deleteVal(cw);
  //   std::cout << "Quadratic probing: " << cw << " is deleted from the hash table.\n";
  // }
  // catch(ValueNotFound<CharacterWrapper>& err){
  //   std::cout << "Quadratic probing: " << cw << " can't be found in the hash table.\n";
  // }
  //
  // try{
  //   ht_double.deleteVal(cw);
  //   std::cout << "Double hashing: " << cw << " is deleted from the hash table.\n";
  // }
  // catch(ValueNotFound<CharacterWrapper>& err){
  //   std::cout << "Double hashing: " << cw << " can't be found in the hash table.\n";
  // }

}
