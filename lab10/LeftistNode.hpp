// 4/17

#ifndef LEFTISTNODE_HPP
#define LEFTISTNODE_HPP

template <typename T>
class LeftistNode{

public:

  LeftistNode(const T& item);

  T get() const;
  void set(const T& item);

  LeftistNode<T>* getLeft() const;
  void setLeft(LeftistNode<T>* left);

  LeftistNode<T>* getRight() const;
  void setRight(LeftistNode<T>* right);

  int getRank() const;
  
private:

  T item;
  int rank;
  LeftistNode<T>* left;
  LeftistNode<T>* right;

  void calcRank();

};

#include "LeftistNode.cpp"

#endif // LEFTISTNODE_HPP
