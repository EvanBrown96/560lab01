/**
 * @author: Evan Brown
 * @file: Levelorder.hpp
 * @date: 2/27/19
 * @brief: definition of level order traversal methods
 *         adapted from 560 lab 5
 */

#ifndef LEVELORDER_HPP
#define LEVELORDER_HPP

#include "Traversal.hpp"

template <typename T>
class Levelorder: public Traversal<T>{
public:

  Levelorder(const BinarySearchTree<T>& bst);

private:

  void creationHelper(BSTNode<T>* st, int& index);

};

#include "Levelorder.cpp"

#endif
