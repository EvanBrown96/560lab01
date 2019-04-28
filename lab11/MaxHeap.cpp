/**
 * @author: Evan Brown
 * @file: MaxHeap.cpp
 * @date: 4/6/19
 * @brief: implementation of functions for max-heap
 *         adapted from 560 lab 8
 */

template <int ch, typename T>
MaxHeap<ch, T>::MaxHeap():
  Heap<ch, T>(max_compare){}

template <int ch, typename T>
MaxHeap<ch, T>::MaxHeap(QuickQueue<T> initial):
  Heap<ch, T>(max_compare, initial){}


template <int ch, typename T>
MaxHeap<ch, T>::MaxHeap(const MaxHeap<ch, T>& copy):
    Heap<ch, T>(min_compare, copy){}

template <int ch, typename T>
MaxHeap<ch, T>& MaxHeap<ch, T>::operator=(const MaxHeap<ch, T>& copy){
  this->destroyHeap();
  copyHeap(copy);

  return *this;
}

template <int ch, typename T>
T MaxHeap<ch, T>::findMin() const{
  return this->findLowest();
}

template <int ch, typename T>
T MaxHeap<ch, T>::findMax() const{
  return this->findHighest();
}

template <int ch, typename T>
void MaxHeap<ch, T>::deleteMin(){
  this->deleteLowest();
}

template <int ch, typename T>
void MaxHeap<ch, T>::deleteMax(){
  this->deleteHighest();
}
