/**
 * @author: Evan Brown
 * @file: Node.cpp
 * @date: 1/25/19
 * @brief: implementation of Node methods
 *         adapted from 560 lab 3
 */

template <typename T>
Node<T>::Node(const T& value): value(value), next(nullptr){

}

template <typename T>
Node<T>::Node(const T& value, Node<T>* next): value(value), next(next){

}

template <typename T>
void Node<T>::setNext(Node<T>* next){
  this->next = next;
}

template <typename T>
Node<T>* Node<T>::getNext() const{
  return next;
}

template <typename T>
void Node<T>::setValue(const T& value){
  this->value = value;
}

template <typename T>
T Node<T>::getValue() const{
  return value;
}
