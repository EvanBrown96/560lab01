#ifndef HEAP_HPP
#define HEAP_HPP

#include "EmptyStructure.hpp"
#include "QuickQueue.hpp"

template <typename T>
class Heap{
public:

  Heap();
  ~Heap();

  void insert(const T& val) = 0;

  T findMin() throw(EmptyStructure) const = 0;
  T findMax() throw(EmptyStructure) const = 0;

  int deleteMin() throw(EmptyStructure) = 0;
  int deleteMax() throw(EmptyStructure) = 0;

  QuickQueue<T> levelOrder() const;

private:

  T** data;
  int size;
  int count;

  void destroyHeap();

};

#include "Heap.cpp"

#endif
