/**
 * @author: Evan Brown
 * @file: Inorder.hpp
 * @date: 2/27/19
 * @brief: definition of in order traversal methods
 *         adapted from 560 lab 5
 */

#ifndef INORDER_HPP
#define INORDER_HPP

#include "Traversal.hpp"

template <typename T>
class Inorder: public Traversal<T>{
public:

  Inorder(const BinarySearchTree<T>& bst);

private:

  void creationHelper(BSTNode<T>* st, int& index);

};

#include "Inorder.cpp"

#endif
