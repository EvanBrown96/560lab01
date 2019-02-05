/**
 * @author: Evan Brown
 * @file: UserInput.hpp
 * @date: 1/26/19
 * @brief: header file for user input functions
 */

#ifndef UserInput_hpp
#define UserInput_hpp

#include "LinkedList.hpp"

class UserInput{

public:

  /**
   * constructor
   * @param startoff: linked list to use as base for program
   * @post: creates userinput instance with the given linked list
   */
  UserInput(const LinkedList<int>& startoff);

  /**
   * enters menu input loop
   * loops until the user exits the menu
   */
  void start();

private:

  int choice;
  LinkedList<int> ll;

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
   * prints the smallest value in the list to the console
   */
  void userSmallest();

  /**
   * prints the largest value in the list to the console
   */
  void userLargest();

  /**
   * prints the average of the values in the list to the console
   */
  void userAverage();

  /**
   * prompts user for a list of values and merges those into the list using merge2lists method
   * @post: list is sorted and has given values added to it
   */
  void userMerge();

};

#endif
