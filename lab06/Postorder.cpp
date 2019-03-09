/**
 * @author: Evan Brown
 * @file: Postorder.cpp
 * @date: 2/27/19
 * @brief: definition of how to create a post order traversal from a bst
 *         adapted from 560 lab 5
 */

template <typename T>
Postorder<T>::Postorder(const BinarySearchTree<T>& bst):
  Traversal<T>(bst){

  int index = 0;
  creationHelper(bst.root, index);
}

template <typename T>
void Postorder<T>::creationHelper(BSTNode<T>* st, int& index){
  if(st != nullptr){
    creationHelper(st->getLeft(), index);
    creationHelper(st->getRight(), index);
    this->values[index] = new T(st->getValue());
    index += 1;
  }
}
