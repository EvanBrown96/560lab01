// 4/16

#ifndef LEFTISTHEAP_HPP
#define LEFTISTHEAP_HPP

#include "LeftistNode.hpp"
#include "QuickQueue.hpp"
#include "EmptyStructure.hpp"

template <typename T>
class LeftistHeap{

public:

  LeftistHeap();

  LeftistHeap(const QuickQueue<T>& initial_data);

  ~LeftistHeap();

  LeftistHeap(const LeftistHeap<T>& copy);

  LeftistHeap<T>& operator=(const LeftistHeap<T>& copy);

  static LeftistHeap<T> merge(const LeftistHeap<T>& h1, const LeftistHeap<T>& h2);

  void insert(const T& item);

  void deleteMax();

  T findMax() const;

  bool isEmpty() const;

  QuickQueue<T> inorder() const;

  QuickQueue<T> preorder() const;

  QuickQueue<T> postorder() const;

  QuickQueue<T> levelorder() const;

private:

  SkewNode<T>* root;

  void destroyHeap(LeftistNode<T>* subtree);

  SkewNode<T>* copyHeap(SkewNode<T>* subtree);

  static SkewNode<T>* baseMerge(SkewNode<T>* st1, SkewNode<T>* st2);

  void preorderHelper(LeftistNode<T>* subtree, QuickQueue<T>& qq) const;

  void inorderHelper(LeftistNode<T>* subtree, QuickQueue<T>& qq) const;

  void postorderHelper(LeftistNode<T>* subtree, QuickQueue<T>& qq) const;

};

#include "LeftistHeap.cpp"

#endif // LEFTISTHEAP_HPP
