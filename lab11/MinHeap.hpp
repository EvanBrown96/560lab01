/**
 * @author: Evan Brown
 * @file: MinHeap.hpp
 * @date: 4/6/19
 * @brief: header file for min-heap
 *         adapted from 560 lab 8
 */

#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include "Heap.hpp"

template <typename T>
bool min_compare(const T& v1, const T& v2){
  return (v1 < v2);
}

template <int ch, typename T>
class MinHeap: public Heap<ch, T>{

public:

  MinHeap(int startsize=1);
  MinHeap(QuickQueue<T> initial);
  MinHeap(const MinHeap<ch, T>& copy);
  MinHeap<ch, T>& operator=(const MinHeap<ch, T>& copy);

  T findMin() const;
  T findMax() const;

  void deleteMin();
  void deleteMax();

};

#include "MinHeap.cpp"

#endif
