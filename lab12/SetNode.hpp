// 5/5

#ifndef SETNODE_HPP
#define SETNODE_HPP

template <typename T>
class Set;

#include "Set.hpp"

template <typename T>
class SetNode{
public:

  SetNode(const T& item, SetNode<T>* parent);
  SetNode(const T& item, Set<T>* myset);

  T getItem() const;
  void setItem(const T& item);

  SetNode<T>* getParent() const;
  void setParent(SetNode<T>* parent);

  Set<T>* getMySet() const;
  void setMySet(Set<T>* myset);

  SetNode<T>* getPrev() const;
  void setPrev(SetNode<T>* prev);

  SetNode<T>* getNext() const;
  void setNext(SetNode<T>* next);

private:

  Set<T>* myset;
  T item;
  SetNode<T>* parent;

  SetNode<T>* prev;
  SetNode<T>* next;

};

#include "SetNode.cpp"

#endif // SETNODE_HPP
