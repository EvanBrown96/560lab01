#include "HashTable.hpp"
#include "LinearProbing.hpp"
#include "CharacterWrapper.hpp"

int myhash(const int& value){
  return value;
}

int main(int argc, char** argv){

  HashTable<CharacterWrapper, LinearProbing> ht(7, CharacterWrapper::cwhash);
  CharacterWrapper cw("test");
  ht.insert(cw);
  ht.print();

  return 0;
}
