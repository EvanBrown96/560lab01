/**
 * @author: Evan Brown
 * @file: ValueNotFound.hpp
 * @date: 1/26/19
 * @brief: header file for value not found exception
 *         adapted from 560 lab 5
 */

#ifndef ValueNotFound_hpp
#define ValueNotFound_hpp

#include <stdexcept>

template <typename A>
class ValueNotFound: public std::logic_error{

public:

  /**
   * constructor
   * @param err_value: the value that caused the error (could not be found)
   */
  ValueNotFound(A err_value);

  /**
   * returns value that caused the error
   * @return: error value
   */
  A getErrValue() const;

private:

  A err_value;

};

#include "ValueNotFound.cpp"

#endif
