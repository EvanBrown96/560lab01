/**
 * @author: Evan Brown
 * @file: MaxHeap.hpp
 * @date: 4/6/19
 * @brief: header file for max-heap
 *         adapted from 560 lab 8
 */

#ifndef MAXHEAP_HPP
#define MAXHEAP_HPP

#include "Heap.hpp"

template <typename T>
bool max_compare(const T& v1, const T& v2){
  return (v1 > v2);
}

template <int ch, typename T>
class MaxHeap: public Heap<ch, T>{

public:

  MaxHeap();
  MaxHeap(QuickQueue<T> initial);

  T findMin() const;
  T findMax() const;

  void deleteMin();
  void deleteMax();

};

#include "MaxHeap.cpp"

#endif
