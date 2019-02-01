/**
 * @author: Evan Brown
 * @file: main.cpp
 * @date: 1/29/18
 * @brief: entry point to program
 */

#include "HashTable.hpp"
#include <iostream>

int myhash(const int& value);

int main(int argc, char** argv){

  HashTable<int> ht(25, myhash);
  //std::cout << ht.hash_function(24) << "\n";

  return 0;

}

int myhash(const int& value){
  return value*2;
}
