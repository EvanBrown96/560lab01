/**
 * @author: Evan Brown
 * @file: LinearProbing.cpp
 * @date: 2/8/19
 * @brief: implementation of linear probing collision resolution strategy
 */

#include "LinearProbing.hpp"

LinearProbing::LinearProbing(int initial_hash): CollisionResolution(initial_hash){}

int LinearProbing::getNewHash() const{
  return initial_hash+state;
}
