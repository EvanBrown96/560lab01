/**
 * @author: Evan Brown
 * @file: InputParser.cpp
 * @date: 3/26/19
 * @brief: implementation of parse method for reading data from input stream
 *         adapted from 560 lab 6
 */

#include "InputParser.hpp"

void InputParser::parse(std::istream& stream, QuickQueue<String>& ll) throw(ParseError){

  char res;

  // repeat until reach end of line, getting strings from input
  while(true){

    InputParser::discardSpaces(stream, res);

    // check if end of input has been reached
    if(res == '\n' || stream.eof()){
      return;
    }

    String cw = InputParser::parseString(stream, res);

    // add the current value to the linked list
    ll.push(cw);

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

String InputParser::parseString(std::istream& stream, char& res){

  QuickQueue<char> char_ll(10);
  int str_size = 0;

  // repeat until we reach space again
  do{

    char_ll.push(res);
    str_size++;

    // get next character
    stream.get(res);

  }while(res != ' ' && res != '\t' && res != '\n' && !stream.eof());

  char* res_string = new char[str_size+1];
  res_string[str_size] = '\0';

  for(int i = 0; i < str_size; i++){
    res_string[i] = char_ll.pop();
  }

  String cw(res_string);
  delete[] res_string;
  return cw;

}

bool InputParser::isInt(char c_val){
  int ret = toInt(c_val);
  return(ret >= 0 && ret <= 9);
}

int InputParser::toInt(char c_val){
  return static_cast<int>(c_val) - 48;
}
