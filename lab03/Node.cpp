/**
 * @author: Evan Brown
 * @file: Node.cpp
 * @date: 1/25/19
 * @brief: implementation of Node methods
 *         adapted from 560 lab 2
 */

template <typename A>
Node<A>::Node(const A& value): value(value), next(nullptr){

}

template <typename A>
Node<A>::Node(const A& value, Node<A>* next): value(value), next(next){

}

template <typename A>
void Node<A>::setNext(Node<A>* next){
  this->next = next;
}

template <typename A>
Node<A>* Node<A>::getNext() const{
  return next;
}

template <typename A>
void Node<A>::setValue(const A& value){
  this->value = value;
}

template <typename A>
A Node<A>::getValue() const{
  return value;
}
