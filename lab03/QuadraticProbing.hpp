/**
 * @author: Evan Brown
 * @file: QuadraticProbing.hpp
 * @date: 2/12/19
 * @brief: specification of quadratic probing collision resolution strategy methods
 */

#ifndef QuadraticProbing_hpp
#define QuadraticProbing_hpp

#include "CollisionResolution.hpp"

class QuadraticProbing: public CollisionResolution{

public:

  QuadraticProbing(int initial_hash);

  int getNewHash() const;

};

#endif
