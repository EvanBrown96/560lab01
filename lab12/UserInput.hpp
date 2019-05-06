/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 5/6/19
 * @brief: header file for user input functions
 *         adapted from 560 lab04
 */

#ifndef USERINPUT_HPP
#define USERINPUT_HPP

#include "Graph.hpp"

class UserInput{

public:

  /**
   * constructor
   * @param startoff: hash table to use as base for program
   * @post: creates userinput instance with the given hash table
   */
  UserInput(Graph* g);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  Graph* g;

  /**
   * ignores any characters still in the input buffer and clears error flags
   * @post: std::cin is ready for input again
   */
  void clearCin();

  void userBFS();

  void userDFS();

  void userKruskal();

  void userPrim();

};

#endif
