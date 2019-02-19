/**
 * @author: Evan Brown
 * @file: DoubleHashing.cpp
 * @date: 2/12/19
 * @brief: implementation of double hashing collision resolution strategy
 *         adapted from 560 lab 3
 */

#include "DoubleHashing.hpp"

DoubleHashing::DoubleHashing(int initial_hash): CollisionResolution(initial_hash){}

int DoubleHashing::getNewHash() const{
  return initial_hash+(state * (5-initial_hash%5));
}
