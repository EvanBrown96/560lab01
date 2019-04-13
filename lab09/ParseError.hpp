/**
 * @author: Evan Brown
 * @file: ParseError.hpp
 * @date: 2/11/19
 * @brief: header file defining exception occuring during input file parsing
 *         adapted from 560 lab 7
 */

#ifndef PARSEERROR_HPP
#define PARSEERROR_HPP

#include <stdexcept>
#include <iostream>

class ParseError: public std::logic_error{

public:

  /**
   * constructor
   * @param stream: the stream that caused the error
   */
  ParseError(std::istream& stream);

  /**
   * returns the position of the erroneous character in the stream
   * @return: position of error
   */
  int getErrPos();

private:

  int err_pos;

};

#endif
