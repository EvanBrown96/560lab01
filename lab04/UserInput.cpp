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
#include "Timer.hpp"
#include "RandomGenerator.hpp"

int myhash(const int& val){
  return val;
}

UserInput::UserInput(const OpenHashTable<int>& startoff_open,
  const ClosedHashTable<int, QuadraticProbing>& startoff_quad,
  const ClosedHashTable<int, DoubleHashing>& startoff_double): test_open(startoff_open), test_quad(startoff_quad), test_double(startoff_double){}

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

  int MAX_RAND = 5 * TABLE_SIZE;
  int SIZES[5];
  int FINDS[5];
  for(int i = 0; i < 5; i++){
    SIZES[i] = floor(TABLE_SIZE * (static_cast<float>(i+1)/10));
    FINDS[i] = floor(0.1 * SIZES[i]);
  }

  Timer build_times[5];
  Timer found_times[5];
  Timer not_found_times[5];

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < 5; j++){

      OpenHashTable<int> oht(TABLE_SIZE, myhash);
      RandomGenerator::seedTime();

      build_times[i].start();
      for(int k = 0; k < SIZES[i]; k++){
        try{
          oht.insert(RandomGenerator::getFromOneTo(MAX_RAND));
        }
        catch(DuplicateValue<int>& err){}
      }
      build_times[i].stop();

      for(int k = 0; k < FINDS[i]; k++){
        int to_find = RandomGenerator::getFromOneTo(MAX_RAND);
        try{
          // test the find to see if item is in the table
          oht.find(to_find);

          // item was found, run found_times timer
          found_times[i].start();
          oht.find(to_find);
          found_times[i].stop();

        }
        catch(ValueNotFound<int>& err){
          // item was not found, run not_found_times timer
          try{
            not_found_times[i].start();
            oht.find(to_find);
          }
          catch(ValueNotFound<int>& err){
            not_found_times[i].stop();
          }
        }
      }
    }

  }

  std::cout << "Performance (Open hashing):\n";
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
  std::cout << "\n";

}

void UserInput::column(){
  std::cout << std::setw(12);
  std::cout << std::left;
}
