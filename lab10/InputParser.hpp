/**
 * @author: Evan Brown
 * @file: InputParser.hpp
 * @date: 3/26/19
 * @brief: header file for input stream parser
 *         adapted from 560 lab 7
 */

#ifndef INPUTPARSER_HPP
#define INPUTPARSER_HPP

#include <istream>
#include "QuickQueue.hpp"
#include "String.hpp"
#include "ParseError.hpp"

class InputParser{
public:

  /**
   * reads data from the given stream and puts them into the given list
   * expects an integer first, then:
   * expects strings to be separated by spaces
   * terminates at first newline (or end of file)
   * @pre: the stream has been opened and is ready for reading
   * @param stream: the istream to read data from
   * @param ll: the QuickQueue to add string data to
   * @post: the linked list contains the strings read from the stream, in order
   */
  static void parse(std::istream& stream, QuickQueue<String>& ll);

  static void discardSpaces(std::istream& stream, char& res);
  static int parseInt(std::istream& stream, char& res);
  static String parseString(std::istream& stream, char& res);

private:

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
