/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 2/2/19
 * @brief: header file for user input functions
 */

#ifndef UserInput_hpp
#define UserInput_hpp

#include "HashTable.hpp"

class UserInput{

public:

  /**
   * constructor
   * @param startoff: hash table to use as base for program
   * @post: creates userinput instance with the given hash table
   */
  UserInput(const HashTable<int>& startoff);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  int choice;
  HashTable<int> ht;

  /**
   * ignores any characters still in the input buffer and clears error flags
   * @post: std::cin is ready for input again
   */
  void clearCin();

  /**
   * prompts user for a value and adds it to the list
   * @post: the value the user gives is added to the list
   */
  void userInsert();

  /**
   * prompts user for a value and deletes that value from the list
   * @post: the value the user gives is removed from the list
   */
  void userDelete();

  /**
   * prompts user for a value and prints the location it was found at
   */
  void userFind();

};

#endif
