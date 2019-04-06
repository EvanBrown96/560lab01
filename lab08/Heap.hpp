#ifndef HEAP_HPP
#define HEAP_HPP

#include "EmptyStructure.hpp"

template <int ch, typename T>
class Heap{
public:

  Heap(bool (*compare)(const T& v1, const T& v2));
  ~Heap();

  void insert(const T& val);

  T findMin() throw(EmptyStructure) const;
  T findMax() throw(EmptyStructure) const;

  int deleteMin() throw(EmptyStructure);
  int deleteMax() throw(EmptyStructure);

  void levelOrder() const;

private:

  T** data;
  int size;
  int count;

  bool (*compare)(const T& v1, const T& v2);

  void destroyHeap();
  void resizeHeap();

  int parent(int child) const;

  void swap(int idx1, int idx2);

};

#include "Heap.cpp"

#endif
