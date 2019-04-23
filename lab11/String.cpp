/**
 * @author: Evan Brown
 * @file: String.cpp
 * @date: 4/8/19
 * @brief: implementation of character wrapper class
 *         adapted from 560 lab 7
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
  // return(getASCII(*this) > getASCII(cw));
  return false;
}

bool String::operator<(const String& cw) const{
  // return(getASCII(*this) < getASCII(cw));
  return false;
}

bool String::operator>=(const String& cw) const{
  // return(getASCII(*this) >= getASCII(cw));
  return false;
}

bool String::operator<=(const String& cw) const{
  // return(getASCII(*this) <= getASCII(cw));
  return false;
}

int String::getInt() const{
  int sum = 0;
  for(int i = 0; i < length; i++){
    sum *= 10;
    sum += static_cast<int>(string[i])-48;
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

void String::printMaxLen(int max) const{
  if(length <= max){
    int side = (max-length)/2;
    for(int i = 0; i < side; i++){
      std::cout << " ";
    }
    std::cout << *this;
    for(int i = 0; i < max - length - side; i++){
      std::cout << " ";
    }
    return;
  }
  for(int i = 0; i < max-3; i++){
    std::cout << string[i];
  }
  std::cout << "...";
}

std::ostream& operator<<(std::ostream& stream, const String& cw){

  stream << cw.string;

  return stream;

}

char& String::operator[](int pos){
  if(pos < 0 || pos >= length) throw std::range_error("Index not in string");
  return string[pos];
}
