/**
 * @author: Evan Brown
 * @file: Node.hpp
 * @date: 1/25/19
 * @brief: header file for Node object
 *         adapted from 560 lab 3
 */

#ifndef NODE_HPP
#define NODE_HPP

template <typename T>
class Node{

public:

  /**
   * constructor
   * @param value: value to put in the node
   * @post: node is created with the given value and nullptr as next
   */
  Node(const T& value);

  /**
   * constructor
   * @param value: value to put in the node
   * @param next: subsequent node in the list
   * @post: node is created with the given value and next pointer
   */
  Node(const T& value, Node<T>* next);

  /**
   * sets the next pointer
   * @param next: new node to point to
   * @post: the next pointer is set to "next"
   */
  void setNext(Node<T>* next);

  /**
   * returns the next pointer
   * @return: the node pointed to in "next"
   */
  Node<T>* getNext() const;

  /**
   * sets the value in the node
   * @param value: new value to put in node
   * @post: the value is set to "value"
   */
  void setValue(const T& value);

  /**
   * returns the value in the node
   * @return: the value in node
   */
  T getValue() const;

private:

  Node<T>* next;
  T value;

};

#include "Node.cpp"

#endif
