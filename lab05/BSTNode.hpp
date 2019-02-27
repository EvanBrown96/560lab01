/**
 * @author: Evan Brown
 * @file: BSTNode.hpp
 * @date: 2/27/19
 * @brief: declaration of binary search tree node methods
 */

#ifndef BSTNODE_HPP
#define BSTNODE_HPP

template <typename T>
class BSTNode{
public:

  BSTNode(const T& value);
  BSTNode(const T& value, BSTNode<T>* lst, BSTNode<T>* rst);

  T getValue() const;
  void setValue(const T& value);

  BSTNode<T>* getLeft() const;
  BSTNode<T>* getRight() const;

  void setLeft(BSTNode<T>* lst);
  void setRight(BSTNode<T>* rst);

  BSTNode<T>* getChildlessCopy() const;

private:

  T value;
  BSTNode<T>* lst;
  BSTNode<T>* rst;

};

#include "BSTNode.cpp"

#endif
