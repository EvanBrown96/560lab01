/**
 * @author: Evan Brown
 * @file: NumberParser.cpp
 * @date: 1/28/19
 * @brief: implementation of parse method for reading numbers from input stream
 */

#include <stdexcept>
#include "NumberParser.hpp"

void NumberParser::parse(std::istream& stream, LinkedList<int>& ll){

  char res;
  int cur;
  int value;
  bool is_neg;

  // get first character of input
  stream.get(res);

  // repeat until reach end of line
  while(res != '\n' && !stream.eof()){

    // reset current value
    value = 0;
    // throw out any whitespace before next number
    while(res == ' ' || res == '\t'){
      stream.get(res);
    }

    // check if first character of input is a minus sign
    is_neg = false;
    if(res == '-'){
      is_neg = true;
      stream.get(res);
    }

    // repeat until we reach space again
    while(res != ' ' && res != '\t' && res != '\n' && !stream.eof()){

      // get integer value of current character
      cur = static_cast<int>(res) - 48;
      // if the character is not a number, exit function
      if(cur < 0 || cur > 9){
        throw std::logic_error("asdf");
      }

      // update current value with the most recent character
      value *= 10;
      value += cur;

      // get next character
      stream.get(res);

    }

    // add the current value to the linked list
    ll.insert(is_neg ? (-1)*value : value);

  }

}
