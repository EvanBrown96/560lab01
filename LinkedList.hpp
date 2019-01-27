#include "Node.hpp"
#include "ValueNotFound.hpp"
#include "EmptyList.hpp"

template <typename A>
class LinkedList{

public:

  LinkedList();

  LinkedList(const LinkedList<A>& copy_list);

  ~LinkedList();

  LinkedList<A>& operator =(const LinkedList<A>& copy_list);

  bool isEmpty() const;

  void insert(const A& value);

  void deleteVal(const A& value) throw(ValueNotFound<A>);

  A smallest() const throw(EmptyList);

  A largest() const throw(EmptyList);

  A average() const throw(EmptyList);

  void merge2lists(const LinkedList<A>& newlist);

  void print() const;

private:

  Node<A>* head;
  Node<A>* tail;

  void removeEverything();
  void copyEverything(const LinkedList<A>& copy_list);
  void mergeHelper(LinkedList<A>& operand, A& value);

  Node<A>* merge_new_head;
  Node<A>* merge_prev;
  Node<A>* merge_next;


};

#include "LinkedList.cpp"
