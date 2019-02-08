

#include "HashTable.hpp"
#include "LinearProbing.hpp"

int myhash(const int& value){
  return value;
}

int main(int argc, char** argv){

  HashTable<int, LinearProbing> ht(7, myhash);
  ht.insert(20);
  ht.print();

  return 0;
}
