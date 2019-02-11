/**
 * @author: Evan Brown
 * @file: EmptyList.hpp
 * @date: 1/26/19
 * @brief: head file defining exception signifying an invalid operation was attempted on an empty list.
 *         adapted from 560 lab 2
 */

#ifndef EmptyList_hpp
#define EmptyList_hpp

#include <stdexcept>

class EmptyList: public std::logic_error{

public:

  /**
   * constructor
   */
  EmptyList();

};

#endif
