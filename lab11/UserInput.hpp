/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 4/23/19
 * @brief: header file for user input functions
 *         adapted from 560 lab04
 */

#ifndef UserInput_hpp
#define UserInput_hpp

#include "BinarySearchTree.hpp"
#include "MinHeap.hpp"
#include "MaxHeap.hpp"
#include "Timer.hpp"

#define TABLE_SIZE 1000003

class UserInput{

public:

  /**
   * constructor
   * @param startoff: hash table to use as base for program
   * @post: creates userinput instance with the given hash table
   */
  UserInput(const BinarySearchTree<int>& startoff_bst,
    const MinHeap<5, int>& startoff_minh,
    const MaxHeap<5, int>& startoff_maxh);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  BinarySearchTree<int> test_bst;
  MinHeap<5, int> test_minh;
  MinHeap<5, int> test_maxh;

  /**
   * ignores any characters still in the input buffer and clears error flags
   * @post: std::cin is ready for input again
   */
  void clearCin();

  void column() const;

  void printTable(Timer* build_times, Timer* found_times, Timer* not_found_times) const;

  void userTest();

  // void userPerformanceOpenHashing();
  //
  // void userPerformanceClosedHashingQuadraticProbing();
  //
  // void userPerformanceClosedHashingDoubleHashing();

  int MAX_RAND;
  int SIZES[5];
  int FINDS[5];

};

#endif
