/**
 * @author: Evan Brown
 * @file: InputFileParser.hpp
 * @date: 2/12/19
 * @brief: header file for input file parser
 */

#ifndef InputFileParser_hpp
#define InputFileParser_hpp

#include <istream>
#include "LinkedList.hpp"
#include "CharacterWrapper.hpp"

class InputFileParser{
public:

  /**
   * reads data from the given stream and puts them into the given list
   * expects an integer first, then:
   * expects strings to be separated by spaces
   * terminates at first newline (or end of file)
   * @pre: the stream has been opened and is ready for reading
   * @param stream: the istream to read data from
   * @param ll: the linkedlist to add string data to
   * @return: the intended size of the hash table (the initial integer read)
   * @post: the linked list contains the strings read from the stream, in order
   */
  static int parse(std::istream& stream, LinkedList<CharacterWrapper>& ll);

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
