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
        ht_quad.findPalindromes();
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

  try{
    ht_quad.insert(cw);
    std::cout << "Quadratic probing: " << cw << " is added to the hash table.\n";
  }
  catch(DuplicateValue<CharacterWrapper>& err){
    std::cout << "Quadratic probing: " << cw << " is a duplicate, can't be added to hash table.\n";
  }

  try{
    ht_double.insert(cw);
    std::cout << "Double hashing: " << cw << " is added to the hash table.\n";
  }
  catch(DuplicateValue<CharacterWrapper>& err){
    std::cout << "Double hashing: " << cw << " is a duplicate, can't be added to hash table.\n";
  }

}

void UserInput::userDelete(){

  std::cout << "Enter string to be deleted: ";

  clearCin();
  char first = std::cin.get();
  CharacterWrapper cw = InputParser::parseString(std::cin, first);

  try{
    ht_quad.deleteVal(cw);
    std::cout << "Quadratic probing: " << cw << " is deleted from the hash table.\n";
  }
  catch(ValueNotFound<CharacterWrapper>& err){
    std::cout << "Quadratic probing: " << cw << " can't be found in the hash table.\n";
  }

  try{
    ht_double.deleteVal(cw);
    std::cout << "Double hashing: " << cw << " is deleted from the hash table.\n";
  }
  catch(ValueNotFound<CharacterWrapper>& err){
    std::cout << "Double hashing: " << cw << " can't be found in the hash table.\n";
  }

}

void UserInput::userFind(){

  std::cout << "Enter a string to be found: ";
  clearCin();
  char first = std::cin.get();
  CharacterWrapper cw = InputParser::parseString(std::cin, first);

  try{
    int loc = ht_quad.find(cw);
    std::cout << "Quadratic probing: " << cw << " is found at location " << loc << "\n";
  }
  catch(ValueNotFound<CharacterWrapper>& err){
    try{
      CharacterWrapper rev_cw = CharacterWrapper::getReverse(cw);
      int loc = ht_quad.find(rev_cw);
      std::cout << "Quadratic probing: " << cw << " is present in reverse order at location " << loc << "\n";
    }
    catch(ValueNotFound<CharacterWrapper>& err){
      std::cout << "Quadratic probing: " << cw << " can't be found in the hash table.\n";
    }
  }

  try{
    int loc = ht_double.find(cw);
    std::cout << "Double hashing: " << cw << " is found at location " << loc << "\n";
  }
  catch(ValueNotFound<CharacterWrapper>& err){
    try{
      CharacterWrapper rev_cw = CharacterWrapper::getReverse(cw);
      int loc = ht_double.find(rev_cw);
      std::cout << "Double hashing: " << cw << " is present in reverse order at location " << loc << "\n";
    }
    catch(ValueNotFound<CharacterWrapper>& err){
      std::cout << "Double hashing: " << cw << " can't be found in the hash table.\n";
    }
  }

}

void UserInput::userReverseString(){

  std::cout << "Enter location of string you want to reverse: ";
  int loc;

  if(std::cin >> loc){
    try{
      CharacterWrapper cw = ht_quad.getByLocation(loc);
      ht_quad.reverseString(loc);
      std::cout << "Quadratic probing: string " << cw << " is changed to " << CharacterWrapper::getReverse(cw) << "\n";
    }
    catch(EmptyLocation& err){
      std::cout << "There is no string at location " << loc << " with quadratic probing.";
    }

    try{
      CharacterWrapper cw = ht_double.getByLocation(loc);
      ht_double.reverseString(loc);
      std::cout << "Double hashing: string " << cw << " is changed to " << CharacterWrapper::getReverse(cw) << "\n";
    }
    catch(EmptyLocation& err){
      std::cout << "There is no string at location " << loc << " with double hashing.";
    }
  }
  else{
    clearCin();
    std::cout << "Invalid number entered.\n";
  }

}
