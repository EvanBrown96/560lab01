/**
 * @author: Evan Brown
 * @file: NumberParseError.hpp
 * @date: 1/28/19
 * @brief: header file defining exception occuring during number parsing
 */

#ifndef NumberParseError_hpp
#define NumberParseError_hpp

#include <stdexcept>
#include <iostream>

class NumberParseError: public std::logic_error{

public:

  /**
   * constructor
   * @param stream: the stream that caused the error
   */
  NumberParseError(std::istream& stream);

  /**
   * returns the position of the erroneous character in the stream
   * @return: position of error
   */
  int getErrPos();

private:

  int err_pos;

};

#endif
