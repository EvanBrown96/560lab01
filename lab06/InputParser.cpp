/**
 * @author: Evan Brown
 * @file: InputParser.cpp
 * @date: 2/12/19
 * @brief: implementation of parse method for reading data from input stream
 *         adapted from 560 lab 3
 */

#include "InputParser.hpp"

void InputParser::parse(std::istream& stream, LinkedList<String>& ll) throw(ParseError){

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
    ll.insertBack(cw);

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

  LinkedList<char> char_ll;
  int str_size = 0;

  // repeat until we reach space again
  do{

    char_ll.insertBack(res);
    str_size++;

    // get next character
    stream.get(res);

  }while(res != ' ' && res != '\t' && res != '\n' && !stream.eof());

  char* res_string = new char[str_size+1];
  res_string[str_size] = '\0';

  for(int i = 0; i < str_size; i++){
    res_string[i] = char_ll.popFront();
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
