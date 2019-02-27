#ifndef TRAVERSAL_HPP
#define TRAVERSAL_HPP

template <typename T> class BinarySearchTree;

#include "BinarySearchTree.hpp"
#include <iostream>

template <typename T>
class Traversal{
public:

  ~Traversal();

  template <typename U>
  friend std::ostream& operator<<(std::ostream& stream, const Traversal<U>& t);

protected:

  T** values;
  int size;

  Traversal();

};

#include "Traversal.cpp"

#endif
