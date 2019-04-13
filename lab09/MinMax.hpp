

#ifndef MINMAX_HPP
#define MINMAX_HPP

#include "EmptyStructure.hpp"
#include "QuickQueue.hpp"

template <typename T>
class MinMax{

public:

  MinMax();
  MinMax(QuickQueue<T> qq);
  ~MinMax();

  MinMax(const MinMax<T>& copy);
  MinMax<T>& operator=(const MinMax<T>& copy);

  void insert(const T& item);

  void deleteMin() throw(EmptyStructure);
  void deleteMax() throw(EmptyStructure);

  T findMin() const throw(EmptyStructure);
  T findMax() const throw(EmptyStructure);

  void levelOrder() const;

private:

  T** data;
  int count;
  int size;

  void resizeHeap();
  void destroyHeap();
  void copyHeap(const MinMax<T>& copy);

  void pushDownMin(int index);
  void pushDownMax(int index);

  int parent(int index) const;
  int grandparent(int index) const;
  int lchild(int index) const;
  int rchild(int index) const;
  bool isMinNode(int index) const;

  bool indexLT(int idx1, int idx2) const;
  bool indexGT(int idx1, int idx2) const;
  bool indexLTE(int idx1, int idx2) const;
  bool indexGTE(int idx1, int idx2) const;

  void swap(int idx1, int idx2);

};

#include "MinMax.cpp"

#endif
