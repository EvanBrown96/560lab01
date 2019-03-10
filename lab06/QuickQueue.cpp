/**
 * @author: Evan Brown
 * @file: QuickQueue.cpp
 * @date: 2/28/19
 * @brief: implementation of a simple queue class
 *         adapted from 560 lab 5
 */

#include <iostream>

template <typename T>
QuickQueue<T>::QuickQueue(int size):
  size(size), start(0), count(0), contents(new T*[size]){}

template <typename T>
QuickQueue<T>::~QuickQueue(){
  destroyQueue();
}

template <typename T>
QuickQueue<T>::QuickQueue(const QuickQueue<T>& qq){
  copyQueue(qq);
}

template <typename T>
QuickQueue<T>& QuickQueue<T>::operator=(const QuickQueue<T>& qq){
  destroyQueue();
  copyQueue(qq);
}

template <typename T>
T QuickQueue<T>::peek() const throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();

  return *contents[start];
}

template <typename T>
T QuickQueue<T>::pop() throw(EmptyStructure){
  if(count == 0) throw EmptyStructure();

  T ret = *contents[start];
  delete contents[start];
  start = (start+1)%size;
  count--;

  return ret;

}

template <typename T>
void QuickQueue<T>::push(const T& item) throw(FullStructure){
  if(count == size) throw FullStructure();

  contents[start+count] = new T(item);
  count++;

}

template <typename T>
bool QuickQueue<T>::isEmpty() const{
  return (count == 0);
}

template <typename T>
void QuickQueue<T>::destroyQueue(){
  for(int i = start; i < start+count; i=(i+1)%size){
    delete contents[i];
  }
  delete[] contents;
}

template <typename T>
void QuickQueue<T>::copyQueue(const QuickQueue<T> copy){
  size = copy.size;
  start = copy.start;
  count = copy.count;
  contents = new T*[size];
  for(int i = start; i < start+count; i=(i+1)%size){
    contents[i] = new T(*copy.contents[i]);
  }
}
