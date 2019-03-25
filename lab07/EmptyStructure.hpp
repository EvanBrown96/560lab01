/**
 * @author: Evan Brown
 * @file: EmptyStructure.hpp
 * @date: 2/27/19
 * @brief: header file defining exception signifying an invalid operation was attempted on an empty data structure.
 *         adapted from 560 lab 6
 */

#ifndef EMPTYSTRUCTURE_HPP
#define EMPTYSTRUCTURE_HPP

#include <stdexcept>

class EmptyStructure: public std::logic_error{

public:

  /**
   * constructor
   */
  EmptyStructure();

};

#endif
