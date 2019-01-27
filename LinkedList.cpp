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
void LinkedList<A>::insert(const A& value){

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

  while(iter != nullptr && iter->getValue() != value){
    prev = iter;
    iter = iter->getNext();
  }

  if(iter == nullptr){
    throw ValueNotFound<A>(value);
  }

  Node<A>* next = iter->getNext();
  delete iter;

  if(prev == nullptr){
    head = next;
  }
  else{
    prev->setNext(next);
  }

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

  if(isEmpty() && new_list.isEmpty()){
    return;
  }

  LinkedList<A> copy_list = new_list;
  merge_new_head = nullptr;

  while(!(isEmpty() || copy_list.isEmpty())){
    A new_value = copy_list.smallest();
    A old_value = smallest();
    while(new_value < old_value){
      mergeHelper(copy_list, new_value);
      if(copy_list.isEmpty()){
        break;
      }
      new_value = copy_list.smallest();
    }
    if(copy_list.isEmpty()){
      break;
    }
    while(new_value >= old_value){
      mergeHelper(*this, old_value);
      if(isEmpty()){
        break;
      }
      old_value = smallest();
    }
  }
  while(!isEmpty()){
    A old_value = smallest();
    mergeHelper(*this, old_value);
  }
  while(!copy_list.isEmpty()){
    A new_value = copy_list.smallest();
    mergeHelper(copy_list, new_value);
  }

  removeEverything();
  head = merge_new_head;
  tail = merge_next;

}

template <typename A>
void LinkedList<A>::mergeHelper(LinkedList<A>& operand, A& value){
  merge_next = new Node<A>(value);
  if(merge_new_head == nullptr){
    merge_new_head = merge_next;
  }
  else{
    merge_prev->setNext(merge_next);
  }
  merge_prev = merge_next;
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
