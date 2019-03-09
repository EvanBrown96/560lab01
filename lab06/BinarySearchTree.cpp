/**
 * @author: Evan Brown
 * @file: BinarySearchTree.cpp
 * @date: 2/27/19
 * @brief: implementation of binary search tree
 *         adapted from 560 lab 5
 */

#include "ClosedHashTable.hpp"
#include "QuadraticProbing.hpp"

template <typename T>
BinarySearchTree<T>::BinarySearchTree():
  root(nullptr), size(0){}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree(){
  destroySubtree(root);
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& bst){
  root = copySubtree(bst.root);
  size = bst.size;
}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree<T>& bst){
  destroySubtree(root);
  root = copySubtree(bst.root);
  size = bst.size;

  return *this;
}

template <typename T>
BinarySearchTree<T> BinarySearchTree<T>::OptimalBSTFactory(T data[], int size){
  OptimalItemData(data[0], 1, 1);
  // count occurances of each item in the data to get probabilities
}

template <typename T>
void BinarySearchTree<T>::insert(const T& value){
  root = insertHelper(root, value);
  size++;
}

template <typename T>
void BinarySearchTree<T>::deleteVal(const T& value) throw(ValueNotFound<T>){
  root = deleteFinder(root, value);
  size--;
}

template <typename T>
bool BinarySearchTree<T>::find(const T& value) const{
  return findHelper(root, value);
}

template <typename T>
T BinarySearchTree<T>::findMin() const throw(EmptyStructure){
  if(root == nullptr) throw EmptyStructure();

  BSTNode<T>* leftmost = root;
  while(leftmost->getLeft() != nullptr){
    leftmost = leftmost->getLeft();
  }

  return leftmost->getValue();
}

template <typename T>
T BinarySearchTree<T>::findMax() const throw(EmptyStructure){
  if(root == nullptr) throw EmptyStructure();

  BSTNode<T>* rightmost = root;
  while(rightmost->getRight() != nullptr){
    rightmost = rightmost->getRight();
  }

  return rightmost->getValue();
}

template <typename T>
Preorder<T> BinarySearchTree<T>::preorder() const{
  return Preorder<T>(*this);
}

template <typename T>
Inorder<T> BinarySearchTree<T>::inorder() const{
  return Inorder<T>(*this);
}

template <typename T>
Postorder<T> BinarySearchTree<T>::postorder() const{
  return Postorder<T>(*this);
}

template <typename T>
Levelorder<T> BinarySearchTree<T>::levelorder() const{
  return Levelorder<T>(*this);
}

template <typename T>
void BinarySearchTree<T>::printVisual() const{
  if(root != nullptr){
    QuickQueue<BSTNode<T>>* qq = new QuickQueue<BSTNode<T>>(size);
    QuickQueue<BSTNode<T>>* qq2 = new QuickQueue<BSTNode<T>>(size);
    qq->push(*root);
    while(!qq->isEmpty()){
      while(!qq->isEmpty()){
        BSTNode<T> next = qq->pop();
        std::cout << next.getValue() << "\t";
        if(next.getLeft() != nullptr) qq2->push(*next.getLeft());
        if(next.getRight() != nullptr) qq2->push(*next.getRight());
      }
      delete qq;
      qq = qq2;
      qq2 = new QuickQueue<BSTNode<T>>(size);
      std::cout << "\n";
    }
    delete qq;
    delete qq2;
  }
}

template <typename T>
void BinarySearchTree<T>::destroySubtree(BSTNode<T>* st){
  if(st != nullptr){
    destroySubtree(st->getLeft());
    destroySubtree(st->getRight());
    delete st;
  }
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::copySubtree(BSTNode<T>* st){
  if(st == nullptr) return nullptr;

  BSTNode<T>* new_st = st->getChildlessCopy();
  new_st->setLeft(copySubtree(st->getLeft()));
  new_st->setRight(copySubtree(st->getRight()));
  return new_st;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::insertHelper(BSTNode<T>* st, const T& value){
  if(st == nullptr){
    return new BSTNode<T>(value);
  }
  else if(value < st->getValue()){
    st->setLeft(insertHelper(st->getLeft(), value));
  }
  else{
    st->setRight(insertHelper(st->getRight(), value));
  }
  return st;
}

template <typename T>
bool BinarySearchTree<T>::findHelper(BSTNode<T>* st, const T& value) const{
  if(st == nullptr) return false;

  if(st->getValue() == value) return true;

  if(value < st->getValue()) return findHelper(st->getLeft(), value);

  return findHelper(st->getRight(), value);
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::deleteFinder(BSTNode<T>* st, const T& value) throw(ValueNotFound<T>){
  if(st == nullptr) throw ValueNotFound<T>(value);

  if(st->getValue() == value) return deleteHelper(st);

  if(value < st->getValue()) st->setLeft(deleteFinder(st->getLeft(), value));
  else st->setRight(deleteFinder(st->getRight(), value));

  return st;
}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::deleteHelper(BSTNode<T>* st){

  BSTNode<T>* save = st->getRight();

  if(save == nullptr){
    save = st->getLeft();
    delete st;
    return save;
  }

  if(save->getLeft() == nullptr){
    save->setLeft(st->getLeft());
    delete st;
    return save;
  }

  while(save->getLeft()->getLeft() != nullptr) save = save->getLeft();
  st->setValue(save->getLeft()->getValue());
  save->setLeft(deleteHelper(save->getLeft()));
  return st;

}
