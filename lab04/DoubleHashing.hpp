/**
 * @author: Evan Brown
 * @file: DoubleHashing.hpp
 * @date: 2/12/19
 * @brief: specification of double hashing collision resolution strategy methods
 *         adapted from 560 lab 3
 */

#ifndef DoubleHashing_hpp
#define DoubleHashing_hpp

#include "CollisionResolution.hpp"

class DoubleHashing: public CollisionResolution{

public:

  DoubleHashing(int initial_hash);

  int getNewHash() const;

};

#endif
