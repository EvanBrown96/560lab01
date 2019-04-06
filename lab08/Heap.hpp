/**
 * @author: Evan Brown
 * @file: Heap.hpp
 * @date: 4/6/19
 * @brief: header file for general heap
 */

#ifndef HEAP_HPP
#define HEAP_HPP

#include "QuickQueue.hpp"
#include "EmptyStructure.hpp"

template <int ch, typename T>
class Heap{

public:

  Heap(bool (*compare)(const T& v1, const T& v2));
  Heap(bool (*compare)(const T& v1, const T& v2), QuickQueue<T> initial);
  ~Heap();

  void insert(const T& val);

  void deleteHighest() throw(EmptyStructure);
  void deleteLowest() throw(EmptyStructure);

  T findHighest() const throw(EmptyStructure);
  T findLowest() const throw(EmptyStructure);

  void levelOrder() const;

protected:

  T** data;
  int size;
  int count;

  int parent(int child) const;

  void swap(int idx1, int idx2);

  void safeRemove(int index);

  bool indexCompare(int idx1, int idx2) const;

private:

  bool (*compare)(const T& v1, const T& v2);

  void pushDown(int index);
  int findLowestIndex() const;

  void destroyHeap();
  void resizeHeap();

};

#include "Heap.cpp"

#endif
