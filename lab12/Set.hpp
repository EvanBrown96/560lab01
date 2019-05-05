// 5/5

#ifndef SET_HPP
#define SET_HPP

template <typename T>
class SetNode;

template <typename T>
class DJS;

#include "SetNode.hpp"
#include "DJS.hpp"

template <typename T>
class Set{
public:

  Set(SetNode<T>* root, int rank=0);
  Set(const T& item);

  T getRootItem() const;

  bool operator==(const Set<T>& test) const;
  bool operator!=(const Set<T>& test) const;

  friend class DJS<T>;

private:

  SetNode<T>* root;
  int rank;

  Set<T>* prev;
  Set<T>* next;

  int getRank() const;
  void setRank(int rank);

  SetNode<T>* getRoot() const;
  void setRoot(SetNode<T>* root);

  Set<T>* getPrev() const;
  void setPrev(Set<T>* prev);

  Set<T>* getNext() const;
  void setNext(Set<T>* next);

};

#include "Set.cpp"

#endif // SET_HPP
