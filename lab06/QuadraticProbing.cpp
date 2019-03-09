/**
 * @author: Evan Brown
 * @file: QuadraticProbing.cpp
 * @date: 2/12/19
 * @brief: implementation of quadratic probing collision resolution strategy
 *         adapted from 560 lab 3
 */

#include "QuadraticProbing.hpp"

QuadraticProbing::QuadraticProbing(int initial_hash): CollisionResolution(initial_hash){}

int QuadraticProbing::getNewHash() const{
  return initial_hash+(state*state);
}
