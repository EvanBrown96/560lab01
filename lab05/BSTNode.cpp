/**
 * @author: Evan Brown
 * @file: BSTNode.cpp
 * @date: 2/27/19
 * @brief: implemetation of binary search tree node
 */

template <typename T>
BSTNode<T>::BSTNode(const T& value):
  value(value), lst(nullptr), rst(nullptr){}

template <typename T>
BSTNode<T>::BSTNode(const T& value, BSTNode<T>* lst, BSTNode<T>* rst):
  value(value), lst(lst), rst(rst){}

template <typename T>
T BSTNode<T>::getValue() const{
  return value;
}

template <typename T>
void BSTNode<T>::setValue(const T& value){
  this->value = value;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getLeft() const{
  return lst;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getRight() const{
  return rst;
}

template <typename T>
void BSTNode<T>::setLeft(BSTNode<T>* lst){
  this->lst = lst;
}

template <typename T>
void BSTNode<T>::setRight(BSTNode<T>* rst){
  this->rst = rst;
}

template <typename T>
BSTNode<T>* BSTNode<T>::getChildlessCopy() const{
  BSTNode<T>* copy = new BSTNode<T>(*this);
  copy->lst = nullptr;
  copy->rst = nullptr;
  return copy;
}
