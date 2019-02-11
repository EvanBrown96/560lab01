/**
 * @author: Evan Brown
 * @file: CollisionResolution.hpp
 * @date: 2/8/19
 * @brief: header file for collision resolution strategies abstract class
 */

#ifndef CollisionResolution_hpp
#define CollisionResolution_hpp

class CollisionResolution{

public:

  CollisionResolution(int initial_hash);

  void next();

  virtual int getNewHash() const = 0;

protected:

  int state;
  int initial_hash;

};

#endif
