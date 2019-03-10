/**
 * @author: Evan Brown
 * @file: String.hpp
 * @date: 2/12/19
 * @brief: header file for character wrapper class
 */

#ifndef STRING_HPP
#define STRING_HPP

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

  static int getASCII(const String& cw);

  int getLength() const;

  friend std::ostream& operator<<(std::ostream& stream, const String& cw);

private:

  void readString(const char* string);

  char* string;
  int length;

};

#endif
