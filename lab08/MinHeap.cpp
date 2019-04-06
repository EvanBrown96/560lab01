/**
 * @author: Evan Brown
 * @file: MinHeap.cpp
 * @date: 4/6/19
 * @brief: implementation of functions for min-heap
 */

template <int ch, typename T>
MinHeap<ch, T>::MinHeap():
  Heap<ch, T>(min_compare){}

template <int ch, typename T>
MinHeap<ch, T>::MinHeap(const QuickQueue<T>& initial):
  Heap<ch, T>(min_compare, initial){}

template <int ch, typename T>
T MinHeap<ch, T>::findMin() const throw(EmptyStructure){
  return this->findHighest();
}

template <int ch, typename T>
T MinHeap<ch, T>::findMax() const throw(EmptyStructure){
  return this->findLowest();
}

template <int ch, typename T>
void MinHeap<ch, T>::deleteMin() throw(EmptyStructure){
  this->deleteHighest();
}

template <int ch, typename T>
void MinHeap<ch, T>::deleteMax() throw(EmptyStructure){
  this->deleteLowest();
}
