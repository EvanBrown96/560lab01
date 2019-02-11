/**
 * @author: Evan Brown
 * @file: main.cpp
 * @date: 2/11/19
 * @brief: main entry point to the program
 */

#include "HashTable.hpp"
#include "LinearProbing.hpp"
#include "CharacterWrapper.hpp"

int main(int argc, char** argv){

  HashTable<CharacterWrapper, LinearProbing> ht(7, CharacterWrapper::cwhash);
  CharacterWrapper cw("test");
  ht.insert(cw);
  ht.print();

  return 0;
}
