/**
 * @author: Evan Brown
 * @file: MinHeap.cpp
 * @date: 4/6/19
 * @brief: implementation of functions for min-heap
 *         adapted from 560 lab 8
 */

template <int ch, typename T>
MinHeap<ch, T>::MinHeap():
  Heap<ch, T>(min_compare){}

template <int ch, typename T>
MinHeap<ch, T>::MinHeap(QuickQueue<T> initial):
  Heap<ch, T>(min_compare, initial){}

template <int ch, typename T>
T MinHeap<ch, T>::findMin() const{
  return this->findHighest();
}

template <int ch, typename T>
T MinHeap<ch, T>::findMax() const{
  return this->findLowest();
}

template <int ch, typename T>
void MinHeap<ch, T>::deleteMin(){
  this->deleteHighest();
}

template <int ch, typename T>
void MinHeap<ch, T>::deleteMax(){
  this->deleteLowest();
}
