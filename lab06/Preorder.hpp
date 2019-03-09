/**
 * @author: Evan Brown
 * @file: Preorder.hpp
 * @date: 2/27/19
 * @brief: definition of pre order traversal methods
 *         adapted from 560 lab 5
 */

#ifndef PREORDER_HPP
#define PREORDER_HPP

#include "Traversal.hpp"

template <typename T>
class Preorder: public Traversal<T>{
public:

  Preorder(const BinarySearchTree<T>& bst);

private:

  void creationHelper(BSTNode<T>* st, int& index);

};

#include "Preorder.cpp"

#endif
