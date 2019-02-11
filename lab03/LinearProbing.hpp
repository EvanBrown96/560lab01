/**
 * @author: Evan Brown
 * @file: LinearProbing.hpp
 * @date: 2/8/19
 * @brief: specification of linear probing collision resolution strategy methods
 */

#ifndef LinearProbing_hpp
#define LinearProbing_hpp

#include "CollisionResolution.hpp"

class LinearProbing: public CollisionResolution{

public:

  LinearProbing(int initial_hash);

  int getNewHash() const;

};

#endif
