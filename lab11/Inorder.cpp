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
