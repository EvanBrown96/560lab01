#include "CollisionResolution.hpp"

CollisionResolution::CollisionResolution(int initial_hash): initial_hash(initial_hash), state(0){}

void CollisionResolution::next(){
  state++;
}
