/**
 * @author: Evan Brown
 * @file: Inorder.cpp
 * @date: 2/27/19
 * @brief: definition of how to create an in order traversal from a bst
 *         adapted from 560 lab 5
 */

template <typename T>
Inorder<T>::Inorder(const BinarySearchTree<T>& bst):
  Traversal<T>(bst){

  int index = 0;
  creationHelper(bst.root, index);
}

template <typename T>
void Inorder<T>::creationHelper(BSTNode<T>* st, int& index){
  if(st != nullptr){
    creationHelper(st->getLeft(), index);
    this->values[index] = new T(st->getValue());
    index += 1;
    creationHelper(st->getRight(), index);
  }
}
