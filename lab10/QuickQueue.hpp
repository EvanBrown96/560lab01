/**
 * @author: Evan Brown
 * @file: QuickQueue.hpp
 * @date: 4/6/19
 * @brief: definition of simple queue class
 *         adapted from 560 lab 9
 */

#ifndef QUICKQUEUE_HPP
#define QUICKQUEUE_HPP

#include "EmptyStructure.hpp"

template <typename T>
class QuickQueue{
public:

  QuickQueue(int size);

  ~QuickQueue();

  QuickQueue(const QuickQueue<T>& qq);

  QuickQueue<T>& operator=(const QuickQueue<T>& qq);

  T peek() const;

  T pop();

  void push(const T& item);

  bool isEmpty() const;

  int getSize() const;

  template <typename U>
  friend std::ostream& operator<<(std::ostream& stream, const QuickQueue<U>& t);

private:

  T** contents;
  int size;
  int start;
  int count;

  void destroyQueue();

  void copyQueue(const QuickQueue<T>& copy);

};

#include "QuickQueue.cpp"

#endif
