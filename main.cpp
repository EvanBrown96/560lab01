/**
 * @author: Evan Brown
 * @file: main.cpp
 * @date: 1/29/18
 * @brief: entry point to program
 */

#include "HashTable.hpp"
#include <iostream>

int myhash(const int& value){
  return value;
}

int main(int argc, char** argv){

  HashTable<int> ht(7, myhash);
  ht.insert(16);
  ht.insert(17);
  ht.insert(29);
  ht.insert(11);
  ht.insert(88);
  ht.insert(14);
  ht.insert(88);

  ht.print();

  HashTable<int> h2(ht);
  h2.insert(100);
  h2.print();
  ht.print();

  return 0;

}
