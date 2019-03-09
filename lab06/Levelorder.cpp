/**
 * @author: Evan Brown
 * @file: Levelorder.cpp
 * @date: 2/27/19
 * @brief: definition of how to create an level order traversal from a bst
 *         adapted from 560 lab 5
 */

#include "QuickQueue.hpp"

template <typename T>
Levelorder<T>::Levelorder(const BinarySearchTree<T>& bst):
  Traversal<T>(bst){

  int index = 0;
  creationHelper(bst.root, index);
}

template <typename T>
void Levelorder<T>::creationHelper(BSTNode<T>* st, int& index){

  if(st != nullptr){
    QuickQueue<BSTNode<T>> qq(this->size);
    qq.push(*st);

    while(!qq.isEmpty()){
      BSTNode<T> next = qq.pop();

      this->values[index] = new T(next.getValue());
      index += 1;

      if(next.getLeft() != nullptr) qq.push(*next.getLeft());
      if(next.getRight() != nullptr) qq.push(*next.getRight());
    }
  }

}
