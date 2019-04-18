// 4/16

#ifndef SKEWNODE_HPP
#define SKEWNODE_HPP

template <typename T>
class SkewNode{

public:

  SkewNode(const T& item);

  T get() const;
  void set(const T& item);

  SkewNode<T>* getLeft() const;
  void setLeft(SkewNode<T>* left);

  SkewNode<T>* getRight() const;
  void setRight(SkewNode<T>* right);

private:

  T item;
  SkewNode<T>* left;
  SkewNode<T>* right;

};

#include "SkewNode.cpp"

#endif // SKEWNODE_HPP
