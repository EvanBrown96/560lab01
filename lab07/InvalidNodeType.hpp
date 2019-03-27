/**
 * @author: Evan Brown
 * @file: InvalidNodeType.hpp
 * @date: 3/25/19
 * @brief: header file defining exception signifying operation performed on incorrect type of 2-3 node
 */

#ifndef INVALIDNODETYPE_HPP
#define INVALIDNODETYPE_HPP

#include <stdexcept>

class InvalidNodeType: public std::logic_error{

public:

  /**
   * constructor
   */
  InvalidNodeType(const char* msg);

};

#endif
