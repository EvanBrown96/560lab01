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

enum NodeType { HOLE, TWO, THREE };

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

  // hole node only
  TwoThreeNode<T>* getTree() const throw(InvalidNodeType);
  void setTree(TwoThreeNode<T>* tree) throw(InvalidNodeType);

  // 2-node and 3-node
  TwoThreeNode<T>* getLeftTree() const throw(InvalidNodeType);
  TwoThreeNode<T>* getRightTree() const throw(InvalidNodeType);

  void setLeftTree(TwoThreeNode<T>* tree) throw(InvalidNodeType);
  void setRightTree(TwoThreeNode<T>* tree) throw(InvalidNodeType);

  void absorbLeftKickUp() throw(InvalidNodeType, EmptyStructure);
  void absorbRightKickUp() throw(InvalidNodeType, EmptyStructure);

private:

  enum NodeType ntype;

  T lvalue;
  T rvalue;
  TwoThreeNode<T>* ltree;
  TwoThreeNode<T>* mtree;
  TwoThreeNode<T>* rtree;

  void checkInvalidType(enum NodeType safe) const throw(InvalidNodeType);
  void checkInvalidType(enum NodeType safe, enum NodeType safe2) const throw(InvalidNodeType);

};

#include "TwoThreeNode.cpp"

#endif
