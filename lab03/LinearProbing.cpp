#include "LinearProbing.hpp"

LinearProbing::LinearProbing(int initial_hash): CollisionResolution(initial_hash){}

int LinearProbing::getNewHash() const{
  return initial_hash+state;
}
