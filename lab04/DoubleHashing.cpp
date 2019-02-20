/**
 * @author: Evan Brown
 * @file: DoubleHashing.cpp
 * @date: 2/12/19
 * @brief: implementation of double hashing collision resolution strategy
 *         adapted from 560 lab 3
 */

//#include "DoubleHashing.hpp"

template <int Num>
DoubleHashing<Num>::DoubleHashing(int initial_hash): CollisionResolution(initial_hash){}

template <int Num>
int DoubleHashing<Num>::getNewHash() const{
  return initial_hash+(state * (Num-initial_hash%5));
}
