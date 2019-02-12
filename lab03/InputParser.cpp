/**
 * @author: Evan Brown
 * @file: InputParser.cpp
 * @date: 2/12/19
 * @brief: implementation of parse method for reading data from input stream
 */

#include "InputParser.hpp"

int InputParser::parse(std::istream& stream, LinkedList<CharacterWrapper>& ll) throw(ParseError){

  char res;

  InputParser::discardSpaces(stream, res);

  if(res == '\n' || stream.eof()){
    throw ParseError(stream);
  }

  int count = InputParser::parseInt(stream, res);

  // repeat until reach end of line, getting strings from input
  while(true){

    InputParser::discardSpaces(stream, res);

    // check if end of input has been reached
    if(res == '\n' || stream.eof()){
      return count;
    }

    CharacterWrapper cw = InputParser::parseString(stream, res);

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

CharacterWrapper InputParser::parseString(std::istream& stream, char& res){

  std::cout <<"enter";

  LinkedList<char> char_ll;
  int str_size = 0;

  // repeat until we reach space again
  do{

    std::cout << res;
    char_ll.insertBack(res);
    str_size++;

    // get next character
    stream.get(res);

  }while(res != ' ' && res != '\t' && res != '\n' && !stream.eof());

  std::cout <<"done";
  char_ll.print();
  char* res_string = new char[str_size+1];
  res_string[str_size] = '\0';

  for(int i = 0; i < str_size; i++){
    res_string[i] = char_ll.popFront();
  }
  std::cout << "aaaa";
  std::cout << res_string;
  return CharacterWrapper(res_string);

}

bool InputParser::isInt(char c_val){
  int ret = toInt(c_val);
  return(ret >= 0 && ret <= 9);
}

int InputParser::toInt(char c_val){
  return static_cast<int>(c_val) - 48;
}
