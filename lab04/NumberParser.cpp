/**
 * @author: Evan Brown
 * @file: NumberParser.cpp
 * @date: 1/28/19
 * @brief: implementation of parse method for reading numbers from input stream
 *         adapted from 560 lab02
 */

#include <stdexcept>
#include "NumberParser.hpp"
#include "NumberParseError.hpp"

void NumberParser::parse(std::istream& stream, LinkedList<int>& ll){

  char res;
  int cur;
  int value;
  bool is_neg;

  // get first character of input
  stream.get(res);

  // repeat until reach end of line
  while(true){

    // reset current value
    value = 0;
    // throw out any whitespace before next number
    while(res == ' ' || res == '\t'){
      stream.get(res);
    }

    // check if end of input has been reached
    if(res == '\n' || stream.eof()){
      return;
    }

    // check if first character of input is a minus sign
    is_neg = false;
    if(res == '-'){
      is_neg = true;
      stream.get(res);
    }

    // repeat until we reach space again
    do{

      if(!isInt(res)){
        throw NumberParseError(stream);
      }

      // update current value with the most recent character
      value *= 10;
      value += toInt(res);

      // get next character
      stream.get(res);

    }while(res != ' ' && res != '\t' && res != '\n' && !stream.eof());

    // add the current value to the linked list
    ll.insertBack(is_neg ? (-1)*value : value);

  }

}

bool NumberParser::isInt(char c_val){
  int ret = toInt(c_val);
  return(ret >= 0 && ret <= 9);
}

int NumberParser::toInt(char c_val){
  return static_cast<int>(c_val) - 48;
}
