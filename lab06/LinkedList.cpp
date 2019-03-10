/**
 * @author: Evan Brown
 * @file: LinkedList.cpp
 * @date: 1/25/19
 * @brief: implementation of linked list methods
 *         adapted from 560 lab 3
 */

#include <iostream>

template <typename T>
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), length(0){

}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copy_list){

  copyEverything(copy_list);

}

template <typename T>
LinkedList<T>::~LinkedList(){

  removeEverything();

}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& copy_list){

  removeEverything();
  copyEverything(copy_list);

  return *this;

}

template <typename T>
bool LinkedList<T>::isEmpty() const{

  return (head == nullptr);

}

template <typename T>
void LinkedList<T>::insertBack(const T& value){

  Node<T>* new_node = new Node<T>(value);

  if(isEmpty()){
    head = tail = new_node;
  }
  else{
    tail->setNext(new_node);
    tail = new_node;
  }

  length++;

}

template <typename T>
void LinkedList<T>::insertFront(const T& value){

  Node<T>* new_node = new Node<T>(value, head);

  if(isEmpty()){
    tail = new_node;
  }
  head = new_node;

  length++;

}

template <typename T>
void LinkedList<T>::deleteVal(const T& value) throw(ValueNotFound<T>){

  Node<T>* prev = nullptr;
  Node<T>* iter = head;

  // iterate until the item is found or the end of the list is reached.
  while(iter != nullptr && iter->getValue() != value){
    prev = iter;
    iter = iter->getNext();
  }

  // throw an error if the end of the list was reached without finding the item
  if(iter == nullptr){
    throw ValueNotFound<T>(value);
  }

  // actually delete the item
  Node<T>* next = iter->getNext();
  delete iter;

  // if it was the first item, reset the head
  if(prev == nullptr){
    head = next;
  }
  else{
    prev->setNext(next);
  }

  // if it was the last item, reset the tail
  if(next == nullptr){
    tail = prev;
  }

  length--;

}

template <typename T>
T LinkedList<T>::popFront() throw(EmptyStructure){

  if(isEmpty()){
    throw EmptyStructure();
  }

  T value = head->getValue();
  Node<T>* next = head->getNext();

  delete head;
  head = next;
  
  length--;

  return value;

}

template <typename T>
bool LinkedList<T>::contains(const T& value) const{

  Node<T>* iter = head;

  while(iter != nullptr){
    if(value == iter->getValue()){
      return true;
    }
    iter = iter->getNext();
  }

  return false;

}

template <typename T>
int LinkedList<T>::getLength() const{
  return length;
}

template <typename T>
T** LinkedList<T>::getArray() const{
  T** ret_arr = new T*[length];

  Node<T>* iter = head;
  int index = 0;

  while(iter != nullptr){
    ret_arr[index] = new T(iter->getValue());
    index++;
    iter = iter->getNext();
  }

  return ret_arr;
}

template <typename T>
T LinkedList<T>::smallest() const throw(EmptyStructure){

  if(isEmpty()){
    throw EmptyStructure();
  }

  T smallest = head->getValue();
  Node<T>* iter = head->getNext();
  T testval;

  while(iter != nullptr){
    testval = iter->getValue();
    if(testval < smallest){
      smallest = testval;
    }
    iter = iter->getNext();
  }

  return smallest;

}

template <typename T>
T LinkedList<T>::largest() const throw(EmptyStructure){

  if(isEmpty()){
    throw EmptyStructure();
  }

  T largest = head->getValue();
  Node<T>* iter = head->getNext();
  T testval;

  while(iter != nullptr){
    testval = iter->getValue();
    if(testval > largest){
      largest = testval;
    }
    iter = iter->getNext();
  }

  return largest;

}

template <typename T>
T LinkedList<T>::average() const throw(EmptyStructure){

  if(isEmpty()){
    throw EmptyStructure();
  }

  T sum = head->getValue();
  Node<T>* iter = head->getNext();
  int count = 1;

  while(iter != nullptr){
    sum += iter->getValue();
    iter = iter->getNext();
    count++;
  }

  return sum/count;

}

template <typename T>
void LinkedList<T>::merge2lists(const LinkedList<T>& new_list){

  // if both lists are empty, there's nothing to be done
  if(isEmpty() && new_list.isEmpty()){
    return;
  }

  // create a copy of the list to merge so we can edit it
  LinkedList<T> copy_list = new_list;
  // reset the merge head
  merge_new_head = nullptr;

  // repeat while both lists are nonempty
  while(!(isEmpty() || copy_list.isEmpty())){
    // get smallest value of both lists
    T new_value = copy_list.smallest();
    T old_value = smallest();

    // repeat until the list to merge has no values smaller than the original list,
    // OR the list to merge is empty
    while(new_value < old_value){
      mergeHelper(copy_list, new_value);
      if(copy_list.isEmpty()){
        break;
      }
      // get next smallest value
      new_value = copy_list.smallest();
    }
    // if the list to merge is empty, leave this loop
    if(copy_list.isEmpty()){
      break;
    }
    // repeat until the original list has no values smaller than the list to merge,
    // OR the original list is empty
    while(new_value >= old_value){
      mergeHelper(*this, old_value);
      if(isEmpty()){
        break;
      }
      // get the next smallest value
      old_value = smallest();
    }
  }
  // at this point at least one of the lists is empty, so we can move all the rest
  // of the items from the other list very simply.
  while(!isEmpty()){
    T old_value = smallest();
    mergeHelper(*this, old_value);
  }
  while(!copy_list.isEmpty()){
    T new_value = copy_list.smallest();
    mergeHelper(copy_list, new_value);
  }

  head = merge_new_head;
  tail = merge_next;

}

template <typename T>
void LinkedList<T>::mergeHelper(LinkedList<T>& operand, T& value){
  // create a new node with the given value
  merge_next = new Node<T>(value);

  // if this is the first item, set the new head, otherwise add it to the list normally
  if(merge_new_head == nullptr){
    merge_new_head = merge_next;
  }
  else{
    merge_prev->setNext(merge_next);
  }
  // increment the previous pointer
  merge_prev = merge_next;
  // delete the value from the list it came from
  operand.deleteVal(value);
}

template <typename T>
void LinkedList<T>::print() const{

  Node<T>* iter = head;
  while(iter != nullptr){
    std::cout << " -> " << iter->getValue();
    iter = iter->getNext();
  }
  std::cout << "\n";

}

template <typename T>
void LinkedList<T>::removeEverything(){

  Node<T>* last;

  while(head != nullptr){
    last = head;
    head = head->getNext();
    delete last;
  }

}

template <typename T>
void LinkedList<T>::copyEverything(const LinkedList<T>& copy_list){

  length = copy_list.length;

  if(copy_list.head == nullptr){
    head = tail = nullptr;
    return;
  }

  head = new Node<T>(copy_list.head->getValue());

  Node<T>* iter = head;
  Node<T>* copy_iter = copy_list.head->getNext();

  while(copy_iter != nullptr){
    iter->setNext(new Node<T>(copy_iter->getValue()));
    iter = iter->getNext();
    copy_iter = copy_iter->getNext();
  }

  tail = iter;

}
