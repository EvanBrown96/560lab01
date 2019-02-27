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
