#ifndef CollisionResolution_hpp
#define CollisionResolution_hpp

class CollisionResolution{

public:

  CollisionResolution();

  void start(int initial_hash);

  void next();

  virtual int getNewHash() const = 0;

private:

  int state;
  int initial_hash;

};

#endif
