/**
 * @author: Evan Brown
 * @file: BinarySearchTree.hpp
 * @date: 2/27/19
 * @brief: definition of binary search tree methods
 *         adapted from 560 lab 5
 */

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

template <typename T> class Traversal;
template <typename T> class Preorder;
template <typename T> class Inorder;
template <typename T> class Postorder;
template <typename T> class Levelorder;

#include "BSTNode.hpp"
#include "ValueNotFound.hpp"
#include "EmptyStructure.hpp"
#include "Preorder.hpp"
#include "Postorder.hpp"
#include "Inorder.hpp"
#include "Levelorder.hpp"

template <typename T>
class BinarySearchTree{
public:

    /**
     * constructor
     * @post: tree initialized with size 0 and root nullptr
     */
    BinarySearchTree();

    /**
     * destructor
     * @post: all nodes previously in the tree are deleted
     */
    ~BinarySearchTree();

    /**
     * copy constructor
     * @param bst: tree to make a copy of
     * @post: new tree initialized with a copy of all the data in 'bst'
     */
    BinarySearchTree(const BinarySearchTree<T>& bst);

    /**
     * assignment operator
     * @param bst: tree to make this tree a copy of
     * @return: reference to current tree, for chaining
     * @post: all data currently in this tree is deleted; all data from 'bst'
     *        is copied into this tree
     */
    BinarySearchTree<T>& operator=(const BinarySearchTree<T>& bst);

    /**
     * factory method that returns an optimal bst based on the data in the given linked list
     * @param data: linked list containing data to create optimal bst with
     * @return: a binary search tree with optimal search complexity for the given data
     */
    static BinarySearchTree<T> OptimalBSTFactory(T data[], int size);

    /**
     * puts a value into the tree
     * @param value: the value to insert into the tree
     * @post: the value is inserted into the tree
     */
    void insert(const T& value);

    /**
     * removes a value from the tree
     * @param value: the value to remove from the tree
     * @throw ValueNotFound<T>: if the given value is not in the tree
     * @post: the highest occurance of the given value is removed from the tree
     */
    void deleteVal(const T& value) throw(ValueNotFound<T>);

    /**
     * test is a value is in the tree
     * @param value: the value to look for
     * @return: true if the value is in the tree, otherwise false
     */
    bool find(const T& value) const;

    /**
     * find the min (leftmost) value in the tree
     * @throw EmptyStructure: if the tree is empty (and therefore has no min)
     * @return: the smallest value in the tree
     */
    T findMin() const throw(EmptyStructure);

    /**
     * find the max (rightmost) value in the tree
     * @throw EmptyStructure: if the tree is empty (and therefore has no max)
     * @return: the largest value in the tree
     */
    T findMax() const throw(EmptyStructure);

    /**
     * do a preorder traversal of the tree
     * @return: a Preorder instance corresponding to this tree
     */
    Preorder<T> preorder() const;

    /**
     * do a inorder traversal of the tree
     * @return: a Inorder instance corresponding to this tree
     */
    Inorder<T> inorder() const;

    /**
     * do a postorder traversal of the tree
     * @return: a Postorder instance corresponding to this tree
     */
    Postorder<T> postorder() const;

    /**
     * do a levelorder traversal of the tree
     * @return: a Levelorder instance corresponding to this tree
     */
    Levelorder<T> levelorder() const;

    friend class Traversal<T>;
    friend class Preorder<T>;
    friend class Inorder<T>;
    friend class Postorder<T>;
    friend class Levelorder<T>;

private:

  BSTNode<T>* root;
  int size;

  // unused
  void printVisual() const;

  void destroySubtree(BSTNode<T>* st);
  BSTNode<T>* copySubtree(BSTNode<T>* st);

  BSTNode<T>* insertHelper(BSTNode<T>* st, const T& value);
  bool findHelper(BSTNode<T>* st, const T& value) const;

  BSTNode<T>* deleteFinder(BSTNode<T>* st, const T& value) throw(ValueNotFound<T>);
  BSTNode<T>* deleteHelper(BSTNode<T>* st);

  struct OptimalItemData{
  public:
    T data;
    int pos;
    int freq;

    OptimalItemData(const T& data, int pos, int freq): data(data), pos(pos), freq(freq){}

    bool operator ==(const OptimalItemData& cmp){ return (data == cmp.data); }
    bool operator !=(const OptimalItemData& cmp){ return (data != cmp.data); }
    bool operator >(const OptimalItemData& cmp){ return (data > cmp.data); }
    bool operator <(const OptimalItemData& cmp){ return (data < cmp.data); }
    bool operator >=(const OptimalItemData& cmp){ return (data >= cmp.data); }
    bool operator <=(const OptimalItemData& cmp){ return (data <= cmp.data); }
  };

};

#include "BinarySearchTree.cpp"

#endif
