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
