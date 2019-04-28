/**
 * @author: Evan Brown
 * @file: Heap.hpp
 * @date: 4/6/19
 * @brief: header file for general heap
 *         adapted from 560 lab 8
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
  virtual ~Heap();

  void insert(const T& val);

  void deleteHighest();
  void deleteLowest();

  T findHighest() const;
  T findLowest() const;

  virtual T findMin() const = 0;
  virtual T findMax() const = 0;

  virtual void deleteMin() = 0;
  virtual void deleteMax() = 0;

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
