template <typename A>
class Node{

public:

  Node(const A& value);
  Node(const A& value, Node<A>* next);
  ~Node();

  void setNext(Node<A>* next);
  Node<A>* getNext() const;

  void setValue(const A& value);
  A getValue() const;

private:

  Node<A>* next;
  A value;

};

#include "Node.cpp"
