/**
 * @author: Evan Brown
 * @file: Node.hpp
 * @date: 1/25/19
 * @brief: header file for Node object
 *         adapted from 560 lab 1
 */

#ifndef Node_hpp
#define Node_hpp

template <typename A>
class Node{

public:

  /**
   * constructor
   * @param value: value to put in the node
   * @post: node is created with the given value and nullptr as next
   */
  Node(const A& value);

  /**
   * constructor
   * @param value: value to put in the node
   * @param next: subsequent node in the list
   * @post: node is created with the given value and next pointer
   */
  Node(const A& value, Node<A>* next);

  /**
   * sets the next pointer
   * @param next: new node to point to
   * @post: the next pointer is set to "next"
   */
  void setNext(Node<A>* next);

  /**
   * returns the next pointer
   * @return: the node pointed to in "next"
   */
  Node<A>* getNext() const;

  /**
   * sets the value in the node
   * @param value: new value to put in node
   * @post: the value is set to "value"
   */
  void setValue(const A& value);

  /**
   * returns the value in the node
   * @return: the value in node
   */
  A getValue() const;

private:

  Node<A>* next;
  A value;

};

#include "Node.cpp"

#endif
