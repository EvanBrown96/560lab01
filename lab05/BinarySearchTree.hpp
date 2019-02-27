/**
 * @author: Evan Brown
 * @file: BinarySearchTree.hpp
 * @date: 2/27/19
 * @brief: definition of binary search tree methods
 */

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

template <typename T> class Traversal;
template <typename T> class Preorder;
template <typename T> class Inorder;
template <typename T> class Levelorder;

#include "BSTNode.hpp"
#include "ValueNotFound.hpp"
#include "EmptyTree.hpp"
#include "Preorder.hpp"

template <typename T>
class BinarySearchTree{
public:

    BinarySearchTree();
    ~BinarySearchTree();

    BinarySearchTree(const BinarySearchTree<T>& bst);
    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& bst);

    void insert(const T& value);
    void deleteVal(const T& value) throw(ValueNotFound<T>);
    bool find(const T& value);

    T findMin() throw(EmptyTree);
    T findMax() throw(EmptyTree);

    Preorder<T> preorder() const;

    friend class Traversal<T>;
    friend class Preorder<T>;
    friend class Inorder<T>;
    friend class Postorder<T>;
    friend class Levelorder<T>;

private:

  BSTNode<T>* root;
  int size;

  void destroySubtree(BSTNode<T>* st);
  BSTNode<T>* copySubtree(BSTNode<T>* st);

  BSTNode<T>* insertHelper(BSTNode<T>* st, const T& value);
  bool findHelper(BSTNode<T>* st, const T& value) const;

};

#include "BinarySearchTree.cpp"

#endif
