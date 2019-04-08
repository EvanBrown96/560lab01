/**
 * @author: Evan Brown
 * @file: String.hpp
 * @date: 2/12/19
 * @brief: header file for character wrapper class
 *         adapted from 560 lab 6
 */

#ifndef STRING_HPP
#define STRING_HPP

#include <stdexcept>

class String{

public:

  String(const char* string);
  ~String();
  String(const String& copy_cw);
  String& operator=(const String& copy_cw);
  String& operator=(const char* string);

  bool operator==(const String& cw) const;
  bool operator!=(const String& cw) const;
  bool operator>(const String& cw) const;
  bool operator<(const String& cw) const;
  bool operator>=(const String& cw) const;
  bool operator<=(const String& cw) const;

  int getInt() const;

  int getLength() const;

  void printMaxLen(int max) const;
  friend std::ostream& operator<<(std::ostream& stream, const String& cw);

  char& operator[](int pos) throw(std::range_error);

private:

  void readString(const char* string);

  char* string;
  int length;

};

#endif
