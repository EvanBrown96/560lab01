/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 2/12/19
 * @brief: header file for user input functions
 */

#ifndef UserInput_hpp
#define UserInput_hpp

#include "HashTable.hpp"
#include "CharacterWrapper.hpp"
#include "LinearProbing.hpp"

class UserInput{

public:

  /**
   * constructor
   * @param startoff: hash table to use as base for program
   * @post: creates userinput instance with the given hash table
   */
  UserInput(const HashTable<CharacterWrapper, LinearProbing>& startoff_quad,
    const HashTable<CharacterWrapper, LinearProbing>& startoff_double);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  HashTable<CharacterWrapper, LinearProbing> ht_quad;
  HashTable<CharacterWrapper, LinearProbing> ht_double;

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

  void userFindPalindrome();

  void userReverseString();

};

#endif
