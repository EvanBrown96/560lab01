#include "ValueNotFound.hpp"
#include <stdexcept>

template <typename T>
DJS<T>::DJS():
    first_set(nullptr), last_set(nullptr), first_node(nullptr), last_node(nullptr){}

    // roots(new SetNode<T>*[DJS_INIT_SIZE]), roots_size(DJS_INIT_SIZE), roots_count(0),
    // others(new SetNode<T>*[DJS_INIT_SIZE]), others_size(DJS_INIT_SIZE), others_count(0){}

template <typename T>
DJS<T>::~DJS(){
  destroyDJS();
}

template <typename T>
DJS<T>::DJS(const DJS<T>& copy){
  throw std::runtime_error("Copying disjoint sets is not supported");
}

template <typename T>
DJS<T>& DJS<T>::operator=(const DJS<T>& copy){
  throw std::runtime_error("Copying disjoint sets is not supported");
}

template <typename T>
void DJS<T>::makeSet(const T& item){

  Set<T>* new_set = new Set<T>(item);
  addSet(new_set);

}

template <typename T>
void DJS<T>::makeSet(const T* items, int count){
  if(count > 0){
    makeSet(items[0]);
  }
  for(int i = 1; i < count; i++){
    makeSet(items[i]);
    setUnion(*last_set, *(last_set->getPrev()));
  }
}

template <typename T>
Set<T>* DJS<T>::find(const T& item){

  Set<T>* cur_set = first_set;
  while(cur_set != nullptr){
    if(cur_set->getRootItem() == item)
      return cur_set;
    cur_set = cur_set->getNext();
  }

  SetNode<T>* cur_node = first_node;
  while(cur_node != nullptr){
    if(cur_node->getItem() == item){
      while(cur_node->getMySet() == nullptr)
        cur_node = cur_node->getParent();
      return cur_node->getMySet();
    }
    cur_node = cur_node->getNext();
  }

  throw ValueNotFound<T>(item);
}

template <typename T>
void DJS<T>::setUnion(const T& item1, const T& item2){

  Set<T>* s1 = find(item1);
  Set<T>* s2 = find(item2);

  setUnion(s1, s2);

}

template <typename T>
void DJS<T>::setUnion(Set<T>* s1, Set<T>* s2){

  if(s1->getRank() == s2->getRank()){
    s2->setRank(s2->getRank()+1);
  }

  if(s1->getRank() < s2->getRank()){
    SetNode<T>* old_root = s1->getRoot();
    old_root->setParent(s2->getRoot());
    s1->setRoot(nullptr);
    removeSet(s1);
    addNode(old_root);
  }
  else{
    SetNode<T>* old_root = s2->getRoot();
    old_root->setParent(s1->getRoot());
    s2->setRoot(nullptr);
    removeSet(s2);
    addNode(old_root);
  }

}

template <typename T>
void DJS<T>::destroyDJS(){

  while(first_set != nullptr){
    removeSet(first_set);
  }

  while(first_node != nullptr){
    removeNode(first_node);
  }

}

template <typename T>
void DJS<T>::addSet(Set<T>* new_set){

  if(last_set == nullptr)
    first_set = new_set;
  else{
    last_set->setNext(new_set);
    new_set->setPrev(last_set);
  }
  last_set = new_set;

}

template <typename T>
void DJS<T>::removeSet(Set<T>* rem_set){

  Set<T>* prev = rem_set->getPrev();
  if(prev == nullptr)
    first_set = rem_set->getNext();
  else
    prev->setNext(rem_set->getNext());

  Set<T>* next = rem_set->getNext();
  if(next == nullptr)
    last_set = rem_set->getPrev();
  else
    next->setPrev(rem_set->getPrev());

  if(rem_set->getRoot() != nullptr) delete rem_set->getRoot();
  delete rem_set;

}

template <typename T>
void DJS<T>::addNode(SetNode<T>* new_node){

  if(last_node == nullptr)
    first_node = new_node;
  else{
    last_node->setNext(new_node);
    new_node->setPrev(last_node);
  }
  last_node = new_node;

}

template <typename T>
void DJS<T>::removeNode(SetNode<T>* rem_node){

  SetNode<T>* prev = rem_node->getPrev();
  if(prev == nullptr)
    first_node = rem_node->getNext();
  else
    prev->setNext(rem_node->getNext());

  SetNode<T>* next = rem_node->getNext();
  if(next == nullptr)
    last_node = rem_node->getPrev();
  else
    next->setPrev(rem_node->getPrev());

  delete rem_node;

}
