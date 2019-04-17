// 4/16

#ifndef LEFTISTHEAP_HPP
#define LEFTISTHEAP_HPP

#include "EmptyStructure.hpp"

template <typename T>
class LeftistHeap{

public:

  LeftistHeap();

  LeftistHeap(const QuickQueue<T>& initial_data);

  ~LeftistHeap();

  LeftistHeap(const LeftistHeap<T>& copy);

  LeftistHeap<T>& operator=(const LeftistHeap<T>& copy);

  static LeftistHeap<T> merge(const LeftistHeap<T>& h1, const LeftistHeap<T>& h2);

  void insert(const T& item);

  void deleteMax();

  T findMax() const;

  QuickQueue<T> inorder() const;

  QuickQueue<T> preorder() const;

  QuickQueue<T> postorder() const;

  QuickQueue<T> levelorder() const;

};

#include "LeftistHeap.cpp"

#endif // LEFTISTHEAP_HPP
