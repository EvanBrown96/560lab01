/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 2/19/19
 * @brief: header file for user input functions
 *         adapted from 560 lab03
 */

#ifndef UserInput_hpp
#define UserInput_hpp

#include "OpenHashTable.hpp"
#include "ClosedHashTable.hpp"
#include "QuadraticProbing.hpp"
#include "DoubleHashing.hpp"

int TABLE_SIZE = 1000003;

int myhash(const int& val);

class UserInput{

public:

  /**
   * constructor
   * @param startoff: hash table to use as base for program
   * @post: creates userinput instance with the given hash table
   */
  UserInput(const OpenHashTable<int>& startoff_open,
    const ClosedHashTable<int, QuadraticProbing>& startoff_quad,
    const ClosedHashTable<int, DoubleHashing>& startoff_double);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  OpenHashTable<int> test_open;
  ClosedHashTable<int, QuadraticProbing> test_quad;
  ClosedHashTable<int, DoubleHashing> test_double;

  /**
   * ignores any characters still in the input buffer and clears error flags
   * @post: std::cin is ready for input again
   */
  void clearCin();

  void column();

  void userTest();

  void userPerformance();

};

#endif
