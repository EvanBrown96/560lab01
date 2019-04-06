/**
 * @author: Evan Brown
 * @file: MaxHeap.hpp
 * @date: 4/6/19
 * @brief: header file for max-heap
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

  T findMin() const throw(EmptyStructure);
  T findMax() const throw(EmptyStructure);

  void deleteMin() throw(EmptyStructure);
  void deleteMax() throw(EmptyStructure);

};

#include "MaxHeap.cpp"

#endif
