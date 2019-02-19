/**
 * @author: Evan Brown
 * @file: CollisionResolution.cpp
 * @date: 2/8/19
 * @brief: implementation of collision resolution abstract class methods
 *         adapted from 560 lab 3
 */

#include "CollisionResolution.hpp"

CollisionResolution::CollisionResolution(int initial_hash): initial_hash(initial_hash), state(0){}

void CollisionResolution::next(){
  state++;
}
