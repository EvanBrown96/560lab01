/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 3/26/19
 * @brief: header file for user input functions
 *         adapted from 560 lab05
 */

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include "TwoThreeTree.hpp"

class UserInput{

public:

  /**
   * constructor
   * @param startoff: hash table to use as base for program
   * @post: creates userinput instance with the given hash table
   */
  UserInput(const TwoThreeTree<char> startoff);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  TwoThreeTree<char> test_tree;

  /**
   * ignores any characters still in the input buffer and clears error flags
   * @post: std::cin is ready for input again
   */
  void clearCin();

  template <typename T>
  bool queryUser(const char* query_str, T& res);

  void userInsert();

  void userDelete();

  void userFind();

};

#endif
