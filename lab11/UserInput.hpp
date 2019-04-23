/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 4/19/19
 * @brief: header file for user input functions
 *         adapted from 560 lab09
 */

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include "SkewHeap.hpp"
#include "LeftistHeap.hpp"

class UserInput{

public:

  /**
   * constructor
   * @param startoff: hash table to use as base for program
   * @post: creates userinput instance with the given hash table
   */
  UserInput(bool isskew, SkewHeap<int>* const sh, LeftistHeap<int>* const lh);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  bool isskew;
  SkewHeap<int> sh;
  LeftistHeap<int> lh;

  /**
   * ignores any characters still in the input buffer and clears error flags
   * @post: std::cin is ready for input again
   */
  void clearCin();

  template <typename T>
  bool queryUser(const char* query_str, T& res);

  void skewInsert();
  void leftistInsert();

};

#endif
