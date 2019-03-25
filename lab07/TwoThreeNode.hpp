/**
 * @author: Evan Brown
 * @file: TwoThreeNode.hpp
 * @date: 3/25/19
 * @brief: specification of 2-3 node methods
 */

#ifndef TWOTHREENODE_HPP
#define TWOTHREENODE_HPP

enum NodeType { TWO, THREE };

// typedef NodeType enum NodeType;

template <typename T>
class TwoThreeNode{
public:

  TwoThreeNode(enum NodeType ntype);

  enum NodeType getType() const;

private:

  enum NodeType ntype;

};


template <typename T>
class TwoNode: public TwoThreeNode<T>{
public:

  TwoNode(const T& value);

  T getVal() const;

  TwoThreeNode<T>* getLeftTree() const;
  TwoThreeNode<T>* getRightTree() const;

  void setVal(const T& value);

  void setLeftTree(TwoThreeNode<T>* tree);
  void setRightTree(TwoThreeNode<T>* tree);

private:

  T value;
  TwoThreeNode<T>* ltree;
  TwoThreeNode<T>* rtree;

};

template <typename T>
class ThreeNode: public TwoThreeNode<T>{
public:

  ThreeNode(const T& lvalue, const T& rvalue);

  T getLeftVal() const;
  T getRightVal() const;

  TwoThreeNode<T>* getLeftTree() const;
  TwoThreeNode<T>* getMiddleTree() const;
  TwoThreeNode<T>* getRightTree() const;

  void setLeftVal(const T& value);
  void setRightVal(const T& value);

  void setLeftTree(TwoThreeNode<T>* tree);
  void setMiddleTree(TwoThreeNode<T>* tree);
  void setRightTree(TwoThreeNode<T>* tree);

private:

  T lvalue;
  T rvalue;
  TwoThreeNode<T>* ltree;
  TwoThreeNode<T>* mtree;
  TwoThreeNode<T>* rtree;

};

#include "TwoThreeNode.cpp"

#endif
