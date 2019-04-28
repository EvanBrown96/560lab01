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

UserInput::UserInput(const BinarySearchTree<int>& startoff_bst,
  const MinHeap<5, int>& startoff_minh,
  const MaxHeap<5, int>& startoff_maxh):
                     test_bst(startoff_bst), test_minh(startoff_minh), test_maxh(startoff_maxh){

  MAX_RAND = 5 * M;
  for(int i = 0; i < 5; i++){
    SIZES[i] = M * (i+1);
    DELETES[i] = floor(0.001 * SIZES[i]);
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
    std::cout << "\t1. Test Data Structures\n";
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
        userPerformanceBST();
        userPerformanceMinHeap();
        userPerformanceMaxHeap();
        break;
      }
    }

    std::cout << "\n";

  }

  std::cout << "Done!\n";

}

void UserInput::userTest(){

  std::cout << "BST:\n";
  std::cout << test_bst.levelorder();
  std::cout << "\nMin-5 Heap:\n";
  test_minh.levelOrder();
  std::cout << "\nMax-5 Heap:\n";
  test_maxh.levelOrder();

}


void UserInput::userPerformanceBST(){

  Timer build_times[5];
  Timer min_times[5];
  Timer max_times[5];
  int location;
  bool found;

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < 5; j++){
      BinarySearchTree<int>* bst = new BinarySearchTree<int>();
      RandomGenerator::seedTime();

      for(int k = 0; k < SIZES[i]; k++){
        int to_insert = RandomGenerator::getFromOneTo(MAX_RAND);

        build_times[i].start();
        bst->insert(to_insert);
        build_times[i].stop();
      }

      BinarySearchTree<int>* bst_dup = new BinarySearchTree<int>(*bst);
      for(int k = 0; k < DELETES[i]; k++){
        // std::cout << bst->size << "\n";
        min_times[i].start();
        bst_dup->deleteMin();
        min_times[i].stop();
      }
      delete bst_dup;

      for(int k = 0; k < DELETES[i]; k++){
        // std::cout << bst->size << "\n";
        max_times[i].start();
        bst->deleteMax();
        max_times[i].stop();
      }
      delete bst;

    }

  }

  std::cout << "Performance (BST):\n";
  printTable(build_times, min_times, max_times);

}


void UserInput::userPerformanceMinHeap(){

  Timer build_times[5];
  Timer min_times[5];
  Timer max_times[5];
  int location;
  bool found;

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < 5; j++){

      MinHeap<5, int>* heap = new MinHeap<5, int>(HEAP_SIZE);
      RandomGenerator::seedTime();

      for(int k = 0; k < SIZES[i]; k++){
        int to_insert = RandomGenerator::getFromOneTo(MAX_RAND);

        build_times[i].start();
        heap->insert(to_insert);
        build_times[i].stop();
      }

      MinHeap<5, int>* heap_dup = new MinHeap<5, int>(*heap);
      for(int k = 0; k < DELETES[i]; k++){
        min_times[i].start();
        heap_dup->deleteMin();
        min_times[i].stop();
      }
      delete heap_dup;

      for(int k = 0; k < DELETES[i]; k++){
        max_times[i].start();
        heap->deleteMax();
        max_times[i].stop();
      }
      delete heap;

    }

  }

  std::cout << "Performance (MinHeap):\n";
  printTable(build_times, min_times, max_times);

}


void UserInput::userPerformanceMaxHeap(){

  Timer build_times[5];
  Timer min_times[5];
  Timer max_times[5];
  int location;
  bool found;

  for(int i = 0; i < 5; i++){

    for(int j = 0; j < 5; j++){

      MaxHeap<5, int>* heap = new MaxHeap<5, int>(HEAP_SIZE);
      RandomGenerator::seedTime();

      for(int k = 0; k < SIZES[i]; k++){
        int to_insert = RandomGenerator::getFromOneTo(MAX_RAND);

        build_times[i].start();
        heap->insert(to_insert);
        build_times[i].stop();
      }

      MaxHeap<5, int>* heap_dup = new MaxHeap<5, int>(*heap);
      for(int k = 0; k < DELETES[i]; k++){
        min_times[i].start();
        heap_dup->deleteMin();
        min_times[i].stop();
      }
      delete heap_dup;

      for(int k = 0; k < DELETES[i]; k++){
        max_times[i].start();
        heap->deleteMax();
        max_times[i].stop();
      }
      delete heap;

    }

  }

  std::cout << "Performance (MaxHeap):\n";
  printTable(build_times, min_times, max_times);

}

void UserInput::printTable(Timer* build_times, Timer* min_times, Timer* max_times) const{

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
  std::cout << "Del Min";
  for(int i = 0; i < 5; i++){
    column();
    std::cout << min_times[i].getMS()/5;
  }
  std::cout << "\n";

  column();
  std::cout << "Del Max";
  for(int i = 0; i < 5; i++){
    column();
    std::cout << max_times[i].getMS()/5;
  }
  std::cout << "\n\n";
}

void UserInput::column() const{
  std::cout << std::setw(12);
  std::cout << std::left;
}
