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
