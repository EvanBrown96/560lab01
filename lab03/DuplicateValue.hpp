/**
 * @author: Evan Brown
 * @file: DuplicateValue.hpp
 * @date: 2/1/19
 * @brief: header file for value not found exception
 *         adapted from 560 lab 2
 */

#ifndef DuplicateValue_hpp
#define DuplicateValue_hpp

#include <stdexcept>

template <typename A>
class DuplicateValue: public std::logic_error{

public:

  /**
   * constructor
   * @param err_value: the value that caused the error (was a duplicate)
   */
  DuplicateValue(A err_value);

  /**
   * returns value that caused the error
   * @return: error value
   */
  A getErrValue() const;

private:

  A err_value;

};

#include "DuplicateValue.cpp"

#endif
