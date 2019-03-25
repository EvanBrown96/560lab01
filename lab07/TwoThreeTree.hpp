/**
 * @author: Evan Brown
 * @file: TwoThreeTree.hpp
 * @date: 3/25/19
 * @brief: specification of 2-3 tree methods
 */

#ifndef TWOTHREETREE_HPP
#define TWOTHREETREE_HPP

#include "ValueNotFound.hpp"
#include "EmptyStructure.hpp"

template <typename T>
class TwoThreeTree{
public:

  TwoThreeTree();
  ~TwoThreeTree();

  TwoThreeTree(const TwoThreeTree<T>& copy);
  TwoThreeTree<T>& operator=(const TwoThreeTree<T>& copy);

  void insert(const T& value);
  void remove(const T& value) throw(ValueNotFound<T>);
  void removeMin() throw(EmptyStructure);
  void removeMax() throw(EmptyStructure);
  bool find(const T& value) const;
  T findMin() const throw(EmptyStructure);
  T findMax() const throw(EmptyStructure);

  // List<T> levelOrder() const;
};

#include "TwoThreeTree.cpp"

#endif
