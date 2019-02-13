/**
 * @author: Evan Brown
 * @file: CharacterWrapper.cpp
 * @date: 2/12/19
 * @brief: implementation of character wrapper class
 */

#include <iostream>
#include "CharacterWrapper.hpp"

CharacterWrapper::CharacterWrapper(const char* string){

  readString(string);

}

CharacterWrapper::~CharacterWrapper(){

  delete[] string;

}

CharacterWrapper::CharacterWrapper(const CharacterWrapper& copy_cw){

  readString(copy_cw.string);

}

CharacterWrapper& CharacterWrapper::operator=(const CharacterWrapper& copy_cw){

  delete[] string;
  readString(copy_cw.string);

  return *this;

}

CharacterWrapper& CharacterWrapper::operator=(const char* string){

  delete[] this->string;
  readString(string);

  return *this;

}

bool CharacterWrapper::operator==(const CharacterWrapper& cw){
  if((cw.length < 8 || length < 8) && cw.length != length){
    return false;
  }

  for(int i = 0; i < 8 && i < length; i++){
    if(string[i] != cw.string[i]){
      return false;
    }
  }

  return true;

}

bool CharacterWrapper::operator!=(const CharacterWrapper& cw){
  return(!(*this == cw));
}

int CharacterWrapper::getLength() const{
  return length;
}

int CharacterWrapper::cwhash(const CharacterWrapper& cw){

  int hash_val = 0;

  for(int i = (cw.length > 7 ? 7 : cw.length); i >= 0; i--){
    hash_val *= 10;
    hash_val += static_cast<int>(cw.string[i]);
  }

  return hash_val;

}

CharacterWrapper CharacterWrapper::getReverse(const CharacterWrapper& cw){

  char* rev_string = new char[cw.length+1];
  rev_string[cw.length] = '\0';

  for(int i = 0; i < cw.length; i++){
    rev_string[i] = cw.string[cw.length-i-1];
  }

  CharacterWrapper rev_cw(rev_string);
  delete[] rev_string;

  return rev_cw;

}

void CharacterWrapper::readString(const char* string){

  length = 0;
  while(string[length] != '\0'){
    length++;
  }

  this->string = new char[length+1];
  this->string[length] = '\0';

  for(int i = 0; i < length; i++){
    this->string[i] = string[i];
  }

}

std::ostream& operator<<(std::ostream& stream, const CharacterWrapper& cw){

  stream << cw.string;

  return stream;

}
