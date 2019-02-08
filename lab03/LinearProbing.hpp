#ifndef LinearProbing_hpp
#define LinearProbing_hpp

#include "CollisionResolution.hpp"

class LinearProbing: public CollisionResolution{

public:

  LinearProbing(int initial_hash);

  int getNewHash() const;

};

#endif
