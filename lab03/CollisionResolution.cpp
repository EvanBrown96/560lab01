CollisionResolution::CollisionResolution(): state(1){}

void CollisionResolution::start(int initial_hash){
  state = 1;
  this->initial_hash = initial_hash;
}

void CollisionResolution::next(){
  state++;
}
