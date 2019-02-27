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
