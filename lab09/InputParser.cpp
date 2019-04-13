/**
 * @author: Evan Brown
 * @file: InputParser.cpp
 * @date: 4/13/19
 * @brief: implementation of parse method for reading data from input stream
 *         adapted from 560 lab 8
 */

#include "InputParser.hpp"

void InputParser::parse(std::istream& stream, QuickQueue<Process>& ll) throw(ParseError){

  char res;

  // repeat until reach end of line, getting strings from input
  while(true){

    stream.get(res);
    while(res == ' ' || res == '\t' || res == ','){
      stream.get(res);
    }
    stream.putback(res);

    // check if end of input has been reached
    if(res == '\n' || stream.eof()){
      return;
    }

    Process p(0, 0);
    if(!(stream >> p)) throw ParseError(stream);

    // add the current value to the linked list
    ll.push(p);

  }

}

void InputParser::discardSpaces(std::istream& stream, char& res){

  stream.get(res);

  while(res == ' ' || res == '\t'){
    stream.get(res);
  }

}

int InputParser::parseInt(std::istream& stream, char& res) throw(ParseError){

  int value = 0;

  do{

    if(!isInt(res)){
      throw ParseError(stream);
    }

    // update current value with the most recent character
    value *= 10;
    value += toInt(res);

    // get next character
    stream.get(res);

  }while(res != ' ' && res != '\t' && res != '\n' && !stream.eof());

  return value;

}

bool InputParser::isInt(char c_val){
  int ret = toInt(c_val);
  return(ret >= 0 && ret <= 9);
}

int InputParser::toInt(char c_val){
  return static_cast<int>(c_val) - 48;
}
