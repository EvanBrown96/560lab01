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

  MinHeap();

  T findMin() const throw(EmptyStructure);
  T findMax() const throw(EmptyStructure);

  void deleteMin() throw(EmptyStructure);
  void deleteMax() throw(EmptyStructure);

};

#include "MinHeap.cpp"

#endif
