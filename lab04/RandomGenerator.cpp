/**
 * @author: Evan Brown
 * @file: RandomGenerator.cpp
 * @date: 2/19/19
 * @brief: implementation of random number wrapper
 */

#include "RandomGenerator.hpp"

void RandomGenerator::seed(unsigned int seedv){
  srand(seedv);
}

void RandomGenerator::seedTime(){
  srand(time(NULL));
}

int RandomGenerator::get(){
  return rand();
}

int RandomGenerator::getFromZeroTo(unsigned int max, enum bound b){
  if(b == EXCLUSIVE){
    return rand() % max;
  }
  return rand() % (max+1);
}

int RandomGenerator::getFromOneTo(unsigned int max, enum bound b){
  if(b == INCLUSIVE){
    return (rand() % max) + 1;
  }
  return (rand() % (max-1)) + 1;
}

int RandomGenerator::getRange(int min, enum bound b_low, int max, enum bound b_high){

  if(b_low == EXCLUSIVE){
    min += 1;
  }
  if(b_high == INCLUSIVE){
    max += 1;
  }
  return (rand() % (b_high-b_low)) + b_low;

}
