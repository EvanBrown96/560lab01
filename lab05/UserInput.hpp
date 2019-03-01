/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 2/28/19
 * @brief: header file for user input functions
 *         adapted from 560 lab04
 */

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include "BinarySearchTree.hpp"

class UserInput{

public:

  /**
   * constructor
   * @param startoff: hash table to use as base for program
   * @post: creates userinput instance with the given hash table
   */
  UserInput(const BinarySearchTree<int> startoff);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  BinarySearchTree<int> test_bst;

  /**
   * ignores any characters still in the input buffer and clears error flags
   * @post: std::cin is ready for input again
   */
  void clearCin();

  bool queryNumber(const char* query_str, int& num);

  void userInsert();

  void userDelete();

  void userFind();

};

#endif
