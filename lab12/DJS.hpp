// 5/5

#ifndef DJS_HPP
#define DJS_HPP

#include "SetNode.hpp"
#include "Set.hpp"

#define DJS_INIT_SIZE 8

template <typename T>
class DJS{
public:

  DJS();
  ~DJS();
  DJS(const DJS<T>& copy);
  DJS<T>& operator=(const DJS<T>& copy);

  void makeSet(const T& item);
  void makeSet(const T* items, int count);

  Set<T>* find(const T& item);
  void setUnion(const T& item1, const T& item2);
  void setUnion(Set<T>* s1, Set<T>* s2);

private:

  Set<T>* first_set;
  Set<T>* last_set;

  SetNode<T>* first_node;
  SetNode<T>* last_node;

  void addSet(Set<T>* new_set);
  void removeSet(Set<T>* rem_set);

  void addNode(SetNode<T>* new_node);
  void removeNode(SetNode<T>* rem_node);

  void destroyDJS();
  void copyDJS(const DJS<T>& copy);

};

#include "DJS.cpp"

#endif // DJS_HPP
