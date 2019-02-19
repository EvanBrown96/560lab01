/**
 * @author: Evan Brown
 * @file: main.cpp
 * @date: 2/19/19
 * @brief: entry point to the program
 */

#include "OpenHashTable.hpp"
#include "ClosedHashTable.hpp"
#include "QuadraticProbing.hpp"

int myhash(const int& val){
  return val;
}

int main(int argc, char** argv){
  OpenHashTable<int> oht(7, myhash);
  ClosedHashTable<int, QuadraticProbing> cht(7, myhash);
}
