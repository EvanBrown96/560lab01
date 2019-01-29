/**
 * @author: Evan Brown
 * @file: LinkedList.cpp
 * @date: 1/25/19
 * @brief: implementation of linked list methods
 *         adapted from 560 lab 1
 */

#include <iostream>

template <typename A>
LinkedList<A>::LinkedList(): head(nullptr), tail(nullptr){

}

template <typename A>
LinkedList<A>::LinkedList(const LinkedList<A>& copy_list){

  copyEverything(copy_list);

}

template <typename A>
LinkedList<A>::~LinkedList(){

  removeEverything();

}

template <typename A>
LinkedList<A>& LinkedList<A>::operator =(const LinkedList<A>& copy_list){

  removeEverything();
  copyEverything(copy_list);

  return *this;

}

template <typename A>
bool LinkedList<A>::isEmpty() const{

  return (head == nullptr);

}

template <typename A>
void LinkedList<A>::insertBack(const A& value){

  Node<A>* new_node = new Node<A>(value);

  if(isEmpty()){
    head = tail = new_node;
  }
  else{
    tail->setNext(new_node);
    tail = new_node;
  }

}

template <typename A>
void LinkedList<A>::deleteVal(const A& value) throw(ValueNotFound<A>){

  Node<A>* prev = nullptr;
  Node<A>* iter = head;

  // iterate until the item is found or the end of the list is reached.
  while(iter != nullptr && iter->getValue() != value){
    prev = iter;
    iter = iter->getNext();
  }

  // throw an error if the end of the list was reached without finding the item
  if(iter == nullptr){
    throw ValueNotFound<A>(value);
  }

  // actually delete the item
  Node<A>* next = iter->getNext();
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

}

template <typename A>
A LinkedList<A>::smallest() const throw(EmptyList){

  if(isEmpty()){
    throw EmptyList();
  }

  A smallest = head->getValue();
  Node<A>* iter = head->getNext();
  A testval;

  while(iter != nullptr){
    testval = iter->getValue();
    if(testval < smallest){
      smallest = testval;
    }
    iter = iter->getNext();
  }

  return smallest;

}

template <typename A>
A LinkedList<A>::largest() const throw(EmptyList){

  if(isEmpty()){
    throw EmptyList();
  }

  A largest = head->getValue();
  Node<A>* iter = head->getNext();
  A testval;

  while(iter != nullptr){
    testval = iter->getValue();
    if(testval > largest){
      largest = testval;
    }
    iter = iter->getNext();
  }

  return largest;

}

template <typename A>
A LinkedList<A>::average() const throw(EmptyList){

  if(isEmpty()){
    throw EmptyList();
  }

  A sum = head->getValue();
  Node<A>* iter = head->getNext();
  int count = 1;

  while(iter != nullptr){
    sum += iter->getValue();
    iter = iter->getNext();
    count++;
  }

  return sum/count;

}

template <typename A>
void LinkedList<A>::merge2lists(const LinkedList<A>& new_list){

  // if both lists are empty, there's nothing to be done
  if(isEmpty() && new_list.isEmpty()){
    return;
  }

  // create a copy of the list to merge so we can edit it
  LinkedList<A> copy_list = new_list;
  // reset the merge head
  merge_new_head = nullptr;

  // repeat while both lists are nonempty
  while(!(isEmpty() || copy_list.isEmpty())){
    // get smallest value of both lists
    A new_value = copy_list.smallest();
    A old_value = smallest();

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
    A old_value = smallest();
    mergeHelper(*this, old_value);
  }
  while(!copy_list.isEmpty()){
    A new_value = copy_list.smallest();
    mergeHelper(copy_list, new_value);
  }

  head = merge_new_head;
  tail = merge_next;

}

template <typename A>
void LinkedList<A>::mergeHelper(LinkedList<A>& operand, A& value){
  // create a new node with the given value
  merge_next = new Node<A>(value);

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

template <typename A>
void LinkedList<A>::print() const{

  std::cout << "List: ";
  Node<A>* iter = head;
  while(iter != nullptr){
    std::cout << iter->getValue() << " ";
    iter = iter->getNext();
  }
  std::cout << "\n";

}

template <typename A>
void LinkedList<A>::removeEverything(){

  Node<A>* last;

  while(head != nullptr){
    last = head;
    head = head->getNext();
    delete last;
  }

}

template <typename A>
void LinkedList<A>::copyEverything(const LinkedList<A>& copy_list){

  if(copy_list.head == nullptr){
    head = tail = nullptr;
    return;
  }

  head = new Node<A>(copy_list.head->getValue());

  Node<A>* iter = head;
  Node<A>* copy_iter = copy_list.head->getNext();

  while(copy_iter != nullptr){
    iter->setNext(new Node<A>(copy_iter->getValue()));
    iter = iter->getNext();
    copy_iter = copy_iter->getNext();
  }

  tail = iter;

}
