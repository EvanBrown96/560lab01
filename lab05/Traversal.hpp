#ifndef TRAVERSAL_HPP
#define TRAVERSAL_HPP

template <typename T> class BinarySearchTree;

#include "BinarySearchTree.hpp"
#include <iostream>

template <typename T>
class Traversal{
public:

  Traversal(const BinarySearchTree<T>& bst);
  ~Traversal();

  template <typename U>
  friend std::ostream& operator<<(std::ostream& stream, const Traversal<U>& t);

protected:

  T** values;
  int size;

  virtual void creationHelper(BSTNode<T>* st, int& index) = 0;

};

#include "Traversal.cpp"

#endif
