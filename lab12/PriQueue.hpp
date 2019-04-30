// 4/30

#ifndef PRIQUEUE_HPP
#define PRIQUEUE_HPP

#include "MinHeap.hpp"

template <typename T>
class PriQueue{
public:

  PriQueue();

  void push(const T& item);

  T pop();

  T peek() const;

private:

  MinHeap<5, T> base;

};

#include "PriQueue.cpp"

#endif // PRIQUEUE_HPP
