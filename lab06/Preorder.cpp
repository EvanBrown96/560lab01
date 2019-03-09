/**
 * @author: Evan Brown
 * @file: Preorder.cpp
 * @date: 2/27/19
 * @brief: definition of how to create a pre order traversal from a bst
 *         adapted from 560 lab 5
 */

template <typename T>
Preorder<T>::Preorder(const BinarySearchTree<T>& bst):
  Traversal<T>(bst){

  int index = 0;
  creationHelper(bst.root, index);
}

template <typename T>
void Preorder<T>::creationHelper(BSTNode<T>* st, int& index){
  if(st != nullptr){
    this->values[index] = new T(st->getValue());
    index += 1;
    creationHelper(st->getLeft(), index);
    creationHelper(st->getRight(), index);
  }
}
