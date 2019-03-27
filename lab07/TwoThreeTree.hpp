/**
 * @author: Evan Brown
 * @file: TwoThreeTree.hpp
 * @date: 3/25/19
 * @brief: specification of 2-3 tree methods
 */

#ifndef TWOTHREETREE_HPP
#define TWOTHREETREE_HPP

#include "TwoThreeNode.hpp"
#include "ValueNotFound.hpp"
#include "EmptyStructure.hpp"
#include "DuplicateValue.hpp"
#include "QuickQueue.hpp"

template <typename T>
class TwoThreeTree{
public:

  TwoThreeTree();
  ~TwoThreeTree();

  TwoThreeTree(const TwoThreeTree<T>& copy);
  TwoThreeTree<T>& operator=(const TwoThreeTree<T>& copy);

  void insert(const T& value) throw(DuplicateValue<T>);
  void remove(const T& value) throw(ValueNotFound<T>);
  void removeMin() throw(EmptyStructure);
  void removeMax() throw(EmptyStructure);
  bool find(const T& value) const;
  T findMin() const throw(EmptyStructure);
  T findMax() const throw(EmptyStructure);

  QuickQueue<T> levelOrder() const;

private:

  TwoThreeNode<T>* root;

  void destroyTree(TwoThreeNode<T>* tree);
  TwoThreeNode<T>* copyTree(TwoThreeNode<T>* tree);

  TwoThreeNode<T>* insertHelper(const T& value, TwoThreeNode<T>* tree, bool& kick_up);
  bool findHelper(const T& value, TwoThreeNode<T>* tree) const;

  void removeHelperFindStage(const T& value, TwoThreeNode<T>* tree) throw(ValueNotFound<T>);
  T removeHelperSingleLeftStage(TwoThreeNode<T>* tree);
  T removeHelperFindPredecessorStage(TwoThreeNode<T>* tree);

};

#include "TwoThreeTree.cpp"

#endif
