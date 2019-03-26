/**
 * @author: Evan Brown
 * @file: TwoThreeNode.hpp
 * @date: 3/25/19
 * @brief: specification of 2-3 node methods
 */

#ifndef TWOTHREENODE_HPP
#define TWOTHREENODE_HPP

#include "InvalidNodeType.hpp"
#include "EmptyStructure.hpp"

enum NodeType { TWO, THREE };

template <typename T>
class TwoThreeNode{
public:

  TwoThreeNode(const T& value);
  TwoThreeNode(const T& lvalue, const T& rvalue);

  enum NodeType getType() const;

  // 2-node only
  T getVal() const throw(InvalidNodeType);
  void setVal(const T& value) throw(InvalidNodeType);

  // 3-node only
  T getLeftVal() const throw(InvalidNodeType);
  T getRightVal() const throw(InvalidNodeType);
  void setLeftVal(const T& value) throw(InvalidNodeType);
  void setRightVal(const T& value) throw(InvalidNodeType);

  TwoThreeNode<T>* getMiddleTree() const throw(InvalidNodeType);
  void setMiddleTree(TwoThreeNode<T>* tree) throw(InvalidNodeType);

  void absorbMiddleKickUp() throw(InvalidNodeType, EmptyStructure);

  // both
  TwoThreeNode<T>* getLeftTree() const;
  TwoThreeNode<T>* getRightTree() const;

  void setLeftTree(TwoThreeNode<T>* tree);
  void setRightTree(TwoThreeNode<T>* tree);

  void absorbLeftKickUp() throw(InvalidNodeType, EmptyStructure);
  void absorbRightKickUp() throw(InvalidNodeType, EmptyStructure);

private:

  enum NodeType ntype;

  T lvalue;
  T rvalue;
  TwoThreeNode<T>* ltree;
  TwoThreeNode<T>* mtree;
  TwoThreeNode<T>* rtree;

};

#include "TwoThreeNode.cpp"

#endif
