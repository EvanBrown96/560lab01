/**
 * @author: Evan Brown
 * @file: InputParser.cpp
 * @date: 3/26/19
 * @brief: implementation of parse method for reading data from input stream
 *         adapted from 560 lab 7
 */

#include "InputParser.hpp"

void InputParser::parse(std::istream& stream, int& count, QuickQueue<int>& ll){

  char res;

  InputParser::discardSpaces(stream, res);

  count = InputParser::parseInt(stream, res);

  for(int i = 0; i < count*count; i++){
    InputParser::discardSpaces(stream, res);

    if(stream.eof()) return;

    ll.push(InputParser::parseInt(stream, res));
  }
  // repeat until reach end of line, getting strings from input
  // while(true){
  //
  //   InputParser::discardSpaces(stream, res);
  //
  //   // check if end of input has been reached
  //   if(res == '\n' || stream.eof()){
  //     return;
  //   }
  //
  //   String cw = InputParser::parseString(stream, res);
  //
  //   // add the current value to the linked list
  //   ll.push(cw);
  //
  // }

}

void InputParser::discardSpaces(std::istream& stream, char& res){

  stream.get(res);

  while(res == ' ' || res == '\t' || res == '\n'){
    stream.get(res);
  }

}

int InputParser::parseInt(std::istream& stream, char& res){

  int value = 0;
  bool is_neg = false;
  if(res == '-'){
    is_neg = true;
    stream.get(res);
  }

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

  if(is_neg) value *= -1;
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
