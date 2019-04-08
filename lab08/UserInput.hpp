/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 4/8/19
 * @brief: header file for user input functions
 *         adapted from 560 lab07
 */

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include "MinHeap.hpp"
#include "MaxHeap.hpp"

class UserInput{

public:

  /**
   * constructor
   * @param startoff: hash table to use as base for program
   * @post: creates userinput instance with the given hash table
   */
  UserInput(Heap<5, int>* startoff);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  Heap<5, int>* test_heap;

  /**
   * ignores any characters still in the input buffer and clears error flags
   * @post: std::cin is ready for input again
   */
  void clearCin();

  template <typename T>
  bool queryUser(const char* query_str, T& res);

  void userInsert();

};

#endif
