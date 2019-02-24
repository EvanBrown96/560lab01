/**
 * @author: Evan Brown
 * @file: UserInput.cpp
 * @date: 2/19/19
 * @brief: implementation of UserInput functions
 *         adapted from 560 lab03
 */

#include "UserInput.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <time.h>
#include <cmath>
#include "RandomGenerator.hpp"

int myhash(const int& val){
  return val;
}

UserInput::UserInput(const OpenHashTable<int>& startoff_open,
                     const ClosedHashTable<int, QuadraticProbing>& startoff_quad,
                     const ClosedHashTable<int, DoubleHashing<5>>& startoff_double):
                     test_open(startoff_open), test_quad(startoff_quad), test_double(startoff_double){

  MAX_RAND = 5 * TABLE_SIZE;
  for(int i = 0; i < 5; i++){
    SIZES[i] = floor(TABLE_SIZE * (static_cast<float>(i+1)/10));
    FINDS[i] = floor(0.1 * SIZES[i]);
  }
}

void UserInput::clearCin(){
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void UserInput::start(){

  int choice = 0;

  while(true){

    std::cout << "Choose one operation from the options below:\n\n";
    std::cout << "\t1. Test Hash Tables\n";
    std::cout << "\t2. Performance Comparison\n";
    std::cout << "\t3. Exit\n";

    while(!(std::cin >> choice && choice > 0 && choice < 4)){
      clearCin();
      std::cout << "Invalid choice, try again: ";
    }

    if(choice == 3){
      break;
    }

    switch(choice){
      case 1: {
        userTest();
        break;
      }
      default: {
        userPerformanceOpenHashing();
        userPerformanceClosedHashingQuadraticProbing();
        userPerformanceClosedHashingDoubleHashing();
        break;
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userTest(){

  std::cout << "Open hashing:\n";
  test_open.print();
  std::cout << "\nClosed hashing with quadratic probing:\n";
  test_quad.print();
  std::cout << "\nClosed hashing with double hashing:\n";
  test_double.print();

}

void UserInput::userPerformanceOpenHashing(){

  Timer build_times[5];
  Timer found_times[5];
  Timer not_found_times[5];
  int location;
  bool found;

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < 5; j++){

      OpenHashTable<int> oht(TABLE_SIZE, myhash);
      RandomGenerator::seedTime();

      for(int k = 0; k < SIZES[i]; k++){
        int to_insert = RandomGenerator::getFromOneTo(MAX_RAND);
        found = oht.findNoExcept(to_insert, location);
        // if the item was found successfully, don't do anything, since it is a duplicate

        if(!found){
          build_times[i].start();
          oht.insert(to_insert);
          build_times[i].stop();
        }
      }

      for(int k = 0; k < FINDS[i]; k++){
        int to_find = RandomGenerator::getFromOneTo(MAX_RAND);
        found = oht.findNoExcept(to_find, location);
        if(found){
          found_times[i].start();
          oht.findNoExcept(to_find, location);
          found_times[i].stop();
        }
        else{
          not_found_times[i].start();
          oht.findNoExcept(to_find, location);
          not_found_times[i].stop();
        }
      }
    }

  }

  std::cout << "Performance (Open hashing):\n";
  printTable(build_times, found_times, not_found_times);

}

void UserInput::userPerformanceClosedHashingQuadraticProbing(){

  Timer build_times[5];
  Timer found_times[5];
  Timer not_found_times[5];
  int location;
  bool found;

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < 5; j++){

      ClosedHashTable<int, QuadraticProbing> ht(TABLE_SIZE, myhash);
      RandomGenerator::seedTime();

      for(int k = 0; k < SIZES[i]; k++){
        int to_insert = RandomGenerator::getFromOneTo(MAX_RAND);
        found = ht.findNoExcept(to_insert, location);
        // if the item was found successfully, don't do anything, since it is a duplicate

        if(!found){
          build_times[i].start();
          ht.insert(to_insert);
          build_times[i].stop();
        }
      }

      for(int k = 0; k < FINDS[i]; k++){
        int to_find = RandomGenerator::getFromOneTo(MAX_RAND);
        found = ht.findNoExcept(to_find, location);
        if(found){
          found_times[i].start();
          ht.findNoExcept(to_find, location);
          found_times[i].stop();
        }
        else{
          not_found_times[i].start();
          ht.findNoExcept(to_find, location);
          not_found_times[i].stop();
        }
      }
    }

  }

  std::cout << "Performance (Closed hashing with quadratic probing):\n";
  printTable(build_times, found_times, not_found_times);

}

void UserInput::userPerformanceClosedHashingDoubleHashing(){

  Timer build_times[5];
  Timer found_times[5];
  Timer not_found_times[5];
  int location;
  bool found;

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < 5; j++){

      ClosedHashTable<int, DoubleHashing<DOUBLE_HASHING_VAL>> ht(TABLE_SIZE, myhash);
      RandomGenerator::seedTime();

      for(int k = 0; k < SIZES[i]; k++){
        int to_insert = RandomGenerator::getFromOneTo(MAX_RAND);
        found = ht.findNoExcept(to_insert, location);
        // if the item was found successfully, don't do anything, since it is a duplicate

        if(!found){
          build_times[i].start();
          ht.insert(to_insert);
          build_times[i].stop();
        }
      }

      for(int k = 0; k < FINDS[i]; k++){
        int to_find = RandomGenerator::getFromOneTo(MAX_RAND);
        found = ht.findNoExcept(to_find, location);
        if(found){
          found_times[i].start();
          ht.findNoExcept(to_find, location);
          found_times[i].stop();
        }
        else{
          not_found_times[i].start();
          ht.findNoExcept(to_find, location);
          not_found_times[i].stop();
        }
      }
    }

  }

  std::cout << "Performance (Closed hashing with quadratic probing):\n";
  printTable(build_times, found_times, not_found_times);

}

void UserInput::printTable(Timer* build_times, Timer* found_times, Timer* not_found_times) const{

  column();
  std::cout << "";
  for(int i = 0; i < 5; i++){
    column();
    std::cout << SIZES[i];
  }
  std::cout << "\n";

  column();
  std::cout << "Build";
  for(int i = 0; i < 5; i++){
    column();
    std::cout << build_times[i].getMS()/5;
  }
  std::cout << "\n";

  column();
  std::cout << "Found";
  for(int i = 0; i < 5; i++){
    column();
    std::cout << found_times[i].getMS()/5;
  }
  std::cout << "\n";

  column();
  std::cout << "Not Found";
  for(int i = 0; i < 5; i++){
    column();
    std::cout << not_found_times[i].getMS()/5;
  }
  std::cout << "\n\n";
}

void UserInput::column() const{
  std::cout << std::setw(12);
  std::cout << std::left;
}
