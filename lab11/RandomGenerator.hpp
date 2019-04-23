/**
 * @author: Evan Brown
 * @file: RandomGenerator.hpp
 * @date: 2/19/19
 * @brief: header file for random number generator wrapper
 *         adapted from 560 lab 4
 */

#ifndef RandomGenerator_hpp
#define RandomGenerator_hpp

#include <stdlib.h>
#include <time.h>

enum bound {INCLUSIVE, EXCLUSIVE};

class RandomGenerator{

public:

  static void seed(unsigned int seedv);

  static void seedTime();

  static int get();

  static int getFromZeroTo(unsigned int max, enum bound b = EXCLUSIVE);

  static int getFromOneTo(unsigned int max, enum bound b = INCLUSIVE);

  static int getRange(int min, enum bound b_low, int max, enum bound b_high);

private:

  RandomGenerator(){}

};

#endif
