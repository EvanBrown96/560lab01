/**
 * @author: Evan Brown
 * @file: Postorder.hpp
 * @date: 2/27/19
 * @brief: definition of post order traversal methods
 *         adapted from 560 lab 5
 */

#ifndef POSTORDER_HPP
#define POSTORDER_HPP

#include "Traversal.hpp"

template <typename T>
class Postorder: public Traversal<T>{
public:

  Postorder(const BinarySearchTree<T>& bst);

private:

  void creationHelper(BSTNode<T>* st, int& index);

};

#include "Postorder.cpp"

#endif
