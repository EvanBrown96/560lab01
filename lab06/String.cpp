/**
 * @author: Evan Brown
 * @file: String.cpp
 * @date: 2/12/19
 * @brief: implementation of character wrapper class
 */

#include <iostream>
#include "String.hpp"

String::String(const char* string){

  readString(string);

}

String::~String(){

  delete[] string;

}

String::String(const String& copy_cw){

  readString(copy_cw.string);

}

String& String::operator=(const String& copy_cw){

  delete[] string;
  readString(copy_cw.string);

  return *this;

}

String& String::operator=(const char* string){

  delete[] this->string;
  readString(string);

  return *this;

}

bool String::operator==(const String& cw) const{

  if(cw.length != length) return false;

  for(int i = 0; i < length; i++){
    if(string[i] != cw.string[i]) return false;
  }
  return true;

}

bool String::operator!=(const String& cw) const{
  return(!(*this == cw));
}

bool String::operator>(const String& cw) const{
  return(getASCII(*this) > getASCII(cw));
}

bool String::operator<(const String& cw) const{
  return(getASCII(*this) < getASCII(cw));
}

bool String::operator>=(const String& cw) const{
  return(getASCII(*this) >= getASCII(cw));
}

bool String::operator<=(const String& cw) const{
  return(getASCII(*this) <= getASCII(cw));
}

int String::getASCII(const String& cw){
  int sum = 0;
  for(int i = 0; i < cw.length; i++){
    sum += static_cast<int>(cw.string[i]);
  }
  return sum;
}

int String::getLength() const{
  return length;
}

void String::readString(const char* string){

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

std::ostream& operator<<(std::ostream& stream, const String& cw){

  stream << cw.string;

  return stream;

}
