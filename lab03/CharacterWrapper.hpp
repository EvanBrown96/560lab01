/**
 * @author: Evan Brown
 * @file: CharacterWrapper.hpp
 * @date: 2/12/19
 * @brief: header file for character wrapper class
 */

#ifndef CharacterWrapper_hpp
#define CharacterWrapper_hpp

class CharacterWrapper{

public:

  CharacterWrapper(const char* string);
  ~CharacterWrapper();
  CharacterWrapper(const CharacterWrapper& copy_cw);
  CharacterWrapper& operator=(const CharacterWrapper& copy_cw);
  CharacterWrapper& operator=(const char* string);

  bool operator==(const CharacterWrapper& cw);
  bool operator!=(const CharacterWrapper& cw);

  int getLength() const;

  static int cwhash(const CharacterWrapper& cw);
  static CharacterWrapper getReverse(const CharacterWrapper& cw);

  friend std::ostream& operator<<(std::ostream& stream, const CharacterWrapper& cw);

private:

  void readString(const char* string);

  char* string;
  int length;

};

#endif
