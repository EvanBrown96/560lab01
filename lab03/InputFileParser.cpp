/**
 * @author: Evan Brown
 * @file: InputFileParser.cpp
 * @date: 2/12/19
 * @brief: implementation of parse method for reading numbers from input stream
 */

#include <stdexcept>
#include "InputFileParser.hpp"
#include "ParseError.hpp"

int InputFileParser::parse(std::istream& stream, LinkedList<CharacterWrapper>& ll){

  char res;
  int count = 0;

  // get size to set the hash table to initially
  stream.get(res);

  while(res == ' ' || res == '\t'){
    stream.get(res);
  }

  if(res == '\n' || stream.eof()){
    throw ParseError(stream);
  }

  do{

    if(!isInt(res)){
      throw ParseError(stream);
    }

    // update current value with the most recent character
    count *= 10;
    count += toInt(res);

    // get next character
    stream.get(res);

  }while(res != ' ' && res != '\t' && res != '\n' && !stream.eof());


  // repeat until reach end of line, getting strings from input
  while(true){

    // throw out any whitespace before next string
    while(res == ' ' || res == '\t'){
      stream.get(res);
    }

    // check if end of input has been reached
    if(res == '\n' || stream.eof()){
      return count;
    }

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

    CharacterWrapper cw(res_string);

    // add the current value to the linked list
    ll.insertBack(cw);

  }

}

bool InputFileParser::isInt(char c_val){
  int ret = toInt(c_val);
  return(ret >= 0 && ret <= 9);
}

int InputFileParser::toInt(char c_val){
  return static_cast<int>(c_val) - 48;
}
