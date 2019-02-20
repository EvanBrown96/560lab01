/**
 * @author: Evan Brown
 * @file: NumberParser.hpp
 * @date: 1/28/19
 * @brief: header file for number parser
 *         adapted from 560 lab02
 */

#ifndef NumberParser_hpp
#define NumberParser_hpp

#include <istream>
#include "LinkedList.hpp"

class NumberParser{
public:

  /**
   * reads numbers from the given stream and puts them into the given list
   * expects numbers to be separated by spaces
   * terminates at first newline (or end of file)
   * @pre: the stream has been opened and is ready for reading
   * @param stream: the istream to read data from
   * @param ll: the linkedlist to add data to
   * @post: the linked list contains the numbers read from the stream, in order
   */
  static void parse(std::istream& stream, LinkedList<int>& ll);

private:

  NumberParser(){}
  
  /**
   * checks if the character is 0-9
   * @param c_val: the character to check
   * @return: true if character is 0-9, false otherwise
   */
  static bool isInt(char c_val);

  /**
   * returns integer representation of character
   * @param c_val: character to convert
   * @return: ascii value of character minus 48
   */
  static int toInt(char c_val);

};

#endif
