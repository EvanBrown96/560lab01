template <typename T>
Levelorder<T>::Levelorder(const BinarySearchTree<T>& bst):
  Traversal<T>(bst){

  int index = 0;
  creationHelper(bst.root, index);
}

template <typename T>
void Levelorder<T>::creationHelper(BSTNode<T>* st, int& index){
  if(st != nullptr){
    this->values[index] = new T(st->getValue());
    index += 1;
    creationHelper(st->getLeft(), index);
    creationHelper(st->getRight(), index);
  }
}
