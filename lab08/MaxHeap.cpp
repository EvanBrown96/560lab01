/**
 * @author: Evan Brown
 * @file: MaxHeap.cpp
 * @date: 4/6/19
 * @brief: implementation of functions for max-heap
 */

template <int ch, typename T>
MaxHeap<ch, T>::MaxHeap():
  Heap<ch, T>(max_compare){}

template <int ch, typename T>
T MaxHeap<ch, T>::findMin() const throw(EmptyStructure){
  return this->findLowest();
}

template <int ch, typename T>
T MaxHeap<ch, T>::findMax() const throw(EmptyStructure){
  return this->findHighest();
}

template <int ch, typename T>
void MaxHeap<ch, T>::deleteMin() throw(EmptyStructure){
  this->deleteLowest();
}

template <int ch, typename T>
void MaxHeap<ch, T>::deleteMax() throw(EmptyStructure){
  this->deleteHighest();
}
