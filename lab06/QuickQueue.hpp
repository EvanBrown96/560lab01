/**
 * @author: Evan Brown
 * @file: QuickQueue.hpp
 * @date: 2/28/19
 * @brief: definition of simple queue class
 *         adapted from 560 lab 5
 */

#ifndef QUICKQUEUE_HPP
#define QUICKQUEUE_HPP

#include "FullStructure.hpp"
#include "EmptyStructure.hpp"

template <typename T>
class QuickQueue{
public:

  QuickQueue(int size);

  ~QuickQueue();

  QuickQueue(const QuickQueue<T>& qq);

  QuickQueue<T>& operator=(const QuickQueue<T>& qq);

  T peek() const throw(EmptyStructure);

  T pop() throw(EmptyStructure);

  void push(const T& item) throw(FullStructure);

  bool isEmpty() const;

private:

  T** contents;
  int size;
  int start;
  int count;

  void destroyQueue();

  void copyQueue(const QuickQueue<T> copy);

};

#include "QuickQueue.cpp"

#endif
